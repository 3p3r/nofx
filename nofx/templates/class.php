<?php
require_once("phpQuery/phpQuery.php");
$className = lcfirst($_GET["className"]);
$url = $_GET["url"];
$deps = isset($_GET['deps']) ? explode(",", $_GET['deps']) : false;

$ofDocPageStr = file_get_contents($url);
$ofDocPage = phpQuery::newDocument($ofDocPageStr);
$methods = array();
$functions = array();
$variables = array();
foreach($ofDocPage['ul.functionslist li a'] as $node) {
    if($node->nodeValue != $className."()") {
        if(substr($node->nodeValue, 0, 2) == "of" && substr($node->nodeValue, -2) == "()") {
            //this is a global function
            array_push($functions, str_replace("()", "", $node->nodeValue ));
        } else if (substr($node->nodeValue, -2) == "()" && !strstr($node->nodeValue, "operator")) {
            //this is a class method
            array_push($methods, str_replace("()", "", $node->nodeValue ));
        } else if(!strstr($node->nodeValue, "operator")) {
            //this is a variable
            $temp = explode(" ", $node->nodeValue);
            array_push($variables, end($temp) );
        } else {
            //this is either unknown or an operator overload
        }
    }
}

function makeHeader($methods, $variables, $className) {
    $lClassName = lcfirst($className);
    $uClassName = ucfirst($className);
    $guard = strtoupper(preg_replace('/(?<=\\w)(?=[A-Z])/',"_$1", $className));
    $count = 1;
    $trimmedName = ucfirst(str_ireplace("of", "", $className, $count));
    $methodsTmpl = "";
    foreach($methods as $method) {
        $methodsTmpl .= "\n            static NAN_METHOD(".ucfirst($method).");";
    }
    
    $getters = "";
    $setters = "";
    foreach($variables as $var) {
        $getters .= "\n            static NAN_GETTER(Get".ucfirst($var).");";
        $setters .= "\n            static NAN_SETTER(Set".ucfirst($var).");";
    }
    
    $template = <<<TMP
#ifndef _NOFX_{$guard}_H_
#define _NOFX_{$guard}_H_

#include "globals.h"
#include <memory>
#include "{$className}.h"
#include "..\\nofx\\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
    namespace {$uClassName}
    {
        class {$uClassName}Wrap
            : public nofx::ObjectWrap< {$lClassName} >
        {

            DeclareObjectRoutines({$trimmedName});
            {$getters}
            {$setters}
            {$methodsTmpl}

        }; // !class {$uClassName}Wrap
    } //!namespace {$uClassName}
} // !namespace nofx

#endif // !_NOFX_{$guard}_H_
    
TMP;

    return $template;
}

function makeSource($methods, $variables, $className, $deps = false) {
    $lClassName = lcfirst($className);
    $uClassName = ucfirst($className);
    $uuClassName = strtoupper($className);
    $protoTmpl = "";
    $methodsTmpl = "";
    $depHeader = "";
    
    if($deps) {
        foreach($deps as $dep) {
            $depHeader .= "\n".'#include "..\nofx_'.$dep.'\nofx_'.$dep.'.h"';
        }
    }
    
    foreach($methods as $method) {
        $protoTmpl .= "\n            NanSetPrototypeTemplate(tpl, NanNew(\"".lcfirst($method)."\"), NanNew<v8::FunctionTemplate>(".ucfirst($method)."), v8::ReadOnly);";

        $methodsTmpl .= "\n        //---------------------------------------------------------\n";
        $methodsTmpl .= "        NAN_METHOD({$uClassName}Wrap::".ucfirst($method).")\n";
        $methodsTmpl .= "        {\n";
        $methodsTmpl .= "            auto self = ObjectWrap::Unwrap<{$uClassName}Wrap>(args.This())->GetWrapped();\n";
        $methodsTmpl .= "            //auto target = ObjectWrap::Unwrap<{$uClassName}Wrap>(args[0]->ToObject())->GetWrapped();\n";
        $methodsTmpl .= "            //implementation\n";
        $methodsTmpl .= "            NanReturnUndefined();\n";
        $methodsTmpl .= "        }\n";
    }
    
    $mutators = "";
    $getters = "";
    $setters = "";
    foreach($variables as $var) {
        $mutators .= "\n            inst->SetAccessor(NanNew(\"".$var."\"), {$uClassName}Wrap::Get".ucfirst($var).", {$uClassName}Wrap::Set".ucfirst($var).");";
        $getters .= "\n            NAN_GETTER({$uClassName}Wrap::Get".ucfirst($var).")
            {
                const auto self = ObjectWrap::Unwrap<{$uClassName}Wrap>(args.This())->GetWrapped();
                NanReturnValue(self->".$var.");
            }
            //----------------------------------------------------\n";
        $setters .= "\n            NAN_SETTER({$uClassName}Wrap::Set".ucfirst($var).")
            {
                auto self = ObjectWrap::Unwrap<{$uClassName}Wrap>(args.This())->GetWrapped();
                self->".$var." = value->NumberValue();
            }
            //----------------------------------------------------\n";
    }
    
    $template = <<<TMP
#include "nofx_{$lClassName}.h"
#include "..\\nofx\\nofx_types.h"{$depHeader}

namespace nofx
{
    namespace {$uClassName}
    {
        using node::ObjectWrap;
    
        Persistent<Function> {$uClassName}Wrap::constructor;

        NAN_METHOD({$uClassName}Wrap::New)
        {
            NanScope();
            if (args.IsConstructCall()) {
                {$uClassName}Wrap* obj;
                if (args[0]->IsNull())
                {
                    obj = new {$uClassName}Wrap(nullptr);
                }
                else if (args.Length() == 0)
                {
                    obj = new {$uClassName}Wrap();
                }
                else
                {
                    //copy constructor
                    obj = new {$uClassName}Wrap(ObjectWrap::Unwrap<{$uClassName}Wrap>(args[0]->ToObject())->GetWrapped());
                }
                obj->Wrap(args.This());
                NanReturnValue(args.This());
            }
            else
            {
                // Invoked as plain function `MyObject(...)`, turn into construct call.
                std::vector<v8::Handle<v8::Value>> lArgvVec;
                for (int i = 0; i < args.Length(); ++i) { lArgvVec.push_back(args[i]); }
                NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(lArgvVec.size(), (lArgvVec.size() == 0) ? nullptr : &lArgvVec[0]));
            }
        }

        //--------------------------------------------------------------
        void {$uClassName}Wrap::Initialize(v8::Handle<Object> exports)
        {
            auto tpl = NanNew<v8::FunctionTemplate>(New);
            tpl->SetClassName(NanNew("{$lClassName}"));

            auto inst = tpl->InstanceTemplate();
            inst->SetInternalFieldCount(1);

{$mutators}
{$protoTmpl}

            NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::{$uuClassName}), v8::ReadOnly);
            NanAssignPersistent(constructor, tpl->GetFunction());
            exports->Set(NanNew<String>("{$lClassName}"), tpl->GetFunction());
        }

        {$getters}
        {$setters}
        {$methodsTmpl}
    } //!namespace {$uClassName}
} //!namespace nofx
TMP;
    return $template;
}

function makeMain($className, $deps = false) {
    $lClassName = lcfirst($className);
    $uClassName = ucfirst($className);
    
    $depHeader = "";
    $depBody = "";
    
    if($deps) {
        $depHeader = "\n".'#include "nofx_dependencies.h"';
        $depBody = "\n".'            target->Set(NanNew<v8::String>("dependencies"), NanNew<v8::FunctionTemplate>(nofx_dependencies)->GetFunction());';
    }
    
    $template = <<<TMP
#include "globals.h"
#include "nofx_{$lClassName}.h"{$depHeader}

namespace nofx
{
    namespace {$uClassName}
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {
            {$depBody}
            {$uClassName}Wrap::Initialize(target);

        } //!Initialize
    } //!namespace {$uClassName}
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_{$lClassName}, nofx::{$uClassName}::Initialize)
TMP;
    return $template;
}

function makeDepSource($className, $deps) {
    $ctors = "";
    $body = "";
    
    $lClassName = lcfirst($className);
    $uClassName = ucfirst($className);
    
    foreach($deps as $dep) {
        $ctors .= "\n".'v8::Persistent<v8::Function> DEP_'.$dep.';';
        $body .= "\n            NanAssignPersistent(DEP_{$dep}, v8::Handle<v8::Function>::Cast(
                args[0]->ToObject()->Get(NanNew(\"{$dep}\"))));";
    }
    
    $templ = <<<TPL
#include "nofx_dependencies.h"
{$ctors}

namespace nofx
{
    namespace {$uClassName}
    {
        NAN_METHOD(nofx_dependencies)
        {

            if (args.Length() != 1)
            {
                NanThrowTypeError("{$lClassName} module has dependencies. Please pass the right dependencies first.");
            }
            {$body}
        
            NanReturnValue(args.This());
        } // !nofx_dependencies
    } // !namespace {$uClassName}
} // !namespace nofx
TPL;
    return $templ;
}
function makeDepHeader($calssName) {
    $uCalssName = ucfirst($calssName);
    $templ = <<<TPL
#ifndef _NOFX_DEPENENCIES_H_
#define _NOFX_DEPENENCIES_H_

#include "globals.h"

namespace nofx
{
    namespace {$uCalssName}
    {
        NAN_METHOD(nofx_dependencies);
    } // !namespace {$uCalssName}
} // !namespace nofx

#endif // !_NOFX_DEPENENCIES_H_    
TPL;
return $templ;
}

function makeGlobals($deps) {
$body = "";
foreach($deps as $dep) {
    $body .= "\n".'extern v8::Persistent<v8::Function> DEP_'.$dep.";";
}
    $templ = <<<TPL
#ifndef _NOFX_GLOBALS_H_
#define _NOFX_GLOBALS_H_

// Make sure you always include node.h first. Otherwise you'll
// get random weird errors about mixing C/C++ routines.

#include "node.h"
#include "v8.h"
#include "nan.h"
{$body}

#endif // !_NOFX_GLOBALS_H_    
TPL;
    return $templ;
}

function savePath($filename) {
    return dirname($_SERVER["SCRIPT_FILENAME"])."/".$filename;
}
if(isset($_GET["build"])) {
    file_put_contents(savePath("nofx_".lcfirst($className).".h"), makeHeader($methods, $variables, $className));
    file_put_contents(savePath("nofx_".lcfirst($className).".cc"), makeSource($methods, $variables, $className, $deps));
    file_put_contents(savePath("main.cc"), makeMain($className, $deps));
    if($deps) {
        file_put_contents(savePath("nofx_dependencies.h"), makeDepHeader($className));    
        file_put_contents(savePath("nofx_dependencies.cc"), makeDepSource($className, $deps));    
        file_put_contents(savePath("globals.h"), makeGlobals($deps));    
    }
    die("done");
}
else {
    var_dump($methods);
    var_dump($variables);
    var_dump($functions);
}
?>
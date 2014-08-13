<?php
require_once("phpQuery/phpQuery.php");
$className = lcfirst($_GET["className"]);
$url = $_GET["url"];
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
var_dump($methods);
var_dump($functions);
var_dump($variables);
function makeHeader($methods, $variables, $className) {
    $lClassName = lcfirst($className);
    $uClassName = ucfirst($className);
    $guard = strtoupper(preg_replace('/(?<=\\w)(?=[A-Z])/',"_$1", $className));
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

using namespace v8;

namespace nofx
{
    namespace {$uClassName}
    {
        class {$uClassName}Wrap
            : public node::ObjectWrap
        {
        public:
            static void Initialize(v8::Handle<Object> target);
            {$lClassName}* GetWrapped() const { return internal_.get(); };
            {$lClassName}* GetWrapped() { return internal_.get(); };
            void SetWrapped({$lClassName}* n)  { internal_.reset(n); };
            static const Persistent<Function>& Factory() { return constructor; }
        private:
            {$uClassName}Wrap();
            {$uClassName}Wrap({$lClassName}*);
            ~{$uClassName}Wrap() {};

            {$getters}
            {$setters}
{$methodsTmpl}
            static Persistent<Function> constructor;
            static NAN_METHOD(New);
            std::shared_ptr<{$lClassName}> internal_;
        }; // !class {$uClassName}Wrap
    } //!namespace {$uClassName}
} // !namespace nofx

#endif // !_NOFX_{$guard}_H_
    
TMP;

    return $template;
}

function makeSource($methods, $variables, $className) {
    $lClassName = lcfirst($className);
    $uClassName = ucfirst($className);
    $uuClassName = strtoupper($className);
    $protoTmpl = "";
    $methodsTmpl = "";
    foreach($methods as $method) {
        $protoTmpl .= "\n            NanSetPrototypeTemplate(tpl, NanNew(\"".lcfirst($method)."\"), NanNew<v8::FunctionTemplate>(".ucfirst($method)."), v8::ReadOnly);";

        $methodsTmpl .= "\n        //---------------------------------------------------------\n";
        $methodsTmpl .= "        NAN_METHOD({$uClassName}Wrap::".ucfirst($method).")\n";
        $methodsTmpl .= "        {\n";
        $methodsTmpl .= "            //implementation\n";
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
                if(self != nullptr) {
                    NanReturnValue(self->".$var.");
                }
            }
            //----------------------------------------------------\n";
        $setters .= "\n            NAN_SETTER({$uClassName}Wrap::Set".ucfirst($var).")
            {
                auto self = ObjectWrap::Unwrap<{$uClassName}Wrap>(args.This())->GetWrapped();
                if(self != nullptr) {
                    self->".$var." = value->NumberValue();
                }
            }
            //----------------------------------------------------\n";
    }
    
    $template = <<<TMP
#include "nofx_{$lClassName}.h"
#include "nofx_noop.h"
#include "..\\nofx\\nofx_types.h"

namespace nofx
{
    namespace {$uClassName}
    {
        Persistent<Function> {$uClassName}Wrap::constructor;

        {$uClassName}Wrap::{$uClassName}Wrap()
            : internal_(nullptr)
        {}

        //--------------------------------------------------------------
        {$uClassName}Wrap::{$uClassName}Wrap({$lClassName}* aInternal)
            : internal_(aInternal)
        {}

        //--------------------------------------------------------------
        NAN_METHOD({$uClassName}Wrap::New)
        {
            NanScope();
            if (args.IsConstructCall()) {
                {$uClassName}Wrap* obj;
                if (args.Length() == 0)
                {
                    //obj = new {$uClassName}Wrap(); //implement me
                }
                else if (args[0]->IsNull())
                {
                    obj = new {$uClassName}Wrap(nullptr);
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

function makeMain($className) {
    $lClassName = lcfirst($className);
    $uClassName = ucfirst($className);
    $template = <<<TMP
#include "globals.h"
#include "nofx_{$lClassName}.h"

namespace nofx
{
    namespace {$uClassName}
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

            {$uClassName}Wrap::Initialize(target);

        } //!Initialize
    } //!namespace {$uClassName}
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_{$lClassName}, nofx::{$uClassName}::Initialize)
TMP;
    return $template;
}

function savePath($filename) {
    return dirname($_SERVER["SCRIPT_FILENAME"])."/".$filename;
}

file_put_contents(savePath("nofx_".lcfirst($className).".h"), makeHeader($methods, $variables, $className));
file_put_contents(savePath("nofx_".lcfirst($className).".cc"), makeSource($methods, $variables, $className));
file_put_contents(savePath("main.cc"), makeMain($className));
?>
<?php

require_once('compiler.php');
$main_class = 'ofRectangle';

$OF_header = OFROOT
.DIRECTORY_SEPARATOR .'openFrameworks'
.DIRECTORY_SEPARATOR .'libs'
.DIRECTORY_SEPARATOR .'openFrameworks'
.DIRECTORY_SEPARATOR .'types'
.DIRECTORY_SEPARATOR .'ofRectangle.h';

class CompilerUnit {

    private $headerName = '';
    private $className = '';
    private $lClassName = '';
    private $uClassName = '';
    private $methods = array();
    private $props = array();
    private $ctor_defs = array();
    private $dependencies = array();

    public function __construct() {

        global $OF_header;
        $data = Compiler::SANITIZED_HEADER_DATA($OF_header);

        $this->className = $data['target'];
        $this->methods = $data['methods'];
        $this->props = $data['properties'];
        $this->headerName = $data['filename'];
        $this->ctor_defs = $data['constructors'];
        $this->lClassName = lcfirst($this->className);
        $this->uClassName = ucfirst($this->className);

        Compiler::PRE_DETERMINE_DEPENDENCIES($this->className, $this->props, $this->methods, $this->dependencies);
    }

    public function main() {
        $depHeader = '';
        $depBody = '';

        if(count($this->dependencies) > 0) {
            $depHeader = "#include \"nofx_{$this->lClassName}_dependencies.h\"";
            $depBody = <<<TPL
target->Set( //##MODULE_NAME## dependency setter, should be called in JS land
    NanNew<v8::String>("dependencies"),
    NanNew<v8::FunctionTemplate>(nofx_##MODULE_NAME##_dependencies)->GetFunction());
        
TPL;
            $depBody = str_replace('##MODULE_NAME##', $this->lClassName, $depBody);
        }

        $template = <<<TMP
#include "nofx_{$this->lClassName}_globals.h"
{$depHeader}
#include "nofx_{$this->lClassName}.h"

namespace nofx
{
    using namespace v8;

    void Initialize{$this->uClassName}(
        v8::Handle<v8::Object> target,
        v8::Handle<v8::Value> unused,
        v8::Handle<v8::Context> context)
    {
        {$depBody}
        ClassWrappers::{$this->uClassName}Wrap::Initialize(target);

    } //!Initialize{$this->uClassName}
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_{$this->lClassName}, nofx::ClassWrappers::Initialize{$this->uClassName})
TMP;
        return $template;
    }
    public function H() {
        $guard = strtoupper(preg_replace('/(?<=\\w)(?=[A-Z])/',"_$1", $this->className));
        $count = 1;
        $trimmedName = ucfirst(str_ireplace("of", "", $this->className, $count));
        $methodsTmpl = "";
        Compiler::METHOD_ITERATOR($this->className, $this->methods, function($mangled_name, $method_def, &$template) {
            $template .= Compiler::NOFX_METHOD_DOCUMENTATION_H($this->className, $mangled_name, $method_def['line_number'], $method_def['debug'], isset($method_def['doxygen']) ? $method_def['doxygen'] : "/// \\brief Doxygen could not be found.");
            $template .= Compiler::NOFX_METHOD_SIGNATURE_H($mangled_name, true);
            $template .= "\n";            
            }, $methodsTmpl);

        $getters = "";
        $setters = "";

        Compiler::PROPERTIES_ITERATOR($this->props, function($name, &$tmpl) {
            $tmpl .= Compiler::NOFX_GETTER_SIGNATURE_H($name, true);            
            }, $getters,
            function($name, &$tmpl) {
                $tmpl .= Compiler::NOFX_SETTER_SIGNATURE_H($name, true);
            }, $setters);

        $template = <<<TMP
#ifndef _NOFX_{$guard}_H_
#define _NOFX_{$guard}_H_

#include <memory>
#include "nofx_{$this->lClassName}_globals.h"
#include "{$this->headerName}"
#include "..\\nofx\\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
    namespace ClassWrappers
    {
        class {$this->uClassName}Wrap
            : public nofx::ObjectWrap< {$this->lClassName} >
        {

            DeclareObjectRoutines({$trimmedName});

{$getters}
{$setters}
{$methodsTmpl}

        }; //!class {$this->uClassName}Wrap
    } //!namespace ClassWrappers
} //!namespace nofx

#endif // !_NOFX_{$guard}_H_
    
TMP;
        return $template;
    }
    public function CC() {
        $lClassName = lcfirst($this->className);
        $uClassName = ucfirst($this->className);
        $uuClassName = strtoupper($this->className);
        $depHeader = "";
        $methodsTmpl = "";

        if(count($this->dependencies) > 0) {
            foreach($this->dependencies as $dep) {
                $depHeader .= "\n".'#include "..\nofx_'.$dep.'\nofx_'.$dep.'.h"';
            }
        }

        foreach($this->methods as $method_name => $method_def) {
            foreach($method_def as $index => $def) {
                $methodsTmpl .= Compiler::NOFX_METHOD_IMPLEMENTATION_CC($this->methods, $method_name, $def, $this->className, $this->dependencies);
            }
        }

        $getters = "";
        $setters = "";
        foreach($this->props as $prop) {
            $getters .= '            ';
            $getters .= Compiler::NOFX_GETTER_IMPLEMENTATION_CC($this->className, $prop['name'],$prop['raw_type'] ,$this->dependencies);
            if($prop['has_setter']) {
                $setters .= '            ';
                $setters .= Compiler::NOFX_SETTER_IMPLEMENTATION_CC($this->className, $prop['name'],$prop['raw_type']);
            }
        }

        $initializer = Compiler::NOFX_JS_INITIALIZER_CC($this->className, $this->methods, $this->props);
        $ctor = Compiler::NOFX_JS_CTOR_IMPLEMENTATION_CC($this->className, $this->ctor_defs);

        $template = <<<TMP
#include "nofx_{$lClassName}.h"
#include "..\\nofx\\nofx_types.h"{$depHeader}

namespace nofx
{
    namespace ClassWrappers
    {
        using nofx::ObjectWrap;
    
        Persistent<Function> {$uClassName}Wrap::constructor;
        {$ctor}
        {$initializer}
        {$getters}
        {$setters}
        {$methodsTmpl}
    } //!namespace {$uClassName}
} //!namespace nofx
TMP;
        return $template;
    }
    public function depCC() {
        $list = '';
        $block = '';

        foreach($this->dependencies as $dep) {
            $list .= "\nv8::Persistent<v8::Function> DEP_{$dep};\nbool isset_DEP_{$dep} = false;\n";
            $block .= "\nif(args[0]->ToObject->Has(NanNew(\"{$dep}\"))) {
            NanAssignPersistent(DEP_{$dep}, v8::Handle<v8::Function>::Cast(
            args[0]->ToObject()->Get(NanNew(\"{$dep}\"))));
            isset_DEP_{$dep} = true;
            }\n";
        }

        $tmpl = <<<TPL
#include "nofx_{$this->lClassName}_dependencies.h"
{$list}
namespace nofx
{
    NAN_METHOD(nofx_{$this->lClassName}_dependencies)
    {

#if NOFX_STRICT
        if (args.Length() < 1 || !args[0]->IsObject())
        {
            NanThrowTypeError("You do not meet the requirements of {$this->lClassName}'s dependencies.");
        }
#endif
{$block}
        NanReturnValue(args.This());
    } // !nofx_{$this->lClassName}_dependencies
} // !namespace nofx

TPL;
        return $tmpl;
    }
    public function depH() {
        $ALL_CAPS_MODULE_NAME = strtoupper($this->className);
        $tmpl = <<<TPL
#ifndef _NOFX_{$ALL_CAPS_MODULE_NAME}_DEPENENCIES_H_
#define _NOFX_{$ALL_CAPS_MODULE_NAME}_DEPENENCIES_H_

#include "nofx_{$this->lClassName}_globals.h"

namespace nofx
{
    
    NAN_METHOD(nofx_{$this->lClassName}_dependencies);
    
} //!namespace nofx

#endif // !_NOFX_{$ALL_CAPS_MODULE_NAME}_DEPENENCIES_H_

TPL;
        return $tmpl;
    }
    public function globals() {
        $ALL_CAPS_MODULE_NAME = strtoupper($this->className);
        $list = '';
        foreach($this->dependencies as $dep) {
            $list .= "\nextern v8::Persistent<v8::Function> DEP_{$dep};\nextern bool isset_DEP_{$dep};\n";
        }
        $tmpl = <<<TPL
#ifndef _NOFX_{$ALL_CAPS_MODULE_NAME}_GLOBALS_H_
#define _NOFX_{$ALL_CAPS_MODULE_NAME}_GLOBALS_H_

// Always including node.h first. Otherwise we'll
// get random weird errors about mixing C/C++ routines.

#include "node.h"
#include "v8.h"
#include "nan.h"
#include "..\\nofx\\nofx_types.h"
{$list}
#endif // !_NOFX_{$ALL_CAPS_MODULE_NAME}_GLOBALS_H_

TPL;
        return $tmpl;
    }
}

$generator = new CompilerUnit();
//echo $generator->H();
//echo $generator->CC();
//echo $generator->main();
//echo $generator->depCC();
//echo $generator->depH();
//echo $generator->globals();

?>
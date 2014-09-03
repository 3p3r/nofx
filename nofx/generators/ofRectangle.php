<?php

require_once('compiler.php');
$main_class = 'ofRectangle';

$OF_header = OFROOT
.DIRECTORY_SEPARATOR .'openFrameworks'
.DIRECTORY_SEPARATOR .'libs'
.DIRECTORY_SEPARATOR .'openFrameworks'
.DIRECTORY_SEPARATOR .'types'
.DIRECTORY_SEPARATOR .'ofRectangle.h';

$header = new Parser($OF_header);
$parsedFileName = basename($OF_header);
$json = $header->getParsedJson();
$class = $json['classes'][$main_class];
$dependencies = [];
$methods_defs = [];
$ctor_defs = [];
$props = [];

if (isset($class['methods']['public']) && !empty($class['methods']['public']))
{
    //We have public methods to deal with
    $methods = $class['methods']['public'];

    foreach ($methods as $method) {
        if ($method['constructor']) {
            //we should deal with constructor overload here
            array_push($ctor_defs, $method);
        } else if($method['destructor']) {
            continue; //we don't care about constructors
        } else if ($method['operator'] != false) {
            //this is an operator overload
            continue; //for now
        } else {
            //this is a general method
            if(!isset($methods_defs[$method['name']]) || !is_array($methods_defs[$method['name']])) {
                $methods_defs[$method['name']] = [];
            }
            array_push($methods_defs[$method['name']], $method);
        }
    }

    //echo Compiler::NOFX_JS_CTOR_IMPLEMENTATION_CC($main_class, $ctor_defs);
    foreach($methods_defs as $method_name => $method_def) {
        foreach($method_def as $index => $def) {
            //echo Compiler::NOFX_SINGLE_METHOD_SIGNATURE_H($methods_defs,$method_name,$def,$main_class);
            //Compiler::NOFX_METHOD_IMPLEMENTATION_CC($methods_defs,$method_name,$def,$main_class, $dependencies);
        }
    }
}

if (isset($class['properties']['public']) && !empty($class['properties']['public']))
{
    //We have public props to deal with here
    $props = $class['properties']['public'];
    $headerRawFile = file($OF_header);

    foreach($props as &$prop) {
        $name = end(explode(' ', rtrim(trim($headerRawFile[$prop['line_number'] - 1]), ";")));
        $prop['name'] = $name;
        $prop['has_setter'] = true;
        Compiler::NOFX_GETTER_BODY_CC($main_class, $prop['name'], $prop['raw_type'],$dependencies);
        //echo "\n";
        //echo Compiler::NOFX_SETTER_BODY_CC($main_class, $prop['name'], $prop['raw_type']);
        //echo "//--------------------------------------------------------\n";
    }
}

//echo Compiler::NOFX_JS_INITIALIZER_CC($main_class, $methods_defs, $props);

class GEN {
    private $className = false;
    private $methods = false;
    private $props = false;
    private $headerName = false;
    private $ctor_defs = false;
    private $dependencies = array();
    public function __construct($className, $methods, $props, $headerName, $ctor_defs) {
        $this->className = $className;
        $this->methods = $methods;
        $this->props = $props;
        $this->headerName = $headerName;
        $this->ctor_defs = $ctor_defs;
        $this->dependencies;

        foreach($this->props as $prop) {
            Compiler::NOFX_GETTER_BODY_CC($this->className, $prop['name'], $prop['raw_type'], $this->dependencies);
        }
        foreach($this->methods as $method_name => $method_defs) {
            foreach($method_defs as $method_def) {
                Compiler::NOFX_METHOD_BODY_CC($this->className, '', false, false, $method_def['returns'], $method_def['parameters'], $this->dependencies);
            }
        }
    }
    public function main() {
        $lClassName = lcfirst($this->className);
        $uClassName = ucfirst($this->className);

        $depHeader = "";
        $depBody = "";

        if(count($this->dependencies) > 0) {
            $depHeader = "\n".'#include "nofx_dependencies.h"';
            $depBody = "\n".'            target->Set(NanNew<v8::String>("dependencies"), NanNew<v8::FunctionTemplate>(nofx_dependencies)->GetFunction());';
        }

        $template = <<<TMP
#include "globals.h"
#include "nofx_{$lClassName}.h"{$depHeader}

namespace nofx
{
    namespace ClassWrappers
    {
        using namespace v8;

        void Initialize_{$uClassName}(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {
            {$depBody}
            {$uClassName}Wrap::Initialize(target);

        } //!Initialize
    } //!namespace ClassWrappers
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_{$lClassName}, nofx::ClassWrappers::Initialize_{$uClassName})
TMP;
        return $template;
    }
    public function H() {
        $lClassName = lcfirst($this->className);
        $uClassName = ucfirst($this->className);
        $guard = strtoupper(preg_replace('/(?<=\\w)(?=[A-Z])/',"_$1", $this->className));
        $count = 1;
        $trimmedName = ucfirst(str_ireplace("of", "", $this->className, $count));
        $methodsTmpl = "";

        foreach($this->methods as $method_name => $method_defs) {
            if (count($this->methods[$method_name]) > 1) {
                foreach($method_defs as $method_def) {
                    $methodsTmpl .= Compiler::NOFX_METHOD_DOCUMENTATION_H($this->className, $method_name, $method_def['line_number'], $method_def['debug'], isset($method_def['doxygen']) ? $method_def['doxygen'] : "/// \\brief Doxygen could not be found.");
                    $methodsTmpl .= '            ';
                    $mangled_name = Compiler::GET_JS_NAME($method_name).'_'.count($this->methods[$method_name]).'_'.Compiler::MANGLE_NAME($method_def['debug']);
                    $methodsTmpl .= Compiler::NOFX_METHOD_SIGNATURE_H($mangled_name, true);
                    $methodsTmpl .= "\n";
                }
            } else {
                $methodsTmpl .= Compiler::NOFX_METHOD_DOCUMENTATION_H($this->className, $method_name, $method_defs[0]['line_number'], $method_defs[0]['debug'], isset($method_defs[0]['doxygen']) ? $method_defs[0]['doxygen'] : "/// \\brief Doxygen could not be found.");
                $methodsTmpl .= '            ';
                $mangled_name = Compiler::GET_JS_NAME($method_name);
                $methodsTmpl .= Compiler::NOFX_METHOD_SIGNATURE_H($mangled_name, true);
                $methodsTmpl .= "\n";
            }
        }

        $getters = "";
        $setters = "";
        foreach($this->props as $prop) {
            $getters .= '            ';
            $getters .= Compiler::NOFX_GETTER_SIGNATURE_H($prop['name'], true);
            if($prop['has_setter']) {
                $setters .= '            ';
                $setters .= Compiler::NOFX_SETTER_SIGNATURE_H($prop['name'], true);
            }
        }

        $template = <<<TMP
#ifndef _NOFX_{$guard}_H_
#define _NOFX_{$guard}_H_

#include "globals.h"
#include <memory>
#include "{$this->headerName}.h"
#include "..\\nofx\\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
    namespace ClassWrappers
    {
        class {$uClassName}Wrap
            : public nofx::ObjectWrap< {$lClassName} >
        {

            DeclareObjectRoutines({$trimmedName});

{$getters}
{$setters}
{$methodsTmpl}

        }; //!class {$uClassName}Wrap
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

    }
    public function depH() {

    }
    public function globals() {

    }
}

$generator = new GEN('ofRectangle', $methods_defs, $props, $parsedFileName, $ctor_defs);
echo $generator->CC();

?>
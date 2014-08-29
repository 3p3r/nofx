<?php

require_once('compiler.php');
$main_class = 'ofRectangle';

$header = new Parser(OFROOT
    .DIRECTORY_SEPARATOR .'openFrameworks'
    .DIRECTORY_SEPARATOR .'libs'
    .DIRECTORY_SEPARATOR .'openFrameworks'
    .DIRECTORY_SEPARATOR .'types'
    .DIRECTORY_SEPARATOR .'ofRectangle.h');

$json = $header->getParsedJson();
$class = $json['classes'][$main_class];
$dependencies = [];
$methods_defs = [];
$props = [];

if (isset($class['methods']['public']) && !empty($class['methods']['public']))
{
    //We have public methods to deal with
    $methods = $class['methods']['public'];

    $ctor_defs = [];

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

    //echo ParserUtils::NOFX_JS_CTOR_IMPLEMENTATION_CC($main_class, $ctor_defs);
    foreach($methods_defs as $method_name => $method_def) {
        foreach($method_def as $index => $def) {
            //echo ParserUtils::NOFX_SINGLE_METHOD_SIGNATURE_H($methods_defs,$method_name,$def,$main_class);
            ParserUtils::NOFX_SINGLE_METHOD_IMPLEMENTATION_CC($methods_defs,$method_name,$def,$main_class, $dependencies);
        }
    }
}

if (isset($class['properties']['public']) && !empty($class['properties']['public']))
{
    //We have public props to deal with here
    $props = $class['properties']['public'];
    $headerRawFile = file(OFROOT
        .DIRECTORY_SEPARATOR .'openFrameworks'
        .DIRECTORY_SEPARATOR .'libs'
        .DIRECTORY_SEPARATOR .'openFrameworks'
        .DIRECTORY_SEPARATOR .'types'
        .DIRECTORY_SEPARATOR .'ofRectangle.h');

    foreach($props as &$prop) {
        $name = end(explode(' ', rtrim(trim($headerRawFile[$prop['line_number'] - 1]), ";")));
        $prop['name'] = $name;
        $prop['has_setter'] = true;
        ParserUtils::NOFX_GETTER_BODY_CC($main_class, $prop['name'], $prop['raw_type'],$dependencies);
        //echo "\n";
        //echo ParserUtils::NOFX_SETTER_BODY_CC($main_class, $prop['name'], $prop['raw_type']);
        //echo "//--------------------------------------------------------\n";
    }
}

//echo ParserUtils::NOFX_JS_INITIALIZER_CC($main_class, $methods_defs, $props);

class GEN {
    private $_hasDep = false;
    public function __construct__($className, $methods, $props, $dependencies) {
        $this->_hasDep = count($dependencies) != 0;
    }
    public function H() {
        
    }
    public function CC() {
        
    }
    public function depCC() {
        
    }
    public function depH() {
        
    }
    public function globals() {
        
    }
}

?>
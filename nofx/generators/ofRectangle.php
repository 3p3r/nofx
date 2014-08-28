<?php

require_once('parser.php');
$main_class = 'ofRectangle';

$header = new Parser(OFROOT
    .DIRECTORY_SEPARATOR .'openFrameworks'
    .DIRECTORY_SEPARATOR .'libs'
    .DIRECTORY_SEPARATOR .'openFrameworks'
    .DIRECTORY_SEPARATOR .'types'
    .DIRECTORY_SEPARATOR .'ofRectangle.h');

$json = $header->getParsedJson();
$class = $json['classes'][$main_class];

if (isset($class['methods']['public']) && !empty($class['methods']['public']))
{
    //We have public methods to deal with
    $methods = $class['methods']['public'];

    $ctor_defs = [];
    $methods_defs = [];

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

    foreach($methods_defs as $method_name => $method_def) {
        /*
        Things we care about:
        
        'line_number' => int //original line no in source
        'returns_pointer' => int
        'rtnType' => string
        'returns_reference' => boolean
        'const' => boolean
        'parameters' => array
        'returns' => string
        'static' => boolean
        'name' => string
        'debug' => string //original signature
        'inline' => boolean
        */
    }
}

if (isset($class['properties']['public']) && !empty($class['properties']['public']))
{
    //We have public props to deal with here
    $props = $class['properties']['public'];
}

?>
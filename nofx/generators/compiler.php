<?php
class Parser {
    private $_path;
    private $_parsedRaw;
    private $_parsedJson;

    function __construct($headerPath) {
        //echo 'parsing '.$headerPath."\n";
        $this->_path = $headerPath;
        $this->_parse();
    }

    private function _parse() {
        $cmd = 'parser.py "'.$this->_path.'"';
        $this->_parsedRaw = `{$cmd}`;
        $this->_toJson();
    }

    private function _toJson() {
        $this->_parsedJson = json_decode($this->_parsedRaw, true);
    }

    public function getParsedJson() {
        if ($this->_parsedJson == NULL)
        {
            throw new Exception("JSON decoding failed. Check the CPP header");
        }
        return $this->_parsedJson;
    }
}

class Compiler {
    /**
    * Determines if the STRICT flag is on for code generation
    */
    static function IS_STRICT() {
        return defined('NOFXSTRICT') && NOFXSTRICT;
    }
    
    /**
    * Generates documentation to go in header of the generated class
    * 
    * @param string $className
    * @param string $method_name (mangled)
    * @param int    $line_no
    * @param string $sig
    * @param string $doxygen
    * @param string $padding
    */
    static function NOFX_METHOD_DOCUMENTATION_H($className, $method_name, $line_no, $sig, $doxygen = "No Doxygen were found for this method.", $padding = '            ') {
        $doxygen = str_replace('///', "{$padding}///", $doxygen);
        $tmpl = <<<TPL
{$padding}/**
{$padding}* {$className}::{$method_name}
{$padding}* Original signature: {$sig}
{$padding}* Corresponds to line no {$line_no}
{$padding}* Original OF doxygen:
{$padding}*
{$doxygen}
{$padding}*
{$padding}*/

TPL;
        return $tmpl;
    }
    
    /**
    * Mangles the name of overloaded methods/functions
    * 
    * @param string $input (non-mangled)
    * @link http://stackoverflow.com/a/3198075/1055628
    */
    static function MANGLE_NAME($input) {
        return substr(strtolower(preg_replace('/[0-9_\/]+/','',base64_encode(sha1($input)))),0,8);
    }
    
    /**
    * Converts OF class name to Wrapped name
    * 
    * @param string $className
    */
    static function GET_CLASS_WRAPPED_NAME($className) {
        return ucfirst($className).'Wrap';
    }
    
    /**
    * Checks to see if a NOFX type is valid
    * 
    * @param int    $argIndex
    * @param string $type
    */
    static function NOFX_INTERNAL_TYPE_CHECK($argIndex, $type) {
        return 'args['.$argIndex.']->IsObject() && args[0]->ToObject()->Has(NanNew("NOFX_TYPE")) && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::'.strtoupper($type);
    }
    
    /**
    * Return a Cpp condition block to check for valid JS passed arguments
    * 
    * @param string $type
    * @param int    $argIndex
    * @param string $methodName
    * @param bool   $justReturnConditionBlock
    */
    static function GENERATE_CPP_JSARG_TYPE_CHECK($type, $argIndex, $methodName, $justReturnConditionBlock = false, $padding = '    ') {
        $gaurd = '';
        switch($type)
        {
            case 'int':
            case 'ofScaleMode':
            case 'ofAspectRatioMode':
            case 'ofAlignHorz':
            case 'ofAlignVert':
                $gaurd = 'args['.$argIndex.']->IsInt32()';
                break;
            case 'size_t':
                $gaurd = 'args['.$argIndex.']->IsUint32()';
                break;
            case 'ofPoint':
            case 'ofVec3f':
                $gaurd = self::NOFX_INTERNAL_TYPE_CHECK($argIndex, 'ofVec3f');
                break;
            case '::ofRectangle':
            case 'const ofRectangle &':
            case 'ofRectangle':
                $gaurd = self::NOFX_INTERNAL_TYPE_CHECK($argIndex, 'ofRectangle');
                break;
            case 'float':
            case 'double':
                $gaurd = 'args['.$argIndex.']->IsNumber()';
                break;
            default:
                throw new Exception('Arg guard can\'t be generated. Type is: ['.$type.']');
                break;
        }
        if ($justReturnConditionBlock) {
            return "({$gaurd})";
        }
        $tmpl = <<<TPL
{$padding}if(!({$gaurd})) {
{$padding}{$gaurd}NanThrowTypeError("Argument at index {$argIndex} is incompatible with {$methodName}'s prototype.\\nExpected type is {$type}.");
{$padding}}

TPL;
        return $tmpl;
    }
    
    /**
    * Converts name to JS side (really a ucfirst fo now)
    * 
    * This is here really for future if I decide to change the naming conventions
    * 
    * @param string $method_name
    */
    static function GET_JS_NAME($method_name) {
        return ucfirst($method_name);
    }
    
    /**
    * Converts name to CPP side (really a lcfirst fo now)
    * 
    * This is here really for future if I decide to change the naming conventions
    * 
    * @param string $method_name
    */
    static function GET_CPP_NAME($method_name) {
        return lcfirst($method_name);
    }
    
    /**
    * CPP Method signature for bindings
    * 
    * @param string $method_name
    * @param bool   $semicolonAndEnter
    */
    static function NOFX_METHOD_SIGNATURE_H($method_name, $semicolonAndEnter = false, $padding = '') {
        return $padding.'static NAN_METHOD('.$method_name.')'.($semicolonAndEnter ? ";\n" : '');
    }
    
    /**
    * CPP Method signature for bindings
    * 
    * @param string $className
    * @param string $method_name
    * @param bool   $bracketAndEnter
    */
    static function NOFX_METHOD_SIGNATURE_CC($className, $method_name, $bracketAndEnter = false, $padding = '') {
        return $padding.'NAN_METHOD('.self::GET_CLASS_WRAPPED_NAME($className).'::'.$method_name.')'.($bracketAndEnter ? " {\n" : '');
    }
    
    /**
    * Generates a new JS instance to be manipulated by CPP, also finds out what are the dependecnies
    * for it. It fills the $dependencies array with a list of found dependencies
    * 
    * @param string $desiredType
    * @param string $className
    * @param array  $dependencies
    */
    static function NOFX_JS_NEW_INSTANCE($desiredType, $className, &$dependencies, $padding = '') {
        if ($desiredType == $className) {
            return $padding.'auto JsReturn = NanNew(Factory())->NewInstance();'."\n";
        } else {
            array_push($dependencies, $desiredType);
            $dependencies = array_unique($dependencies);
            return $padding.'auto JsReturn = DepNewInstance(DEP_'.self::GET_CPP_NAME($desiredType).');'."\n";
        }
    }
    
    /**
    * Unwraps JsReturns or explicitly passed 'what' param
    * 
    * @param string $desiredType
    * @param string $className
    * @param string $what
    * @param string $padding
    */
    static function NOFX_JS_UNWRAP($desiredType, $className, $what = '', $padding = '') {
        if (strlen($what) != 0) {
            return $padding.'nofx::ObjectWrap::Unwrap<nofx::ClassWrappers::'.self::GET_CLASS_WRAPPED_NAME($desiredType).'>('.$what.')';
        }
        if ($desiredType == $className) {
            return $padding.'nofx::ObjectWrap::Unwrap<nofx::ClassWrappers::'.self::GET_CLASS_WRAPPED_NAME($desiredType).'>(JsReturn)';
        } else {
            return $padding.'nofx::ObjectWrap::Unwrap<nofx::ClassWrappers::'.self::GET_CLASS_WRAPPED_NAME($desiredType).'>(JsReturn->ToObject())';
        }
    }
    
    /**
    * Generates a class method body for CPP
    * 
    * @param string $className
    * @param string $methodName
    * @param bool   $is_static
    * @param bool   $is_const
    * @param string $return_type
    * @param array  $args
    * @param array  $dependencies
    */
    static function NOFX_METHOD_BODY_CC(
        $className,
        $methodName,
        $is_static,
        $is_const,
        $return_type,
        $args,
        &$dependencies,
        $padding = ''
    ) {
        $tmpl = '';
        if ( !$is_static ) {
            /******************************
            * Self pointer
            ******************************/
            //Method is not static. We need a pointer to self.
            if ($is_const) $tmpl .= 'const ';
            $tmpl = $padding + $tmpl;
            $tmpl .= 'auto self = '.self::NOFX_JS_UNWRAP('ofRectangle', $className, 'args.This()').'->GetWrapped();';
            $tmpl .= "\n";
            //Pointer to self obtained, shall we check it?
            if (self::IS_STRICT()) {
                //checking if pointer got from ObjectWrap is empty or not. Ideally it should never happen
                $name = self::GET_CPP_NAME($methodName);
                $tmpl .= <<<TPL
#if NOFX_STRICT
{$padding}if(!self) {
{$padding}{$padding}NanThrowError("nofx pointer to self is empty @ {$name}");
{$padding}}
#endif

TPL;
            }
            //self pointer Checks are passed (if any)
        }
        /******************************
        * Method body, arguments
        ******************************/
        $processed_args = self::NOFX_PROCESS_CPP_ARGS($args, $methodName, $className);
        $args_to_pass = $processed_args['args_to_pass'];
        $args_guards = $processed_args['args_guards'];

        if (self::IS_STRICT() && strlen($args_guards) != 0) {
            $tmpl .= '#if NOFX_STRICT'."\n";
            $tmpl .= $args_guards;
            $tmpl .= '#endif'."\n";
        }
        /******************************
        * Method body, operation
        ******************************/
        $return_statement = '';
        $callerObj = $is_static ? $className.'::' : 'self->';
        switch ($return_type) {
            case 'void':
                $tmpl .= $callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass});\n";
                break;
            case 'ofRectangle':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofRectangle', $className, $dependencies, $padding);
                $tmpl .= self::NOFX_JS_UNWRAP('ofRectangle', $className).'->SetWrapped('.$callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass}));\n";
                $return_statement .= 'JsReturn';
                break;
            case 'ofPoint':
            case 'ofVec3f':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofVec3f', $className, $dependencies, $padding);
                $tmpl .= self::NOFX_JS_UNWRAP('ofVec3f', $className).'->SetWrapped('.$callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass}));\n";
                $return_statement .= 'JsReturn';
                break;
            case 'bool':
            case 'int':
            case 'double':
            case 'float':
            case 'size_t':
                $return_statement .= $callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass})";
                break;
            default:
                throw new Exception('Return type for method body can\'t be recognized. Type is: ['.$return_type.']');
                break;
        }
        /******************************
        * Return type
        ******************************/
        $tmpl .= self::NOFX_PROCESS_RETURN_TYPE($return_type, $return_statement);
        return $tmpl;
    }
    
    /**
    * Getter body generator
    * 
    * @param string $className
    * @param string $propName
    * @param string $return_type
    * @param array  $dependencies
    */
    static function NOFX_GETTER_BODY_CC(
        $className,
        $propName,
        $return_type,
        &$dependencies,
        $padding = ''
    ) {
        $tmpl = $padding.'NAN_GETTER('.self::GET_CLASS_WRAPPED_NAME($className).'::Get'.self::GET_JS_NAME($propName).') {'."\n";
        $tmpl .= $padding.$padding.'const auto self = '.self::NOFX_JS_UNWRAP($className, $className, 'args.This()').'->GetWrapped();';
        $tmpl .= "\n";
        //Pointer to self obtained, shall we check it?
        if (self::IS_STRICT()) {
            //checking if pointer got from ObjectWrap is empty or not. Ideally it should never happen
            $tmpl .= <<<TPL
#if NOFX_STRICT
{$padding}if(!self) {
{$padding}{$padding}NanReturnUndefined();
{$padding}}
#endif

TPL;
        }
        //self pointer Checks are passed (if any)
        $return_statement = '';
        $tmpl .= '    ';
        $callerObj = 'self->';
        switch ($return_type) {
            case 'ofRectangle':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofRectangle', $className, $dependencies);
                $tmpl .= '    ';
                $tmpl .= self::NOFX_JS_UNWRAP('ofRectangle', $className).'->SetWrapped('.$callerObj.$propName.");\n";
                $return_statement .= 'JsReturn';
                break;
            case 'ofPoint':
            case 'ofVec3f':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofVec3f', $className, $dependencies);
                $tmpl .= '    ';
                $tmpl .= self::NOFX_JS_UNWRAP('ofVec3f', $className).'->SetWrapped('.$callerObj.$propName.");\n";
                $return_statement .= 'JsReturn';
                break;
            case 'bool':
            case 'int':
            case 'double':
            case 'float':
            case 'size_t':
                $return_statement .= $callerObj.$propName;
                break;
            default:
                throw new Exception('Return type for method body can\'t be recognized. Type is: ['.$return_type.']');
                break;
        }
        $tmpl .= self::NOFX_PROCESS_RETURN_TYPE($return_type, $return_statement);
        $tmpl .= "} //!Get".self::GET_JS_NAME($propName)."\n";
        return $tmpl;
    }
    
    /**
    * Setter body generator
    * 
    * @param mixed $className
    * @param mixed $propName
    * @param mixed $return_type
    */
    static function NOFX_SETTER_BODY_CC(
        $className,
        $propName,
        $return_type
    ) {
        $tmpl = 'NAN_SETTER('.self::GET_CLASS_WRAPPED_NAME($className).'::Set'.self::GET_JS_NAME($propName).') {'."\n";
        $tmpl .= '    auto self = '.self::NOFX_JS_UNWRAP($className, $className, 'args.This()').'->GetWrapped();';
        $tmpl .= "\n";
        //Pointer to self obtained, shall we check it?
        if (self::IS_STRICT()):
            //checking if pointer got from ObjectWrap is empty or not. Ideally it should never happen
            $tmpl .= <<<TPL
#if NOFX_STRICT
    if(!self) {
        NanThrowError("You can't use setter for '{$propName}' before object of type '{$className}' is initialized.");
    }
#endif

TPL;
            endif;
        //self pointer Checks are passed (if any)
        $callerObj = '    self->';
        switch ($return_type) {
            case 'ofRectangle':
                $tmpl .= $callerObj.$propName.'.set(*'.self::NOFX_JS_UNWRAP('ofRectangle', $className, 'args.This()').'->GetWrapped());'."\n";
                break;
            case 'ofPoint':
            case 'ofVec3f':
                $tmpl .= $callerObj.$propName.'.set(*'.self::NOFX_JS_UNWRAP('ofVec3f', $className, 'args.This()').'->GetWrapped());'."\n";
                break;
            case 'bool':
                $tmpl .= $callerObj.$propName.' = value->BooleanValue();'."\n";
                break;
            case 'int':
                $tmpl .= $callerObj.$propName.' = value->Int32Value();'."\n";
                break;
            case 'size_t':
                $tmpl .= $callerObj.$propName.' = value->Uint32Value();'."\n";
                break;
            case 'double':
            case 'float':
                $tmpl .= $callerObj.$propName.' = value->NumberValue();'."\n";
                break;
            default:
                throw new Exception('Return type for method body can\'t be recognized. Type is: ['.$return_type.']');
                break;
        }
        $tmpl .= "} //!Set".self::GET_JS_NAME($propName)."\n";
        return $tmpl;
    }
    
    /**
    * Return type analyzer
    * 
    * @param mixed $return_type
    * @param mixed $return_statement
    */
    static function NOFX_PROCESS_RETURN_TYPE($return_type, $return_statement) {
        $return = '';
        switch ($return_type)
        {
            case 'void':
                $return .= 'NanReturnUndefined();'."\n";
                break;
            case 'string':
                $return .= 'NanReturnValue(*NanUtf8String('.$return_statement.'));'."\n";
                break;
            case 'bool':
            case 'int':
            case 'double':
            case 'float':
            case 'size_t':
            case 'ofRectangle':
            case 'ofPoint':
            case 'ofVec3f':
                $return .= 'NanReturnValue('.$return_statement.');'."\n";
                break;
            default:
                throw new Exception('Return type can\'t be recognized. Type is: ['.$return_type.']');
                break;
        }
        return $return;
    }
    
    /**
    * Getter sig for initializer
    * 
    * @param mixed $className
    * @param mixed $name
    * @param mixed $semicolonAndEnter
    */
    static function NOFX_GETTER_SIGNATURE_CC($className, $name, $semicolonAndEnter = false) {
        return 'NAN_GETTER('.self::GET_CLASS_WRAPPED_NAME($className).'::Get'.self::GET_JS_NAME($name).')'.($semicolonAndEnter ? ";\n" : '');
    }
    
    /**
    * Getter sig for header
    * 
    * @param mixed $method_name
    * @param mixed $semicolonAndEnter
    */
    static function NOFX_GETTER_SIGNATURE_H($method_name, $semicolonAndEnter = false) {
        return 'static NAN_GETTER(Get'.self::GET_JS_NAME($method_name).')'.($semicolonAndEnter ? ";\n" : '');
    }
    
    /**
    * setter sig for header
    * 
    * @param mixed $method_name
    * @param mixed $semicolonAndEnter
    */
    static function NOFX_SETTER_SIGNATURE_H($method_name, $semicolonAndEnter = false) {
        return 'static NAN_SETTER(Set'.self::GET_JS_NAME($method_name).')'.($semicolonAndEnter ? ";\n" : '');
    }
    
    /**
    * argument type analyzer
    * 
    * @param mixed $args
    * @param mixed $methodName
    * @param mixed $className
    */
    static function NOFX_PROCESS_CPP_ARGS($args, $methodName, $className) {
        $args_to_pass = '';
        $args_guards = '';
        foreach($args as $index => $arg) {
            if($methodName != null) {
                $args_guards .= self::GENERATE_CPP_JSARG_TYPE_CHECK($arg['raw_type'], $index, $methodName);
            }
            $current_arg_str = '';
            switch($arg['raw_type']) {
                case 'float':
                case 'double':
                    $current_arg_str .= "args[{$index}]->NumberValue(),";
                    break;
                case 'int':
                    $current_arg_str .= "args[{$index}]->Int32Value(),";
                    break;
                case 'bool':
                    $current_arg_str .= "args[{$index}]->BooleanValue(),";
                    break;
                case 'size_t':
                    $current_arg_str .= "args[{$index}]->Uint32Value(),";
                    break;
                case 'ofPoint':
                case 'ofVec3f':
                    $current_arg_str .= "*".self::NOFX_JS_UNWRAP('ofVec3f', $className, "args[{$index}]->ToObject()")."->GetWrapped(),";
                    break;
                case 'ofRectangle':
                case '::ofRectangle': //reference
                    $current_arg_str .= "*".self::NOFX_JS_UNWRAP('ofRectangle', $className, "args[{$index}]->ToObject()")."->GetWrapped(),";
                    break;
                case 'ofScaleMode':
                    $current_arg_str .= "static_cast<ofScaleMode>(args[{$index}]->Int32Value()),";
                    break;
                case 'ofAspectRatioMode':
                    $current_arg_str .= "static_cast<ofAspectRatioMode>(args[{$index}]->Int32Value()),";
                    break;
                case 'ofAlignHorz':
                    $current_arg_str .= "static_cast<ofAlignHorz>(args[{$index}]->Int32Value()),";
                    break;
                case 'ofAlignVert':
                    $current_arg_str .= "static_cast<ofAlignVert>(args[{$index}]->Int32Value()),";
                    break;
                default:
                    throw new Exception('Argument type can\'t be recognized. Type is: ['.$arg['raw_type'].'@'.$arg['line_number'].']');
                    break;
            }
            if(isset($arg['defaultValue'])) {
                $current_arg_str = "args[{$index}]->IsUndefined()) ? ".$arg['defaultValue']." : ".$current_arg_str;
            }
            $args_to_pass .= $current_arg_str;
        }
        if (strlen($args_to_pass) > 0) {
            $args_to_pass = rtrim($args_to_pass, ",");
        }
        return array('args_to_pass' => $args_to_pass, 'args_guards' => $args_guards);
    }
    
    /**
    * Method sig for header
    * 
    * @param mixed $methods_defs
    * @param mixed $method_name
    * @param mixed $def
    * @param mixed $main_class
    */
    static function NOFX_SINGLE_METHOD_SIGNATURE_H(
        $methods_defs,
        $method_name,
        $def,
        $main_class
    ) {
        $tmpl = '';
        if (count($methods_defs[$method_name]) > 1) {
            $mangled_name = ParserUtils::GET_JS_METHOD_NAME($method_name).'_'.count($methods_defs[$method_name]).'_'.ParserUtils::GET_MANGLED_METHOD_NAME($def['debug']);
            $tmpl .= ParserUtils::NOFX_METHOD_DOCUMENTATION_H($main_class, $mangled_name, $def['line_number'], $def['debug'], isset($def['doxygen']) ? $def['doxygen'] : "No Doxygen were found for this method.");
            $tmpl .= ParserUtils::NOFX_METHOD_SIGNATURE_H($mangled_name, true);
        } else {
            $tmpl .= ParserUtils::NOFX_METHOD_DOCUMENTATION_H($main_class, $method_name, $def['line_number'], $def['debug'], isset($def['doxygen']) ? $def['doxygen'] : "No Doxygen were found for this method.");
            $tmpl .= ParserUtils::NOFX_METHOD_SIGNATURE_H(ParserUtils::GET_JS_METHOD_NAME($method_name), true);
        }
        return $tmpl;
    }
    
    /**
    * Method sig for CPP
    * 
    * @param mixed $methods_defs
    * @param mixed $method_name
    * @param mixed $def
    * @param mixed $main_class
    * @param mixed $dependencies
    */
    static function NOFX_SINGLE_METHOD_IMPLEMENTATION_CC(
        $methods_defs,
        $method_name,
        $def,
        $main_class,
        &$dependencies
    ) {
        $tmpl = '';
        $mangled_name = '';
        if (count($methods_defs[$method_name]) > 1) {
            $mangled_name = ParserUtils::GET_JS_METHOD_NAME($method_name).'_'.count($methods_defs[$method_name]).'_'.ParserUtils::GET_MANGLED_METHOD_NAME($def['debug']);
            $tmpl .= ParserUtils::NOFX_METHOD_SIGNATURE_CC($main_class, $mangled_name, true);
        } else {
            $mangled_name = ParserUtils::GET_JS_METHOD_NAME($method_name);
            $tmpl .= ParserUtils::NOFX_METHOD_SIGNATURE_CC($main_class, $mangled_name, true);
        }
        $tmpl .= ParserUtils::NOFX_METHOD_BODY_CC(
            $main_class,
            $method_name,
            $def['static'],
            $def['const'],
            $def['returns'],
            $def['parameters'],
            $dependencies);
        $tmpl .= "} //!{$mangled_name} \n\n";
        return $tmpl;
    }
    
    /**
    * JS ctor
    * 
    * @param mixed $className
    * @param mixed $name
    * @param mixed $return_type
    */
    static function NOFX_JS_SETTER_IMPLEMENTATION_CC($className, $name, $return_type) {
        /**
        * THIS CLASS STILL NEEDS TO HANDLE OPTIONAL CTOR ARGUMENTS!
        * TODO
        * TODOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!
        */
        $tmpl = 'NAN_SETTER('.self::GET_CLASS_WRAPPED_NAME($className).'::Set'.self::GET_JS_NAME($name).') {'."\n";
        $tmpl .= self::NOFX_SETTER_BODY_CC($className, $name, $return_type);
        $tmpl .= '} //!Set'.self::GET_JS_NAME($name)."\n";
        return $tmpl;
    }
    
    /**
    * initializer template generator
    * 
    * @param mixed $className
    * @param mixed $methods
    * @param mixed $props
    */
    static function NOFX_JS_INITIALIZER_CC($className, $methods, $props = array()) {
        $classNameWrapped = self::GET_CLASS_WRAPPED_NAME($className);
        $classUname = strtoupper($className);
        $mutators = '';        
        foreach($props as $prop) {
            $mutators .= "    inst->SetAccessor(NanNew(\"".$prop['name']."\"), {$classNameWrapped}::Get".ucfirst($prop['name']);
            if ($prop['has_setter']) {
                $mutators .= ", {$classNameWrapped}::Set".ucfirst($prop['name']).");\n";
            } else {
                $mutators .= ");\n";
            }
        }
        
        $method_tmpl = '';
        foreach($methods as $method_name => $method_defs) {
            if (count($methods[$method_name]) > 1) {
                foreach($method_defs as $method_def) {
                    $mangled_name = ParserUtils::GET_JS_METHOD_NAME($method_name).'_'.count($methods[$method_name]).'_'.ParserUtils::GET_MANGLED_METHOD_NAME($method_def['debug']);
                    $method_tmpl .= "    NanSetPrototypeTemplate(tpl, NanNew(\"".lcfirst($mangled_name)."\"), NanNew<v8::FunctionTemplate>(".$mangled_name."), v8::ReadOnly);\n";
                }
            } else {
                $mangled_name = ParserUtils::GET_JS_METHOD_NAME($method_name);
                $method_tmpl .= "    NanSetPrototypeTemplate(tpl, NanNew(\"".lcfirst($mangled_name)."\"), NanNew<v8::FunctionTemplate>(".$mangled_name."), v8::ReadOnly);\n";
            }
        }
        
        $tmpl = <<<TPL
void {$classNameWrapped}::Initialize(v8::Handle<v8::Object> exports)
{
    auto tpl = NanNew<v8::FunctionTemplate>(New);
    tpl->SetClassName(NanNew("{$className}"));

    auto inst = tpl->InstanceTemplate();
    inst->SetInternalFieldCount(1);

{$mutators}
{$method_tmpl}

    NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::{$classUname}), v8::ReadOnly);
    NanAssignPersistent(constructor, tpl->GetFunction());
    exports->Set(NanNew<String>("{$className}"), tpl->GetFunction());
}

TPL;
    return $tmpl;
    }
    
    /**
    * JS ctor implementation
    * 
    * @param mixed $className
    * @param mixed $ctor_defs
    */
    static function NOFX_JS_CTOR_IMPLEMENTATION_CC($className, $ctor_defs) {
        $classWrappedName = self::GET_CLASS_WRAPPED_NAME($className);
        $ctor_defs_temp = $ctor_defs;
        $ctor_defs = [];
        foreach($ctor_defs_temp as $index => $ctor_def) {
            if (!isset($ctor_defs[count($ctor_def['parameters'])])) {
                $ctor_defs[count($ctor_def['parameters'])] = [];
            }
            array_push($ctor_defs[count($ctor_def['parameters'])], $ctor_def);
        }
        //sort($ctor_defs);
        $conditionLoop = '';
        foreach($ctor_defs as $arg_count => $ctor_def) {
            $shouldBeANestedLoop = count($ctor_def) > 1 || $arg_count == 1;
            $conditionLoop .= "        ";
            $conditionLoop .= "else if (args.Length() == {$arg_count}) {\n";
            foreach($ctor_def as $ctor_overload) {
                if ($shouldBeANestedLoop) {
                    //No need for argument guards here. We should check them anyway
                    $conditionLoop .= '            ';
                    $conditionLoop .= '//Arguments with length == 1 must be always type checked. They can be easilly confused with copy constructors.'."\n";
                    $conditionLoop .= '            ';
                    $conditionLoop .= 'if (';
                    foreach($ctor_overload['parameters'] as $index => $arg) {
                        $conditionLoop .= self::GENERATE_CPP_JSARG_TYPE_CHECK($arg['type'], $index, $className.' constructor', true).' &&';
                    }
                    $conditionLoop = rtrim($conditionLoop, " &&");
                    $conditionLoop .= ') {'."\n";
                    $processed_args = self::NOFX_PROCESS_CPP_ARGS($ctor_overload['parameters'], $className.' constructor', $className);
                    $args_to_pass = $processed_args['args_to_pass'];
                    $conditionLoop .= "                ";
                    $conditionLoop .= "obj = new {$classWrappedName}(new {$className}({$args_to_pass}));\n";
                    $conditionLoop .= "            ";
                    $conditionLoop .= "}\n";
                } else {
                    $processed_args = self::NOFX_PROCESS_CPP_ARGS($ctor_overload['parameters'], $className.' constructor', $className);
                    $args_to_pass = $processed_args['args_to_pass'];
                    $args_guards = $processed_args['args_guards'];
                    if (self::IS_STRICT() && strlen($args_guards) != 0):
                        $conditionLoop .= '#if NOFX_STRICT'."\n";
                        $conditionLoop .= $args_guards;
                        $conditionLoop .= '#endif'."\n";
                        endif;
                    $conditionLoop .= "            ";
                    $conditionLoop .= "obj = new {$classWrappedName}(new {$className}({$args_to_pass}));\n";
                }
            }
            $conditionLoop .= "        ";
            $conditionLoop .= "}\n";
        }
        $conditionLoop = rtrim($conditionLoop, "\n");
        $tmpl = <<<TPL
NAN_METHOD({$classWrappedName}::New)
{
    NanScope();
    if (args.IsConstructCall()) {
        {$classWrappedName}* obj;
        if (args[0]->IsNull())
        {
            obj = new {$classWrappedName}(nullptr);
        }
{$conditionLoop}
        else
        {
            //Javascript side copy constructor
            obj = new {$classWrappedName}(*nofx::ObjectWrap::Unwrap<nofx::ClassWrappers::{$classWrappedName}>(args[0]->ToObject())->GetWrapped());
        }
        obj->Wrap(args.This());
        NanReturnValue(args.This());
    }
    else
    {
        // Invoked as plain function "{$classWrappedName}(...)", forward to construct call.
        std::vector<v8::Handle<v8::Value>> lArgvVec;
        for (int i = 0; i < args.Length(); ++i) { lArgvVec.push_back(args[i]); }
        NanReturnValue(NanNew(Factory())->NewInstance(lArgvVec.size(), (lArgvVec.size() == 0) ? nullptr : &lArgvVec[0]));
    }
}

TPL;
        return $tmpl;
    }
}
?>
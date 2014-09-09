<?php
require_once('messages.php');
require_once('parser.php');
require_once('cunit.php');

class Compiler {

    /**
    * This function basically converts the output of Python's CPPHeaderParser to a NOFX friendly array
    * 
    * @param mixed $absoluteHeaderPath
    * @param mixed $className
    */
    static function SANITIZED_HEADER_DATA($absoluteHeaderPath, $className = '') {
        $header = new Parser($absoluteHeaderPath);
        $parsedFileName = basename($absoluteHeaderPath);
        $json = $header->getParsedJson();
        $className = strlen($className) == 0 ? str_replace('.h', '', $parsedFileName) : $className;
        $class = $json['classes'][$className];
        $methods_defs = [];
        $ctor_defs = [];
        $props = [];
        $index_mutators = [];

        if (isset($class['methods']['public']) && !empty($class['methods']['public']))
        {
            //We have public methods to deal with here
            $methods = $class['methods']['public'];

            foreach ($methods as $method) {
                if ($method['constructor']) {
                    //we should deal with constructor overload here
                    array_push($ctor_defs, $method);
                } else if($method['destructor']) {
                    continue; //we don't care about deconstructors
                } else if ($method['operator'] != false) {
                    //this is an operator overload
                    if ($method['operator'] == "[]") {
                        $index_mutators['getter'] = array('type' => $method['rtnType']);
                        if ($method['returns_reference']) {
                            $index_mutators['setter'] = array('type' => $method['rtnType']);
                        }
                    }
                    continue; //for now
                } else {
                    //this is a general method
                    if(!isset($methods_defs[$method['name']]) || !is_array($methods_defs[$method['name']])) {
                        $methods_defs[$method['name']] = [];
                    }
                    array_push($methods_defs[$method['name']], $method);
                }
            }
        }

        if (isset($class['properties']['public']) && !empty($class['properties']['public']))
        {
            //We have public props to deal with here
            $props = $class['properties']['public'];
            $props_clean = array();
            $processed_names = array();
            $headerRawFile = file($absoluteHeaderPath);

            foreach($props as $index => $prop) {
                if (isset($prop['static']) && $prop['static']) {
                    $lvalue = trim(explode('=', $headerRawFile[$prop['line_number'] - 1])[0]);
                    $names = trim(end(explode(' ', $lvalue)));
                    if(in_array($names, $processed_names)) {
                        continue;
                    }
                    $props_clean[] = $prop;
                    $props_clean[count($props_clean) - 1]['name'] = $names;
                    $processed_names[] = $names;
                    if(isset($prop['constant']) && !$prop['constant']) {
                        $props_clean[count($props_clean) - 1]['has_setter'] = true;
                    } else {
                        $props_clean[count($props_clean) - 1]['has_setter'] = false;
                    }
                    continue;
                }

                $names = preg_replace('/[a-zA-Z0-9]+\s/', '', rtrim(trim($headerRawFile[$prop['line_number'] - 1]), ";"));
                //for properties separated with ","
                if(strstr($names, ',') != false) {
                    $temp_names = explode(',',$names);
                    foreach($temp_names as $index2 => $prop2) {
                        if(in_array(trim($prop2), $processed_names)) {
                            continue;
                        }
                        $props_clean[] = $prop;
                        $props_clean[count($props_clean) - 1]['name'] = trim($prop2);
                        $processed_names[] = trim($prop2);
                        if(isset($prop['constant']) && !$prop['constant']) {
                            $props_clean[count($props_clean) - 1]['has_setter'] = true;
                        } else {
                            $props_clean[count($props_clean) - 1]['has_setter'] = false;
                        }                        
                    }
                } else {
                    if(in_array($names, $processed_names)) {
                        continue;
                    }
                    $props_clean[] = $prop;
                    $props_clean[count($props_clean) - 1]['name'] = $names;
                    $processed_names[] = $names;
                    if(isset($prop['constant']) && !$prop['constant']) {
                        $props_clean[count($props_clean) - 1]['has_setter'] = true;
                    } else {
                        $props_clean[count($props_clean) - 1]['has_setter'] = false;
                    }
                }
            }
        }
        
        //fixing array_size here
        foreach($props_clean as &$prop) {
            if (isset($prop) && $prop['array']) {
                if (preg_match_all('/\[/', $prop['name']) > 1) throw new Exception("This is a multidimensional array");
                $prop['array_size'] = intval(end(explode('[',rtrim($prop['name'], ']'))));
                $prop['name'] = explode('[',rtrim($prop['name'], ']'))[0];
            }
        }

        return array(
            'filename' => $parsedFileName,
            'methods' => $methods_defs,
            'properties' => $props_clean,
            'constructors' => $ctor_defs,
            'target' => $className,
            'index_mutators' => $index_mutators
        );
    }
    
    static function NOFX_INDEX_GETTER_SIGNATURE_H($semicolonAndEnter = false) {
        return 'static NAN_INDEX_GETTER(IndexGetter)'.($semicolonAndEnter ? ";\n" : '');
    }
    static function NOFX_INDEX_GETTER_SIGNATURE_CC($className, $enterAndBracket = false) {
        return "NAN_INDEX_GETTER(".self::GET_CLASS_WRAPPED_NAME($className)."::IndexGetter)".($enterAndBracket ? "\n{" : '');
    }
    static function NOFX_INDEX_GETTER_BODY_CC($className, $index_type, &$dependencies, &$cpp_dependencies) {        
        $tmpl = 'const auto self = '.self::NOFX_JS_UNWRAP($className, $className, 'args.This()', $cpp_dependencies).'->GetWrapped();';
        $tmpl .= "\n";
        //Pointer to self obtained, shall we check it?
        if (self::IS_STRICT()) {
            //checking if pointer got from ObjectWrap is empty or not. Ideally it should never happen
            $tmpl .= <<<TPL
#if NOFX_STRICT
if(!self) {
    NanReturnUndefined();
}
#endif

TPL;
        }
        //self pointer Checks are passed (if any)
        $return_statement = '';
        $tmpl .= '    ';
        $callerObj = '*self[index]';
        switch ($index_type) {
            case 'ofRectangle':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofRectangle', $className, $dependencies);
                $tmpl .= '    ';
                $tmpl .= self::NOFX_JS_UNWRAP('ofRectangle', $className, '', $cpp_dependencies).'->SetWrapped('.$callerObj.");\n";
                $return_statement .= 'JsReturn';
                break;
            case 'ofPoint':
            case 'ofVec3f':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofVec3f', $className, $dependencies);
                $tmpl .= '    ';
                $tmpl .= self::NOFX_JS_UNWRAP('ofVec3f', $className, '', $cpp_dependencies).'->SetWrapped('.$callerObj.");\n";
                $return_statement .= 'JsReturn';
                break;
            case 'bool':
            case 'int':
            case 'double':
            case 'float':
            case 'inline float':
            case 'size_t':
                $return_statement .= $callerObj;
                break;
            default:
                throw new Exception('Return type for index getter body can\'t be recognized. Type is: ['.$index_type.']');
                break;
        }
        $tmpl .= self::NOFX_PROCESS_RETURN_TYPE($index_type, $return_statement);
        return $tmpl;
    }
    static function NOFX_INDEX_SETTER_SIGNATURE_H($semicolonAndEnter = false) {
        return 'static NAN_INDEX_SETTER(IndexSetter)'.($semicolonAndEnter ? ";\n" : '');
    }
    static function NOFX_INDEX_SETTER_SIGNATURE_CC($className, $enterAndBracket = false) {
        return "NAN_INDEX_SETTER(".self::GET_CLASS_WRAPPED_NAME($className)."::IndexSetter)".($enterAndBracket ? "\n{" : '');
    }
    static function NOFX_INDEX_SETTER_IMPLEMENTATION_CC($className, $index_type, &$cpp_deps = null) {
        $tmpl = self::NOFX_INDEX_SETTER_SIGNATURE_CC($className, true);
        $tmpl .= self::NOFX_INDEX_SETTER_BODY_CC($className, $index_type, $cpp_deps);
        $tmpl .= "\n}\n";
        return $tmpl;
    }
    static function NOFX_INDEX_GETTER_IMPLEMENTATION_CC($className, $index_type,&$js_deps = null, &$cpp_deps = null) {
        $tmpl = self::NOFX_INDEX_GETTER_SIGNATURE_CC($className, true);
        $tmpl .= self::NOFX_INDEX_GETTER_BODY_CC($className, $index_type,$js_deps, $cpp_deps);
        $tmpl .= "\n}\n";
        return $tmpl;
    }
    static function NOFX_INDEX_SETTER_BODY_CC($className, $index_type, &$cpp_dependencies) {
        $tmpl = 'auto self = '.self::NOFX_JS_UNWRAP($className, $className, 'args.This()', $cpp_dependencies).'->GetWrapped();';
        $tmpl .= "\n";
        //Pointer to self obtained, shall we check it?
        if (self::IS_STRICT()):
            //checking if pointer got from ObjectWrap is empty or not. Ideally it should never happen
            $msg = Messages::Format(Messages::NULL_SELF_ACCESS, array(
                'name' => "indexed setter",
                'type' => $className
            ));
            $tmpl .= <<<TPL
#if NOFX_STRICT
if(!self) {
    NanThrowError("{$msg}");
}
#endif

TPL;
            endif;
        //self pointer Checks are passed (if any)
        $callerObj = '    *self[index]';
        switch ($index_type) {
            case 'ofRectangle':
                $tmpl .= $callerObj.'.set(*'.self::NOFX_JS_UNWRAP('ofRectangle', $className, 'args.This()', $cpp_dependencies).'->GetWrapped());'."\n";
                break;
            case 'ofPoint':
            case 'ofVec3f':
                $tmpl .= $callerObj.'.set(*'.self::NOFX_JS_UNWRAP('ofVec3f', $className, 'args.This()', $cpp_dependencies).'->GetWrapped());'."\n";
                break;
            case 'bool':
                $tmpl .= $callerObj.' = value->BooleanValue();'."\n";
                break;
            case 'int':
                $tmpl .= $callerObj.' = value->Int32Value();'."\n";
                break;
            case 'size_t':
                $tmpl .= $callerObj.' = value->Uint32Value();'."\n";
                break;
            case 'double':
            case 'float':
            case 'inline float':
            case 'inline float &':
            case 'float &':
                $tmpl .= $callerObj.' = value->NumberValue();'."\n";
                break;
            default:
                throw new Exception('Return type for index setter body can\'t be recognized. Type is: ['.$index_type.']');
                break;
        }
        return $tmpl;
    }

    /**
    * Finds dependencies of a module based on its methods/getters definitions
    * and filles the $deps array
    * 
    * @param mixed $className
    * @param mixed $properties
    * @param mixed $methods
    * @param mixed $deps
    */
    static function PRE_DETERMINE_DEPENDENCIES($className, $properties, $methods, $ctors, $index_mutators, &$deps, &$cpp_deps) {
        if (!empty($index_mutators)) {
            if (isset($index_mutators['getter'])) self::NOFX_INDEX_GETTER_BODY_CC($className, $index_mutators['getter']['type'], $deps, $cpp_deps);
            if (isset($index_mutators['setter'])) self::NOFX_INDEX_SETTER_BODY_CC($className, $index_mutators['getter']['type'], $cpp_deps);
        }
        foreach($properties as $prop) {
            self::NOFX_GETTER_BODY_CC($className, $prop['name'], $prop['raw_type'], $deps, $cpp_deps);
            if ($prop['has_setter'])
                self::NOFX_SETTER_BODY_CC($className, $prop['name'], $prop['raw_type'], $deps, $cpp_deps);
        }
        foreach($methods as $method_name => $method_defs) {
            foreach($method_defs as $method_def) {
                self::NOFX_METHOD_BODY_CC($className, '', false, false, $method_def['rtnType'], $method_def['parameters'], $deps, $cpp_deps);
            }
        }
        self::NOFX_JS_CTOR_IMPLEMENTATION_CC($className, $ctors, $cpp_deps);
    }

    static function PROPERTIES_ITERATOR($props, $cb_getter, &$getter_template, $cb_setter = null, &$setter_template = null)
    {
        foreach($props as $prop) {
            $cb_getter($prop['name'], $getter_template);
            if($prop['has_setter'] && $cb_setter != null) {
                $cb_setter($prop['name'], $setter_template);
            }
        }
    }

    static function METHOD_ITERATOR($className, $methods, $cb, &$template)
    {
        $mangled_name = '';
        foreach($methods as $method_name => $method_defs) {
            if (count($methods[$method_name]) > 1) {
                foreach($method_defs as $method_def) {
                    $mangled_name = self::GET_JS_NAME($method_name).'_'.count($methods[$method_name]).'_'.self::MANGLE_NAME($method_def['debug']);
                    $cb($mangled_name, $method_def, $template);
                }
            } else {
                $mangled_name = self::GET_JS_NAME($method_name);
                $cb($mangled_name, $method_defs[0], $template);
            }
        }
    }

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
    */
    static function NOFX_METHOD_DOCUMENTATION_H($className, $method_name, $line_no, $sig, $doxygen = "No Doxygen were found for this method.") {
        $tmpl = <<<TPL
/**
* {$className}::{$method_name}
* Original signature: {$sig}
* Corresponds to line no {$line_no}
* Original OF doxygen:
*
{$doxygen}
*
*/

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
    static function GENERATE_CPP_JSARG_TYPE_CHECK($type, $argIndex, $methodName, $justReturnConditionBlock = false) {
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
            case 'const ofVec3f &':
            case '::ofVec3f':
                $gaurd = self::NOFX_INTERNAL_TYPE_CHECK($argIndex, 'ofVec3f');
                break;
            case 'const ofVec2f &':
            case 'ofVec2f':
            case '::ofVec2f':
                $gaurd = self::NOFX_INTERNAL_TYPE_CHECK($argIndex, 'ofVec2f');
                break;
            case 'const ofVec4f &':
            case 'ofVec4f':
            case '::ofVec4f':
                $gaurd = self::NOFX_INTERNAL_TYPE_CHECK($argIndex, 'ofVec4f');
                break;
            case '::ofRectangle':
            case 'const ofRectangle &':
            case 'ofRectangle':
                $gaurd = self::NOFX_INTERNAL_TYPE_CHECK($argIndex, 'ofRectangle');
                break;
            case '::ofMatrix4x4':
            case 'ofMatrix4x4':
            case 'const ofMatrix4x4 &':
                $gaurd = self::NOFX_INTERNAL_TYPE_CHECK($argIndex, 'ofMatrix4x4');
                break;
            case 'const ofQuaternion &':
            case 'ofQuaternion':
            case '::ofQuaternion':
                $gaurd = self::NOFX_INTERNAL_TYPE_CHECK($argIndex, 'ofQuaternion');
                break;
            case 'float const * const':
                $gaurd = self::NOFX_INTERNAL_TYPE_CHECK($argIndex, 'floatPtr');
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
        $msg = Messages::Format(Messages::CPP_JSARG_TYPE_CHECK_FAILED, array(
            'index' => $argIndex,
            'method' => $methodName,
            'type' => $type,
        ));
        $tmpl = <<<TPL
if(!({$gaurd})) {
    NanThrowTypeError("{$msg}");
}

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
    static function NOFX_METHOD_SIGNATURE_H($method_name, $semicolonAndEnter = false) {
        return 'static NAN_METHOD('.$method_name.')'.($semicolonAndEnter ? ";\n" : '');
    }

    /**
    * CPP Method signature for bindings
    * 
    * @param string $className
    * @param string $method_name
    * @param bool   $bracketAndEnter
    */
    static function NOFX_METHOD_SIGNATURE_CC($className, $method_name, $bracketAndEnter = false) {
        return 'NAN_METHOD('.self::GET_CLASS_WRAPPED_NAME($className).'::'.$method_name.')'.($bracketAndEnter ? " {\n" : '');
    }

    /**
    * Generates a new JS instance to be manipulated by CPP, also finds out what are the dependecnies
    * for it. It fills the $dependencies array with a list of found dependencies
    * 
    * @param string $desiredType
    * @param string $className
    * @param array  $dependencies
    */
    static function NOFX_JS_NEW_INSTANCE($desiredType, $className, &$dependencies) {
        if ($desiredType == $className) {
            return 'auto JsReturn = NanNew(Factory())->NewInstance();'."\n";
        } else {
            array_push($dependencies, $desiredType);
            $dependencies = array_unique($dependencies);
            return 'auto JsReturn = DepNewInstance(DEP_'.self::GET_CPP_NAME($desiredType).');'."\n";
        }
    }

    /**
    * Unwraps JsReturns or explicitly passed 'what' param
    * 
    * @param string $desiredType
    * @param string $className
    * @param string $what
    */
    static function NOFX_JS_UNWRAP($desiredType, $className, $what = '', &$CPP_dependencies = null) {
        if (strlen($what) != 0) {
            if ($desiredType != $className) {$CPP_dependencies[] = $desiredType; $CPP_dependencies = array_unique($CPP_dependencies);}
            return 'nofx::ObjectWrap::Unwrap<nofx::ClassWrappers::'.self::GET_CLASS_WRAPPED_NAME($desiredType).'>('.$what.')';
        }
        if ($desiredType == $className) {
            return 'nofx::ObjectWrap::Unwrap<nofx::ClassWrappers::'.self::GET_CLASS_WRAPPED_NAME($desiredType).'>(JsReturn)';
        } else if(strstr($desiredType, 'Ptr') != false) {
            $CPP_dependencies[] = 'nofx_pointer'; $CPP_dependencies = array_unique($CPP_dependencies);
            return 'ObjectWrap::Unwrap<nofx::Pointer::RawPointerWrap<'.str_replace('_', ' ', strtolower(CompilerUnit::camelCasedToUnderScored(str_replace('Ptr', '', $desiredType)))).'>>(JsReturn->ToObject())';
        } else {
            $CPP_dependencies[] = $desiredType; $CPP_dependencies = array_unique($CPP_dependencies);
            return 'nofx::ObjectWrap::Unwrap<nofx::ClassWrappers::'.self::GET_CLASS_WRAPPED_NAME($desiredType).'>(JsReturn->ToObject())';
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
        &$cpp_dependencies = null, //this is a list of headers needed to be included in C++ land. not actual dependecies
        $original_def = array()
    ) {
        $tmpl = '';
        if ( !$is_static ) {
            /******************************
            * Self pointer
            ******************************/
            //Method is not static. We need a pointer to self.
            if ($is_const) $tmpl .= 'const ';
            $tmpl .= 'auto self = '.self::NOFX_JS_UNWRAP($className, $className, 'args.This()', $cpp_dependencies).'->GetWrapped();';
            $tmpl .= "\n";
            //Pointer to self obtained, shall we check it?
            if (self::IS_STRICT()) {
                //checking if pointer got from ObjectWrap is empty or not. Ideally it should never happen
                $name = self::GET_CPP_NAME($methodName);
                $msg = Messages::Format(Messages::NULL_SELF_ACCESS, array(
                    'name' => $methodName,
                    'type' => $className
                ));
                $tmpl .= <<<TPL
#if NOFX_STRICT
if(!self) {
    NanThrowError("{$msg}");
}
#endif

TPL;
            }
            //self pointer Checks are passed (if any)
        }
        /******************************
        * Method body, arguments
        ******************************/
        $processed_args = self::NOFX_PROCESS_CPP_ARGS($args, $methodName, $className, $cpp_dependencies);
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
        $should_derefrence = false;
        if (!empty($original_def)) {$should_derefrence = $original_def['returns_pointer'];}
        switch ($return_type) {
            case 'inline void':
            case 'void':
                $tmpl .= $callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass});\n";
                break;
            case 'ofRectangle':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofRectangle', $className, $dependencies);
                $tmpl .= self::NOFX_JS_UNWRAP('ofRectangle', $className, '', $cpp_dependencies).'->SetWrapped('.($should_derefrence ? '*' : '').$callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass}));\n";
                $return_statement .= 'JsReturn';
                break;
            case 'ofPoint':
            case 'ofPoint &':
            case 'inline static ofVec3f':
            case 'inline ofVec3f':
            case 'ofVec3f':
            case 'ofVec3f &':
            case 'static ofVec3f':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofVec3f', $className, $dependencies);
                $tmpl .= self::NOFX_JS_UNWRAP('ofVec3f', $className, '', $cpp_dependencies).'->SetWrapped('.($should_derefrence ? '*' : '').$callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass}));\n";
                $return_statement .= 'JsReturn';
                break;
            case 'ofVec2f':
            case 'ofVec2f &':
            case 'static ofVec2f':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofVec2f', $className, $dependencies);
                $tmpl .= self::NOFX_JS_UNWRAP('ofVec2f', $className, '', $cpp_dependencies).'->SetWrapped('.($should_derefrence ? '*' : '').$callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass}));\n";
                $return_statement .= 'JsReturn';
                break;
            case 'ofVec4f':
            case 'inline ofVec4f':
            case 'ofVec4f &':
            case 'static ofVec4f':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofVec4f', $className, $dependencies);
                $tmpl .= self::NOFX_JS_UNWRAP('ofVec4f', $className, '', $cpp_dependencies).'->SetWrapped('.($should_derefrence ? '*' : '').$callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass}));\n";
                $return_statement .= 'JsReturn';
                break;
            case 'inline const ofQuaternion':
            case 'inline ofQuaternion':
            case 'ofQuaternion':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofQuaternion', $className, $dependencies);
                $tmpl .= self::NOFX_JS_UNWRAP('ofQuaternion', $className, '', $cpp_dependencies).'->SetWrapped('.($should_derefrence ? '*' : '').$callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass}));\n";
                $return_statement .= 'JsReturn';
                break;
            case 'inline const ofMatrix4x4':
            case 'inline static ofMatrix4x4':
            case 'inline ofMatrix4x4':
            case 'ofMatrix4x4':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofMatrix4x4', $className, $dependencies);
                $tmpl .= self::NOFX_JS_UNWRAP('ofMatrix4x4', $className, '', $cpp_dependencies).'->SetWrapped('.($should_derefrence ? '*' : '').$callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass}));\n";
                $return_statement .= 'JsReturn';
                break;
            case 'inline bool':
            case 'bool':
            case 'int':
            case 'double':
            case 'float':
            case 'inline float &':
            case 'inline float':
            case 'size_t':
                $return_statement .= $callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass})";
                break;
            case 'const float *':
            case 'float *':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('floatPtr', $className, $dependencies);
                $tmpl .= self::NOFX_JS_UNWRAP('floatPtr', $className, '', $cpp_dependencies).'->SetWrapped('.$callerObj.self::GET_CPP_NAME($methodName)."({$args_to_pass}));\n";
                $return_statement .= 'JsReturn';
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
        &$cpp_dependencies = null //this is a list of headers needed to be included in C++ land. not actual dependecies
    ) {
        $tmpl = 'const auto self = '.self::NOFX_JS_UNWRAP($className, $className, 'args.This()', $cpp_dependencies).'->GetWrapped();';
        $tmpl .= "\n";
        //Pointer to self obtained, shall we check it?
        if (self::IS_STRICT()) {
            //checking if pointer got from ObjectWrap is empty or not. Ideally it should never happen
            $tmpl .= <<<TPL
#if NOFX_STRICT
if(!self) {
    NanReturnUndefined();
}
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
                $tmpl .= self::NOFX_JS_UNWRAP('ofRectangle', $className, '', $cpp_dependencies).'->SetWrapped('.$callerObj.$propName.");\n";
                $return_statement .= 'JsReturn';
                break;
            case 'ofPoint':
            case 'ofVec3f':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofVec3f', $className, $dependencies);
                $tmpl .= '    ';
                $tmpl .= self::NOFX_JS_UNWRAP('ofVec3f', $className, '', $cpp_dependencies).'->SetWrapped('.$callerObj.$propName.");\n";
                $return_statement .= 'JsReturn';
                break;
            case 'ofVec4f':
                $tmpl .= self::NOFX_JS_NEW_INSTANCE('ofVec4f', $className, $dependencies);
                $tmpl .= '    ';
                $tmpl .= self::NOFX_JS_UNWRAP('ofVec4f', $className, '', $cpp_dependencies).'->SetWrapped('.$callerObj.$propName.");\n";
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
        $return_type,
        &$cpp_dependencies = null //this is a list of headers needed to be included in C++ land. not actual dependecies
    ) {
        $tmpl = 'auto self = '.self::NOFX_JS_UNWRAP($className, $className, 'args.This()', $cpp_dependencies).'->GetWrapped();';
        $tmpl .= "\n";
        //Pointer to self obtained, shall we check it?
        if (self::IS_STRICT()):
            //checking if pointer got from ObjectWrap is empty or not. Ideally it should never happen
            $msg = Messages::Format(Messages::NULL_SELF_ACCESS, array(
                'name' => $propName,
                'type' => $className
            ));
            $tmpl .= <<<TPL
#if NOFX_STRICT
if(!self) {
    NanThrowError("{$msg}");
}
#endif

TPL;
            endif;
        //self pointer Checks are passed (if any)
        $callerObj = '    self->';
        switch ($return_type) {
            case 'ofRectangle':
                $tmpl .= $callerObj.$propName.'.set(*'.self::NOFX_JS_UNWRAP('ofRectangle', $className, 'args.This()', $cpp_dependencies).'->GetWrapped());'."\n";
                break;
            case 'ofPoint':
            case 'ofVec3f':
                $tmpl .= $callerObj.$propName.'.set(*'.self::NOFX_JS_UNWRAP('ofVec3f', $className, 'args.This()', $cpp_dependencies).'->GetWrapped());'."\n";
                break;
            case 'ofVec4f':
                $tmpl .= $callerObj.$propName.'.set(*'.self::NOFX_JS_UNWRAP('ofVec4f', $className, 'args.This()', $cpp_dependencies).'->GetWrapped());'."\n";
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
                throw new Exception('Return type for setter body can\'t be recognized. Type is: ['.$return_type.']');
                break;
        }
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
            case 'inline void':
            case 'void':
                $return .= 'NanReturnUndefined();'."\n";
                break;
            case 'string':
                $return .= 'NanReturnValue(*NanUtf8String('.$return_statement.'));'."\n";
                break;
            case 'bool':
            case 'inline bool':
            case 'int':
            case 'double':
            case 'float':
            case 'inline float &':
            case 'inline float':
            case 'size_t':
            case 'ofRectangle':
            case 'static ofVec2f':
            case 'ofVec2f':
            case 'ofVec2f &':
            case 'inline static ofMatrix4x4':
            case 'static ofMatrix4x4':
            case 'ofMatrix4x4':
            case 'ofMatrix4x4 &':
            case 'static ofVec4f':
            case 'inline ofVec4f':
            case 'ofVec4f':
            case 'ofVec4f &':
            case 'ofPoint':
            case 'ofPoint &':
            case 'inline ofVec3f':
            case 'inline static ofVec3f':
            case 'ofVec3f':
            case 'ofVec3f &':
            case 'static ofVec3f':
            case 'ofQuaternion':
            case 'inline ofQuaternion':
            case 'inline const ofQuaternion':
            case 'float *':
            case 'const float *':
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
    static function NOFX_GETTER_SIGNATURE_CC($className, $name, $bracketAndEnter = false) {
        return 'NAN_GETTER('.self::GET_CLASS_WRAPPED_NAME($className).'::Get'.self::GET_JS_NAME($name).')'.($bracketAndEnter ? " {\n" : '');
    }

    /**
    * Generates getter for CC files
    * 
    * @param mixed $className
    * @param mixed $name
    * @param mixed $returnType
    * @param mixed $deps
    */
    static function NOFX_GETTER_IMPLEMENTATION_CC($className, $name, $returnType, &$deps) {
        $tmpl = '';
        $tmpl .= self::NOFX_GETTER_SIGNATURE_CC($className, $name, true);
        $tmpl .= self::NOFX_GETTER_BODY_CC($className, $name, $returnType, $deps);
        $tmpl .= "} //!Get".self::GET_JS_NAME($name)."\n";
        return $tmpl;
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
    static function NOFX_PROCESS_CPP_ARGS($args, $methodName, $className, &$cpp_dependencies /*this is a list of headers needed to be included in C++ land. not actual dependecies*/) {
        $args_to_pass = '';
        $args_guards = '';
        if (count($args) == 1 && $args[0]['raw_type'] == 'void') {return array('args_to_pass' => $args_to_pass, 'args_guards' => $args_guards);}
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
                case '::ofVec3f':
                    $current_arg_str .= "*".self::NOFX_JS_UNWRAP('ofVec3f', $className, "args[{$index}]->ToObject()", $cpp_dependencies)."->GetWrapped(),";
                    break;
                case 'ofVec2f':
                case '::ofVec2f':
                    $current_arg_str .= "*".self::NOFX_JS_UNWRAP('ofVec2f', $className, "args[{$index}]->ToObject()", $cpp_dependencies)."->GetWrapped(),";
                    break;
                case 'ofVec4f':
                case '::ofVec4f':
                    $current_arg_str .= "*".self::NOFX_JS_UNWRAP('ofVec4f', $className, "args[{$index}]->ToObject()", $cpp_dependencies)."->GetWrapped(),";
                    break;
                case 'ofMatrix4x4':
                case '::ofMatrix4x4':
                    $current_arg_str .= "*".self::NOFX_JS_UNWRAP('ofMatrix4x4', $className, "args[{$index}]->ToObject()", $cpp_dependencies)."->GetWrapped(),";
                    break;
                case 'ofRectangle':
                case '::ofRectangle': //reference
                    $current_arg_str .= "*".self::NOFX_JS_UNWRAP('ofRectangle', $className, "args[{$index}]->ToObject()", $cpp_dependencies)."->GetWrapped(),";
                    break;
                case '::ofQuaternion': //reference
                case 'ofQuaternion':
                    $current_arg_str .= "*".self::NOFX_JS_UNWRAP('ofQuaternion', $className, "args[{$index}]->ToObject()", $cpp_dependencies)."->GetWrapped(),";
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
    static function NOFX_METHODS_SIGNATURES_H(
        $methods_defs,
        $method_name,
        $def,
        $main_class
    ) {
        $tmpl = '';
        if (count($methods_defs[$method_name]) > 1) {
            $mangled_name = Compiler::GET_JS_NAME($method_name).'_'.count($methods_defs[$method_name]).'_'.Compiler::MANGLE_NAME($def['debug']);
            $tmpl .= Compiler::NOFX_METHOD_DOCUMENTATION_H($main_class, $mangled_name, $def['line_number'], $def['debug'], isset($def['doxygen']) ? $def['doxygen'] : "No Doxygen were found for this method.");
            $tmpl .= Compiler::NOFX_METHOD_SIGNATURE_H($mangled_name, true);
        } else {
            $tmpl .= Compiler::NOFX_METHOD_DOCUMENTATION_H($main_class, $method_name, $def['line_number'], $def['debug'], isset($def['doxygen']) ? $def['doxygen'] : "No Doxygen were found for this method.");
            $tmpl .= Compiler::NOFX_METHOD_SIGNATURE_H(Compiler::GET_JS_NAME($method_name), true);
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
    static function NOFX_METHOD_IMPLEMENTATION_CC(
        $methods_defs,
        $method_name,
        $def,
        $main_class,
        &$dependencies
    ) {
        $tmpl = '';
        $mangled_name = '';
        if (count($methods_defs[$method_name]) > 1) {
            $mangled_name = Compiler::GET_JS_NAME($method_name).'_'.count($methods_defs[$method_name]).'_'.Compiler::MANGLE_NAME($def['debug']);
            $tmpl .= Compiler::NOFX_METHOD_SIGNATURE_CC($main_class, $mangled_name, true);
        } else {
            $mangled_name = Compiler::GET_JS_NAME($method_name);
            $tmpl .= Compiler::NOFX_METHOD_SIGNATURE_CC($main_class, $mangled_name, true);
        }
        $dummy = array();
        $tmpl .= Compiler::NOFX_METHOD_BODY_CC(
            $main_class,
            $method_name,
            isset($def['static']) ? $def['static'] : false,
            isset($def['const']) ? $def['const'] : false,
            $def['rtnType'],
            $def['parameters'],
            $dependencies,$dummy,$def);
        $tmpl .= "} //!{$mangled_name} \n\n";
        return $tmpl;
    }

    /**
    * Setter sig for header
    * 
    * @param mixed $method_name
    * @param mixed $semicolonAndEnter
    */
    static function NOFX_SETTER_SIGNATURE_CC($className, $name, $bracketAndEnter = false) {
        return 'NAN_SETTER('.self::GET_CLASS_WRAPPED_NAME($className).'::Set'.self::GET_JS_NAME($name).')'.($bracketAndEnter ? " {\n" : '');
    }

    /**
    * JS ctor
    * 
    * @param mixed $className
    * @param mixed $name
    * @param mixed $return_type
    */
    static function NOFX_SETTER_IMPLEMENTATION_CC($className, $name, $return_type) {
        $tmpl = self::NOFX_SETTER_SIGNATURE_CC($className, $name, true);
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
    static function NOFX_JS_INITIALIZER_CC($className, $methods, $props = array(), $index_mutators = array()) {
        $classNameWrapped = self::GET_CLASS_WRAPPED_NAME($className);
        $classUname = strtoupper($className);
        $mutators = '';        
        foreach($props as $prop) {
            $mutators .= "inst->SetAccessor(NanNew(\"".$prop['name']."\"), {$classNameWrapped}::Get".ucfirst($prop['name']);
            if ($prop['has_setter']) {
                $mutators .= ", {$classNameWrapped}::Set".ucfirst($prop['name']).");\n";
            } else if(isset($prop['static']) && $prop['static']) {
                $mutators .= ", 0, v8::Handle<v8::Value>(), v8::PROHIBITS_OVERWRITING);\n";
            } else {
                $mutators .= ");\n";
            }
        }
        
        if(!empty($index_mutators) && isset($index_mutators['getter'])) {
            $mutators .= "inst->SetIndexedPropertyHandler(".self::GET_CLASS_WRAPPED_NAME($className)."::IndexGetter";
            if (isset($index_mutators['setter'])) {
                $mutators .= ", OfVec3fWrap::IndexSetter);\n";
            } else {
                $mutators .= ");\n";
            }
        }

        $method_tmpl = '';
        foreach($methods as $method_name => $method_defs) {
            if (count($methods[$method_name]) > 1) {
                foreach($method_defs as $method_def) {
                    $mangled_name = Compiler::GET_JS_NAME($method_name).'_'.count($methods[$method_name]).'_'.Compiler::MANGLE_NAME($method_def['debug']);
                    $method_tmpl .= "NanSetPrototypeTemplate(tpl, NanNew(\"".lcfirst($mangled_name)."\"), NanNew<v8::FunctionTemplate>(".$mangled_name."), v8::ReadOnly);\n";
                }
            } else {
                $mangled_name = Compiler::GET_JS_NAME($method_name);
                $method_tmpl .= "NanSetPrototypeTemplate(tpl, NanNew(\"".lcfirst($mangled_name)."\"), NanNew<v8::FunctionTemplate>(".$mangled_name."), v8::ReadOnly);\n";
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
    static function NOFX_JS_CTOR_IMPLEMENTATION_CC($className, $ctor_defs, &$cpp_dependencies = null) {
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
                    //Arguments with length == 1 must be always type checked. They can be easilly confused with copy constructors.
                    $conditionLoop .= 'if (';
                    foreach($ctor_overload['parameters'] as $index => $arg) {
                        $conditionLoop .= self::GENERATE_CPP_JSARG_TYPE_CHECK($arg['type'], $index, $className.' constructor', true).' &&';
                    }
                    $conditionLoop = rtrim($conditionLoop, " &&");
                    $conditionLoop .= ') {'."\n";
                    $processed_args = self::NOFX_PROCESS_CPP_ARGS($ctor_overload['parameters'], $className.' constructor', $className, $cpp_dependencies);
                    $args_to_pass = $processed_args['args_to_pass'];
                    $conditionLoop .= "                ";
                    $conditionLoop .= "obj = new {$classWrappedName}(new {$className}({$args_to_pass}));\n";
                    $conditionLoop .= "            ";
                    $conditionLoop .= "}\n";
                } else {
                    $processed_args = self::NOFX_PROCESS_CPP_ARGS($ctor_overload['parameters'], $className.' constructor', $className, $cpp_dependencies);
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
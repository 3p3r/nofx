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

class ParserUtils {
    static function NOFX_METHOD_DOCUMENTATION_H($className, $method_name, $line_no, $sig, $doxygen = "No Doxygen docs were found for this method.") {
        $tmpl = <<<TPL
/**
* Original signature: {$sig}
* Corresponds to line no {$line_no}
* Original OF doxygen:
{$doxygen}
*
*/
TPL;
        return $tmpl;
    }
    static function GET_CLASS_WRAPPED_NAME($className) {
        return ucfirst($className).'Wrap';
    }
    static function GET_JS_METHOD_NAME($method_name) {
        return ucfirst($method_name);
    }
    static function GET_CPP_METHOD_NAME($method_name) {
        return lcfirst($method_name);
    }
    static function NOFX_METHOD_SIGNATURE_H($method_name, $semicolonAndEnter = false) {
        return 'static NAN_METHOD('.$this->GET_JS_METHOD_NAME($method_name).')'.($semicolonAndEnter ? ";\n" : '');
    }
    static function NOFX_METHOD_SIGNATURE_CC($className, $method_name, $semicolonAndEnter = false) {
        return 'NAN_METHOD('.$this->GET_CLASS_WRAPPED_NAME($className).'.Wrap::'.$this->GET_JS_METHOD_NAME($method_name).')'.($semicolonAndEnter ? ";\n" : '');
    }
    static function NOFX_METHOD_BODY_CC($className, $methodName, $is_static, $is_const, $return_type) {
        $tmpl = '';
        if ($is_static) {
            
        } else {
            if ($is_const) $tmpl .= 'const ';
            $tmpl .= 'auto self = nofx::ObjectWrap::Unwrap<'.$this->GET_CLASS_WRAPPED_NAME($className).'>(args.This())->GetWrapped();';
            $tmpl .= "\n";
            if ($return_type == 'void') {
                $tmpl .= 'self->'.$this->GET_CPP_METHOD_NAME($methodName).'();'."\n";
                $tmpl .= 'NanReturnUndefined();'."\n";
            }
        }
    }
    static function NOFX_GETTER_SIGNATURE_CC($className, $method_name, $semicolonAndEnter = false) {
        return 'NAN_GETTER('.$this->GET_CLASS_WRAPPED_NAME($className).'.Wrap::'.$this->GET_JS_METHOD_NAME($method_name).')'.($semicolonAndEnter ? ";\n" : '');
    }
}
?>
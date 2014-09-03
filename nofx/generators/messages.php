<?php
class Messages
{
    /**
    * Formats a const memeber of the Messages class and replaces passed ##vars##
    * 
    * @param string $msg
    * @param array  $params
    * 
    * @returns the formatted string
    */
    static function Format($msg, $params = array()) {
        if (!empty($params)) {
            foreach($params as $search => $replace) {
                $msg = str_ireplace('##'.$search.'##', $replace, $msg);
            }
        }
        return $msg;
    }
    
    // Static compiler messages
    const PARSE_FAILED = 'JSON decoding / parsing failed. Check the CPP header. Passed header is: ##header##';
    const CPP_JSARG_TYPE_CHECK_FAILED = 'Argument at index ##index## is incompatible with ##method##\'s prototype.\nExpected type is ##type##.';
    const SINGLE_ARG_NOTE = '//Arguments with length == 1 must be always type checked. They can be easilly confused with copy constructors.';
    const NULL_SELF_ACCESS = 'You can\'t use setter for ##name## before object of type ##type## is initialized. (self is null)';
}
?>
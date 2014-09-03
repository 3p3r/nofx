<?php
class Parser {
    private $_path;
    private $_parsedRaw;
    private $_parsedJson;

    function __construct($headerPath) {
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
            throw new Exception(Messages::Format(Messages::PARSE_FAILED, array('header' => $this->_path)));
        }
        return $this->_parsedJson;
    }
}
?>
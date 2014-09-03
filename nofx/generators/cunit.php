<?php
abstract class CompilerUnit
{
    private $class_name   = '';
    private $methods      = array();
    private $properties   = array();
    private $header_name  = '';
    private $constructors = array();
    private $dependencies = array();

    protected function getClassName()           {return $this->class_name;}
    protected function setClassName($name)      {$this->class_name = $name;}

    protected function getMethods()             {return $this->methods;}
    protected function setMethods($methods)     {$this->methods = $methods;}

    protected function getProperties()          {return $this->properties;}
    protected function setProperties($props)    {$this->properties = $props;}    

    protected function getHeaderName()          {return $this->header_name;}
    protected function setHeaderName($name)     {$this->header_name = $name;}

    protected function getConstructor()         {return $this->constructors;}
    protected function setConstructor($ctor)    {$this->constructors = $ctor;}

    protected function &getDependencies()       {return $this->dependencies;}
    protected function setDependencies($deps)   {$this->dependencies = $deps;}

    protected function getLClassName()          {return lcfirst($this->getClassName());}
    protected function getUClassName()          {return ucfirst($this->getClassName());}

    protected function getAllCapsClassName()    {return strtoupper($this->getClassName());}
    protected function getNoCapsClassName()     {return strtolower($this->getClassName());}

    static protected function camelCasedToUnderScored($input)
    {return strtoupper(preg_replace('/(?<=\\w)(?=[A-Z])/',"_$1", $input));}

    static protected function trimOfPrefix($input)
    {$count = 1; return ucfirst(str_ireplace("of", "", $input, $count));}

    public function __construct($header_absolute_path) {
        $data = Compiler::SANITIZED_HEADER_DATA($header_absolute_path);

        $this->setClassName($data['target']);
        $this->setMethods($data['methods']);
        $this->setProperties($data['properties']);
        $this->setHeaderName($data['filename']);
        $this->setConstructor($data['constructors']);

        Compiler::PRE_DETERMINE_DEPENDENCIES($this->getclassname(), $this->getProperties(), $this->getMethods(), $this->getDependencies());
    }

    public abstract function main();
    public abstract function globals();
    public abstract function H();
    public abstract function CC();
    public abstract function depCC();
    public abstract function depH();
    public function compile() {
        $this->globals();
        $this->main();
        $this->H();
        $this->CC();
        if(count($this->getDependencies()) > 0) {
            $this->depH();
            $this->depCC();
        }
    }

    protected function getDependencySetterBlock() {
        $depBody = '';
        if(count($this->getDependencies()) > 0) {
            //$depHeader = "#include \"nofx_{$this->lClassName}_dependencies.h\"";
            $depBody = <<<TPL
target->Set( //##MODULE_NAME## dependency setter, should be called in JS land
    NanNew<v8::String>("dependencies"),
    NanNew<v8::FunctionTemplate>(nofx_##MODULE_NAME##_dependencies)->GetFunction());
        
TPL;
            $depBody = str_replace('##MODULE_NAME##', $this->getLClassName(), $depBody);
        }
        return $depBody;
    }

    protected function getNofxDependencyHeaderInclude() {
        $depHeader = '';
        if(count($this->getDependencies()) > 0) {
            $depHeader = "#include \"nofx_{$this->getLClassName()}_dependencies.h\"";
        }
        return $depHeader;
    }
    
    protected function getNofxDependencyHeaderFiles() {
        $depHeader = "";
        if(count($this->getDependencies()) > 0) {
            foreach($this->getDependencies() as $dep) {
                $depHeader .= '#include "..\nofx_'.$dep.'\nofx_'.$dep.'.h"'."\n";
            }
        }
        return $depHeader;
    }

    protected function getClassMethodsForWrapperHeader() {
        $methodsTmpl = "";
        Compiler::METHOD_ITERATOR($this->getClassName(), $this->getMethods(), function($mangled_name, $method_def, &$template) {
            $template .= Compiler::NOFX_METHOD_DOCUMENTATION_H($this->getClassName(), $mangled_name, $method_def['line_number'], $method_def['debug'], isset($method_def['doxygen']) ? $method_def['doxygen'] : "/// \\brief Doxygen could not be found.");
            $template .= Compiler::NOFX_METHOD_SIGNATURE_H($mangled_name, true);
            $template .= "\n";            
            }, $methodsTmpl);
        return $methodsTmpl;
    }

    protected function getClassMethodsForWrapperSource() {
        $methodsTmpl = "";
        foreach($this->getMethods() as $method_name => $method_def) {
            foreach($method_def as $index => $def) {
                $methodsTmpl .= Compiler::NOFX_METHOD_IMPLEMENTATION_CC($this->getMethods(), $method_name, $def, $this->getClassName(), $this->getDependencies());
            }
        }
        return $methodsTmpl;
    }
    
    protected function getClassGettersForWrapperHeader() {
        $getters = "";
        $setters = "";

        Compiler::PROPERTIES_ITERATOR($this->getProperties(), function($name, &$tmpl) {
            $tmpl .= Compiler::NOFX_GETTER_SIGNATURE_H($name, true);            
            }, $getters,
            function($name, &$tmpl) {
                $tmpl .= Compiler::NOFX_SETTER_SIGNATURE_H($name, true);
            }, $setters);
        
        return $getters;
    }
    
    protected function getClassSettersForWrapperHeader() {
        $getters = "";
        $setters = "";

        Compiler::PROPERTIES_ITERATOR($this->getProperties(), function($name, &$tmpl) {
            $tmpl .= Compiler::NOFX_GETTER_SIGNATURE_H($name, true);            
            }, $getters,
            function($name, &$tmpl) {
                $tmpl .= Compiler::NOFX_SETTER_SIGNATURE_H($name, true);
            }, $setters);
        
        return $setters;
    }
    
    protected function getClassGettersForWrapperSource() {
        $getters = "";
        $setters = "";
        foreach($this->getProperties() as $prop) {
            $getters .= Compiler::NOFX_GETTER_IMPLEMENTATION_CC($this->getClassName(), $prop['name'],$prop['raw_type'] ,$this->getDependencies());
            if($prop['has_setter']) {
                $setters .= Compiler::NOFX_SETTER_IMPLEMENTATION_CC($this->getClassName(), $prop['name'],$prop['raw_type']);
            }
        }
        
        return $getters;
    }
    
    protected function getClassSettersForWrapperSource() {
        $getters = "";
        $setters = "";
        foreach($this->getProperties() as $prop) {
            $getters .= Compiler::NOFX_GETTER_IMPLEMENTATION_CC($this->getClassName(), $prop['name'],$prop['raw_type'] ,$this->getDependencies());
            if($prop['has_setter']) {
                $setters .= Compiler::NOFX_SETTER_IMPLEMENTATION_CC($this->getClassName(), $prop['name'],$prop['raw_type']);
            }
        }
        
        return $setters;
    }
    
    protected function getClassInitializer() {
        return Compiler::NOFX_JS_INITIALIZER_CC($this->getClassName(), $this->getMethods(), $this->getProperties());
    }
    
    protected function getConstructorImplementation() {
        return Compiler::NOFX_JS_CTOR_IMPLEMENTATION_CC($this->getClassName(), $this->getConstructor());
    }
    
    protected function getDependencyListForGlobals() {
        $list = '';
        foreach($this->getDependencies() as $dep) {
            $list .= "\nextern v8::Persistent<v8::Function> DEP_{$dep};\nextern bool isset_DEP_{$dep};\n";
        }
        
        return $list;
    }
    
    protected function getDependencyListForSource() {
        $list = '';
        $block = '';

        foreach($this->getDependencies() as $dep) {
            $list .= "\nv8::Persistent<v8::Function> DEP_{$dep};\nbool isset_DEP_{$dep} = false;\n";
            $block .= "\nif(args[0]->ToObject->Has(NanNew(\"{$dep}\"))) {
            NanAssignPersistent(DEP_{$dep}, v8::Handle<v8::Function>::Cast(
            args[0]->ToObject()->Get(NanNew(\"{$dep}\"))));
            isset_DEP_{$dep} = true;
            }\n";
        }
        
        return $list;
    }
    
    protected function getDependencyBlockForSource() {
        $list = '';
        $block = '';

        foreach($this->getDependencies() as $dep) {
            $list .= "\nv8::Persistent<v8::Function> DEP_{$dep};\nbool isset_DEP_{$dep} = false;\n";
            $block .= "\nif(args[0]->ToObject->Has(NanNew(\"{$dep}\"))) {
            NanAssignPersistent(DEP_{$dep}, v8::Handle<v8::Function>::Cast(
            args[0]->ToObject()->Get(NanNew(\"{$dep}\"))));
            isset_DEP_{$dep} = true;
            }\n";
        }
        
        return $block;
    }
    
    function writeSource($filename, $source) {
        if(!is_dir('build')) {
            mkdir('build');
        }
        if(!is_dir('build'.DIRECTORY_SEPARATOR.$this->getClassName())) {
            mkdir('build'.DIRECTORY_SEPARATOR.$this->getClassName());
        }
        file_put_contents('build'.DIRECTORY_SEPARATOR.$this->getClassName().DIRECTORY_SEPARATOR.$filename, $this->formatSource($source, true));
        echo 'Wrote '.$filename.'<br />';
    }
    
    function formatSource($source, $return = false) {
        if ($return) {
            return self::formatCppSource($source);
        } else {
            echo self::formatCppSource($source);
        }
    }
    
    static public function formatCppSource($source, $extension = '.cc') {
        $file_name = md5(microtime().$source); //This is SLOAAAAW!
        file_put_contents($file_name.$extension, $source);
        shell_exec(escapeshellcmd('astyle '.$file_name.$extension.' --style=google --indent=spaces=4'));
        $formatted = file_get_contents($file_name.$extension);
        unlink($file_name.$extension);
        @unlink($file_name.$extension.'.orig');
        return $formatted;
    }
}
?>
<?php
require_once("phpQuery/phpQuery.php");
$className = lcfirst($_GET["className"]);
$url = $_GET["url"];
$ofDocPageStr = file_get_contents($url);
$ofDocPage = phpQuery::newDocument($ofDocPageStr);
$methods = array();
$functions = array();
$variables = array();
foreach($ofDocPage['ul.functionslist li a'] as $node) {
    if($node->nodeValue != $className."()") {
        if(substr($node->nodeValue, 0, 2) == "of" && substr($node->nodeValue, -2) == "()") {
            //this is a global function
            array_push($functions, str_replace("()", "", $node->nodeValue ));
        } else if (substr($node->nodeValue, -2) == "()" && !strstr($node->nodeValue, "operator")) {
            //this is a class method
            array_push($methods, str_replace("()", "", $node->nodeValue ));
        } else if(!strstr($node->nodeValue, "operator")) {
            //this is a variable
            $temp = explode(" ", $node->nodeValue);
            array_push($variables, end($temp) );
        } else {
            //this is either unknown or an operator overload
        }
    }
}

function makeHeader($method, $headerName) {
    $header = "#ifndef _NOFX_".strtoupper($method)."_H_
#define _NOFX_".strtoupper($method)."_H_

#include \"globals.h\"

namespace nofx
{
    namespace ".ucfirst(substr($headerName, 2))."
    {
        NAN_METHOD(nofx_".lcfirst($method).");
    } // !namespace ".ucfirst(substr($headerName, 2))."
} // !namespace nofx

#endif // !_NOFX_".strtoupper($method)."_H_";
    return $header;
}

function makeSource($method, $headerName) {
    $source = "#include \"nofx_".lcfirst($method).".h\"
#include \"".$headerName.".h\"

namespace nofx
{
    namespace ".ucfirst(substr($headerName, 2))."
    {
        NAN_METHOD(nofx_".lcfirst($method).")
        {
        
            //".lcfirst($method)."(...);
        
            NanReturnUndefined();
        } // !nofx_".lcfirst($method)."
    } // !namespace ".ucfirst(substr($headerName, 2))."
} // !namespace nofx";
return $source;
}

function makeTargetBindings($methods, $headerName) {
$includes = "";
$init = "\n";
foreach($methods as $method) {
    $includes .= "#include \"nofx_".lcfirst($method).".h\"\n";
    $init .= "          target->Set(NanNew<v8::String>(\"".lcfirst($method)."\"), NanNew<v8::FunctionTemplate>(nofx_".lcfirst($method).")->GetFunction());\n";
}
$target_bindings = "#include \"globals.h\"
".$includes."
namespace nofx
{
    namespace ".ucfirst(substr($headerName, 2))."
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {
".$init."
        } //!Initialize
    } //!namespace ".ucfirst(substr($headerName, 2))."
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_".lcfirst($headerName).", nofx::".ucfirst(substr($headerName, 2))."::Initialize)
";
return $target_bindings;
}

if(isset($_GET["build"])) {
    foreach ($functions as $method) {
        file_put_contents("nofx_".lcfirst($method).".h", makeHeader($method, $className));
        file_put_contents("nofx_".lcfirst($method).".cc", makeSource($method, $className));
    }
    file_put_contents("main.cc", makeTargetBindings($functions, $className));
} else {
    die(var_dump($functions));
}
?>
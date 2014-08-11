<?php
$methods = array(
    "ofDoesHWOrientation",
    "ofExit",
    "ofGetAppPtr",
    "ofGetFrameNum",
    "ofGetFrameRate",
    "ofGetHeight",
    "ofGetLastFrameTime",
    "ofGetOrientation",
    "ofGetScreenHeight",
    "ofGetScreenWidth",
    "ofGetTargetFrameRate",
    "ofGetWidth",
    "ofGetWindowHeight",
    "ofGetWindowMode",
    "ofGetWindowPositionX",
    "ofGetWindowPositionY",
    "ofGetWindowPtr",
    "ofGetWindowRect",
    "ofGetWindowSize",
    "ofGetWindowWidth",
    "ofHideCursor",
    "ofRunApp",
    "ofSetAppPtr",
    "ofSetFrameRate",
    "ofSetFullscreen",
    "ofSetOrientation",
    "ofSetVerticalSync",
    "ofSetWindowPosition",
    "ofSetWindowShape",
    "ofSetWindowTitle",
    "ofSetupOpenGL",
    "ofShowCursor",
    "ofSleepMillis",
    "ofToggleFullscreen"
);

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

foreach ($methods as $method) {
    file_put_contents("nofx_".lcfirst($method).".h", makeHeader($method, "ofAppRunner"));
    file_put_contents("nofx_".lcfirst($method).".cc", makeSource($method, "ofAppRunner"));
}
file_put_contents("main.cc", makeTargetBindings($methods, "ofAppRunner"));
?>
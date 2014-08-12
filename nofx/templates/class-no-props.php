<?php
$className = "ofAppBaseWindow";
$methods = array(
    "disableSetupScreen",
    "doesHWOrientation",
    "enableSetupScreen",
    "getHeight",
    "getOrientation",
    "getScreenSize",
    "getWidth",
    "getWindowMode",
    "getWindowPosition",
    "getWindowSize",
    "hideCursor",
    "initializeWindow",
    "runAppViaInfiniteLoop",
    "setFullscreen",
    "setOrientation",
    "setVerticalSync",
    "setWindowPosition",
    "setWindowShape",
    "setWindowTitle",
    "setupOpenGL",
    "showCursor",
    "toggleFullscreen"
);

function makeHeader($methods, $className) {
    $lClassName = lcfirst($className);
    $uClassName = ucfirst($className);
    $guard = strtoupper(preg_replace('/(?<=\\w)(?=[A-Z])/',"_$1", $className));
    $methodsTmpl = "";
    foreach($methods as $method) {
        $methodsTmpl .= "            static NAN_METHOD(".ucfirst($method).");\n";
    }
    $template = <<<TMP
#ifndef _NOFX_{$guard}_H_
#define _NOFX_{$guard}_H_

#include "globals.h"
#include "{$className}.h"

using namespace v8;

namespace nofx
{
    namespace {$uClassName}
    {
        class {$uClassName}Wrap
            : public node::ObjectWrap
        {
        public:
            static void Initialize(v8::Handle<Object> target);
            {$lClassName}* GetWrapped() const { return internal_.get(); };
            void SetWrapped({$lClassName}* n)  { internal_.reset(n); };
            static const Persistent<Function>& Factory() { return constructor; }
        private:
            {$uClassName}Wrap();
            {$uClassName}Wrap({$lClassName}*);
            ~{$uClassName}Wrap() {};

            // Methods
{$methodsTmpl}
            static Persistent<Function> constructor;
            static NAN_METHOD(New);
            std::shared_ptr<{$lClassName}> internal_;
        }; // !class {$uClassName}Wrap
    } //!namespace {$uClassName}
} // !namespace nofx

#endif // !_NOFX_{$guard}_H_
    
TMP;

    return $template;
}

function makeSource($methods, $className) {
    $lClassName = lcfirst($className);
    $uClassName = ucfirst($className);
    $protoTmpl = "";
    $methodsTmpl = "";
    foreach($methods as $method) {
        $protoTmpl .= "            NanSetPrototypeTemplate(tpl, NanNew(\"".lcfirst($method)."\"), NanNew<v8::FunctionTemplate>(".ucfirst($method)."), v8::ReadOnly);\n";
        
        $methodsTmpl .= "\n        //---------------------------------------------------------\n";
        $methodsTmpl .= "        NAN_METHOD({$uClassName}Wrap::".ucfirst($method).")\n";
        $methodsTmpl .= "        {\n";
        $methodsTmpl .= "            //implementation\n";
        $methodsTmpl .= "        }\n";
    }
    $template = <<<TMP
#include "nofx_{$lClassName}.h"
#include "nofx_noop.h"

namespace nofx
{
    namespace {$uClassName}
    {
        Persistent<Function> {$uClassName}Wrap::constructor;

        {$uClassName}Wrap::{$uClassName}Wrap()
            //: internal_(...) //implement me
        {}

        //--------------------------------------------------------------
        {$uClassName}Wrap::{$uClassName}Wrap({$lClassName}* aInternal)
            : internal_(aInternal)
        {}

        //--------------------------------------------------------------
        NAN_METHOD({$uClassName}Wrap::New)
        {
            NanScope();
            if (args.IsConstructCall()) {
                {$uClassName}Wrap* obj;
                if (args.Length() == 0)
                {
                    //obj = new {$uClassName}Wrap(); //implement me
                }
                else if (args[0]->IsNull())
                {
                    obj = new {$uClassName}Wrap(nullptr);
                }
                else
                {
                    //copy constructor
                    obj = new {$uClassName}Wrap(ObjectWrap::Unwrap<{$uClassName}Wrap>(args[0]->ToObject())->GetWrapped());
                }
                obj->Wrap(args.This());
                NanReturnValue(args.This());
            }
            else
            {
                // Invoked as plain function `MyObject(...)`, turn into construct call.
                std::vector<v8::Handle<v8::Value>> lArgvVec;
                for (int i = 0; i < args.Length(); ++i) { lArgvVec.push_back(args[i]); }
                NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(lArgvVec.size(), (lArgvVec.size() == 0) ? nullptr : &lArgvVec[0]));
            }
        }

        //--------------------------------------------------------------
        void {$uClassName}Wrap::Initialize(v8::Handle<Object> exports)
        {
            auto tpl = NanNew<v8::FunctionTemplate>(New);
            tpl->SetClassName(NanNew("{$lClassName}"));

            auto inst = tpl->InstanceTemplate();
            inst->SetInternalFieldCount(1);

{$protoTmpl}

            NanAssignPersistent(constructor, tpl->GetFunction());
            exports->Set(NanNew<String>("{$lClassName}"), tpl->GetFunction());
        }

        {$methodsTmpl}
    } //!namespace {$uClassName}
} //!namespace nofx
TMP;
    return $template;
}

function makeMain($className) {
    $lClassName = lcfirst($className);
    $uClassName = ucfirst($className);
    $template = <<<TMP
#include "globals.h"
#include "nofx_{$lClassName}.h"

namespace nofx
{
    namespace {$uClassName}
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

            {$uClassName}Wrap::Initialize(target);

        } //!Initialize
    } //!namespace {$uClassName}
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_{$lClassName}, nofx::{$uClassName}::Initialize)
TMP;
return $template;
}

file_put_contents("nofx_".lcfirst($className).".h", makeHeader($methods, $className));
file_put_contents("nofx_".lcfirst($className).".cc", makeSource($methods, $className));
file_put_contents("main.cc", makeMain($className));
?>
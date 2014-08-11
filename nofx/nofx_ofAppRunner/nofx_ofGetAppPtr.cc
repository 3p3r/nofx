#include "nofx_ofGetAppPtr.h"
#include "ofAppRunner.h"
#include "..\nofx_ofBaseApp\nofx_ofApp.h"

namespace nofx
{
    namespace AppRunner
    {
		using nofx::BaseApp::OfAppImpl;
		using nofx::BaseApp::OfAppWrap;

        NAN_METHOD(nofx_ofGetAppPtr)
        {

			Local<Value> argv[] = { v8::Null(Isolate::GetCurrent()) };
			auto JsAppPtr = NanNew(JsOfBaseApp)->Call(args.This(), 0, nullptr);
			node::ObjectWrap::Unwrap<OfAppWrap>(JsAppPtr->ToObject())->SetWrapped((OfAppImpl*)ofGetAppPtr());
        
			NanReturnValue(JsAppPtr);
        } // !nofx_ofGetAppPtr
    } // !namespace AppRunner
} // !namespace nofx
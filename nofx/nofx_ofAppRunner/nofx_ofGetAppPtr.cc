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

			auto JsAppPtr = DepNewInstance(DEP_ofApp);
			node::ObjectWrap::Unwrap<OfAppWrap>(JsAppPtr->ToObject())->SetWrapped((OfAppImpl*)ofGetAppPtr());
        
			NanReturnValue(JsAppPtr);
        } // !nofx_ofGetAppPtr
    } // !namespace AppRunner
} // !namespace nofx
#include "nofx_ofGetWindowPtr.h"
#include "ofAppRunner.h"
#include "..\nofx_ofAppBaseWindow\nofx_ofAppBaseWindow.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetWindowPtr)
        {
        
			auto JsWindowPtr = DepNewInstance(DEP_ofAppBaseWindow);
			node::ObjectWrap::Unwrap<OfAppBaseWindow::OfAppBaseWindowWrap>(JsWindowPtr->ToObject())->SetWrapped(ofGetWindowPtr());
        
            NanReturnValue(JsWindowPtr);
        } // !nofx_ofGetWindowPtr
    } // !namespace AppRunner
} // !namespace nofx
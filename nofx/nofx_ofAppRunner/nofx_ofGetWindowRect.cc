#include "nofx_ofGetWindowRect.h"
#include "ofAppRunner.h"
#include "..\nofx_ofRectangle\nofx_ofRectangle.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetWindowRect)
        {
        
			auto JsRectangle = DepNewInstance(DEP_ofRectangle);
			node::ObjectWrap::Unwrap<nofx::OfRectangle::OfRectangleWrap>(JsRectangle->ToObject())->SetWrapped(ofGetWindowRect());
            NanReturnValue(JsRectangle);

        } // !nofx_ofGetWindowRect
    } // !namespace AppRunner
} // !namespace nofx
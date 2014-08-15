#include "nofx_ofGetWindowSize.h"
#include "ofAppRunner.h"
#include "..\nofx_ofVec3f\nofx_ofVec3f.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetWindowSize)
        {
        
			auto JsVec3f = DepNewInstance(DEP_ofVec3f);
			node::ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(JsVec3f->ToObject())->SetWrapped(ofGetWindowSize());
			NanReturnValue(JsVec3f);

        } // !nofx_ofGetWindowSize
    } // !namespace AppRunner
} // !namespace nofx
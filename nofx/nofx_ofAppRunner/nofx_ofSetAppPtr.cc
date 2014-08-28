#include "nofx_ofSetAppPtr.h"
#include "ofAppRunner.h"
#include "..\nofx_ofBaseApp\nofx_ofApp.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofSetAppPtr)
        {
        
			ofSetAppPtr( static_cast<std::shared_ptr<ofBaseApp>>( node::ObjectWrap::Unwrap<ClassWrappers::OfAppWrap>(args[0]->ToObject())->GetWrapped() ));
        
            NanReturnUndefined();
        } // !nofx_ofSetAppPtr
    } // !namespace AppRunner
} // !namespace nofx
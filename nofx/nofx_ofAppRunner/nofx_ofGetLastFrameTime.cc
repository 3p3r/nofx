#include "nofx_ofGetLastFrameTime.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetLastFrameTime)
        {
        
			NanReturnValue(ofGetLastFrameTime());
        } // !nofx_ofGetLastFrameTime
    } // !namespace AppRunner
} // !namespace nofx
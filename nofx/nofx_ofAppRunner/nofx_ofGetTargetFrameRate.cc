#include "nofx_ofGetTargetFrameRate.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetTargetFrameRate)
        {
        
			NanReturnValue(ofGetTargetFrameRate());
        } // !nofx_ofGetTargetFrameRate
    } // !namespace AppRunner
} // !namespace nofx
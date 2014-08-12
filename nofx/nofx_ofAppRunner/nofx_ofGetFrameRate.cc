#include "nofx_ofGetFrameRate.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetFrameRate)
        {
        
			NanReturnValue(ofGetFrameRate());
        } // !nofx_ofGetFrameRate
    } // !namespace AppRunner
} // !namespace nofx
#include "nofx_ofGetWindowHeight.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetWindowHeight)
        {
        
			NanReturnValue(ofGetWindowHeight());
        } // !nofx_ofGetWindowHeight
    } // !namespace AppRunner
} // !namespace nofx
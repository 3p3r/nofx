#include "nofx_ofGetWindowWidth.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetWindowWidth)
        {
        
			NanReturnValue(ofGetWindowWidth());
        } // !nofx_ofGetWindowWidth
    } // !namespace AppRunner
} // !namespace nofx
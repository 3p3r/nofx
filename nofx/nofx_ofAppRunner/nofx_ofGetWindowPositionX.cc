#include "nofx_ofGetWindowPositionX.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetWindowPositionX)
        {
        
			NanReturnValue(ofGetWindowPositionX());
        } // !nofx_ofGetWindowPositionX
    } // !namespace AppRunner
} // !namespace nofx
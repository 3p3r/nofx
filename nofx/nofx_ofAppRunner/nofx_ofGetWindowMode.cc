#include "nofx_ofGetWindowMode.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetWindowMode)
        {
        
			NanReturnValue(ofGetWindowMode());
        } // !nofx_ofGetWindowMode
    } // !namespace AppRunner
} // !namespace nofx
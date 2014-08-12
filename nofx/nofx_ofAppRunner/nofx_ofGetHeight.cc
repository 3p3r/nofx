#include "nofx_ofGetHeight.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetHeight)
        {
        
			NanReturnValue(ofGetHeight());
        } // !nofx_ofGetHeight
    } // !namespace AppRunner
} // !namespace nofx
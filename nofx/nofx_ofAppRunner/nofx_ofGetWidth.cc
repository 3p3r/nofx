#include "nofx_ofGetWidth.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetWidth)
        {
        
			NanReturnValue(ofGetWidth());
        } // !nofx_ofGetWidth
    } // !namespace AppRunner
} // !namespace nofx
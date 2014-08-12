#include "nofx_ofGetScreenHeight.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetScreenHeight)
        {
        
			NanReturnValue(ofGetScreenHeight());
        } // !nofx_ofGetScreenHeight
    } // !namespace AppRunner
} // !namespace nofx
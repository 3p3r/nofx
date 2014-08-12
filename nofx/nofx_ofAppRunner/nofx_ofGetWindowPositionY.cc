#include "nofx_ofGetWindowPositionY.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetWindowPositionY)
        {
        
			NanReturnValue(ofGetWindowPositionY());
        } // !nofx_ofGetWindowPositionY
    } // !namespace AppRunner
} // !namespace nofx
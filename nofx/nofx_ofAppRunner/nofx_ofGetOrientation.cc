#include "nofx_ofGetOrientation.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetOrientation)
        {
        
			NanReturnValue(ofGetOrientation());
        } // !nofx_ofGetOrientation
    } // !namespace AppRunner
} // !namespace nofx
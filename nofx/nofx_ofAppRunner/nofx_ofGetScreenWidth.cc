#include "nofx_ofGetScreenWidth.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetScreenWidth)
        {
        
			NanReturnValue(ofGetScreenWidth());
        } // !nofx_ofGetScreenWidth
    } // !namespace AppRunner
} // !namespace nofx
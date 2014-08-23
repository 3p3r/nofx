#include "nofx_ofNormalize.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofNormalize)
        {
        
            NanReturnValue( ofNormalize(
				args[0]->NumberValue(),
				args[1]->NumberValue(),
				args[2]->NumberValue()));

        } // !nofx_ofNormalize
    } // !namespace Math
} // !namespace nofx
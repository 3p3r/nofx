#include "nofx_ofLerp.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofLerp)
        {
        
			NanReturnValue(ofLerp(
				args[0]->NumberValue(),
				args[1]->NumberValue(),
				args[2]->NumberValue()));

        } // !nofx_ofLerp
    } // !namespace Math
} // !namespace nofx
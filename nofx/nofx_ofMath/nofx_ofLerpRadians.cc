#include "nofx_ofLerpRadians.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofLerpRadians)
        {
        
			NanReturnValue(ofLerpRadians(
				args[0]->NumberValue(),
				args[1]->NumberValue(),
				args[2]->NumberValue()));

        } // !nofx_ofLerpRadians
    } // !namespace Math
} // !namespace nofx
#include "nofx_ofLerpDegrees.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofLerpDegrees)
        {
        
			NanReturnValue(ofLerpDegrees(
				args[0]->NumberValue(),
				args[1]->NumberValue(),
				args[2]->NumberValue()));

        } // !nofx_ofLerpDegrees
    } // !namespace Math
} // !namespace nofx
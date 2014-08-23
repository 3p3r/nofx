#include "nofx_ofAngleDifferenceRadians.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofAngleDifferenceRadians)
        {
			NanReturnValue(ofAngleDifferenceRadians(args[0]->NumberValue(), args[1]->NumberValue()));
        } // !nofx_ofAngleDifferenceRadians
    } // !namespace Math
} // !namespace nofx
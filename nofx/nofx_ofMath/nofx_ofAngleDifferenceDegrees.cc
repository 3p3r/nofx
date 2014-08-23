#include "nofx_ofAngleDifferenceDegrees.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofAngleDifferenceDegrees)
        {
            NanReturnValue( ofAngleDifferenceDegrees(args[0]->NumberValue(), args[1]->NumberValue()) );
        } // !nofx_ofAngleDifferenceDegrees
    } // !namespace Math
} // !namespace nofx
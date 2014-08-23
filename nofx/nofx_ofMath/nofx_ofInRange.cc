#include "nofx_ofInRange.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofInRange)
        {
			NanReturnValue(ofInRange(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()));
        } // !nofx_ofInRange
    } // !namespace Math
} // !namespace nofx
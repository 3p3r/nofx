#include "nofx_ofDistSquared.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofDistSquared)
        {
			NanReturnValue(ofDistSquared(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue()));
        } // !nofx_ofDistSquared
    } // !namespace Math
} // !namespace nofx
#include "nofx_ofDegToRad.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofDegToRad)
        {
            NanReturnValue ( ofDegToRad(args[0]->NumberValue()) );
        } // !nofx_ofDegToRad
    } // !namespace Math
} // !namespace nofx
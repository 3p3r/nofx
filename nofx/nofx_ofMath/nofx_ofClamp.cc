#include "nofx_ofClamp.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofClamp)
        {
            NanReturnValue( ofClamp(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()) );
        } // !nofx_ofClamp
    } // !namespace Math
} // !namespace nofx
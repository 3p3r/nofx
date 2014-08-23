#include "nofx_ofRadToDeg.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofRadToDeg)
        {
        
            NanReturnValue( ofRadToDeg(args[0]->NumberValue()) );

        } // !nofx_ofRadToDeg
    } // !namespace Math
} // !namespace nofx
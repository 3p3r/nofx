#include "nofx_ofNextPow2.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofNextPow2)
        {
        
            NanReturnValue( ofNextPow2(args[0]->Int32Value()) );

        } // !nofx_ofNextPow2
    } // !namespace Math
} // !namespace nofx
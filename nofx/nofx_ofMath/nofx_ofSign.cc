#include "nofx_ofSign.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofSign)
        {
        
			NanReturnValue(ofSign(args[0]->NumberValue()));

        } // !nofx_ofSign
    } // !namespace Math
} // !namespace nofx
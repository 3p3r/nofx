#include "nofx_ofRandomuf.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofRandomuf)
        {
        
			NanReturnValue(ofRandomuf());

        } // !nofx_ofRandomuf
    } // !namespace Math
} // !namespace nofx
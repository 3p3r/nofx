#include "nofx_ofRandomHeight.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofRandomHeight)
        {
        
			NanReturnValue(ofRandomHeight());

        } // !nofx_ofRandomHeight
    } // !namespace Math
} // !namespace nofx
#include "nofx_ofRandomf.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofRandomf)
        {
        
			NanReturnValue(ofRandomf());

        } // !nofx_ofRandomf
    } // !namespace Math
} // !namespace nofx
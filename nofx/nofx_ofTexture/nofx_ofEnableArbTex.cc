#include "nofx_ofEnableArbTex.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofEnableArbTex)
        {
        
            ofEnableArbTex();
        
            NanReturnUndefined();
        } // !nofx_ofEnableArbTex
    } // !namespace ClassWrappers
} // !namespace nofx
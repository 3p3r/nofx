#include "nofx_ofDisableArbTex.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofDisableArbTex)
        {
        
            ofDisableArbTex();
        
            NanReturnUndefined();
        } // !nofx_ofDisableArbTex
    } // !namespace ClassWrappers
} // !namespace nofx
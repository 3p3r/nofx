#include "nofx_ofEnableArbTex.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofEnableArbTex)
        {
        
            ofEnableArbTex();
        
            NanReturnUndefined();
        } // !nofx_ofEnableArbTex
    } // !namespace OfTexture
} // !namespace nofx
#include "nofx_ofDisableArbTex.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofDisableArbTex)
        {
        
            ofDisableArbTex();
        
            NanReturnUndefined();
        } // !nofx_ofDisableArbTex
    } // !namespace OfTexture
} // !namespace nofx
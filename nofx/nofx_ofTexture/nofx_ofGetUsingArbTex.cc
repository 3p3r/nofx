#include "nofx_ofGetUsingArbTex.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofGetUsingArbTex)
        {
			NanReturnValue(ofGetUsingArbTex());
        } // !nofx_ofGetUsingArbTex
    } // !namespace OfTexture
} // !namespace nofx
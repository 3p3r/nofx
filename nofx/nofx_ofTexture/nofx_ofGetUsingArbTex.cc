#include "nofx_ofGetUsingArbTex.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofGetUsingArbTex)
        {
			NanReturnValue(ofGetUsingArbTex());
        } // !nofx_ofGetUsingArbTex
    } // !namespace ClassWrappers
} // !namespace nofx
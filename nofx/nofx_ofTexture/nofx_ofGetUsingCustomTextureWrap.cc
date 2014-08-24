#include "nofx_ofGetUsingCustomTextureWrap.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofGetUsingCustomTextureWrap)
        {
			NanReturnValue(ofGetUsingCustomTextureWrap());
        } // !nofx_ofGetUsingCustomTextureWrap
    } // !namespace OfTexture
} // !namespace nofx
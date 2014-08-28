#include "nofx_ofGetUsingCustomTextureWrap.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofGetUsingCustomTextureWrap)
        {
			NanReturnValue(ofGetUsingCustomTextureWrap());
        } // !nofx_ofGetUsingCustomTextureWrap
    } // !namespace ClassWrappers
} // !namespace nofx
#include "nofx_ofGetUsingNormalizedTexCoords.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofGetUsingNormalizedTexCoords)
        {
			NanReturnValue(ofGetUsingNormalizedTexCoords());
        } // !nofx_ofGetUsingNormalizedTexCoords
    } // !namespace ClassWrappers
} // !namespace nofx
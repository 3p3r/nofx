#include "nofx_ofGetUsingNormalizedTexCoords.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofGetUsingNormalizedTexCoords)
        {
			NanReturnValue(ofGetUsingNormalizedTexCoords());
        } // !nofx_ofGetUsingNormalizedTexCoords
    } // !namespace OfTexture
} // !namespace nofx
#include "nofx_ofIsTextureEdgeHackEnabled.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofIsTextureEdgeHackEnabled)
        {
			NanReturnValue(ofIsTextureEdgeHackEnabled());
        } // !nofx_ofIsTextureEdgeHackEnabled
    } // !namespace OfTexture
} // !namespace nofx
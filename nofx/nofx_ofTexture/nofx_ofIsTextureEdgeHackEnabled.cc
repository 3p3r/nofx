#include "nofx_ofIsTextureEdgeHackEnabled.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofIsTextureEdgeHackEnabled)
        {
			NanReturnValue(ofIsTextureEdgeHackEnabled());
        } // !nofx_ofIsTextureEdgeHackEnabled
    } // !namespace ClassWrappers
} // !namespace nofx
#include "nofx_ofEnableTextureEdgeHack.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofEnableTextureEdgeHack)
        {
        
            ofEnableTextureEdgeHack();
        
            NanReturnUndefined();
        } // !nofx_ofEnableTextureEdgeHack
    } // !namespace OfTexture
} // !namespace nofx
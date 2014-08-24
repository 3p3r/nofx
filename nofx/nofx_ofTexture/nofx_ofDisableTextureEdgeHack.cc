#include "nofx_ofDisableTextureEdgeHack.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofDisableTextureEdgeHack)
        {
        
            ofDisableTextureEdgeHack();
        
            NanReturnUndefined();
        } // !nofx_ofDisableTextureEdgeHack
    } // !namespace OfTexture
} // !namespace nofx
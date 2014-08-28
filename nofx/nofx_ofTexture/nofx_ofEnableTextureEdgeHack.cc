#include "nofx_ofEnableTextureEdgeHack.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofEnableTextureEdgeHack)
        {
        
            ofEnableTextureEdgeHack();
        
            NanReturnUndefined();
        } // !nofx_ofEnableTextureEdgeHack
    } // !namespace ClassWrappers
} // !namespace nofx
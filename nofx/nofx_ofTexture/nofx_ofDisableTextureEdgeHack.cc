#include "nofx_ofDisableTextureEdgeHack.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofDisableTextureEdgeHack)
        {
        
            ofDisableTextureEdgeHack();
        
            NanReturnUndefined();
        } // !nofx_ofDisableTextureEdgeHack
    } // !namespace ClassWrappers
} // !namespace nofx
#include "nofx_ofRestoreTextureWrap.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofRestoreTextureWrap)
        {
        
            ofRestoreTextureWrap();
        
            NanReturnUndefined();
        } // !nofx_ofRestoreTextureWrap
    } // !namespace OfTexture
} // !namespace nofx
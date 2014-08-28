#include "nofx_ofRestoreTextureWrap.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofRestoreTextureWrap)
        {
        
            ofRestoreTextureWrap();
        
            NanReturnUndefined();
        } // !nofx_ofRestoreTextureWrap
    } // !namespace ClassWrappers
} // !namespace nofx
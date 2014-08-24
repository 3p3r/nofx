#include "nofx_ofRestoreMinMagFilters.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofRestoreMinMagFilters)
        {
        
            ofRestoreMinMagFilters();
        
            NanReturnUndefined();
        } // !nofx_ofRestoreMinMagFilters
    } // !namespace OfTexture
} // !namespace nofx
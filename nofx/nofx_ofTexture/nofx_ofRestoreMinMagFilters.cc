#include "nofx_ofRestoreMinMagFilters.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofRestoreMinMagFilters)
        {
        
            ofRestoreMinMagFilters();
        
            NanReturnUndefined();
        } // !nofx_ofRestoreMinMagFilters
    } // !namespace ClassWrappers
} // !namespace nofx
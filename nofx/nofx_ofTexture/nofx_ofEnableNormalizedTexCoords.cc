#include "nofx_ofEnableNormalizedTexCoords.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofEnableNormalizedTexCoords)
        {
        
            ofEnableNormalizedTexCoords();
        
            NanReturnUndefined();
        } // !nofx_ofEnableNormalizedTexCoords
    } // !namespace ClassWrappers
} // !namespace nofx
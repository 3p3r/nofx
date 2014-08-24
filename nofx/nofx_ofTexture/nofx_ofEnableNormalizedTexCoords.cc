#include "nofx_ofEnableNormalizedTexCoords.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofEnableNormalizedTexCoords)
        {
        
            ofEnableNormalizedTexCoords();
        
            NanReturnUndefined();
        } // !nofx_ofEnableNormalizedTexCoords
    } // !namespace OfTexture
} // !namespace nofx
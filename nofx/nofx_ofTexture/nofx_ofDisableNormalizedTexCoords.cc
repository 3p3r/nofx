#include "nofx_ofDisableNormalizedTexCoords.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofDisableNormalizedTexCoords)
        {
        
            ofDisableNormalizedTexCoords();
        
            NanReturnUndefined();
        } // !nofx_ofDisableNormalizedTexCoords
    } // !namespace OfTexture
} // !namespace nofx
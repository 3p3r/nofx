#include "nofx_ofDisableNormalizedTexCoords.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofDisableNormalizedTexCoords)
        {
        
            ofDisableNormalizedTexCoords();
        
            NanReturnUndefined();
        } // !nofx_ofDisableNormalizedTexCoords
    } // !namespace ClassWrappers
} // !namespace nofx
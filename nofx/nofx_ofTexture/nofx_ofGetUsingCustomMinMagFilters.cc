#include "nofx_ofGetUsingCustomMinMagFilters.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofGetUsingCustomMinMagFilters)
        {
			NanReturnValue(ofGetUsingCustomMinMagFilters());
        } // !nofx_ofGetUsingCustomMinMagFilters
    } // !namespace OfTexture
} // !namespace nofx
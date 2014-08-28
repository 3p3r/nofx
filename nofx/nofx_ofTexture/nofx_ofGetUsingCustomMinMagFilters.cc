#include "nofx_ofGetUsingCustomMinMagFilters.h"
#include "ofTexture.h"

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_ofGetUsingCustomMinMagFilters)
        {
			NanReturnValue(ofGetUsingCustomMinMagFilters());
        } // !nofx_ofGetUsingCustomMinMagFilters
    } // !namespace ClassWrappers
} // !namespace nofx
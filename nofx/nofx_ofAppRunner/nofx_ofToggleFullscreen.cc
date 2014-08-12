#include "nofx_ofToggleFullscreen.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofToggleFullscreen)
        {
        
            ofToggleFullscreen();
        
            NanReturnUndefined();
        } // !nofx_ofToggleFullscreen
    } // !namespace AppRunner
} // !namespace nofx
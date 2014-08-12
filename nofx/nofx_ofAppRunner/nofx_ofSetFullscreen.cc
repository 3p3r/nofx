#include "nofx_ofSetFullscreen.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofSetFullscreen)
        {
        
            ofSetFullscreen(args[0]->BooleanValue());
        
            NanReturnUndefined();
        } // !nofx_ofSetFullscreen
    } // !namespace AppRunner
} // !namespace nofx
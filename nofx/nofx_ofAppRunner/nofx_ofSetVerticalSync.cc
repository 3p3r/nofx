#include "nofx_ofSetVerticalSync.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofSetVerticalSync)
        {
        
            ofSetVerticalSync(args[0]->BooleanValue());
        
            NanReturnUndefined();
        } // !nofx_ofSetVerticalSync
    } // !namespace AppRunner
} // !namespace nofx
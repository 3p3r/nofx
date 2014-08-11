#include "nofx_ofDoesHWOrientation.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofDoesHWOrientation)
        {
        
            NanReturnValue(ofDoesHWOrientation());
        
        } // !nofx_ofDoesHWOrientation
    } // !namespace AppRunner
} // !namespace nofx
#include "nofx_ofSleepMillis.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofSleepMillis)
        {
        
            ofSleepMillis(args[0]->Int32Value());
        
            NanReturnUndefined();
        } // !nofx_ofSleepMillis
    } // !namespace AppRunner
} // !namespace nofx
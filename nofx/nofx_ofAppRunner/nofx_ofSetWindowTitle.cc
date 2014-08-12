#include "nofx_ofSetWindowTitle.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofSetWindowTitle)
        {
        
            ofSetWindowTitle(*NanUtf8String(args[0]));
        
            NanReturnUndefined();
        } // !nofx_ofSetWindowTitle
    } // !namespace AppRunner
} // !namespace nofx
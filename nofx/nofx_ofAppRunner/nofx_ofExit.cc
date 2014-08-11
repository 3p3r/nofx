#include "nofx_ofExit.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofExit)
        {
        
            ofExit(args[0]->IsUndefined() ? NULL : args[0]->Int32Value());
        
            NanReturnUndefined();
        } // !nofx_ofExit
    } // !namespace AppRunner
} // !namespace nofx
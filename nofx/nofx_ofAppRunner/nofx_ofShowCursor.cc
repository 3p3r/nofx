#include "nofx_ofShowCursor.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofShowCursor)
        {
        
            ofShowCursor();
        
            NanReturnUndefined();
        } // !nofx_ofShowCursor
    } // !namespace AppRunner
} // !namespace nofx
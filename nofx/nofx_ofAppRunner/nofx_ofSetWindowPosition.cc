#include "nofx_ofSetWindowPosition.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofSetWindowPosition)
        {
        
			ofSetWindowPosition(args[0]->Int32Value(), args[1]->Int32Value());
        
            NanReturnUndefined();
        } // !nofx_ofSetWindowPosition
    } // !namespace AppRunner
} // !namespace nofx
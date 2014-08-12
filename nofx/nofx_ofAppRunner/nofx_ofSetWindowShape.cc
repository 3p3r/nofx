#include "nofx_ofSetWindowShape.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofSetWindowShape)
        {
        
			ofSetWindowShape(args[0]->Int32Value(), args[1]->Int32Value());
        
            NanReturnUndefined();
        } // !nofx_ofSetWindowShape
    } // !namespace AppRunner
} // !namespace nofx
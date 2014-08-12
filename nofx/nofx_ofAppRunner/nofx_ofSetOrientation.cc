#include "nofx_ofSetOrientation.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofSetOrientation)
        {
        
            ofSetOrientation((ofOrientation) args[0]->Uint32Value());
        
            NanReturnUndefined();
        } // !nofx_ofSetOrientation
    } // !namespace AppRunner
} // !namespace nofx
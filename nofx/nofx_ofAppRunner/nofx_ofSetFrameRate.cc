#include "nofx_ofSetFrameRate.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofSetFrameRate)
        {
        
            ofSetFrameRate(args[0]->Uint32Value());
        
            NanReturnUndefined();
        } // !nofx_ofSetFrameRate
    } // !namespace AppRunner
} // !namespace nofx
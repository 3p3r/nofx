#include "nofx_ofGetFrameNum.h"
#include "ofAppRunner.h"

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_ofGetFrameNum)
        {
        
			NanReturnValue(ofGetFrameNum());

        } // !nofx_ofGetFrameNum
    } // !namespace AppRunner
} // !namespace nofx
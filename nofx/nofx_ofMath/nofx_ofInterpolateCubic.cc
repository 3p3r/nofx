#include "nofx_ofInterpolateCubic.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofInterpolateCubic)
        {
        
			NanReturnValue(ofInterpolateCubic(
				args[0]->NumberValue(),
				args[1]->NumberValue(),
				args[2]->NumberValue(),
				args[3]->NumberValue(),
				args[4]->NumberValue()));

        } // !nofx_ofInterpolateCubic
    } // !namespace Math
} // !namespace nofx
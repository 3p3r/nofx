#include "nofx_ofInterpolateCosine.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofInterpolateCosine)
        {
        
			NanReturnValue(ofInterpolateCosine(
				args[0]->NumberValue(),
				args[1]->NumberValue(),
				args[2]->NumberValue()));

        } // !nofx_ofInterpolateCosine
    } // !namespace Math
} // !namespace nofx
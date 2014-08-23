#include "nofx_ofWrapDegrees.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofWrapDegrees)
        {
        
			NanReturnValue(ofWrapDegrees(
				args[0]->NumberValue(),
				args[1]->IsUndefined() ? -180.0f : args[1]->NumberValue(),
				args[2]->IsUndefined() ? +180.0f : args[2]->NumberValue()));

        } // !nofx_ofWrapDegrees
    } // !namespace Math
} // !namespace nofx
#include "nofx_ofInterpolateHermite.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofInterpolateHermite)
        {
        
			if (args.Length() == 5)
			{
				NanReturnValue(ofInterpolateHermite(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue(),
					args[3]->NumberValue(),
					args[4]->NumberValue()));
			}
			else
			{
				NanReturnValue(ofInterpolateHermite(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue(),
					args[3]->NumberValue(),
					args[4]->NumberValue(),
					args[5]->NumberValue(),
					args[6]->NumberValue()));
			}

        } // !nofx_ofInterpolateHermite
    } // !namespace Math
} // !namespace nofx
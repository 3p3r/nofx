#include "nofx_ofInterpolateCatmullRom.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofInterpolateCatmullRom)
        {
        
			NanReturnValue(ofInterpolateCatmullRom(
				args[0]->NumberValue(),
				args[1]->NumberValue(),
				args[2]->NumberValue(),
				args[3]->NumberValue(),
				args[4]->NumberValue()));

        } // !nofx_ofInterpolateCatmullRom
    } // !namespace Math
} // !namespace nofx
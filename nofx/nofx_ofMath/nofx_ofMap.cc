#include "nofx_ofMap.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofMap)
        {
        
			bool clamp = args[6]->IsUndefined() ? false : args[args.Length() - 1]->BooleanValue();
			NanReturnValue( ofMap(
				args[0]->NumberValue(),
				args[1]->NumberValue(),
				args[2]->NumberValue(),
				args[3]->NumberValue(),
				args[4]->NumberValue(),
				clamp) );

        } // !nofx_ofMap
    } // !namespace Math
} // !namespace nofx
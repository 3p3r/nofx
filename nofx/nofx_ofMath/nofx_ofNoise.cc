#include "nofx_ofNoise.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofNoise)
        {
        
			float result = 0.0f;
			
			if (args.Length() == 1)
			{
				result = ofNoise(args[0]->NumberValue());
			}
			else if (args.Length() == 2)
			{
				result = ofNoise(args[0]->NumberValue(), args[1]->NumberValue());
			}
			else if (args.Length() == 3)
			{
				result = ofNoise(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
			}
			else
			{
				result = ofNoise(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
			}
			
			NanReturnValue(result);
        } // !nofx_ofNoise
    } // !namespace Math
} // !namespace nofx
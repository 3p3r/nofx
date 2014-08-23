#include "nofx_ofSignedNoise.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofSignedNoise)
        {
			float result = 0.0f;

			if (args.Length() == 1)
			{
				result = ofSignedNoise(args[0]->NumberValue());
			}
			else if (args.Length() == 2)
			{
				result = ofSignedNoise(args[0]->NumberValue(), args[1]->NumberValue());
			}
			else if (args.Length() == 3)
			{
				result = ofSignedNoise(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
			}
			else
			{
				result = ofSignedNoise(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
			}

			NanReturnValue(result);
        } // !nofx_ofSignedNoise
    } // !namespace Math
} // !namespace nofx
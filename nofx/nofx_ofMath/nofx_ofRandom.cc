#include "nofx_ofRandom.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofRandom)
        {
        
			float result = 0.0f;

			if (args.Length() == 1)
			{
				result = ofRandom(args[0]->NumberValue());
			}
			else
			{
				result = ofRandom(args[0]->NumberValue(), args[1]->NumberValue());
			}
			
			NanReturnValue(result);

        } // !nofx_ofRandom
    } // !namespace Math
} // !namespace nofx
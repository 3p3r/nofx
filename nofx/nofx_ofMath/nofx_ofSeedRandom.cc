#include "nofx_ofSeedRandom.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofSeedRandom)
        {
        
			if (args.Length() == 1)
			{
				ofSeedRandom(args[0]->Int32Value());
			}
			else
			{
				ofSeedRandom();
			}

        } // !nofx_ofSeedRandom
    } // !namespace Math
} // !namespace nofx
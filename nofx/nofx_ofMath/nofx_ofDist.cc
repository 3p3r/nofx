#include "nofx_ofDist.h"
#include "ofMath.h"

namespace nofx
{
	namespace Math
	{
		NAN_METHOD(nofx_ofDist)
		{
			NanReturnValue( ofDist(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue()) );
		} // !nofx_ofDist
	} // !namespace Math
} // !namespace nofx
#include "nofx_ofWrap.h"
#include "ofMath.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofWrap)
        {
        
			NanReturnValue( ofWrap(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()) );

        } // !nofx_ofWrap
    } // !namespace Math
} // !namespace nofx
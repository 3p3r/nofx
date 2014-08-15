#include "nofx_dependencies.h"

v8::Persistent<v8::Function> DEP_floatPtr;

namespace nofx
{
    namespace OfVec4f
    {
        NAN_METHOD(nofx_dependencies)
        {

			if (args.Length() != 1)
			{
				NanThrowTypeError("OfVec4f module has dependencies. Please pass the right dependencies first.");
			}
        
			NanAssignPersistent(DEP_floatPtr, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("floatPtr"))));
        
            NanReturnValue(args.This());
        } // !nofx_dependencies
    } // !namespace OfVec4f
} // !namespace nofx
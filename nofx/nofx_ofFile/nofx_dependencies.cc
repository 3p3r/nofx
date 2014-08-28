#include "nofx_dependencies.h"

v8::Persistent<v8::Function> DEP_ofBuffer;

namespace nofx
{
	namespace ClassWrappers
	{
		NAN_METHOD(nofx_dependencies)
		{

			if (args.Length() != 1)
			{
				NanThrowTypeError("ofFile module has dependencies. Please pass the right dependencies first.");
			}

			NanAssignPersistent(DEP_ofBuffer, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofBuffer"))));

			NanReturnValue(args.This());
		} // !nofx_dependencies
	} // !namespace ClassWrappers
} // !namespace nofx
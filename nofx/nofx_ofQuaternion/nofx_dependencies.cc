#include "nofx_dependencies.h"

v8::Persistent<v8::Function> DEP_ofVec3f;
v8::Persistent<v8::Function> DEP_ofVec4f;

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_dependencies)
        {

			if (args.Length() != 1)
			{
				NanThrowTypeError("ofAppRunner module has dependencies. Please pass the right dependencies first.");
			}
        
			NanAssignPersistent(DEP_ofVec3f, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofVec3f"))));
			NanAssignPersistent(DEP_ofVec4f, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofVec4f"))));
        
            NanReturnValue(args.This());
        } // !nofx_dependencies
    } // !namespace AppRunner
} // !namespace nofx
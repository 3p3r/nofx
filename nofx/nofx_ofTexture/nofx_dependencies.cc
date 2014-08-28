#include "nofx_dependencies.h"

v8::Persistent<v8::Function> DEP_ofVec3f;
v8::Persistent<v8::Function> DEP_ofTextureData;

namespace nofx
{
	namespace ClassWrappers
    {
        NAN_METHOD(nofx_dependencies)
        {

			if (args.Length() != 1)
			{
				NanThrowTypeError("OfTexture module has dependencies. Please pass the right dependencies first.");
			}
        
			NanAssignPersistent(DEP_ofVec3f, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofVec3f"))));        
			NanAssignPersistent(DEP_ofTextureData, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofTextureData"))));
        
            NanReturnValue(args.This());
        } // !nofx_dependencies
    } // !namespace AppRunner
} // !namespace nofx
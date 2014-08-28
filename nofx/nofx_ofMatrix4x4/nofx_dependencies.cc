#include "nofx_dependencies.h"

v8::Persistent<v8::Function> DEP_ofQuaternion;
v8::Persistent<v8::Function> DEP_ofVec4f;
v8::Persistent<v8::Function> DEP_ofVec3f;
v8::Persistent<v8::Function> DEP_floatPtr;

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_dependencies)
        {

			if (args.Length() != 1)
			{
				NanThrowTypeError("ofMatrix4x4 module has dependencies. Please pass the right dependencies first.");
			}
        
			NanAssignPersistent(DEP_ofQuaternion, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofQuaternion"))));        
			NanAssignPersistent(DEP_ofVec4f, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofVec4f"))));        
			NanAssignPersistent(DEP_ofVec3f, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofVec3f"))));        
			NanAssignPersistent(DEP_floatPtr, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("floatPtr"))));
        
            NanReturnValue(args.This());
        } // !nofx_dependencies
    } // !namespace ClassWrappers
} // !namespace nofx
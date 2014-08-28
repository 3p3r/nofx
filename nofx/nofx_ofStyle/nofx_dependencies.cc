#include "nofx_dependencies.h"

v8::Persistent<v8::Function> DEP_ofColor;

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_dependencies)
        {

			if (args.Length() != 1)
			{
				NanThrowTypeError("ofStyle module has dependencies. Please pass the right dependencies first.");
			}
        
			NanAssignPersistent(DEP_ofColor, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofColor"))));        
        
            NanReturnValue(args.This());
        } // !nofx_dependencies
    } // !namespace OfMatrix4x4
} // !namespace nofx
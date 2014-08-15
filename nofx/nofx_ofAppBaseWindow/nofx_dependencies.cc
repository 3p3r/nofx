#include "nofx_dependencies.h"

v8::Persistent<v8::Function> DEP_ofVec3f;

namespace nofx
{
    namespace OfAppBaseWindow
    {
        NAN_METHOD(nofx_dependencies)
        {

			if (args.Length() != 1)
			{
				NanThrowTypeError("ofAppBaseWindow module has dependencies. Please pass the right dependencies first.");
			}
        
			NanAssignPersistent(DEP_ofVec3f, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofVec3f"))));
        
            NanReturnValue(args.This());
        } // !nofx_dependencies
    } // !namespace OfAppBaseWindow
} // !namespace nofx
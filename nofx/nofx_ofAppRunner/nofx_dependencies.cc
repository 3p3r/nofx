#include "nofx_dependencies.h"

v8::Persistent<v8::Function> JsOfBaseApp;

namespace nofx
{
    namespace AppRunner
    {
        NAN_METHOD(nofx_dependencies)
        {

			if (args.Length() == 0 || !args[0]->IsObject())
			{
				NanThrowTypeError("ofAppRunner module has dependencies. Please pass the right dependencies first.");
			}
        
			NanAssignPersistent(JsOfBaseApp, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofApp"))));
        
            NanReturnValue(args.This());
        } // !nofx_dependencies
    } // !namespace AppRunner
} // !namespace nofx
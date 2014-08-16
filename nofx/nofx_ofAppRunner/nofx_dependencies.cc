#include "nofx_dependencies.h"

v8::Persistent<v8::Function> DEP_ofApp;
v8::Persistent<v8::Function> DEP_ofVec3f;
v8::Persistent<v8::Function> DEP_ofRectangle;
v8::Persistent<v8::Function> DEP_ofAppBaseWindow;

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
        
			NanAssignPersistent(DEP_ofApp, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofApp"))));
			NanAssignPersistent(DEP_ofAppBaseWindow, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofAppBaseWindow"))));
			NanAssignPersistent(DEP_ofVec3f, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofRectangle"))));
			NanAssignPersistent(DEP_ofVec3f, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofRectangle"))));
        
            NanReturnValue(args.This());
        } // !nofx_dependencies
    } // !namespace AppRunner
} // !namespace nofx
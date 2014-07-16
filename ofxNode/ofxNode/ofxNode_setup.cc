#include "ofxNode_setup.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_setup) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		if (args.Length() == 1 && args[0]->IsFunction())
		{
			args.This()->SetHiddenValue(NanNew<v8::String>("setup_"), v8::Local<v8::Function>::Cast(args[0]));
		}
		else
		{
			NanThrowTypeError("Bad argument passed to the setup method. Function expected.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_setup
} // !namespace ofxNode
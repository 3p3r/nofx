#include "ofxNode_exit.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_exit) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		if (args.Length() == 1 && args[0]->IsFunction())
		{
			args.This()->SetHiddenValue(NanNew<v8::String>("exit_"), v8::Local<v8::Function>::Cast(args[0]));
		}
		else
		{
			NanThrowTypeError("Bad argument passed to the exit method. Function expected.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_exit
} // !namespace ofxNode
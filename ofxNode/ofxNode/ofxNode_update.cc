#include "ofxNode_update.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_update) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		if (args.Length() == 1 && args[0]->IsFunction())
		{
			args.This()->SetHiddenValue(NanNew<v8::String>("update_"), v8::Local<v8::Function>::Cast(args[0]));
		}
		else
		{
			NanThrowTypeError("Bad argument passed to the update method. Function expected.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_update
} // !namespace ofxNode
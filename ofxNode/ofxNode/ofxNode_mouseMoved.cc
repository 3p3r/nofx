#include "ofxNode_mouseMoved.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_mouseMoved) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		if (args.Length() == 1 && args[0]->IsFunction())
		{
			args.This()->SetHiddenValue(NanNew<v8::String>("mouseMoved_"), v8::Local<v8::Function>::Cast(args[0]));
		}
		else
		{
			NanThrowTypeError("Bad argument passed to the mouseMoved method. Function expected.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_mouseMoved
} // !namespace ofxNode
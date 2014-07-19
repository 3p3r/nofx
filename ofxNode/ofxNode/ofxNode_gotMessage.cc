#include "ofxNode_gotMessage.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_gotMessage) {

		NanScope();
		
		if (args.Length() == 1 && args[0]->IsFunction())
		{
			args.This()->SetHiddenValue(NanNew<v8::String>("gotMessage_"), v8::Local<v8::Function>::Cast(args[0]));
		}
		else
		{
			NanThrowTypeError("Bad argument passed to the gotMessage method. Function expected.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_gotMessage
} // !namespace ofxNode
#include "ofxNode_dragEvent.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_dragEvent) {
		NanScope();
		
		if (args.Length() == 1 && args[0]->IsFunction())
		{
			args.This()->SetHiddenValue(NanNew<v8::String>("dragEvent_"), v8::Local<v8::Function>::Cast(args[0]));
		}
		else
		{
			NanThrowTypeError("Bad argument passed to the dragEvent method. Function expected.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_dragEvent
} // !namespace ofxNode
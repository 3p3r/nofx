#include "ofxNode_mouseDragged.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_mouseDragged) {
		NanScope();
		
		if (args.Length() == 1 && args[0]->IsFunction())
		{
			args.This()->SetHiddenValue(NanNew<v8::String>("mouseDragged_"), v8::Local<v8::Function>::Cast(args[0]));
		}
		else
		{
			NanThrowTypeError("Bad argument passed to the mouseDragged method. Function expected.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_mouseDragged
} // !namespace ofxNode
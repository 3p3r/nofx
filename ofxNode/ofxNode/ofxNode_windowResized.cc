#include "ofxNode_windowResized.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_windowResized) {
		NanScope();
		
		if (args.Length() == 1 && args[0]->IsFunction())
		{
			args.This()->SetHiddenValue(NanNew<v8::String>("windowResized_"), v8::Local<v8::Function>::Cast(args[0]));
		}
		else
		{
			NanThrowTypeError("Bad argument passed to the windowResized method. Function expected.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_windowResized
} // !namespace ofxNode
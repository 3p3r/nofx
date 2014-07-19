#include "ofxNode_keyPressed.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_keyPressed) {
		NanScope();
		
		if (args.Length() == 1 && args[0]->IsFunction())
		{
			args.This()->SetHiddenValue(NanNew<v8::String>("keyPressed_"), v8::Local<v8::Function>::Cast(args[0]));
		}
		else
		{
			NanThrowTypeError("Bad argument passed to the keyPressed method. Function expected.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_keyPressed
} // !namespace ofxNode
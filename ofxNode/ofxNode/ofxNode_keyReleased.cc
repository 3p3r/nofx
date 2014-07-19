#include "ofxNode_keyReleased.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_keyReleased) {
		NanScope();
		
		if (args.Length() == 1 && args[0]->IsFunction())
		{
			args.This()->SetHiddenValue(NanNew<v8::String>("keyReleased_"), v8::Local<v8::Function>::Cast(args[0]));
		}
		else
		{
			NanThrowTypeError("Bad argument passed to the keyReleased method. Function expected.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_keyReleased
} // !namespace ofxNode
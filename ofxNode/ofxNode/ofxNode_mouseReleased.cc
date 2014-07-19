#include "ofxNode_mouseReleased.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_mouseReleased) {
		NanScope();
		
		if (args.Length() == 1 && args[0]->IsFunction())
		{
			args.This()->SetHiddenValue(NanNew<v8::String>("mouseReleased_"), v8::Local<v8::Function>::Cast(args[0]));
		}
		else
		{
			NanThrowTypeError("Bad argument passed to the mouseReleased method. Function expected.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_mouseReleased
} // !namespace ofxNode
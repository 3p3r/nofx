#include "ofxNode_draw.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_draw) {
		NanScope();
		
		if (args.Length() == 1 && args[0]->IsFunction())
		{
			args.This()->SetHiddenValue(NanNew<v8::String>("draw_"), v8::Local<v8::Function>::Cast(args[0]));
		}
		else
		{
			NanThrowTypeError("Bad argument passed to the draw method. Function expected.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_draw
} // !namespace ofxNode
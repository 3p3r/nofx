#include "ofxNode_ofClear.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofClear) {
		NanScope();
		
		if (args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
		{
			ofClear(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofClear
} // !namespace ofxNode
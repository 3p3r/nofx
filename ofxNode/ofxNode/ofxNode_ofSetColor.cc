#include "ofxNode_ofSetColor.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofSetColor) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		if (args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
		{
			ofSetColor(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofSetColor
} // !namespace ofxNode
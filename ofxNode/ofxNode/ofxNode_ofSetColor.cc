#include "ofxNode_ofSetColor.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofSetColor) {
		NanScope();
		
		if (args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
		{
			ofSetColor(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		}
		else if (args.Length() == 4 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber() && args[3]->IsNumber())
		{
			ofSetColor(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofSetColor
} // !namespace ofxNode
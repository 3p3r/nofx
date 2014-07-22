#include "ofxNode_ofSetColor.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofColor.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofSetColor) {
		if (args.Length() == 1 && args[0]->IsObject())
		{
			ofSetColor(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 1)
		{
			ofSetColor(V8_ARG_NUMBER(args[0]));
		}
		else if (args.Length() == 2)
		{
			ofSetColor(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self(), V8_ARG_NUMBER(args[1]));
		}
		else if (args.Length() == 3)
		{
			ofSetColor(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		}
		else
		{
			ofSetColor(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		}
		NanReturnValue(args.This());
	} // !ofxNode_ofSetColor
} // !namespace ofxNode
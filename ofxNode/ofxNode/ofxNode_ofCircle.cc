#include "ofxNode_ofCircle.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofCircle) {
		NanScope();
		if (args.Length() == 2)
		{
			ofCircle(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(), V8_ARG_NUMBER(args[1]));
		}		
		else if (args.Length() == 3)
		{
			ofCircle(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		}
		else
		{
			ofCircle(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		}
		NanReturnValue(args.This());
	} // !ofxNode_ofCircle
} // !namespace ofxNode
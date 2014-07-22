#include "ofxNode_ofCurveVertex.h"
#include "ofGraphics.h"
#include "ofTypes.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofCurveVertex) {
		if (args.Length() == 1)
		{
			ofCurveVertex(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 2)
		{
			ofCurveVertex(args[0]->NumberValue(), args[1]->NumberValue());
		}
		else
		{
			ofCurveVertex(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		}
		NanReturnValue(args.This());
	} // !ofxNode_ofCurveVertex
} // !namespace ofxNode
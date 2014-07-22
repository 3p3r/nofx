#include "ofxNode_ofDrawBitmapString.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDrawBitmapString) {
		const auto textString = NanCString(args[0], nullptr);
		if (args.Length() == 2)
		{
			ofDrawBitmapString(textString, node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self());
		}
		else if (args.Length() == 3)
		{
			ofDrawBitmapString(textString, args[1]->NumberValue(), args[2]->NumberValue());
		}
		else
		{
			ofDrawBitmapString(textString, args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		}
		NanReturnValue(args.This());
	} // !ofxNode_ofDrawBitmapString
} // !namespace ofxNode
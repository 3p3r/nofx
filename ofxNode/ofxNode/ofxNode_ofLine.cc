#include "ofxNode_ofLine.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofLine) {
		if (args.Length() == 2)
		{
			const auto p1 = node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self();
			const auto p2 = node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self();
			ofLine(p1, p2);
		}
		else if (args.Length() == 4)
		{
			ofLine(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3])
				);
		}
		else
		{
			ofLine(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3]),
				V8_ARG_NUMBER(args[4]),
				V8_ARG_NUMBER(args[5])
				);
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofLine
} // !namespace ofxNode

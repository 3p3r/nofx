#include "ofxNode_ofTriangle.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofTriangle) {
		if (args.Length() == 3)
		{
			ofTriangle(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self(),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[2]->ToObject())->self()
				);
		}
		else if (args.Length() == 6)
		{
			ofTriangle(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3]),
				V8_ARG_NUMBER(args[4]),
				V8_ARG_NUMBER(args[5])
				);
		}
		else
		{
			ofTriangle(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3]),
				V8_ARG_NUMBER(args[4]),
				V8_ARG_NUMBER(args[5]),
				V8_ARG_NUMBER(args[6]),
				V8_ARG_NUMBER(args[7]),
				V8_ARG_NUMBER(args[8])
				);
		}

        NanReturnValue(args.This());
    } // !{ofxNode_ofTriangle}
} // !namespace ofxNode
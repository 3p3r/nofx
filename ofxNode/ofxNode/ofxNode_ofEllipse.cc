#include "ofxNode_ofEllipse.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEllipse) {
		if (args.Length() == 3)
		{
			ofEllipse(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				V8_ARG_NUMBER(args[1]), 
				V8_ARG_NUMBER(args[2]));
		}
		else if (args.Length() == 4)
		{
			ofEllipse(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]), V8_ARG_NUMBER(args[3]));
		}
		else
		{
			ofEllipse(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]), V8_ARG_NUMBER(args[3]), V8_ARG_NUMBER(args[4]));
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofEllipse
} // !namespace ofxNode
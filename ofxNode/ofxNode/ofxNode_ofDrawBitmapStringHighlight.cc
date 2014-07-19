#include "ofxNode_ofDrawBitmapStringHighlight.h"
#include "ofGraphics.h"
#include "ofPoint.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDrawBitmapStringHighlight) {
		NanScope();
		
		//TODO(sepehr) implement all the methods overloads of ofDrawBitmapStringHighlight
		if (args.Length() == 4 &&
			IS_V8_ARG_STRING(args[0]) &&
			IS_V8_ARG_2D_OF_POS(args[1]) &&
			IS_V8_ARG_OF_COLOR(args[2]) &&
			IS_V8_ARG_OF_COLOR(args[3]))
		{
			ofDrawBitmapStringHighlight(V8_ARG_STRING(args[0]) ,
				ofPoint(V8_POS_X(args[1]), V8_POS_Y(args[1]), V8_POS_Z(args[1])), 
				ofColor(V8_COLOR_R(args[2]), V8_COLOR_G(args[2]), V8_COLOR_B(args[2]), V8_COLOR_A(args[2])), 
				ofColor(V8_COLOR_R(args[3]), V8_COLOR_G(args[3]), V8_COLOR_B(args[3]), V8_COLOR_A(args[3])));
		}
		else if (args.Length() == 5 &&
			IS_V8_ARG_STRING(args[0]) &&
			IS_V8_ARG_NUMBER(args[1]) &&
			IS_V8_ARG_NUMBER(args[2]) &&
			IS_V8_ARG_OF_COLOR(args[3]) &&
			IS_V8_ARG_OF_COLOR(args[4]))
		{
			ofDrawBitmapStringHighlight(V8_ARG_STRING(args[0]) ,
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				ofColor(V8_COLOR_R(args[3]), V8_COLOR_G(args[3]), V8_COLOR_B(args[3]), V8_COLOR_A(args[3])), 
				ofColor(V8_COLOR_R(args[4]), V8_COLOR_G(args[4]), V8_COLOR_B(args[4]), V8_COLOR_A(args[4])));
		}
		else
		{
			NanThrowError("wrong arguments passed to ofDrawBitmapStringHighlight.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofDrawBitmapStringHighlight
} // !namespace ofxNode
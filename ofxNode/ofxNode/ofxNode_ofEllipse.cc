#include "ofxNode_ofEllipse.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEllipse) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		if (args.Length() == 3 &&
			IS_V8_ARG_2D_OF_POS(args[0]) &&
			IS_V8_ARG_NUMBER(args[1]) &&
			IS_V8_ARG_NUMBER(args[2]))
		{
			ofEllipse(ofPoint(V8_POS_X(args[0]), V8_POS_X(args[1]), V8_POS_X(args[2])) ,
				V8_ARG_NUMBER(args[1]), 
				V8_ARG_NUMBER(args[2]));
		}
		else if (args.Length() == 4 &&
			IS_V8_ARG_NUMBER(args[0]) &&
			IS_V8_ARG_NUMBER(args[1]) &&
			IS_V8_ARG_NUMBER(args[2]) &&
			IS_V8_ARG_NUMBER(args[3]))
		{
			ofEllipse(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]), V8_ARG_NUMBER(args[3]));
		}
		else if (args.Length() == 5 &&
			IS_V8_ARG_NUMBER(args[0]) &&
			IS_V8_ARG_NUMBER(args[1]) &&
			IS_V8_ARG_NUMBER(args[2]) &&
			IS_V8_ARG_NUMBER(args[3]) &&
			IS_V8_ARG_NUMBER(args[4]))
		{
			ofEllipse(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]), V8_ARG_NUMBER(args[3]), V8_ARG_NUMBER(args[4]));
		}
		else
		{
			NanThrowError("bad arguments passed to ofEllipse.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofEllipse
} // !namespace ofxNode
#include "ofxNode_ofRectRounded.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofRectangle.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofRectRounded) {
        const auto lArgc = args.Length();
		if (lArgc == 2)
        {
			ofRectRounded(node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self(), V8_ARG_NUMBER(args[1]));
        }
		else if (lArgc == 4)
		{
			ofRectRounded(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(), 
				V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]), V8_ARG_NUMBER(args[3]));
		}
		else if (lArgc == 5 && args[0]->IsObject())
		{
			ofRectRounded(node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self(),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3]),
				V8_ARG_NUMBER(args[4]));
		}
		else if (lArgc == 5)
		{
			ofRectRounded(V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3]),
				V8_ARG_NUMBER(args[4]));
		}
		else if (lArgc == 7)
		{
			ofRectRounded(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3]),
				V8_ARG_NUMBER(args[4]),
				V8_ARG_NUMBER(args[5]),
				V8_ARG_NUMBER(args[6]));
		}
		else
		{
			ofRectRounded(V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3]),
				V8_ARG_NUMBER(args[4]),
				V8_ARG_NUMBER(args[5]),
				V8_ARG_NUMBER(args[6]),
				V8_ARG_NUMBER(args[7]),
				V8_ARG_NUMBER(args[8]));
		}

        NanReturnValue(args.This());
    } // !{ofxNode_ofRectRounded}
} // !namespace ofxNode
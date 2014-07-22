#include "ofxNode_ofVertex.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofVertex) {
        if (args.Length() == 1)
        {
			ofVertex(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
        }
		else if (args.Length() == 2)
		{
			ofVertex(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]));
		}
		else
		{
			ofVertex(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]));
		}

        NanReturnValue(args.This());
    } // !{ofxNode_ofVertex}
} // !namespace ofxNode
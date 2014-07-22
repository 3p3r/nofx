#include "ofxNode_ofRotate.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofRotate) {
        if (args.Length() == 1)
        {
			ofRotate(V8_ARG_NUMBER(args[0]));
        }
		else
		{
			ofRotate(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3])
				);
		}

        NanReturnValue(args.This());
    } // !{ofxNode_ofRotate}
} // !namespace ofxNode
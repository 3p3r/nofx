#include "ofxNode_ofRotateY.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofRotateY) {
        NanScope();

        ofRotateY(V8_ARG_NUMBER(args[0]));

        NanReturnValue(args.This());
    } // !{ofxNode_ofRotateY}
} // !namespace ofxNode
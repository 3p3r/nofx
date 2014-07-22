#include "ofxNode_ofRotateX.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofRotateX) {
        ofRotateX(V8_ARG_NUMBER(args[0]));
        NanReturnValue(args.This());
    } // !{ofxNode_ofRotateX}
} // !namespace ofxNode
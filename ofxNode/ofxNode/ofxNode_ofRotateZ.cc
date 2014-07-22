#include "ofxNode_ofRotateZ.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofRotateZ) {
        ofRotateZ(V8_ARG_NUMBER(args[0]));
        NanReturnValue(args.This());
    } // !{ofxNode_ofRotateZ}
} // !namespace ofxNode
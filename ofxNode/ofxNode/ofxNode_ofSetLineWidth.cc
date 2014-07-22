#include "ofxNode_ofSetLineWidth.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetLineWidth) {
        NanScope();

        ofSetLineWidth(V8_ARG_NUMBER(args[0]));

        NanReturnValue(args.This());
    } // !{ofxNode_ofSetLineWidth}
} // !namespace ofxNode
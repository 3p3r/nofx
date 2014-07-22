#include "ofxNode_ofSetCurveResolution.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetCurveResolution) {
        NanScope();

        ofSetCurveResolution(V8_ARG_NUMBER(args[0]));

        NanReturnValue(args.This());
    } // !{ofxNode_ofSetCurveResolution}
} // !namespace ofxNode
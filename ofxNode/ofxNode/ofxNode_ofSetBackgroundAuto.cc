#include "ofxNode_ofSetBackgroundAuto.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetBackgroundAuto) {
        ofSetBackgroundAuto(args[0]->BooleanValue());
        NanReturnValue(args.This());
    } // !{ofxNode_ofSetBackgroundAuto}
} // !namespace ofxNode
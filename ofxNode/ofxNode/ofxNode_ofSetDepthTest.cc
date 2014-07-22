#include "ofxNode_ofSetDepthTest.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetDepthTest) {
        NanScope();

        ofSetDepthTest(args[0]->BooleanValue());

        NanReturnValue(args.This());
    } // !{ofxNode_ofSetDepthTest}
} // !namespace ofxNode
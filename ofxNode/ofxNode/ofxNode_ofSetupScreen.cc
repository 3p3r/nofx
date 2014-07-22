#include "ofxNode_ofSetupScreen.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetupScreen) {
        NanScope();

        ofSetupScreen();

        NanReturnValue(args.This());
    } // !{ofxNode_ofSetupScreen}
} // !namespace ofxNode
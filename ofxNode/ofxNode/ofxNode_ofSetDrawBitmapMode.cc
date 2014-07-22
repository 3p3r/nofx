#include "ofxNode_ofSetDrawBitmapMode.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetDrawBitmapMode) {
        ofSetDrawBitmapMode((ofDrawBitmapMode)args[0]->Uint32Value());
        NanReturnValue(args.This());
    } // !{ofxNode_ofSetDrawBitmapMode}
} // !namespace ofxNode
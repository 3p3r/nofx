#include "ofxNode_ofSetRectMode.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetRectMode) {
        NanScope();

        ofSetRectMode((ofRectMode)args[0]->Uint32Value());

        NanReturnValue(args.This());
    } // !{ofxNode_ofSetRectMode}
} // !namespace ofxNode
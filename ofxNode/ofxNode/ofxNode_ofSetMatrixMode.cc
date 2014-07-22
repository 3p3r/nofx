#include "ofxNode_ofSetMatrixMode.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetMatrixMode) {
        ofSetMatrixMode((ofMatrixMode)args[0]->Uint32Value());
        NanReturnValue(args.This());
    } // !{ofxNode_ofSetMatrixMode}
} // !namespace ofxNode
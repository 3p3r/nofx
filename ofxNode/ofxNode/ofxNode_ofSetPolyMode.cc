#include "ofxNode_ofSetPolyMode.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetPolyMode) {
        ofSetPolyMode((ofPolyWindingMode)args[0]->Uint32Value());
        NanReturnValue(args.This());
    } // !{ofxNode_ofSetPolyMode}
} // !namespace ofxNode
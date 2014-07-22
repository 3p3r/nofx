#include "ofxNode_ofSetCoordHandedness.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetCoordHandedness) {
        ofSetCoordHandedness((ofHandednessType)args[0]->Uint32Value());
        NanReturnValue(args.This());
    } // !{ofxNode_ofSetCoordHandedness}
} // !namespace ofxNode
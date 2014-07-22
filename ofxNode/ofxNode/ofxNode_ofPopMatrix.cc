#include "ofxNode_ofPopMatrix.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofPopMatrix) {
        ofPopMatrix();
        NanReturnValue(args.This());
    } // !{ofxNode_ofPopMatrix}
} // !namespace ofxNode
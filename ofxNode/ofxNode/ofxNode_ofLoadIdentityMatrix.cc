#include "ofxNode_ofLoadIdentityMatrix.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofLoadIdentityMatrix) {
        NanScope();

        ofLoadIdentityMatrix();

        NanReturnValue(args.This());
    } // !{ofxNode_ofLoadIdentityMatrix}
} // !namespace ofxNode
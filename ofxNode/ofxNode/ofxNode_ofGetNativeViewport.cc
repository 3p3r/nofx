#include "ofxNode_ofGetNativeViewport.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofGetNativeViewport) {
        NanScope();

        //Insert code here

        NanReturnValue(args.This());
    } // !{ofxNode_ofGetNativeViewport}
} // !namespace ofxNode
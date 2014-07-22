#include "ofxNode_ofPushStyle.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofPushStyle) {
        NanScope();

        ofPushStyle();

        NanReturnValue(args.This());
    } // !{ofxNode_ofPushStyle}
} // !namespace ofxNode
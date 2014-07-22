#include "ofxNode_ofPopStyle.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofPopStyle) {
        NanScope();

        ofPopStyle();

        NanReturnValue(args.This());
    } // !{ofxNode_ofPopStyle}
} // !namespace ofxNode
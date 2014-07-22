#include "ofxNode_ofPushView.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofPushView) {
        NanScope();

        ofPushView();

        NanReturnValue(args.This());
    } // !{ofxNode_ofPushView}
} // !namespace ofxNode
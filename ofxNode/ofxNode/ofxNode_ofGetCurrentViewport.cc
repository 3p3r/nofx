#include "ofxNode_ofGetCurrentViewport.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofRectangle.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofGetCurrentViewport) {
        auto lRect = NanNew(ofxNode_ofRectangle::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(lRect)->self() = ofGetCurrentViewport();
        NanReturnValue(lRect);
    } // !{ofxNode_ofGetCurrentViewport}
} // !namespace ofxNode
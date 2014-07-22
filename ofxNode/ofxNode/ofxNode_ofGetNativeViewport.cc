#include "ofxNode_ofGetNativeViewport.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofRectangle.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofGetNativeViewport) {
		auto lRect = NanNew(ofxNode_ofRectangle::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(lRect)->self() = ofGetNativeViewport();
		NanReturnValue(lRect);
    } // !{ofxNode_ofGetNativeViewport}
} // !namespace ofxNode
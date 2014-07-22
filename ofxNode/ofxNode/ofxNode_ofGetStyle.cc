#include "ofxNode_ofGetStyle.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofStyle.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofGetStyle) {
        auto lStyle = NanNew(ofxNode_ofStyle::factory())->CallAsConstructor(0, nullptr);
		node::ObjectWrap::Unwrap<ofxNode_ofStyle>(lStyle->ToObject())->self() = ofGetStyle();
        NanReturnValue(lStyle);
    } // !{ofxNode_ofGetStyle}
} // !namespace ofxNode
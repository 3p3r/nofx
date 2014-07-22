#include "ofxNode_ofGetBackground.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofColor.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofGetBackground) {
		auto lOfColor = NanNew(ofxNode_ofColor::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lOfColor)->self() = ofGetBackground();
		NanReturnValue(lOfColor);
	} // !ofxNode_ofGetBackground
} // !namespace ofxNode
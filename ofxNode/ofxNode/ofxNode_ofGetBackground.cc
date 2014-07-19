#include "ofxNode_ofGetBackground.h"
#include "ofGraphics.h"
#include "ofTypes.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofGetBackground) {
		NanScope();
		
		const auto lOfColor = ofGetBackground();
		auto lColor = NanNew<v8::Object>();
		lColor->Set(NanNew("r"), NanNew(lOfColor.r));
		lColor->Set(NanNew("g"), NanNew(lOfColor.g));
		lColor->Set(NanNew("b"), NanNew(lOfColor.b));
		lColor->Set(NanNew("a"), NanNew(lOfColor.a));

		NanReturnValue(lColor);
	} // !ofxNode_ofGetBackground
} // !namespace ofxNode
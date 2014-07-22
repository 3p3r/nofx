#include "ofxNode_ofDrawBitmapStringHighlight.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofVec3f.h"
#include "ofxNode_wrapper_ofColor.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDrawBitmapStringHighlight) {
		const auto textString = NanCString(args[0], nullptr);
		if (args[1]->IsObject())
		{
			const auto bg = args[2]->IsUndefined() ? ofColor::black : node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[2]->ToObject())->self();
			const auto fg = args[3]->IsUndefined() ? ofColor::black : node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[3]->ToObject())->self();
			ofDrawBitmapStringHighlight(textString,
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self(),
				bg, fg);
		}
		else
		{
			const auto bg = args[3]->IsUndefined() ? ofColor::black : node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[3]->ToObject())->self();
			const auto fg = args[4]->IsUndefined() ? ofColor::black : node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[4]->ToObject())->self();
			ofDrawBitmapStringHighlight(textString,
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				bg, fg);
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofDrawBitmapStringHighlight
} // !namespace ofxNode
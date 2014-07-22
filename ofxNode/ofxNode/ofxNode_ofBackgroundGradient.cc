#include "ofxNode_ofBackgroundGradient.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofColor.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBackgroundGradient) {
		const ofGradientMode mode = args[2]->IsUndefined() ? OF_GRADIENT_CIRCULAR : (ofGradientMode)args[2]->Uint32Value();
		ofBackgroundGradient(
			node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[1]->ToObject())->self(),
			mode
			);
		NanReturnValue(args.This());
	} // !ofxNode_ofBackgroundGradient
} // !namespace ofxNode
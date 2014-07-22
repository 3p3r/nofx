#include "ofxNode_ofViewport.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofRectangle.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofViewport) {
		if (args.Length() == 1)
		{
			ofViewport(node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self());
		}
		else
		{
			const auto x = args[0]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[0]);
			const auto y = args[1]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[1]);
			const auto w = args[2]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[2]);
			const auto h = args[3]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[3]);
			const auto vFlip = args[4]->IsUndefined() ? 0 : args[4]->BooleanValue();
			ofViewport(x,y,w,h,vFlip);
		}

		NanReturnValue(args.This());
	} // !{ofxNode_ofViewport}
} // !namespace ofxNode
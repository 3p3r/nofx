#include "ofxNode_ofClear.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofColor.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofClear) {
		if (args.Length() >= 3)
		{
			const auto alpha = args[3]->IsUndefined() ? ofColor::limit() : args[3]->Uint32Value();
			ofClear(
				args[0]->Uint32Value(),
				args[1]->Uint32Value(),
				args[2]->Uint32Value(),
				alpha);
		}
		else if (args[0]->IsObject())
		{
			ofClear(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self());
		}
		else
		{
			const auto alpha = args[1]->IsUndefined() ? ofColor::limit() : args[1]->Uint32Value();
			ofClear(args[0]->Uint32Value(), alpha);
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofClear
} // !namespace ofxNode
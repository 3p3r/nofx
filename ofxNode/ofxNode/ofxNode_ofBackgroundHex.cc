#include "ofxNode_ofBackgroundHex.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBackgroundHex) {
		const auto alpha = args[1]->IsUndefined() ? ofColor::limit() : args[1]->Uint32Value();
		ofBackgroundHex(args[0]->Uint32Value(), alpha);
		NanReturnValue(args.This());
	} // !ofxNode_ofBackgroundHex
} // !namespace ofxNode
#include "ofxNode_ofDisableBlendMode.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDisableBlendMode) {
		ofDisableBlendMode();
		NanReturnValue(args.This());
	} // !ofxNode_ofDisableBlendMode
} // !namespace ofxNode
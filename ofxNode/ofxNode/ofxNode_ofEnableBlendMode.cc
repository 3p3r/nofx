#include "ofxNode_ofEnableBlendMode.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEnableBlendMode) {
		ofEnableBlendMode((ofBlendMode) args[0]->Int32Value());
		NanReturnValue(args.This());
	} // !ofxNode_ofEnableBlendMode
} // !namespace ofxNode
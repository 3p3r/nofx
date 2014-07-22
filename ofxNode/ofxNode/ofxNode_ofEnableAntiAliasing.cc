#include "ofxNode_ofEnableAntiAliasing.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEnableAntiAliasing) {
		ofEnableAntiAliasing();
		NanReturnValue(args.This());
	} // !ofxNode_ofEnableAntiAliasing
} // !namespace ofxNode
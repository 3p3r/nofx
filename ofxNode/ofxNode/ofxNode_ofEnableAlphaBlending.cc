#include "ofxNode_ofEnableAlphaBlending.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEnableAlphaBlending) {
		ofEnableAlphaBlending();
		NanReturnValue(args.This());
	} // !ofxNode_ofEnableAlphaBlending
} // !namespace ofxNode
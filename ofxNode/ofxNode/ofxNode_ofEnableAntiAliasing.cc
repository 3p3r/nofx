#include "ofxNode_ofEnableAntiAliasing.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEnableAntiAliasing) {
		NanScope();
		
		ofEnableAntiAliasing();

		NanReturnValue(args.This());
	} // !ofxNode_ofEnableAntiAliasing
} // !namespace ofxNode
#include "ofxNode_ofDisableDepthTest.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDisableDepthTest) {
		ofDisableDepthTest();
		NanReturnValue(args.This());
	} // !ofxNode_ofDisableDepthTest
} // !namespace ofxNode
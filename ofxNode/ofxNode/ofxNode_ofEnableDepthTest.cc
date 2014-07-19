#include "ofxNode_ofEnableDepthTest.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEnableDepthTest) {
		NanScope();
		
		ofEnableDepthTest();

		NanReturnValue(args.This());
	} // !ofxNode_ofEnableDepthTest
} // !namespace ofxNode
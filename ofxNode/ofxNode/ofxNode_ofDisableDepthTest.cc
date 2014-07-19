#include "ofxNode_ofDisableDepthTest.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDisableDepthTest) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		ofDisableDepthTest();

		NanReturnValue(args.This());
	} // !ofxNode_ofDisableDepthTest
} // !namespace ofxNode
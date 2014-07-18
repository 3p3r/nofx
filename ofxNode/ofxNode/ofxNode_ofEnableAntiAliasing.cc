#include "ofxNode_ofEnableAntiAliasing.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEnableAntiAliasing) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		ofEnableAntiAliasing();

		NanReturnValue(args.This());
	} // !ofxNode_ofEnableAntiAliasing
} // !namespace ofxNode
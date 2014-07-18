#include "ofxNode_ofDisableBlendMode.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDisableBlendMode) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		ofDisableBlendMode();

		NanReturnValue(args.This());
	} // !ofxNode_ofDisableBlendMode
} // !namespace ofxNode
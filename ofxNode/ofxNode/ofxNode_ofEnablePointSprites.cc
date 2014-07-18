#include "ofxNode_ofEnablePointSprites.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEnablePointSprites) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		ofEnablePointSprites();

		NanReturnValue(args.This());
	} // !ofxNode_ofEnablePointSprites
} // !namespace ofxNode
#include "ofxNode_ofDisablePointSprites.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDisablePointSprites) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		ofDisablePointSprites();

		NanReturnValue(args.This());
	} // !ofxNode_ofDisablePointSprites
} // !namespace ofxNode
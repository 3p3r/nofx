#include "ofxNode_ofBeginShape.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBeginShape) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		ofBeginShape();

		NanReturnValue(args.This());
	} // !ofxNode_ofBeginShape
} // !namespace ofxNode
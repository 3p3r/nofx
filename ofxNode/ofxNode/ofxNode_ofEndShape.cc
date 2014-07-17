#include "ofxNode_ofEndShape.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEndShape) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		ofEndShape();

		NanReturnValue(args.This());
	} // !ofxNode_ofEndShape
} // !namespace ofxNode
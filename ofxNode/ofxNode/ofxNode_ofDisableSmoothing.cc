#include "ofxNode_ofDisableSmoothing.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDisableSmoothing) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		ofDisableSmoothing();

		NanReturnValue(args.This());
	} // !ofxNode_ofDisableSmoothing
} // !namespace ofxNode
#include "ofxNode_ofClearAlpha.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofClearAlpha) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		ofClearAlpha();

		NanReturnValue(args.This());
	} // !ofxNode_ofClearAlpha
} // !namespace ofxNode
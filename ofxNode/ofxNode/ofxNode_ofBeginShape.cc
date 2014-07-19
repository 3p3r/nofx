#include "ofxNode_ofBeginShape.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBeginShape) {
		NanScope();
		
		ofBeginShape();

		NanReturnValue(args.This());
	} // !ofxNode_ofBeginShape
} // !namespace ofxNode
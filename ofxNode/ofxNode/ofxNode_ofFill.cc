#include "ofxNode_ofFill.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofFill) {
		ofFill();
		NanReturnValue(args.This());
	} // !ofxNode_ofFill
} // !namespace ofxNode
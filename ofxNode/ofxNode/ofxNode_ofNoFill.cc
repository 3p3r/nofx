#include "ofxNode_ofNoFill.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofNoFill) {
		NanScope();

		ofNoFill();

		NanReturnValue(args.This());
	} // !ofxNode_ofNoFill
} // !namespace ofxNode

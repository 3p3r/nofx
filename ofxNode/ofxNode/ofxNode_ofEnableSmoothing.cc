#include "ofxNode_ofEnableSmoothing.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEnableSmoothing) {
		ofEnableSmoothing();
		NanReturnValue(args.This());
	} // !ofxNode_ofEnableSmoothing
} // !namespace ofxNode
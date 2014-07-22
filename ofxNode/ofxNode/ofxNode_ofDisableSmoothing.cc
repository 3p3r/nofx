#include "ofxNode_ofDisableSmoothing.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDisableSmoothing) {
		ofDisableSmoothing();
		NanReturnValue(args.This());
	} // !ofxNode_ofDisableSmoothing
} // !namespace ofxNode
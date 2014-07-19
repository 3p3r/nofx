#include "ofxNode_ofSetCircleResolution.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofSetCircleResolution) {
		NanScope();

		ofSetCircleResolution(args[0]->NumberValue());

		NanReturnValue(args.This());
	} // !ofxNode_ofSetCircleResolution
} // !namespace ofxNode

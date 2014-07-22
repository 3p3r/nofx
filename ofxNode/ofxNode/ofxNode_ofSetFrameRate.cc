#include "ofxNode_ofSetFrameRate.h"
#include "ofAppRunner.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofSetFrameRate) {
		ofSetFrameRate(args[0]->NumberValue());
		NanReturnValue(args.This());
	} // !ofxNode_ofSetFrameRate
} // !namespace ofxNode

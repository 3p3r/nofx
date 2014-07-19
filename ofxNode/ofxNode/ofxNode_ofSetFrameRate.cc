#include "ofxNode_ofSetFrameRate.h"
#include "ofAppRunner.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofSetFrameRate) {
		NanScope();

		if (args.Length() == 1)
		{
			ofSetFrameRate(args[0]->NumberValue());
		}
		else
		{
			NanThrowError("bad args passed to ofSetFrameRate.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofSetFrameRate
} // !namespace ofxNode

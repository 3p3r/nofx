#include "ofxNode_ofSetWindowTitle.h"
#include "ofAppRunner.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofSetWindowTitle) {
		ofSetWindowTitle(NanCString(args[0], nullptr));
		NanReturnValue(args.This());
	} // !ofxNode_ofSetWindowTitle
} // !namespace ofxNode

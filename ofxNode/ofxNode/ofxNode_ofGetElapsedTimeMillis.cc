#include "ofxNode_ofGetElapsedTimeMillis.h"
#include "ofUtils.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofGetElapsedTimeMillis) {
		NanScope();
		NanReturnValue((double)ofGetElapsedTimeMillis());
	} // !ofxNode_ofGetElapsedTimeMillis
} // !namespace ofxNode
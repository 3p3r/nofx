#include "ofxNode_ofGetElapsedTimeMillis.h"
#include "ofUtils.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofGetElapsedTimeMillis) {
		NanReturnValue((double)ofGetElapsedTimeMillis());
	} // !ofxNode_ofGetElapsedTimeMillis
} // !namespace ofxNode
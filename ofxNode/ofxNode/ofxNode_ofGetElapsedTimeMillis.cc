#include "ofxNode_ofGetElapsedTimeMillis.h"
#include "ofUtils.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofGetElapsedTimeMillis) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		NanReturnValue((double)ofGetElapsedTimeMillis());
	} // !ofxNode_ofGetElapsedTimeMillis
} // !namespace ofxNode
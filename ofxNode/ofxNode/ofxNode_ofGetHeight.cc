#include "ofxNode_ofGetHeight.h"
#include "ofMain.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofGetHeight) {
		NanReturnValue(NanNew(ofGetHeight()));
	} // !ofxNode_ofGetHeight
} // !namespace ofxNode
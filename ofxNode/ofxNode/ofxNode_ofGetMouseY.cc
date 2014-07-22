#include "ofxNode_ofGetMouseY.h"
#include "ofMain.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofGetMouseY) {
		NanReturnValue(NanNew(ofGetMouseY()));
	} // !ofxNode_ofGetMouseY
} // !namespace ofxNode
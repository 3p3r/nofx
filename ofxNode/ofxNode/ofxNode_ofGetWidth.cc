#include "ofxNode_ofGetWidth.h"
#include "ofMain.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofGetWidth) {
		NanReturnValue(NanNew(ofGetWidth()));
	} // !ofxNode_ofGetWidth
} // !namespace ofxNode
#include "ofxNode_ofGetMouseX.h"
#include "ofMain.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofGetMouseX) {
		NanReturnValue(NanNew(ofGetMouseX()));
	} // !ofxNode_ofGetMouseX
} // !namespace ofxNode
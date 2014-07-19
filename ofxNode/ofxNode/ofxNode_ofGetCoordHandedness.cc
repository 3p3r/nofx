#include "ofxNode_ofGetCoordHandedness.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofGetCoordHandedness) {
		NanScope();
		NanReturnValue(ofGetCoordHandedness());
	} // !ofxNode_ofGetCoordHandedness
} // !namespace ofxNode
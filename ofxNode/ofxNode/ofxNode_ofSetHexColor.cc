#include "ofxNode_ofSetHexColor.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofSetHexColor) {
		ofSetHexColor(args[0]->Uint32Value());
		NanReturnValue(args.This());
	} // !ofxNode_ofSetHexColor
} // !namespace ofxNode

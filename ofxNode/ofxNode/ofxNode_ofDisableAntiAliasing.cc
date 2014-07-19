#include "ofxNode_ofDisableAntiAliasing.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDisableAntiAliasing) {
		NanScope();
		
		ofDisableAntiAliasing();

		NanReturnValue(args.This());
	} // !ofxNode_ofDisableAntiAliasing
} // !namespace ofxNode
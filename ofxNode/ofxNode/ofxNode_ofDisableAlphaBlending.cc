#include "ofxNode_ofDisableAlphaBlending.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDisableAlphaBlending) {
		NanScope();
		
		ofDisableAlphaBlending();

		NanReturnValue(args.This());
	} // !ofxNode_ofDisableAlphaBlending
} // !namespace ofxNode
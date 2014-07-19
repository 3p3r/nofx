#include "ofxNode_ofEnablePointSprites.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEnablePointSprites) {
		NanScope();
		
		ofEnablePointSprites();

		NanReturnValue(args.This());
	} // !ofxNode_ofEnablePointSprites
} // !namespace ofxNode
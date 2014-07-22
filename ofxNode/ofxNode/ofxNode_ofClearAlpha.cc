#include "ofxNode_ofClearAlpha.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofClearAlpha) {
		ofClearAlpha();
		NanReturnValue(args.This());
	} // !ofxNode_ofClearAlpha
} // !namespace ofxNode
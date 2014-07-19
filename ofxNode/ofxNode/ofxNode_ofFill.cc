#include "ofxNode_ofFill.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofFill) {
		NanScope();
		
		ofFill();

		NanReturnValue(args.This());
	} // !ofxNode_ofFill
} // !namespace ofxNode
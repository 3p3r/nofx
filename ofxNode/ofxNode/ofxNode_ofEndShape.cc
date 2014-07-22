#include "ofxNode_ofEndShape.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEndShape) {
		ofEndShape(args[0]->IsUndefined() ? false : args[0]->BooleanValue());
		NanReturnValue(args.This());
	} // !ofxNode_ofEndShape
} // !namespace ofxNode
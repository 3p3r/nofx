#include "ofxNode_ofEndShape.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEndShape) {
		NanScope();
		
		bool lClose = false;
		if (args.Length() > 0 && args[0]->IsBoolean())
		{
			lClose = args[0]->BooleanValue();
		}
		ofEndShape(lClose);

		NanReturnValue(args.This());
	} // !ofxNode_ofEndShape
} // !namespace ofxNode
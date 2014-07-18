#include "ofxNode_ofEnableBlendMode.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEnableBlendMode) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		if (args.Length() > 0 && IS_V8_ARG_NUMBER(args[0]))
		{
			ofEnableBlendMode((ofBlendMode) args[0]->Int32Value());
		}
		else
		{
			NanThrowError("bad arguments passed to ofEnableBlendMode");
		}
		NanReturnValue(args.This());
	} // !ofxNode_ofEnableBlendMode
} // !namespace ofxNode
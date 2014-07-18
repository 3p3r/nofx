#include "ofxNode_ofEndSaveScreenAsPDF.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofEndSaveScreenAsPDF) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		ofEndSaveScreenAsPDF();

		NanReturnValue(args.This());
	} // !ofxNode_ofEndSaveScreenAsPDF
} // !namespace ofxNode
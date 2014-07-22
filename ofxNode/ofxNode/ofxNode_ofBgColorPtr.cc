#include "ofxNode_ofBgColorPtr.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBgColorPtr) {
		float * lBgColor = ofBgColorPtr();
		float r = lBgColor[0];   //red
		float g = lBgColor[1];   //green
		float b = lBgColor[2];   //blue
		float a = lBgColor[3];   //alpha

		auto lBgColorO = NanNew<v8::Array>();
		lBgColorO->Set(0, NanNew(r));
		lBgColorO->Set(1, NanNew(g));
		lBgColorO->Set(2, NanNew(b));
		lBgColorO->Set(3, NanNew(a));
		
		NanReturnValue(lBgColorO);
	} // !ofxNode_ofBgColorPtr
} // !namespace ofxNode
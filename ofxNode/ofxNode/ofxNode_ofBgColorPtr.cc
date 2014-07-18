#include "ofxNode_ofBgColorPtr.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBgColorPtr) {
		ASSERT_FALSE(self_.IsEmpty());
		NanScope();
		
		float * lBgColor = ofBgColorPtr();
		float r = lBgColor[0];   //red
		float g = lBgColor[1];   //green
		float b = lBgColor[2];   //blue
		float a = lBgColor[3];   //alpha

		auto lBgColorO = NanNew<v8::Object>();
		lBgColorO->Set(NanNew("r"), NanNew(r));
		lBgColorO->Set(NanNew("g"), NanNew(g));
		lBgColorO->Set(NanNew("b"), NanNew(b));
		lBgColorO->Set(NanNew("a"), NanNew(a));
		
		NanReturnValue(lBgColorO);
	} // !ofxNode_ofBgColorPtr
} // !namespace ofxNode
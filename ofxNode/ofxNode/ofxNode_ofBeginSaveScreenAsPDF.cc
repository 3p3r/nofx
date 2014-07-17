#include "ofxNode_ofBeginSaveScreenAsPDF.h"
#include "ofGraphics.h"
#include "ofTypes.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBeginSaveScreenAsPDF) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		//void ofBeginSaveScreenAsPDF(string filename, bool bMultipage=false, bool b3D=false, ofRectangle viewport=ofRectangle(0, 0, 0, 0))
		if (args.Length() > 0 && args[0]->IsString())
		{
			bool bMultipage = false;
			bool b3D = false;
			ofRectangle viewport(0, 0, 0, 0);
			if (args.Length() > 1 && args[1]->IsBoolean())
			{
				bMultipage = args[1]->BooleanValue();
			}
			else if (args.Length() > 2 && args[2]->IsBoolean())
			{
				b3D = args[2]->BooleanValue();
			}
			else if (args.Length() > 3 &&
				args[3]->IsObject() &&
				args[3]->ToObject()->Has(NanNew("px")) &&
				args[3]->ToObject()->Has(NanNew("py")) &&
				args[3]->ToObject()->Has(NanNew("w")) &&
				args[3]->ToObject()->Has(NanNew("h")) &&
				args[3]->ToObject()->Get(NanNew("px"))->IsNumber() &&
				args[3]->ToObject()->Get(NanNew("py"))->IsNumber() &&
				args[3]->ToObject()->Get(NanNew("w"))->IsNumber() &&
				args[3]->ToObject()->Get(NanNew("h"))->IsNumber())
			{
				viewport.set(
					ofPoint(args[3]->ToObject()->Get(NanNew("px"))->NumberValue(), args[3]->ToObject()->Get(NanNew("py"))->NumberValue()) ,
					args[3]->ToObject()->Get(NanNew("w"))->NumberValue() ,
					args[3]->ToObject()->Get(NanNew("h"))->NumberValue());
			}
			ofBeginSaveScreenAsPDF(NanCString(args[0], nullptr), bMultipage, b3D, viewport);
		}
		else
		{
			NanThrowError("bad arguments passed to ofBeginSaveScreenAsPDF.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofBeginSaveScreenAsPDF
} // !namespace ofxNode
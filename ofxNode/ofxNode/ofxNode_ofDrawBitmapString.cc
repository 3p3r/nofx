#include "ofxNode_ofDrawBitmapString.h"
#include "ofGraphics.h"
#include "ofPoint.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofDrawBitmapString) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		if (args.Length() == 2 &&
			args[0]->IsString() &&
			args[1]->IsObject() &&
			args[1]->ToObject()->Has(NanNew("x")) &&
			args[1]->ToObject()->Get(NanNew("x"))->IsNumber() &&
			args[1]->ToObject()->Has(NanNew("y")) &&
			args[1]->ToObject()->Get(NanNew("y"))->IsNumber())
		{
			float x = 0, y = 0, z = 0;

			x = args[1]->ToObject()->Get(NanNew("x"))->NumberValue();
			y = args[1]->ToObject()->Get(NanNew("y"))->NumberValue();

			if (args[1]->ToObject()->Has(NanNew("z")) &&
				args[1]->ToObject()->Get(NanNew("z"))->IsNumber())
			{
				z = args[1]->ToObject()->Get(NanNew("z"))->NumberValue();
			}

			ofDrawBitmapString(NanCString(args[0], nullptr), ofPoint(x, y, z));
		}
		else if (args.Length() == 3 &&
			args[0]->IsString() &&
			args[1]->IsNumber() &&
			args[2]->IsNumber())
		{
			ofDrawBitmapString(NanCString(args[0], nullptr), args[1]->NumberValue(), args[2]->NumberValue());
		}
		else if (args.Length() == 4 &&
			args[0]->IsString() &&
			args[1]->IsNumber() &&
			args[2]->IsNumber() &&
			args[3]->IsNumber())
		{
			ofDrawBitmapString(NanCString(args[0], nullptr), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		}
		else
		{
			NanThrowError("Bad arguments passed to ofDrawBitmapString.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofDrawBitmapString
} // !namespace ofxNode
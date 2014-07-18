#include "ofxNode_ofCurveVertex.h"
#include "ofGraphics.h"
#include "ofTypes.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofCurveVertex) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		if (args.Length() == 1 &&
			args[0]->IsObject() &&
			args[0]->ToObject()->Has(NanNew("x")) &&
			args[0]->ToObject()->Has(NanNew("y")) &&
			args[0]->ToObject()->Get(NanNew("x"))->IsNumber() &&
			args[0]->ToObject()->Get(NanNew("y"))->IsNumber())
		{
			double x = 0, y = 0, z = 0;
			
			x = args[0]->ToObject()->Get(NanNew("x"))->NumberValue();
			y = args[0]->ToObject()->Get(NanNew("y"))->NumberValue();

			if (args[0]->ToObject()->Has(NanNew("z")) &&
				args[0]->ToObject()->Get(NanNew("z"))->IsNumber())
			{
				z = args[0]->ToObject()->Get(NanNew("z"))->NumberValue();
			}
			
			ofCurveVertex(ofPoint(x , y, z));
		}
		else if (args.Length() == 2 &&
			args[0]->IsNumber() &&
			args[1]->IsNumber())
		{
			ofCurveVertex(args[0]->NumberValue(), args[1]->NumberValue());
		}
		else if (args.Length() == 3 &&
			args[0]->IsNumber() &&
			args[1]->IsNumber() &&
			args[2]->IsNumber())
		{
			ofCurveVertex(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		}
		else
		{
			NanThrowError("wrong arguments passed to ofCurveVertex.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofCurveVertex
} // !namespace ofxNode
#include "ofxNode_ofCurve.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofCurve) {
		NanScope();
		
		//void ofCurve(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3)
		if (args.Length() == 8 &&
			args[0]->IsNumber() &&
			args[1]->IsNumber() &&
			args[2]->IsNumber() &&
			args[3]->IsNumber() &&
			args[4]->IsNumber() &&
			args[5]->IsNumber() &&
			args[6]->IsNumber() &&
			args[7]->IsNumber())
		{
			ofCurve(args[0]->NumberValue() ,
				args[1]->NumberValue() ,
				args[2]->NumberValue() ,
				args[3]->NumberValue() ,
				args[4]->NumberValue() ,
				args[5]->NumberValue() ,
				args[6]->NumberValue() ,
				args[7]->NumberValue());
		}
		//void ofCurve(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
		else if (args.Length() == 12 &&
			args[0]->IsNumber() &&
			args[1]->IsNumber() &&
			args[2]->IsNumber() &&
			args[3]->IsNumber() &&
			args[4]->IsNumber() &&
			args[5]->IsNumber() &&
			args[6]->IsNumber() &&
			args[7]->IsNumber() &&
			args[8]->IsNumber() &&
			args[9]->IsNumber() &&
			args[10]->IsNumber() &&
			args[11]->IsNumber())
		{
			ofCurve(args[0]->NumberValue() ,
				args[1]->NumberValue() ,
				args[2]->NumberValue() ,
				args[3]->NumberValue() ,
				args[4]->NumberValue() ,
				args[5]->NumberValue() ,
				args[6]->NumberValue() ,
				args[7]->NumberValue() ,
				args[8]->NumberValue() ,
				args[9]->NumberValue() ,
				args[10]->NumberValue() ,
				args[11]->NumberValue());
		}
		else
		{
			NanThrowError("wrong argument passed to ofCurve.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofCurve
} // !namespace ofxNode
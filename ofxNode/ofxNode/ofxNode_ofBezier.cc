#include "ofxNode_ofBezier.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBezier) {
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
			ofBezier(args[0]->NumberValue() ,
				args[1]->NumberValue() ,
				args[2]->NumberValue() ,
				args[3]->NumberValue() ,
				args[4]->NumberValue() ,
				args[5]->NumberValue() ,
				args[6]->NumberValue() ,
				args[7]->NumberValue());
		} else {
			ofBezier(args[0]->NumberValue() ,
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
		NanReturnValue(args.This());
	} // !ofxNode_ofBezier
} // !namespace ofxNode
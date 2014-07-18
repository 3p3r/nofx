#include "ofxNode_ofBezierVertex.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBezierVertex) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		//void ofBezierVertex(float x1, float y1, float x2, float y2, float x3, float y3)
		if (args.Length() == 6 &&
			args[0]->IsNumber() &&
			args[1]->IsNumber() &&
			args[2]->IsNumber() &&
			args[3]->IsNumber() &&
			args[4]->IsNumber() &&
			args[5]->IsNumber())
		{
			ofBezierVertex(args[0]->NumberValue() ,
				args[1]->NumberValue() ,
				args[2]->NumberValue() ,
				args[3]->NumberValue() ,
				args[4]->NumberValue() ,
				args[5]->NumberValue());
		}
		else if (args.Length() == 9 &&
			args[0]->IsNumber() &&
			args[1]->IsNumber() &&
			args[2]->IsNumber() &&
			args[3]->IsNumber() &&
			args[4]->IsNumber() &&
			args[5]->IsNumber() &&
			args[6]->IsNumber() &&
			args[7]->IsNumber() &&
			args[8]->IsNumber())
		{
			//void ofBezierVertex(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
			ofBezierVertex(args[0]->NumberValue() ,
				args[1]->NumberValue() ,
				args[2]->NumberValue() ,
				args[3]->NumberValue() ,
				args[4]->NumberValue() ,
				args[5]->NumberValue() ,
				args[6]->NumberValue() ,
				args[7]->NumberValue() ,
				args[8]->NumberValue());
		}
		else
		{
			NanThrowError("wrong argument passed to ofBezierVertex.");
		}

 		//TODO(sepehr)
 		//void ofBezierVertex(const ofPoint &p1, const ofPoint &p2, const ofPoint &p3)

		NanReturnValue(args.This());
	} // !ofxNode_ofBezierVertex
} // !namespace ofxNode
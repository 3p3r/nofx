#include "ofxNode_ofCircle.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofCircle) {
// 		ASSERT_FALSE(self_.IsEmpty());
// 
// 		NanScope();
		
// 		if (args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
// 		{
			ofCircle(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
// 		}
// 		else if (args.Length() == 4 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber()  && args[2]->IsNumber())
// 		{
// 			ofCircle(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
// 		}
// 		else
// 		{
// 			NanThrowError("Bad arguments passed to ofCircle.");
// 		}
		return;
		//NanReturnValue(args.This());
	} // !ofxNode_ofCircle
} // !namespace ofxNode
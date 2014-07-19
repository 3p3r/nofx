#include "ofxNode_ofBackground.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBackground) {
		NanScope();
		if (args.Length() == 1 && args[0]->IsNumber())
		{
			//void ofBackground(int brightness)
			ofBackground(args[0]->NumberValue());
		}
		else if (args.Length() == 2 && args[0]->IsNumber() && args[1]->IsNumber())
		{
			//void ofBackground(int brightness, int alpha=255)
			ofBackground(args[0]->NumberValue(), args[1]->NumberValue());
		}
		else if (args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
		{
			//void ofBackground(int r, int g, int b)
			ofBackground(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		}
		else if (args.Length() == 4 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber() && args[3]->IsNumber())
		{
			//void ofBackground(int r, int g, int b, int a=255)
			ofBackground(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[2]->NumberValue());
		}
		else
		{
			NanThrowError("Bad arguments passed to ofCircle.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofBackground
} // !namespace ofxNode
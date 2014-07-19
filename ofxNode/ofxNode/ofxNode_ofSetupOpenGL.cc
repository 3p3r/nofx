#include "ofxNode_ofSetupOpenGL.h"
#include "ofMain.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofSetupOpenGL) {
		NanScope();
		// We need at least two arguments for this function
		if (args.Length() < 2)
		{
			NanThrowTypeError("ofSetupOpenGL needs at least two arguments");
		}
		// Two fist arguments must be numbers
		if (!args[0]->IsNumber() || !args[1]->IsNumber())
		{
			NanThrowError("ofSetupOpenGL needs its two first arguments to be window dimensions (positive numbers).");
		}

		double lWindowWidth = args[0]->NumberValue();
		double lWindowHeight = args[1]->NumberValue();
		ofWindowMode lOpenGLWindowEnum = OF_WINDOW;

		if (args.Length() > 2)
		{
			if (!args[2]->IsNumber())
			{
				NanThrowError("ofSetupOpenGL needs its third argument to be a number or undefined or null");
			}
			else if(args[2]->IsNumber())
			{
				//TODO(sepehr) check if number is in range of ofWindowMode enum
				lOpenGLWindowEnum = (ofWindowMode)args[2]->Int32Value();
			}
			else if (args[2]->IsNull() || args[2]->IsUndefined())
			{
				lOpenGLWindowEnum = OF_WINDOW; //default value
			}
			else
			{
				NanThrowError("ofSetupOpenGL needs its third argument to be a number. unknown type is passed.");
			}
		}

		ofSetupOpenGL(lWindowWidth, lWindowHeight, lOpenGLWindowEnum);
		NanReturnValue(args.This());
	} // !ofxNode_ofSetupOpenGL
} // !namespace ofxNode
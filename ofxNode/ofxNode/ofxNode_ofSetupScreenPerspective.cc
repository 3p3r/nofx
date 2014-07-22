#include "ofxNode_ofSetupScreenPerspective.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetupScreenPerspective) {
		const auto width = args[0]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[0]);
		const auto height = args[1]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[1]);
		
		if (args[6]->IsUndefined())
		{
			const auto fov = args[2]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[2]);
			const auto nearDist = args[3]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[3]);
			const auto farDist = args[4]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[4]);			
			
			ofSetupScreenPerspective(width, height, fov, nearDist, farDist);
		}
		else
		{
			const auto orientation = args[2]->IsUndefined() ? OF_ORIENTATION_UNKNOWN : (ofOrientation )args[2]->Uint32Value();
			const auto vFlip = args[3]->IsUndefined() ? true : args[2]->BooleanValue();
			const auto fov = args[4]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[2]);
			const auto nearDist = args[5]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[3]);
			const auto farDist = args[6]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[4]);

			ofSetupScreenPerspective(width, height, orientation, vFlip, fov, nearDist, farDist);
		}

        NanReturnValue(args.This());
    } // !{ofxNode_ofSetupScreenPerspective}
} // !namespace ofxNode
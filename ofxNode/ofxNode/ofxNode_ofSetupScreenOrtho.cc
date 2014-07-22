#include "ofxNode_ofSetupScreenOrtho.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetupScreenOrtho) {
        const auto width = args[0]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[0]);
		const auto height = args[1]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[1]);

		if (args[5]->IsUndefined())
		{
			const auto nearDist = args[2]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[3]);
			const auto farDist = args[2]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[4]);			

			ofSetupScreenOrtho(width, height, nearDist, farDist);
		}
		else
		{
			const auto orientation = args[2]->IsUndefined() ? OF_ORIENTATION_UNKNOWN : (ofOrientation )args[2]->Uint32Value();
			const auto vFlip = args[3]->IsUndefined() ? true : args[2]->BooleanValue();
			const auto nearDist = args[4]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[3]);
			const auto farDist = args[5]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[4]);

			ofSetupScreenOrtho(width, height, orientation, vFlip, nearDist, farDist);
		}

        NanReturnValue(args.This());
    } // !{ofxNode_ofSetupScreenOrtho}
} // !namespace ofxNode
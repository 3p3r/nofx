#include "ofxNode_ofSeedRandom.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSeedRandom) {

        if (args.Length() == 0)
        {
			ofSeedRandom();
        }
		else
		{
			ofSeedRandom(args[0]->NumberValue());
		}

        NanReturnValue(args.This());
    } // !ofxNode_ofSeedRandom
} // !namespace ofxNode
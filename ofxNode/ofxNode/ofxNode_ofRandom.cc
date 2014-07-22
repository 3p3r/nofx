#include "ofxNode_ofRandom.h"
#include "ofMath.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofRandom) {
		if (args.Length() == 1)
		{
			NanReturnValue(NanNew(ofRandom(args[0]->NumberValue())));
		}
		else
		{
			NanReturnValue(NanNew(ofRandom(args[0]->NumberValue(), args[1]->NumberValue())));
		}
	} // !ofxNode_ofRandom
} // !namespace ofxNode

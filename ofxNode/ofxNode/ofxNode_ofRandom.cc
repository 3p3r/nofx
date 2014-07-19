#include "ofxNode_ofRandom.h"
#include "ofMath.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofRandom) {
		NanScope();

		if (args.Length() == 1)
		{
			NanReturnValue(NanNew(ofRandom(args[0]->NumberValue())));
		}
		else if (args.Length() == 2)
		{
			NanReturnValue(NanNew(ofRandom(args[0]->NumberValue(), args[1]->NumberValue())));
		}
		else
		{
			NanThrowError("bad args passed to ofRandom");
		}
	} // !ofxNode_ofRandom
} // !namespace ofxNode

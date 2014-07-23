#include "ofxNode_ofDistSquared.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofDistSquared) {
		NanReturnValue(NanNew(ofDistSquared(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue())));
    } // !ofxNode_ofDistSquared
} // !namespace ofxNode
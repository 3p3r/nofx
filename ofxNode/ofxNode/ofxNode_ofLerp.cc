#include "ofxNode_ofLerp.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofLerp) {
		NanReturnValue(NanNew(ofLerp(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue())));
    } // !ofxNode_ofLerp
} // !namespace ofxNode
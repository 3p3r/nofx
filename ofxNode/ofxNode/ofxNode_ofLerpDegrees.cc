#include "ofxNode_ofLerpDegrees.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofLerpDegrees) {
		NanReturnValue(NanNew(ofLerpDegrees(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue())));
    } // !ofxNode_ofLerpDegrees
} // !namespace ofxNode
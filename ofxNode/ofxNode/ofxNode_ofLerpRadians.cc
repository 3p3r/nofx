#include "ofxNode_ofLerpRadians.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofLerpRadians) {
		NanReturnValue(NanNew(ofLerpRadians(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue())));
    } // !ofxNode_ofLerpRadians
} // !namespace ofxNode
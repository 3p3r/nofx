#include "ofxNode_ofAngleDifferenceRadians.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofAngleDifferenceRadians) {
		NanReturnValue(NanNew(ofAngleDifferenceRadians(args[0]->NumberValue(), args[1]->NumberValue())));
    } // !ofxNode_ofAngleDifferenceRadians
} // !namespace ofxNode
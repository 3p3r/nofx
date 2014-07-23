#include "ofxNode_ofAngleDifferenceDegrees.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofAngleDifferenceDegrees) {
        NanReturnValue(NanNew(ofAngleDifferenceDegrees(args[0]->NumberValue(), args[1]->NumberValue())));
    } // !ofxNode_ofAngleDifferenceDegrees
} // !namespace ofxNode
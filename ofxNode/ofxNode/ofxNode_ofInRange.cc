#include "ofxNode_ofInRange.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofInRange) {
		NanReturnValue(ofInRange(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()));
    } // !ofxNode_ofInRange
} // !namespace ofxNode
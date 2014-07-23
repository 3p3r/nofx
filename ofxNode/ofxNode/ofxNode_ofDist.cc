#include "ofxNode_ofDist.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofDist) {
		NanReturnValue(NanNew(ofDist(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue())));
    } // !ofxNode_ofDist
} // !namespace ofxNode
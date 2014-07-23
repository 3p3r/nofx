#include "ofxNode_ofInterpolateCubic.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofInterpolateCubic) {
		NanReturnValue(NanNew(ofInterpolateCubic(args[0]->NumberValue(),args[1]->NumberValue(),args[2]->NumberValue(),args[3]->NumberValue(),args[4]->NumberValue())));
    } // !ofxNode_ofInterpolateCubic
} // !namespace ofxNode
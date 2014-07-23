#include "ofxNode_ofInterpolateCosine.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofInterpolateCosine) {
		NanReturnValue(NanNew(ofInterpolateCosine(args[0]->NumberValue(),args[1]->NumberValue(),args[2]->NumberValue())));
    } // !ofxNode_ofInterpolateCosine
} // !namespace ofxNode
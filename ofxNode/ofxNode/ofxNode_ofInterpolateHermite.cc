#include "ofxNode_ofInterpolateHermite.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofInterpolateHermite) {
		NanReturnValue(NanNew(ofInterpolateHermite(args[0]->NumberValue(),args[1]->NumberValue(),args[2]->NumberValue(),args[3]->NumberValue(),args[4]->NumberValue(),args[5]->NumberValue(),args[6]->NumberValue())));
    } // !ofxNode_ofInterpolateHermite
} // !namespace ofxNode
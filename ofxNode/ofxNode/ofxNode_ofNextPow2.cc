#include "ofxNode_ofNextPow2.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofNextPow2) {
		NanReturnValue(NanNew(ofNextPow2(args[0]->Int32Value())));
    } // !ofxNode_ofNextPow2
} // !namespace ofxNode
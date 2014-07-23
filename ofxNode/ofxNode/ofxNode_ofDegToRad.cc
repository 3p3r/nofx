#include "ofxNode_ofDegToRad.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofDegToRad) {
		NanReturnValue(NanNew(ofDegToRad(args[0]->NumberValue())));
    } // !ofxNode_ofDegToRad
} // !namespace ofxNode
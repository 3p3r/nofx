#include "ofxNode_ofRadToDeg.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofRadToDeg) {
		NanReturnValue(NanNew(ofRadToDeg(args[0]->NumberValue())));
    } // !ofxNode_ofRadToDeg
} // !namespace ofxNode
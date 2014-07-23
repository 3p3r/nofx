#include "ofxNode_ofSign.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSign) {
		NanReturnValue(NanNew(ofSign(args[0]->NumberValue())));
    } // !ofxNode_ofSign
} // !namespace ofxNode
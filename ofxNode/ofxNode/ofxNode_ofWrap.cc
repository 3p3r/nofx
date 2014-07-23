#include "ofxNode_ofWrap.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofWrap) {
		NanReturnValue(NanNew(ofWrap(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue())));
    } // !ofxNode_ofWrap
} // !namespace ofxNode
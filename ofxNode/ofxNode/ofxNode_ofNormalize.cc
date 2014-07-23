#include "ofxNode_ofNormalize.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofNormalize) {
        NanReturnValue(NanNew(ofNormalize(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue())));
    } // !ofxNode_ofNormalize
} // !namespace ofxNode
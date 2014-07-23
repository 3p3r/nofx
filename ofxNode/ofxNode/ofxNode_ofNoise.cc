#include "ofxNode_ofNoise.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofNoise) {
		NanReturnValue(NanNew(ofNoise(args[0]->NumberValue(),
			args[1]->IsUndefined() ? NULL : args[1]->NumberValue(),
			args[2]->IsUndefined() ? NULL : args[2]->NumberValue(),
			args[3]->IsUndefined() ? NULL : args[3]->NumberValue())));
    } // !ofxNode_ofNoise
} // !namespace ofxNode
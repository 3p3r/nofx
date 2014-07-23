#include "ofxNode_ofWrapDegrees.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofWrapDegrees) {
		NanReturnValue(NanNew(ofWrapDegrees(args[0]->NumberValue(), args[1]->IsUndefined() ? NULL : args[1]->NumberValue(), args[2]->IsUndefined() ? NULL : args[2]->NumberValue())));
    } // !ofxNode_ofWrapDegrees
} // !namespace ofxNode
#include "ofxNode_ofWrapRadians.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofWrapRadians) {
		NanReturnValue(NanNew(ofWrapRadians(args[0]->NumberValue(), args[1]->IsUndefined() ? NULL : args[1]->NumberValue(), args[2]->IsUndefined() ? NULL : args[2]->NumberValue())));
    } // !ofxNode_ofWrapRadians
} // !namespace ofxNode
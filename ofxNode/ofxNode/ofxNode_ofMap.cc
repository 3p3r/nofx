#include "ofxNode_ofMap.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofMap) {
		NanReturnValue(NanNew(ofMap(
			args[0]->NumberValue(),
			args[1]->NumberValue(),
			args[2]->NumberValue(),
			args[3]->NumberValue(),
			args[4]->NumberValue(),
			args[5]->IsUndefined() ? NULL : args[6]->BooleanValue()
			)));
    } // !ofxNode_ofMap
} // !namespace ofxNode
#include "ofxNode_ofInterpolateCatmullRom.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofInterpolateCatmullRom) {
		NanReturnValue(NanNew(ofInterpolateCatmullRom(args[0]->NumberValue(),args[1]->NumberValue(),args[2]->NumberValue(),args[3]->NumberValue(),args[4]->NumberValue())));
    } // !ofxNode_ofInterpolateCatmullRom
} // !namespace ofxNode
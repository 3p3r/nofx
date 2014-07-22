#include "ofxNode_ofOrientationToDegrees.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofOrientationToDegrees) {
		NanReturnValue(NanNew(ofOrientationToDegrees((ofOrientation)args[0]->Uint32Value())));
    } // !{ofxNode_ofOrientationToDegrees}
} // !namespace ofxNode
#include "ofxNode_ofRandomuf.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofRandomuf) {
		NanReturnValue(NanNew(ofRandomuf()));
    } // !ofxNode_ofRandomuf
} // !namespace ofxNode
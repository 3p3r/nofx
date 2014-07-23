#include "ofxNode_ofRandomHeight.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofRandomHeight) {
		NanReturnValue(NanNew(ofRandomHeight()));
    } // !ofxNode_ofRandomHeight
} // !namespace ofxNode
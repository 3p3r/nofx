#include "ofxNode_ofRandomWidth.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofRandomWidth) {
		NanReturnValue(NanNew(ofRandomWidth()));
    } // !ofxNode_ofRandomWidth
} // !namespace ofxNode
#include "ofxNode_ofRandomf.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofRandomf) {
		NanReturnValue(NanNew(ofRandomf()));
    } // !ofxNode_ofRandomf
} // !namespace ofxNode
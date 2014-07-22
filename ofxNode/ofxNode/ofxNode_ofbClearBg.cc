#include "ofxNode_ofbClearBg.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofbClearBg) {
		NanReturnValue(NanNew(ofbClearBg()));
    } // !{ofxNode_ofbClearBg}
} // !namespace ofxNode
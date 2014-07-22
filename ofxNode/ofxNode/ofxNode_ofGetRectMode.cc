#include "ofxNode_ofGetRectMode.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofGetRectMode) {
		NanReturnValue(NanNew(ofGetRectMode()));
    } // !{ofxNode_ofGetRectMode}
} // !namespace ofxNode
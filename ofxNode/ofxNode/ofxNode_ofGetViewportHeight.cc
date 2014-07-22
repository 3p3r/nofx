#include "ofxNode_ofGetViewportHeight.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofGetViewportHeight) {
		NanReturnValue(NanNew(ofGetViewportHeight()));
    } // !{ofxNode_ofGetViewportHeight}
} // !namespace ofxNode
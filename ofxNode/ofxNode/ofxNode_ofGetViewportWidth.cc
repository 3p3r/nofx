#include "ofxNode_ofGetViewportWidth.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofGetViewportWidth) {
		NanReturnValue(NanNew(ofGetViewportWidth()));
    } // !{ofxNode_ofGetViewportWidth}
} // !namespace ofxNode
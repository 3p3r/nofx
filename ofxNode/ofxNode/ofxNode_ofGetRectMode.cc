#include "ofxNode_ofGetRectMode.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofGetRectMode) {
        NanScope();
		NanReturnValue(NanNew(ofGetRectMode()));
    } // !{ofxNode_ofGetRectMode}
} // !namespace ofxNode
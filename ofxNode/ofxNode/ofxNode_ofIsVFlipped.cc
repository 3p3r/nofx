#include "ofxNode_ofIsVFlipped.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofIsVFlipped) {
        NanScope();
		NanReturnValue(NanNew(ofIsVFlipped()));
    } // !{ofxNode_ofIsVFlipped}
} // !namespace ofxNode
#include "ofxNode_ofIsVFlipped.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofIsVFlipped) {
		NanReturnValue(ofIsVFlipped());
    } // !{ofxNode_ofIsVFlipped}
} // !namespace ofxNode
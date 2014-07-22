#include "ofxNode_ofNextContour.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofNextContour) {
        ofNextContour(args[0]->IsUndefined() ? args[0]->BooleanValue() : false);
        NanReturnValue(args.This());
    } // !{ofxNode_ofNextContour}
} // !namespace ofxNode
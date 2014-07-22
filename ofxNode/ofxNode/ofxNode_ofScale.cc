#include "ofxNode_ofScale.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofScale) {
        ofScale(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), args[2]->IsUndefined() ? 1.0f : V8_ARG_NUMBER(args[2]));
        NanReturnValue(args.This());
    } // !{ofxNode_ofScale}
} // !namespace ofxNode
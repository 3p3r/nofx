#include "ofxNode_ofSetBackgroundColorHex.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetBackgroundColorHex) {
		const auto alpha = args[1]->IsUndefined() ? ofColor::limit() : V8_ARG_NUMBER(args[1]);
		ofSetBackgroundColor(args[0]->Uint32Value(), alpha);
        NanReturnValue(args.This());
    } // !{ofxNode_ofSetBackgroundColorHex}
} // !namespace ofxNode
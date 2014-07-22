#include "ofxNode_ofSetStyle.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofStyle.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetStyle) {
        NanScope();

        ofSetStyle(node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args[0]->ToObject())->self());

        NanReturnValue(args.This());
    } // !{ofxNode_ofSetStyle}
} // !namespace ofxNode
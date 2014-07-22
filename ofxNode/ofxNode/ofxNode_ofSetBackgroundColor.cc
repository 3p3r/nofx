#include "ofxNode_ofSetBackgroundColor.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofColor.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofSetBackgroundColor) {
        NanScope();

        if (args.Length() > 2)
        {
			const auto alpha = args[3]->IsUndefined() ? ofColor::limit() : V8_ARG_NUMBER(args[3]);
			ofSetBackgroundColor(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]), alpha);
        }
		else if (args[0]->IsNumber())
		{
			const auto alpha = args[1]->IsUndefined() ? ofColor::limit() : V8_ARG_NUMBER(args[1]);
			ofSetBackgroundColor(V8_ARG_NUMBER(args[0]), alpha);
		}
		else
		{
			ofSetBackgroundColor(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self());
		}

        NanReturnValue(args.This());
    } // !{ofxNode_ofSetBackgroundColor}
} // !namespace ofxNode
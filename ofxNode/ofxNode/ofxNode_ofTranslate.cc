#include "ofxNode_ofTranslate.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofTranslate) {
        if (args.Length() == 1)
        {
			ofTranslate(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
        }
		else
		{
			const auto z = args[2]->IsUndefined() ? 0 : V8_ARG_NUMBER(args[2]);
			ofTranslate(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), z);
		}

        NanReturnValue(args.This());
    } // !{ofxNode_ofTranslate}
} // !namespace ofxNode
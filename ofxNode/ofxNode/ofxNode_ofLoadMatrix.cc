#include "ofxNode_ofLoadMatrix.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofMatrix4x4.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofLoadMatrix) {
        NanScope();

		ofLoadMatrix(node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self());

        NanReturnValue(args.This());
    } // !{ofxNode_ofLoadMatrix}
} // !namespace ofxNode
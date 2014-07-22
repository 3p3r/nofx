#include "ofxNode_ofGetCurrentMatrix.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofMatrix4x4.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofGetCurrentMatrix) {
        const ofMatrixMode matrixMode_ = (ofMatrixMode)args[0]->Uint32Value();
		auto lMatrix = NanNew(ofxNode_ofMatrix4x4::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(lMatrix)->self() = ofGetCurrentMatrix(matrixMode_);
		NanReturnValue(lMatrix);
    } // !{ofxNode_ofGetCurrentMatrix}
} // !namespace ofxNode
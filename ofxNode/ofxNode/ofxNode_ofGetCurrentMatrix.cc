#include "ofxNode_ofGetCurrentMatrix.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofMatrix4x4.h"
#include "ofMatrix4x4.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofGetCurrentMatrix) {
        NanScope();

        const ofMatrixMode matrixMode_ = (ofMatrixMode)args[0]->Uint32Value();
		const auto resultMat = ofGetCurrentMatrix(matrixMode_);

		v8::Local<v8::Value> lArgv[] = {
			NanNew(resultMat._mat[0][0]),
			NanNew(resultMat._mat[0][1]),
			NanNew(resultMat._mat[0][2]),
			NanNew(resultMat._mat[0][3]),
			NanNew(resultMat._mat[1][0]),
			NanNew(resultMat._mat[1][1]),
			NanNew(resultMat._mat[1][2]),
			NanNew(resultMat._mat[1][3]),
			NanNew(resultMat._mat[2][0]),
			NanNew(resultMat._mat[2][1]),
			NanNew(resultMat._mat[2][2]),
			NanNew(resultMat._mat[2][3]),
			NanNew(resultMat._mat[3][0]),
			NanNew(resultMat._mat[3][1]),
			NanNew(resultMat._mat[3][2]),
			NanNew(resultMat._mat[3][3])
		};

		NanReturnValue(NanNew(ofxNode_ofMatrix4x4::factory())->CallAsConstructor(16, lArgv));
    } // !{ofxNode_ofGetCurrentMatrix}
} // !namespace ofxNode
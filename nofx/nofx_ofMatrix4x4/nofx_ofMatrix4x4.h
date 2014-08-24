#ifndef _NOFX_OF_MATRIX4X4_H_
#define _NOFX_OF_MATRIX4X4_H_

#include "globals.h"
#include <memory>
#include "ofMatrix4x4.h"
#include "..\nofx\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
	namespace OfMatrix4x4
	{
		class OfMatrix4x4Wrap
			: public nofx::ObjectWrap < ofMatrix4x4 >
		{

			DeclareObjectRoutines(Matrix4x4);

			static NAN_INDEX_GETTER(IndexGetter);
			static NAN_INDEX_SETTER(IndexSetter);

			static NAN_METHOD(Decompose);
			static NAN_METHOD(GetFrustum);
			static NAN_METHOD(GetInverse);
			static NAN_METHOD(GetInverseOf);
			static NAN_METHOD(GetLookAt);
			static NAN_METHOD(GetOrtho);
			static NAN_METHOD(GetOrthoNormalOf);
			static NAN_METHOD(GetPerspective);
			static NAN_METHOD(GetPtr);
			static NAN_METHOD(GetRotate);
			static NAN_METHOD(GetRowAsVec3f);
			static NAN_METHOD(GetRowAsVec4f);
			static NAN_METHOD(GetScale);
			static NAN_METHOD(GetTranslation);
			static NAN_METHOD(GetTransposedOf);
			static NAN_METHOD(GlRotate);
			static NAN_METHOD(GlRotateRad);
			static NAN_METHOD(GlScale);
			static NAN_METHOD(GlTranslate);
			static NAN_METHOD(IsIdentity);
			static NAN_METHOD(IsNaN);
			static NAN_METHOD(IsValid);
			static NAN_METHOD(MakeFromMultiplicationOf);
			static NAN_METHOD(MakeFrustumMatrix);
			static NAN_METHOD(MakeIdentityMatrix);
			static NAN_METHOD(MakeInvertOf);
			static NAN_METHOD(MakeLookAtMatrix);
			static NAN_METHOD(MakeLookAtViewMatrix);
			static NAN_METHOD(MakeOrtho2DMatrix);
			static NAN_METHOD(MakeOrthoMatrix);
			static NAN_METHOD(MakeOrthoNormalOf);
			static NAN_METHOD(MakePerspectiveMatrix);
			static NAN_METHOD(MakeRotationMatrix);
			static NAN_METHOD(MakeScaleMatrix);
			static NAN_METHOD(MakeTranslationMatrix);
			static NAN_METHOD(NewFrustumMatrix);
			static NAN_METHOD(NewIdentityMatrix);
			static NAN_METHOD(NewLookAtMatrix);
			static NAN_METHOD(NewOrtho2DMatrix);
			static NAN_METHOD(NewOrthoMatrix);
			static NAN_METHOD(NewPerspectiveMatrix);
			static NAN_METHOD(NewRotationMatrix);
			static NAN_METHOD(NewScaleMatrix);
			static NAN_METHOD(NewTranslationMatrix);
			static NAN_METHOD(PostMult);
			static NAN_METHOD(PostMultRotate);
			static NAN_METHOD(PostMultScale);
			static NAN_METHOD(PostMultTranslate);
			static NAN_METHOD(PreMult);
			static NAN_METHOD(PreMultRotate);
			static NAN_METHOD(PreMultScale);
			static NAN_METHOD(PreMultTranslate);
			static NAN_METHOD(Rotate);
			static NAN_METHOD(RotateRad);
			static NAN_METHOD(Scale);
			static NAN_METHOD(Set);
			static NAN_METHOD(SetRotate);
			static NAN_METHOD(SetTranslation);
			static NAN_METHOD(Transform3x3);
			static NAN_METHOD(Translate);

		}; // !class OfMatrix4x4Wrap
	} //!namespace OfMatrix4x4
} // !namespace nofx

#endif // !_NOFX_OF_MATRIX4X4_H_

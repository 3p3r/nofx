#ifndef _ofxNode_wrapper_ofMatrix4x4_H_
#define _ofxNode_wrapper_ofMatrix4x4_H_

#include "globals.h"
#include "ofMatrix4x4.h"
#include "ofxNode_wrapper_ofQuaternion.h"
#include "ofxNode_wrapper_ofVec3f.h"
#include "ofxNode_wrapper_ofVec4f.h"

namespace ofxNode
{
	class ofxNode_ofMatrix4x4
		: public node::ObjectWrap
	{
	public:
		friend class ofxNode_ofQuaternion;
		static void Init(v8::Handle<v8::Object> exports);
		ofMatrix4x4& self() {return internal_;}
		static const v8::Persistent<v8::Function>& factory() {return constructor;}
	private:
		// will be used to initialize native OF datatype
		ofMatrix4x4 internal_;

		// C++ constructors
		explicit ofxNode_ofMatrix4x4(ofMatrix4x4&);
		~ofxNode_ofMatrix4x4();

		// Mutators
		// setters
		static NAN_SETTER(SetA00);
		static NAN_SETTER(SetA01);
		static NAN_SETTER(SetA02);
		static NAN_SETTER(SetA03);
		static NAN_SETTER(SetA10);
		static NAN_SETTER(SetA11);
		static NAN_SETTER(SetA12);
		static NAN_SETTER(SetA13);
		static NAN_SETTER(SetA20);
		static NAN_SETTER(SetA21);
		static NAN_SETTER(SetA22);
		static NAN_SETTER(SetA23);
		static NAN_SETTER(SetA30);
		static NAN_SETTER(SetA31);
		static NAN_SETTER(SetA32);
		static NAN_SETTER(SetA33);

		// getters
		static NAN_GETTER(GetA00);
		static NAN_GETTER(GetA01);
		static NAN_GETTER(GetA02);
		static NAN_GETTER(GetA03);
		static NAN_GETTER(GetA10);
		static NAN_GETTER(GetA11);
		static NAN_GETTER(GetA12);
		static NAN_GETTER(GetA13);
		static NAN_GETTER(GetA20);
		static NAN_GETTER(GetA21);
		static NAN_GETTER(GetA22);
		static NAN_GETTER(GetA23);
		static NAN_GETTER(GetA30);
		static NAN_GETTER(GetA31);
		static NAN_GETTER(GetA32);
		static NAN_GETTER(GetA33);

		// JS constructors
		static v8::Persistent<v8::Function> constructor;
		static NAN_METHOD(New);

		// methods
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

		// Primitives
		static NAN_METHOD(ToString);
		//static NAN_METHOD(Times); maybe?
	};

} // !namespace ofxNode

#endif // !_ofxNode_wrapper_ofMatrix4x4_H_
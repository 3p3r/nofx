#include "ofxNode_wrapper_ofMatrix4x4.h"

#define DEFINE_GETTER_SETTER(row, col) \
	NAN_GETTER(ofxNode_ofMatrix4x4::GetA##row##col) \
	{ \
	NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self()._mat[row][col])); \
	} \
	NAN_SETTER(ofxNode_ofMatrix4x4::SetA##row##col) \
	{ \
	node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self()._mat[row][col] = value->NumberValue(); \
	}

namespace ofxNode
{
	v8::Persistent<v8::Function> ofxNode_ofMatrix4x4::constructor;

	ofxNode_ofMatrix4x4::ofxNode_ofMatrix4x4(ofMatrix4x4& aOfMatrix4x4)
		: internal_(aOfMatrix4x4)
	{}

	ofxNode_ofMatrix4x4::~ofxNode_ofMatrix4x4()
	{}

	NAN_METHOD(ofxNode_ofMatrix4x4::New)
	{
		if (args.IsConstructCall()) {
			// Invoked as constructor: `new ofMatrix4x4(...)`
			ofxNode_ofMatrix4x4* obj;
			if (args.Length() == 0)
			{
				obj = new ofxNode_ofMatrix4x4(ofMatrix4x4());
			}
			else if (args.Length() == 16)
			{
				ofMatrix4x4 lMat(
					V8_ARG_NUMBER(args[0]),
					V8_ARG_NUMBER(args[1]),
					V8_ARG_NUMBER(args[2]),
					V8_ARG_NUMBER(args[3]),
					V8_ARG_NUMBER(args[4]),
					V8_ARG_NUMBER(args[5]),
					V8_ARG_NUMBER(args[6]),
					V8_ARG_NUMBER(args[7]),
					V8_ARG_NUMBER(args[8]),
					V8_ARG_NUMBER(args[9]),
					V8_ARG_NUMBER(args[10]),
					V8_ARG_NUMBER(args[11]),
					V8_ARG_NUMBER(args[12]),
					V8_ARG_NUMBER(args[13]),
					V8_ARG_NUMBER(args[14]),
					V8_ARG_NUMBER(args[15])
					);
				obj = new ofxNode_ofMatrix4x4(lMat);
			}
			else if (args.Length() == 1)
			{
				obj = new ofxNode_ofMatrix4x4(ofMatrix4x4(ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->self()));
			}
			else
			{
				//copy constructor like a BOSS!
				obj = new ofxNode_ofMatrix4x4(ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->internal_);
			}
			obj->Wrap(args.This());
			NanReturnValue(args.This());
		} else {
			// Invoked as plain function `MyObject(...)`, turn into construct call.
			std::vector<v8::Handle<v8::Value>> lArgvVec;
			for (int i = 0; i < args.Length(); ++i) {lArgvVec.push_back(args[i]);}
			NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(lArgvVec.size(), (lArgvVec.size()==0) ? nullptr : &lArgvVec[0]));
		}
	}

	void ofxNode_ofMatrix4x4::Init(v8::Handle<v8::Object> exports)
	{
		// Prepare constructor template
		auto tpl = NanNew<v8::FunctionTemplate>(New);
		tpl->SetClassName(NanNew("ofMatrix4x4"));
		
		auto inst = tpl->InstanceTemplate();
		inst->SetInternalFieldCount(1);
		inst->SetAccessor(NanNew("a00")	, GetA00 , SetA00);
		inst->SetAccessor(NanNew("a01")	, GetA01 , SetA01);
		inst->SetAccessor(NanNew("a02")	, GetA02 , SetA02);
		inst->SetAccessor(NanNew("a03")	, GetA03 , SetA03);
		inst->SetAccessor(NanNew("a10")	, GetA10 , SetA10);
		inst->SetAccessor(NanNew("a11")	, GetA11 , SetA11);
		inst->SetAccessor(NanNew("a12")	, GetA12 , SetA12);
		inst->SetAccessor(NanNew("a13")	, GetA13 , SetA13);
		inst->SetAccessor(NanNew("a20")	, GetA20 , SetA20);
		inst->SetAccessor(NanNew("a21")	, GetA21 , SetA21);
		inst->SetAccessor(NanNew("a22")	, GetA22 , SetA22);
		inst->SetAccessor(NanNew("a23")	, GetA23 , SetA23);
		inst->SetAccessor(NanNew("a30")	, GetA30 , SetA30);
		inst->SetAccessor(NanNew("a31")	, GetA31 , SetA31);
		inst->SetAccessor(NanNew("a32")	, GetA32 , SetA32);
		inst->SetAccessor(NanNew("a33")	, GetA33 , SetA33);


		NanSetPrototypeTemplate(tpl, NanNew("decompose"), NanNew<v8::FunctionTemplate>(Decompose), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getFrustum"), NanNew<v8::FunctionTemplate>(GetFrustum), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getInverse"), NanNew<v8::FunctionTemplate>(GetInverse), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getInverseOf"), NanNew<v8::FunctionTemplate>(GetInverseOf), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getLookAt"), NanNew<v8::FunctionTemplate>(GetLookAt), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getOrtho"), NanNew<v8::FunctionTemplate>(GetOrtho), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getOrthoNormalOf"), NanNew<v8::FunctionTemplate>(GetOrthoNormalOf), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getPerspective"), NanNew<v8::FunctionTemplate>(GetPerspective), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getPtr"), NanNew<v8::FunctionTemplate>(GetPtr), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getRotate"), NanNew<v8::FunctionTemplate>(GetRotate), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getRowAsVec3f"), NanNew<v8::FunctionTemplate>(GetRowAsVec3f), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getRowAsVec4f"), NanNew<v8::FunctionTemplate>(GetRowAsVec4f), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getScale"), NanNew<v8::FunctionTemplate>(GetScale), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getTranslation"), NanNew<v8::FunctionTemplate>(GetTranslation), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getTransposedOf"), NanNew<v8::FunctionTemplate>(GetTransposedOf), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("glRotate"), NanNew<v8::FunctionTemplate>(GlRotate), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("glRotateRad"), NanNew<v8::FunctionTemplate>(GlRotateRad), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("glScale"), NanNew<v8::FunctionTemplate>(GlScale), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("glTranslate"), NanNew<v8::FunctionTemplate>(GlTranslate), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("isIdentity"), NanNew<v8::FunctionTemplate>(IsIdentity), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("isNaN"), NanNew<v8::FunctionTemplate>(IsNaN), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("isValid"), NanNew<v8::FunctionTemplate>(IsValid), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeFromMultiplicationOf"), NanNew<v8::FunctionTemplate>(MakeFromMultiplicationOf), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeFrustumMatrix"), NanNew<v8::FunctionTemplate>(MakeFrustumMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeIdentityMatrix"), NanNew<v8::FunctionTemplate>(MakeIdentityMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeInvertOf"), NanNew<v8::FunctionTemplate>(MakeInvertOf), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeLookAtMatrix"), NanNew<v8::FunctionTemplate>(MakeLookAtMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeLookAtViewMatrix"), NanNew<v8::FunctionTemplate>(MakeLookAtViewMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeOrtho2DMatrix"), NanNew<v8::FunctionTemplate>(MakeOrtho2DMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeOrthoMatrix"), NanNew<v8::FunctionTemplate>(MakeOrthoMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeOrthoNormalOf"), NanNew<v8::FunctionTemplate>(MakeOrthoNormalOf), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makePerspectiveMatrix"), NanNew<v8::FunctionTemplate>(MakePerspectiveMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeRotationMatrix"), NanNew<v8::FunctionTemplate>(MakeRotationMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeScaleMatrix"), NanNew<v8::FunctionTemplate>(MakeScaleMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeTranslationMatrix"), NanNew<v8::FunctionTemplate>(MakeTranslationMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("newFrustumMatrix"), NanNew<v8::FunctionTemplate>(NewFrustumMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("newIdentityMatrix"), NanNew<v8::FunctionTemplate>(NewIdentityMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("newLookAtMatrix"), NanNew<v8::FunctionTemplate>(NewLookAtMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("newOrtho2DMatrix"), NanNew<v8::FunctionTemplate>(NewOrtho2DMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("newOrthoMatrix"), NanNew<v8::FunctionTemplate>(NewOrthoMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("newPerspectiveMatrix"), NanNew<v8::FunctionTemplate>(NewPerspectiveMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("newRotationMatrix"), NanNew<v8::FunctionTemplate>(NewRotationMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("newScaleMatrix"), NanNew<v8::FunctionTemplate>(NewScaleMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("newTranslationMatrix"), NanNew<v8::FunctionTemplate>(NewTranslationMatrix), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("postMult"), NanNew<v8::FunctionTemplate>(PostMult), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("postMultRotate"), NanNew<v8::FunctionTemplate>(PostMultRotate), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("postMultScale"), NanNew<v8::FunctionTemplate>(PostMultScale), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("postMultTranslate"), NanNew<v8::FunctionTemplate>(PostMultTranslate), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("preMult"), NanNew<v8::FunctionTemplate>(PreMult), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("preMultRotate"), NanNew<v8::FunctionTemplate>(PreMultRotate), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("preMultScale"), NanNew<v8::FunctionTemplate>(PreMultScale), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("preMultTranslate"), NanNew<v8::FunctionTemplate>(PreMultTranslate), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("rotate"), NanNew<v8::FunctionTemplate>(Rotate), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("rotateRad"), NanNew<v8::FunctionTemplate>(RotateRad), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("scale"), NanNew<v8::FunctionTemplate>(Scale), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("set"), NanNew<v8::FunctionTemplate>(Set), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setRotate"), NanNew<v8::FunctionTemplate>(SetRotate), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setTranslation"), NanNew<v8::FunctionTemplate>(SetTranslation), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("transform3x3"), NanNew<v8::FunctionTemplate>(Transform3x3), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("translate"), NanNew<v8::FunctionTemplate>(Translate), v8::ReadOnly);

		NanSetPrototypeTemplate(tpl, NanNew("toString"), NanNew<v8::FunctionTemplate>(ToString), v8::ReadOnly);

		NanSetPrototypeTemplate(tpl, NanNew("OFXNODE_TYPE"), NanNew(OFXNODE_TYPES::OFMATRIX4X4), v8::DontEnum);
		NanAssignPersistent(constructor, tpl->GetFunction());
		exports->Set(NanNew<v8::String>("ofMatrix4x4"), tpl->GetFunction());
	}

	DEFINE_GETTER_SETTER(0, 0);
	DEFINE_GETTER_SETTER(0, 1);
	DEFINE_GETTER_SETTER(0, 2);
	DEFINE_GETTER_SETTER(0, 3);
	DEFINE_GETTER_SETTER(1, 0);
	DEFINE_GETTER_SETTER(1, 1);
	DEFINE_GETTER_SETTER(1, 2);
	DEFINE_GETTER_SETTER(1, 3);
	DEFINE_GETTER_SETTER(2, 0);
	DEFINE_GETTER_SETTER(2, 1);
	DEFINE_GETTER_SETTER(2, 2);
	DEFINE_GETTER_SETTER(2, 3);
	DEFINE_GETTER_SETTER(3, 0);
	DEFINE_GETTER_SETTER(3, 1);
	DEFINE_GETTER_SETTER(3, 2);
	DEFINE_GETTER_SETTER(3, 3);


	NAN_METHOD(ofxNode_ofMatrix4x4::Decompose)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();

		ofVec3f translation, scale;
		ofQuaternion rotation, so;
		self.decompose(translation, rotation, scale, so);
		v8::Local<v8::Value> lArgvTranslation[] = {NanNew(translation.x), NanNew(translation.y), NanNew(translation.z)};
		v8::Local<v8::Value> lArgvRotation[] = {NanNew(rotation.x()), NanNew(rotation.y()), NanNew(rotation.z()), NanNew(rotation.w())};
		v8::Local<v8::Value> lArgvScale[] = {NanNew(scale.x), NanNew(scale.y), NanNew(scale.z)};
		v8::Local<v8::Value> lArgvSo[] = {NanNew(so.x()), NanNew(so.y()), NanNew(so.z()), NanNew(so.w())};
		auto toRet = NanNew<v8::Object>();
		toRet->Set(NanNew("translation"), NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgvTranslation));
		toRet->Set(NanNew("rotation"), NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(4, lArgvRotation));
		toRet->Set(NanNew("scale"), NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgvScale));
		toRet->Set(NanNew("so"), NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(4, lArgvSo));
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetFrustum)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		double left = 0,
			right = 0,
			bottom = 0,
			top = 0,
			zNear = 0,
			zFar = 0;
		bool success = self.getFrustum(left, right, bottom, top, zNear, zFar);
		auto toRet = NanNew<v8::Object>();
		toRet->Set(NanNew("success"), NanNew(success));
		toRet->Set(NanNew("left"), NanNew(left));
		toRet->Set(NanNew("right"), NanNew(right));
		toRet->Set(NanNew("bottom"), NanNew(bottom));
		toRet->Set(NanNew("top"), NanNew(top));
		toRet->Set(NanNew("zNear"), NanNew(zNear));
		toRet->Set(NanNew("zFar"), NanNew(zFar));
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetInverse)
	{
		auto toRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self().getInverse();
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetInverseOf)
	{
		auto toRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() = ofMatrix4x4::getInverseOf(node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self());
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetLookAt)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		ofVec3f eye, center, up;
		float lookDistance = args[0]->IsNumber() ? args[0]->NumberValue() : 1.0f;
		self.getLookAt(eye, center, up);
		v8::Local<v8::Value> lArgvEye[] = {NanNew(eye.x), NanNew(eye.y), NanNew(eye.z)};
		v8::Local<v8::Value> lArgvCenter[] = {NanNew(center.x), NanNew(center.y), NanNew(center.z)};
		v8::Local<v8::Value> lArgvUp[] = {NanNew(up.x), NanNew(up.y), NanNew(up.z)};
		auto toRet = NanNew<v8::Object>();
		toRet->Set(NanNew("eye"), NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgvEye));
		toRet->Set(NanNew("center"), NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgvCenter));
		toRet->Set(NanNew("up"), NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgvUp));
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetOrtho)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		double left = 0,
			right = 0,
			bottom = 0,
			top = 0,
			zNear = 0,
			zFar = 0;
		bool success = self.getOrtho(left, right, bottom, top, zNear, zFar);
		auto toRet = NanNew<v8::Object>();
		toRet->Set(NanNew("success"), NanNew(success));
		toRet->Set(NanNew("left"), NanNew(left));
		toRet->Set(NanNew("right"), NanNew(right));
		toRet->Set(NanNew("bottom"), NanNew(bottom));
		toRet->Set(NanNew("top"), NanNew(top));
		toRet->Set(NanNew("zNear"), NanNew(zNear));
		toRet->Set(NanNew("zFar"), NanNew(zFar));
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetOrthoNormalOf)
	{
		auto toRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() = ofMatrix4x4::getOrthoNormalOf(node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self());
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetPerspective)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		double fovy = 0,
			aspectRatio = 0,
			zNear = 0,
			zFar = 0;
		bool success = self.getPerspective(fovy, aspectRatio, zNear, zFar);
		auto toRet = NanNew<v8::Object>();
		toRet->Set(NanNew("fovy"), NanNew(fovy));
		toRet->Set(NanNew("aspectRatio"), NanNew(aspectRatio));
		toRet->Set(NanNew("zNear"), NanNew(zNear));
		toRet->Set(NanNew("zFar"), NanNew(zFar));
		toRet->Set(NanNew("success"), NanNew(success));
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetPtr)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		auto toRet = NanNew<v8::Array>();
		toRet->Set(0, NanNew(self._mat[0][0]));
		toRet->Set(1, NanNew(self._mat[0][1]));
		toRet->Set(2, NanNew(self._mat[0][2]));
		toRet->Set(3, NanNew(self._mat[0][3]));
		toRet->Set(4, NanNew(self._mat[1][0]));
		toRet->Set(5, NanNew(self._mat[1][1]));
		toRet->Set(6, NanNew(self._mat[1][2]));
		toRet->Set(7, NanNew(self._mat[1][3]));
		toRet->Set(8, NanNew(self._mat[2][0]));
		toRet->Set(9, NanNew(self._mat[2][1]));
		toRet->Set(10, NanNew(self._mat[2][2]));
		toRet->Set(11, NanNew(self._mat[2][3]));
		toRet->Set(12, NanNew(self._mat[3][0]));
		toRet->Set(13, NanNew(self._mat[3][1]));
		toRet->Set(14, NanNew(self._mat[3][2]));
		toRet->Set(15, NanNew(self._mat[3][3]));
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetRotate)
	{
		auto toRet = NanNew(ofxNode_ofQuaternion::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(toRet)->self() = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self().getRotate();
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetRowAsVec3f)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(toRet)->self() = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self().getRowAsVec3f(args[0]->NumberValue());
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetRowAsVec4f)
	{
		auto toRet = NanNew(ofxNode_ofVec4f::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofVec4f>(toRet)->self() = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self().getRowAsVec4f(args[0]->NumberValue());
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetScale)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(toRet)->self() = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self().getScale();
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetTranslation)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(toRet)->self() = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self().getTranslation();
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GetTransposedOf)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() = ofMatrix4x4::getTransposedOf(node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self());
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GlRotate)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 4)
		{
			self.glRotate(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]), V8_ARG_NUMBER(args[3]));
		}
		else
		{
			self.glRotate(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->self());
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GlRotateRad)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.glRotateRad(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]), V8_ARG_NUMBER(args[3]));
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GlScale)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 3)
		{
			self.glScale(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]));
		}
		else
		{
			self.glScale(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::GlTranslate)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 3)
		{
			self.glTranslate(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]));
		}
		else
		{
			self.glTranslate(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::IsIdentity)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		NanReturnValue(self.isIdentity());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::IsNaN)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		NanReturnValue(self.isNaN());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::IsValid)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		NanReturnValue(self.isValid());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakeFromMultiplicationOf)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.makeFromMultiplicationOf(
			node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[1]->ToObject())->self()
			);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakeFrustumMatrix)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.makeFrustumMatrix(
			V8_ARG_NUMBER(args[0]),
			V8_ARG_NUMBER(args[1]),
			V8_ARG_NUMBER(args[2]),
			V8_ARG_NUMBER(args[3]),
			V8_ARG_NUMBER(args[4]),
			V8_ARG_NUMBER(args[5])
			);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakeIdentityMatrix)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.makeIdentityMatrix();
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakeInvertOf)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		NanReturnValue(self.makeInvertOf(
			node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self()
			));
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakeLookAtMatrix)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.makeLookAtMatrix(
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[2]->ToObject())->self()
			);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakeLookAtViewMatrix)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.makeLookAtViewMatrix(
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[2]->ToObject())->self()
			);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakeOrtho2DMatrix)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.makeOrtho2DMatrix(
			V8_ARG_NUMBER(args[0]),
			V8_ARG_NUMBER(args[1]),
			V8_ARG_NUMBER(args[2]),
			V8_ARG_NUMBER(args[3])
			);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakeOrthoMatrix)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.makeOrthoMatrix(
			V8_ARG_NUMBER(args[0]),
			V8_ARG_NUMBER(args[1]),
			V8_ARG_NUMBER(args[2]),
			V8_ARG_NUMBER(args[3]),
			V8_ARG_NUMBER(args[4]),
			V8_ARG_NUMBER(args[5])
			);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakeOrthoNormalOf)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.makeOrthoNormalOf(node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakePerspectiveMatrix)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.makePerspectiveMatrix(
			V8_ARG_NUMBER(args[0]),
			V8_ARG_NUMBER(args[1]),
			V8_ARG_NUMBER(args[2]),
			V8_ARG_NUMBER(args[3])
			);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakeRotationMatrix)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 1)
		{
			self.makeRotationMatrix(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 2 && (args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F))
		{
			self.makeRotationMatrix(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self()
				);
		}
		else if (args.Length() == 2 && args[0]->IsNumber())
		{
			self.makeRotationMatrix(
				V8_ARG_NUMBER(args[0]),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self()
				);
		}
		else if (args.Length() == 4)
		{
			self.makeRotationMatrix(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3])
				);
		}
		else
		{
			self.makeRotationMatrix(
				V8_ARG_NUMBER(args[0]),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self(),
				V8_ARG_NUMBER(args[2]),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[3]->ToObject())->self(),
				V8_ARG_NUMBER(args[4]),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[5]->ToObject())->self()
				);
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakeScaleMatrix)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 1)
		{
			self.makeScaleMatrix(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else
		{
			self.makeScaleMatrix(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2])
				);
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::MakeTranslationMatrix)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 1)
		{
			self.makeTranslationMatrix(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else
		{
			self.makeTranslationMatrix(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2])
				);
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::NewFrustumMatrix)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newFrustumMatrix(
			V8_ARG_NUMBER(args[0]),
			V8_ARG_NUMBER(args[1]),
			V8_ARG_NUMBER(args[2]),
			V8_ARG_NUMBER(args[3]),
			V8_ARG_NUMBER(args[4]),
			V8_ARG_NUMBER(args[5])
			);
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::NewIdentityMatrix)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newIdentityMatrix();
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::NewLookAtMatrix)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newLookAtMatrix(
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[2]->ToObject())->self()
			);
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::NewOrtho2DMatrix)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newOrtho2DMatrix(
			V8_ARG_NUMBER(args[0]),
			V8_ARG_NUMBER(args[1]),
			V8_ARG_NUMBER(args[2]),
			V8_ARG_NUMBER(args[3])
			);
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::NewOrthoMatrix)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newOrthoMatrix(
			V8_ARG_NUMBER(args[0]),
			V8_ARG_NUMBER(args[1]),
			V8_ARG_NUMBER(args[2]),
			V8_ARG_NUMBER(args[3]),
			V8_ARG_NUMBER(args[4]),
			V8_ARG_NUMBER(args[5])
			);
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::NewPerspectiveMatrix)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newPerspectiveMatrix(
			V8_ARG_NUMBER(args[0]),
			V8_ARG_NUMBER(args[1]),
			V8_ARG_NUMBER(args[2]),
			V8_ARG_NUMBER(args[3])
			);
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::NewRotationMatrix)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		if (args.Length() == 1)
		{
			node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newRotationMatrix(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 2 && (args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F))
		{
			node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newRotationMatrix(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self()
				);
		}
		else if (args.Length() == 2 && args[0]->IsNumber())
		{
			node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newRotationMatrix(
				V8_ARG_NUMBER(args[0]),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self()
				);
		}
		else if (args.Length() == 4)
		{
			node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newRotationMatrix(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3])
				);
		}
		else
		{
			node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newRotationMatrix(
				V8_ARG_NUMBER(args[0]),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self(),
				V8_ARG_NUMBER(args[2]),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[3]->ToObject())->self(),
				V8_ARG_NUMBER(args[4]),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[5]->ToObject())->self()
				);
		}
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::NewScaleMatrix)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		if (args.Length() == 1)
		{
			node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newScaleMatrix(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else
		{
			node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newScaleMatrix(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2])
				);
		}
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::NewTranslationMatrix)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		if (args.Length() == 1)
		{
			node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newTranslationMatrix(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else
		{
			node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(toRet)->self() =  ofMatrix4x4::newTranslationMatrix(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2])
				);
		}
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::PostMult)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)
		{
			auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(toRet)->self() = self.postMult(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
			NanReturnValue(toRet);
		}
		else if (args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC4F)
		{
			auto toRet = NanNew(ofxNode_ofVec4f::factory())->NewInstance();
			node::ObjectWrap::Unwrap<ofxNode_ofVec4f>(toRet)->self() = self.postMult(node::ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->self());
			NanReturnValue(toRet);
		}
		else
		{
			self.postMult(node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self());
			NanReturnValue(args.This());
		}
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::PostMultRotate)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 1)
		{
			self.postMultRotate(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->self());
		}
		else
		{
			self.postMultRotate(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3])
				);
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::PostMultScale)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 1)
		{
			self.postMultScale(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else
		{
			self.postMultScale(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2])
				);
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::PostMultTranslate)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 1)
		{
			self.postMultTranslate(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else
		{
			self.postMultTranslate(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2])
				);
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::PreMult)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)
		{
			auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(toRet)->self() = self.preMult(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
			NanReturnValue(toRet);
		}
		else if (args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC4F)
		{
			auto toRet = NanNew(ofxNode_ofVec4f::factory())->NewInstance();
			node::ObjectWrap::Unwrap<ofxNode_ofVec4f>(toRet)->self() = self.preMult(node::ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->self());
			NanReturnValue(toRet);
		}
		else
		{
			self.preMult(node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self());
			NanReturnValue(args.This());
		}
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::PreMultRotate)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.preMultRotate(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->self());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::PreMultScale)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.preMultScale(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::PreMultTranslate)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.preMultTranslate(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::Rotate)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 1)
		{
			self.rotate(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->self());
		}
		else
		{
			self.rotate(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3])
				);
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::RotateRad)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.rotateRad(
			V8_ARG_NUMBER(args[0]),
			V8_ARG_NUMBER(args[1]),
			V8_ARG_NUMBER(args[2]),
			V8_ARG_NUMBER(args[3])
			);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::Scale)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 1)
		{
			self.scale(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else
		{
			self.scale(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2])
				);
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::Set)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 16)
		{
			self.set(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3]),
				V8_ARG_NUMBER(args[4]),
				V8_ARG_NUMBER(args[5]),
				V8_ARG_NUMBER(args[6]),
				V8_ARG_NUMBER(args[7]),
				V8_ARG_NUMBER(args[8]),
				V8_ARG_NUMBER(args[9]),
				V8_ARG_NUMBER(args[10]),
				V8_ARG_NUMBER(args[11]),
				V8_ARG_NUMBER(args[12]),
				V8_ARG_NUMBER(args[13]),
				V8_ARG_NUMBER(args[14]),
				V8_ARG_NUMBER(args[15])
				);
		}
		else
		{
			self.set(ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self());
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::SetRotate)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		self.setRotate(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->self());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::SetTranslation)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 1)
		{
			self.setTranslation(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else
		{
			self.setTranslation(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2])
				);
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::Transform3x3)
	{
		auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		if (args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFMATRIX4X4)
		{
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(toRet)->self() = ofMatrix4x4::transform3x3(
				node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self(),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self()
				);
		}
		else
		{
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(toRet)->self() = ofMatrix4x4::transform3x3(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self()				
				);
		}
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::Translate)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		if (args.Length() == 1)
		{
			self.translate(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else
		{
			self.translate(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2])
				);
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofMatrix4x4::ToString)
	{
		const auto& self = ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args.This())->self();
		std::ostringstream out;
		out << self;
		NanReturnValue( NanNew(out.str().c_str()) );
	}
} // !namespace ofxNode
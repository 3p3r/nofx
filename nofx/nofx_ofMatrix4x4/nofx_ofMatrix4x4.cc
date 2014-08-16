#include "nofx_ofMatrix4x4.h"
#include "..\nofx\nofx_types.h"
#include "..\nofx_ofVec4f\nofx_ofVec4f.h"
#include "..\nofx_ofVec3f\nofx_ofVec3f.h"
#include "..\nofx_ofQuaternion\nofx_ofQuaternion.h"
#include "..\nofx_pointer\nofx_pointer.h"

namespace nofx
{
	namespace OfMatrix4x4
	{
		using node::ObjectWrap;

		Persistent<Function> OfMatrix4x4Wrap::constructor;

		OfMatrix4x4Wrap::OfMatrix4x4Wrap()
			: internal_(nullptr)
		{}

		//--------------------------------------------------------------
		OfMatrix4x4Wrap::OfMatrix4x4Wrap(ofMatrix4x4* aInternal)
			: internal_(aInternal)
		{}

		//--------------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfMatrix4x4Wrap* obj;
				if (args[0]->IsNull())
				{
					obj = new OfMatrix4x4Wrap(nullptr);
				}
				else if (args.Length() == 0)
				{
					obj = new OfMatrix4x4Wrap(new ofMatrix4x4());
				}
				else if (args.Length() == 16)
				{
					obj = new OfMatrix4x4Wrap(new ofMatrix4x4(
						args[0]->NumberValue(),
						args[1]->NumberValue(),
						args[2]->NumberValue(),
						args[3]->NumberValue(),
						args[4]->NumberValue(),
						args[5]->NumberValue(),
						args[6]->NumberValue(),
						args[7]->NumberValue(),
						args[8]->NumberValue(),
						args[9]->NumberValue(),
						args[10]->NumberValue(),
						args[11]->NumberValue(),
						args[12]->NumberValue(),
						args[13]->NumberValue(),
						args[14]->NumberValue(),
						args[15]->NumberValue()
						));
				}
				else
				{
					//copy constructor
					obj = new OfMatrix4x4Wrap(ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped());
				}
				obj->Wrap(args.This());
				NanReturnValue(args.This());
			}
			else
			{
				// Invoked as plain function `MyObject(...)`, turn into construct call.
				std::vector<v8::Handle<v8::Value>> lArgvVec;
				for (int i = 0; i < args.Length(); ++i) { lArgvVec.push_back(args[i]); }
				NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(lArgvVec.size(), (lArgvVec.size() == 0) ? nullptr : &lArgvVec[0]));
			}
		}

		//--------------------------------------------------------------
		void OfMatrix4x4Wrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofMatrix4x4"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);

			inst->SetIndexedPropertyHandler(OfMatrix4x4Wrap::IndexGetter, OfMatrix4x4Wrap::IndexSetter);

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

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFMATRIX4X4), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofMatrix4x4"), tpl->GetFunction());
		}



		NAN_INDEX_GETTER(OfMatrix4x4Wrap::IndexGetter)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			auto JsVec4f = DepNewInstance(DEP_ofVec4f);
			ObjectWrap::Unwrap<nofx::OfVec4f::OfVec4fWrap>(JsVec4f->ToObject())->SetWrapped(&self->_mat[index]);
			NanReturnValue(JsVec4f);
		}
		NAN_INDEX_SETTER(OfMatrix4x4Wrap::IndexSetter)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			self->_mat[index].set(*ObjectWrap::Unwrap<nofx::OfVec4f::OfVec4fWrap>(value->ToObject())->GetWrapped());
		}


		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::Decompose)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			ofVec3f translation, scale;
			ofQuaternion rotation, so;
			
			auto JsTranslation = DepNewInstance(DEP_ofVec3f);
			auto JsScale = DepNewInstance(DEP_ofVec3f);
			auto JsRotation = DepNewInstance(DEP_ofQuaternion);
			auto JsSo = DepNewInstance(DEP_ofQuaternion);

			self->decompose(translation, rotation, scale, so);
			
			ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(JsTranslation->ToObject())->SetWrapped(translation);
			ObjectWrap::Unwrap<nofx::OfQuaternion::OfQuaternionWrap>(JsRotation->ToObject())->SetWrapped(rotation);
			ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(JsScale->ToObject())->SetWrapped(scale);
			ObjectWrap::Unwrap<nofx::OfQuaternion::OfQuaternionWrap>(JsSo->ToObject())->SetWrapped(so);

			auto toRet = NanNew<Array>();

			toRet->Set(NanNew("translation"), JsTranslation);
			toRet->Set(NanNew("rotation"), JsRotation);
			toRet->Set(NanNew("scale"), JsScale);
			toRet->Set(NanNew("so"), JsSo);

			NanReturnValue(toRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetFrustum)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			double left = 0,
				right = 0,
				bottom = 0,
				top = 0,
				zNear = 0,
				zFar = 0;
			if(self->getFrustum(left, right, bottom, top, zNear, zFar))
			{
				auto toRet = NanNew<Array>();
				toRet->Set(NanNew("left"), NanNew(left));
				toRet->Set(NanNew("right"), NanNew(right));
				toRet->Set(NanNew("bottom"), NanNew(bottom));
				toRet->Set(NanNew("top"), NanNew(top));
				toRet->Set(NanNew("zNear"), NanNew(zNear));
				toRet->Set(NanNew("zFar"), NanNew(zFar));
				NanReturnValue(toRet);
			}
			else
			{
				NanReturnValue(false);
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetInverse)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			auto toRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfMatrix4x4Wrap>(toRet)->SetWrapped(self->getInverse());
			NanReturnValue(toRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetInverseOf)
		{
			auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			auto toRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfMatrix4x4Wrap>(toRet)->SetWrapped(ofMatrix4x4::getInverseOf(*target));
			NanReturnValue(toRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetLookAt)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			ofVec3f eye, center, up;
			float lookDistance = args[0]->IsNumber() ? args[0]->NumberValue() : 1.0f;
			self->getLookAt(eye, center, up);
			
			auto JsEye = DepNewInstance(DEP_ofVec3f);
			auto JsCenter = DepNewInstance(DEP_ofVec3f);
			auto JsUp = DepNewInstance(DEP_ofVec3f);

			ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(JsEye->ToObject())->SetWrapped(eye);
			ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(JsCenter->ToObject())->SetWrapped(center);
			ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(JsUp->ToObject())->SetWrapped(up);

			auto toRet = NanNew<Array>();
			toRet->Set(NanNew("eye"), JsEye);
			toRet->Set(NanNew("center"), JsCenter);
			toRet->Set(NanNew("up"), JsUp);

			NanReturnValue(toRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetOrtho)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			double left = 0,
				right = 0,
				bottom = 0,
				top = 0,
				zNear = 0,
				zFar = 0;
			if(self->getOrtho(left, right, bottom, top, zNear, zFar))
			{
				auto toRet = NanNew<Array>();
				toRet->Set(NanNew("left"), NanNew(left));
				toRet->Set(NanNew("right"), NanNew(right));
				toRet->Set(NanNew("bottom"), NanNew(bottom));
				toRet->Set(NanNew("top"), NanNew(top));
				toRet->Set(NanNew("zNear"), NanNew(zNear));
				toRet->Set(NanNew("zFar"), NanNew(zFar));
				NanReturnValue(toRet);
			}
			else
			{
				NanReturnValue(false);
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetOrthoNormalOf)
		{
			auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			auto toRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfMatrix4x4Wrap>(toRet)->SetWrapped(ofMatrix4x4::getOrthoNormalOf(*target));
			NanReturnValue(toRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetPerspective)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			double fovy = 0,
				aspectRatio = 0,
				zNear = 0,
				zFar = 0;
			if (self->getPerspective(fovy, aspectRatio, zNear, zFar))
			{
				auto toRet = NanNew<Array>();
				toRet->Set(NanNew("fovy"), NanNew(fovy));
				toRet->Set(NanNew("aspectRatio"), NanNew(aspectRatio));
				toRet->Set(NanNew("zNear"), NanNew(zNear));
				toRet->Set(NanNew("zFar"), NanNew(zFar));
				NanReturnValue(toRet);
			}
			else
			{
				NanReturnValue(false);
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetPtr)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			auto JsPtr = DepNewInstance(DEP_floatPtr);
			auto CppBridge = ObjectWrap::Unwrap<nofx::Pointer::PointerWrap<float>>(JsPtr->ToObject());
			CppBridge->SetDisplayLength(16);
			CppBridge->SetWrapped(self->getPtr());
			NanReturnValue(JsPtr);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetRotate)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetRowAsVec3f)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetRowAsVec4f)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetScale)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetTranslation)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GetTransposedOf)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GlRotate)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GlRotateRad)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GlScale)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::GlTranslate)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::IsIdentity)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::IsNaN)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::IsValid)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakeFromMultiplicationOf)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakeFrustumMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakeIdentityMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakeInvertOf)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakeLookAtMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakeLookAtViewMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakeOrtho2DMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakeOrthoMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakeOrthoNormalOf)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakePerspectiveMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakeRotationMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakeScaleMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::MakeTranslationMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::NewFrustumMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::NewIdentityMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::NewLookAtMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::NewOrtho2DMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::NewOrthoMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::NewPerspectiveMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::NewRotationMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::NewScaleMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::NewTranslationMatrix)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::PostMult)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::PostMultRotate)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::PostMultScale)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::PostMultTranslate)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::PreMult)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::PreMultRotate)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::PreMultScale)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::PreMultTranslate)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::Rotate)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::RotateRad)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::Scale)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::Set)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::SetRotate)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::SetTranslation)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::Transform3x3)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix4x4Wrap::Translate)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args.This())->GetWrapped();
			//auto target = ObjectWrap::Unwrap<OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped();
			//implementation
			NanReturnUndefined();
		}

	} //!namespace OfMatrix4x4
} //!namespace nofx
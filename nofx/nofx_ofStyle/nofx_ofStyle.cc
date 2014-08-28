#include "nofx_ofStyle.h"
#include "..\nofx\nofx_types.h"
#include "..\nofx_ofColor\nofx_ofColor.h"

namespace nofx
{
	namespace ClassWrappers
	{
		using node::ObjectWrap;

		Persistent<Function> OfStyleWrap::constructor;

		//--------------------------------------------------------------
		NAN_METHOD(OfStyleWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfStyleWrap* obj;
				if (args[0]->IsNull())
				{
					obj = new OfStyleWrap(nullptr);
				}
				else if (args.Length() == 0)
				{
					obj = new OfStyleWrap(new ofStyle());
				}
				else
				{
					//copy constructor
					obj = new OfStyleWrap(ObjectWrap::Unwrap<OfStyleWrap>(args[0]->ToObject())->GetWrapped());
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
		void OfStyleWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofStyle"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);


			inst->SetAccessor(NanNew("bFill"), OfStyleWrap::GetBFill, OfStyleWrap::SetBFill);
			inst->SetAccessor(NanNew("bgColor"), OfStyleWrap::GetBgColor, OfStyleWrap::SetBgColor);
			inst->SetAccessor(NanNew("blendingMode"), OfStyleWrap::GetBlendingMode, OfStyleWrap::SetBlendingMode);
			inst->SetAccessor(NanNew("circleResolution"), OfStyleWrap::GetCircleResolution, OfStyleWrap::SetCircleResolution);
			inst->SetAccessor(NanNew("color"), OfStyleWrap::GetColor, OfStyleWrap::SetColor);
			inst->SetAccessor(NanNew("curveResolution"), OfStyleWrap::GetCurveResolution, OfStyleWrap::SetCurveResolution);
			inst->SetAccessor(NanNew("drawBitmapMode"), OfStyleWrap::GetDrawBitmapMode, OfStyleWrap::SetDrawBitmapMode);
			inst->SetAccessor(NanNew("lineWidth"), OfStyleWrap::GetLineWidth, OfStyleWrap::SetLineWidth);
			inst->SetAccessor(NanNew("polyMode"), OfStyleWrap::GetPolyMode, OfStyleWrap::SetPolyMode);
			inst->SetAccessor(NanNew("rectMode"), OfStyleWrap::GetRectMode, OfStyleWrap::SetRectMode);
			inst->SetAccessor(NanNew("smoothing"), OfStyleWrap::GetSmoothing, OfStyleWrap::SetSmoothing);
			inst->SetAccessor(NanNew("sphereResolution"), OfStyleWrap::GetSphereResolution, OfStyleWrap::SetSphereResolution);


			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFSTYLE), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofStyle"), tpl->GetFunction());
		}


		NAN_GETTER(OfStyleWrap::GetBFill)
		{
			const auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->bFill);
		}
		//----------------------------------------------------

		NAN_GETTER(OfStyleWrap::GetBgColor)
		{
			const auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			auto JsColor = DepNewInstance(DEP_ofColor);
			node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfColorWrap>(JsColor->ToObject())->SetWrapped(self->bgColor);
			NanReturnValue(JsColor);
		}
		//----------------------------------------------------

		NAN_GETTER(OfStyleWrap::GetBlendingMode)
		{
			const auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->blendingMode);
		}
		//----------------------------------------------------

		NAN_GETTER(OfStyleWrap::GetCircleResolution)
		{
			const auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->circleResolution);
		}
		//----------------------------------------------------

		NAN_GETTER(OfStyleWrap::GetColor)
		{
			const auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			auto JsColor = DepNewInstance(DEP_ofColor);
			node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfColorWrap>(JsColor->ToObject())->SetWrapped(self->color);
			NanReturnValue(JsColor);
		}
		//----------------------------------------------------

		NAN_GETTER(OfStyleWrap::GetCurveResolution)
		{
			const auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->curveResolution);
		}
		//----------------------------------------------------

		NAN_GETTER(OfStyleWrap::GetDrawBitmapMode)
		{
			const auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->drawBitmapMode);
		}
		//----------------------------------------------------

		NAN_GETTER(OfStyleWrap::GetLineWidth)
		{
			const auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->lineWidth);
		}
		//----------------------------------------------------

		NAN_GETTER(OfStyleWrap::GetPolyMode)
		{
			const auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->polyMode);
		}
		//----------------------------------------------------

		NAN_GETTER(OfStyleWrap::GetRectMode)
		{
			const auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->rectMode);
		}
		//----------------------------------------------------

		NAN_GETTER(OfStyleWrap::GetSmoothing)
		{
			const auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->smoothing);
		}
		//----------------------------------------------------

		NAN_GETTER(OfStyleWrap::GetSphereResolution)
		{
			const auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->sphereResolution);
		}
		//----------------------------------------------------


		NAN_SETTER(OfStyleWrap::SetBFill)
		{
			auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			self->bFill = value->BooleanValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfStyleWrap::SetBgColor)
		{
			auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			self->bgColor.set(*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfColorWrap>(value->ToObject())->GetWrapped());
		}
		//----------------------------------------------------

		NAN_SETTER(OfStyleWrap::SetBlendingMode)
		{
			auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			self->blendingMode = static_cast<ofBlendMode>(value->Uint32Value());
		}
		//----------------------------------------------------

		NAN_SETTER(OfStyleWrap::SetCircleResolution)
		{
			auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			self->circleResolution = value->Int32Value();
		}
		//----------------------------------------------------

		NAN_SETTER(OfStyleWrap::SetColor)
		{
			auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			self->color.set(*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfColorWrap>(value->ToObject())->GetWrapped());
		}
		//----------------------------------------------------

		NAN_SETTER(OfStyleWrap::SetCurveResolution)
		{
			auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			self->curveResolution = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfStyleWrap::SetDrawBitmapMode)
		{
			auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			self->drawBitmapMode = static_cast<ofDrawBitmapMode>(value->Uint32Value());
		}
		//----------------------------------------------------

		NAN_SETTER(OfStyleWrap::SetLineWidth)
		{
			auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			self->lineWidth = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfStyleWrap::SetPolyMode)
		{
			auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			self->polyMode = static_cast<ofPolyWindingMode>(value->Uint32Value());
		}
		//----------------------------------------------------

		NAN_SETTER(OfStyleWrap::SetRectMode)
		{
			auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			self->rectMode = static_cast<ofRectMode>(value->Uint32Value());
		}
		//----------------------------------------------------

		NAN_SETTER(OfStyleWrap::SetSmoothing)
		{
			auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			self->smoothing = value->BooleanValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfStyleWrap::SetSphereResolution)
		{
			auto self = ObjectWrap::Unwrap<OfStyleWrap>(args.This())->GetWrapped();
			self->sphereResolution = value->Int32Value();
		}
		//----------------------------------------------------


	} //!namespace ClassWrappers
} //!namespace nofx
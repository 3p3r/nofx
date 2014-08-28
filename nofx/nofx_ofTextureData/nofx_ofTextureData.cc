#include "nofx_ofTextureData.h"
#include "..\nofx\nofx_types.h"

namespace nofx
{
	namespace ClassWrappers
	{
		using node::ObjectWrap;

		Persistent<Function> OfTextureDataWrap::constructor;

		//--------------------------------------------------------------
		NAN_METHOD(OfTextureDataWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfTextureDataWrap* obj;
				if (args[0]->IsNull())
				{
					obj = new OfTextureDataWrap(nullptr);
				}
				else if (args.Length() == 0)
				{
					obj = new OfTextureDataWrap(new ofTextureData());
				}
				else
				{
					//copy constructor
					obj = new OfTextureDataWrap(ObjectWrap::Unwrap<OfTextureDataWrap>(args[0]->ToObject())->GetWrapped());
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
		void OfTextureDataWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofTextureData"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);

			inst->SetAccessor(NanNew("bAllocated"), OfTextureDataWrap::GetBAllocated, OfTextureDataWrap::SetBAllocated);
			inst->SetAccessor(NanNew("bFlipTexture"), OfTextureDataWrap::GetBFlipTexture, OfTextureDataWrap::SetBFlipTexture);
			inst->SetAccessor(NanNew("compressionType"), OfTextureDataWrap::GetCompressionType, OfTextureDataWrap::SetCompressionType);
			inst->SetAccessor(NanNew("glTypeInternal"), OfTextureDataWrap::GetGlTypeInternal, OfTextureDataWrap::SetGlTypeInternal);
			inst->SetAccessor(NanNew("height"), OfTextureDataWrap::GetHeight, OfTextureDataWrap::SetHeight);
			inst->SetAccessor(NanNew("tex_h"), OfTextureDataWrap::GetTex_h, OfTextureDataWrap::SetTex_h);
			inst->SetAccessor(NanNew("tex_t"), OfTextureDataWrap::GetTex_t, OfTextureDataWrap::SetTex_t);
			inst->SetAccessor(NanNew("tex_u"), OfTextureDataWrap::GetTex_u, OfTextureDataWrap::SetTex_u);
			inst->SetAccessor(NanNew("tex_w"), OfTextureDataWrap::GetTex_w, OfTextureDataWrap::SetTex_w);
			inst->SetAccessor(NanNew("textureID"), OfTextureDataWrap::GetTextureID, OfTextureDataWrap::SetTextureID);
			inst->SetAccessor(NanNew("textureTarget"), OfTextureDataWrap::GetTextureTarget, OfTextureDataWrap::SetTextureTarget);
			inst->SetAccessor(NanNew("width"), OfTextureDataWrap::GetWidth, OfTextureDataWrap::SetWidth);


			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFTEXTUREDATA), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofTextureData"), tpl->GetFunction());
		}


		NAN_GETTER(OfTextureDataWrap::GetBAllocated)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			NanReturnValue(self->bAllocated);
		}
		//----------------------------------------------------

		NAN_GETTER(OfTextureDataWrap::GetBFlipTexture)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			NanReturnValue(self->bFlipTexture);
		}
		//----------------------------------------------------

		NAN_GETTER(OfTextureDataWrap::GetCompressionType)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			NanReturnValue(self->compressionType);
		}
		//----------------------------------------------------

		NAN_GETTER(OfTextureDataWrap::GetGlTypeInternal)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			NanReturnValue(self->glTypeInternal);
		}
		//----------------------------------------------------

		NAN_GETTER(OfTextureDataWrap::GetHeight)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			NanReturnValue(self->height);
		}
		//----------------------------------------------------

		NAN_GETTER(OfTextureDataWrap::GetTex_h)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			NanReturnValue(self->tex_h);
		}
		//----------------------------------------------------

		NAN_GETTER(OfTextureDataWrap::GetTex_t)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			NanReturnValue(self->tex_t);
		}
		//----------------------------------------------------

		NAN_GETTER(OfTextureDataWrap::GetTex_u)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			NanReturnValue(self->tex_u);
		}
		//----------------------------------------------------

		NAN_GETTER(OfTextureDataWrap::GetTex_w)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			NanReturnValue(self->tex_w);
		}
		//----------------------------------------------------

		NAN_GETTER(OfTextureDataWrap::GetTextureID)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			NanReturnValue(self->textureID);
		}
		//----------------------------------------------------

		NAN_GETTER(OfTextureDataWrap::GetTextureTarget)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			NanReturnValue(self->textureTarget);
		}
		//----------------------------------------------------

		NAN_GETTER(OfTextureDataWrap::GetWidth)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			NanReturnValue(self->width);
		}
		//----------------------------------------------------


		NAN_SETTER(OfTextureDataWrap::SetBAllocated)
		{
			auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			self->bAllocated = value->BooleanValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfTextureDataWrap::SetBFlipTexture)
		{
			auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			self->bFlipTexture = value->BooleanValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfTextureDataWrap::SetCompressionType)
		{
			auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			self->compressionType = static_cast<ofTexCompression>(value->Int32Value());
		}
		//----------------------------------------------------

		NAN_SETTER(OfTextureDataWrap::SetGlTypeInternal)
		{
			auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			self->glTypeInternal = value->Int32Value();
		}
		//----------------------------------------------------

		NAN_SETTER(OfTextureDataWrap::SetHeight)
		{
			auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			self->height = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfTextureDataWrap::SetTex_h)
		{
			auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			self->tex_h = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfTextureDataWrap::SetTex_t)
		{
			auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			self->tex_t = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfTextureDataWrap::SetTex_u)
		{
			auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			self->tex_u = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfTextureDataWrap::SetTex_w)
		{
			auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			self->tex_w = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfTextureDataWrap::SetTextureID)
		{
			auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			self->textureID = value->Uint32Value();
		}
		//----------------------------------------------------

		NAN_SETTER(OfTextureDataWrap::SetTextureTarget)
		{
			auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			self->textureTarget = value->Int32Value();
		}
		//----------------------------------------------------

		NAN_SETTER(OfTextureDataWrap::SetWidth)
		{
			auto self = ObjectWrap::Unwrap<OfTextureDataWrap>(args.This())->GetWrapped();
			self->width = value->NumberValue();
		}
		//----------------------------------------------------


	} //!namespace ClassWrappers
} //!namespace nofx
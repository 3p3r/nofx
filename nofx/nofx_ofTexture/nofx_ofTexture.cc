#include "nofx_ofTexture.h"
#include "..\nofx\nofx_types.h"
#include "..\nofx_ofTextureData\nofx_ofTextureData.h"
#include "..\nofx_ofPixels\nofx_ofPixels.h"
#include "..\nofx_ofRectangle\nofx_ofRectangle.h"
#include "..\nofx_ofVec3f\nofx_ofVec3f.h"
#include "..\nofx_pointer\nofx_pointer.h"

namespace nofx
{
	namespace OfTexture
	{
		using node::ObjectWrap;

		Persistent<Function> OfTextureWrap::constructor;

		//--------------------------------------------------------------
		NAN_METHOD(OfTextureWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfTextureWrap* obj;
				if (args.Length() == 0)
				{
					//obj = new OfTextureWrap(); //implement me
				}
				else if (args[0]->IsNull())
				{
					obj = new OfTextureWrap(nullptr);
				}
				else
				{
					//copy constructor
					obj = new OfTextureWrap(ObjectWrap::Unwrap<OfTextureWrap>(args[0]->ToObject())->GetWrapped());
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
		void OfTextureWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofTexture"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);

			NanSetPrototypeTemplate(tpl, NanNew("allocate"), NanNew<v8::FunctionTemplate>(Allocate), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("bAllocated"), NanNew<v8::FunctionTemplate>(BAllocated), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("clear"), NanNew<v8::FunctionTemplate>(Clear), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("draw"), NanNew<v8::FunctionTemplate>(Draw), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("drawSubsection"), NanNew<v8::FunctionTemplate>(DrawSubsection), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getCoordFromPercent"), NanNew<v8::FunctionTemplate>(GetCoordFromPercent), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getCoordFromPoint"), NanNew<v8::FunctionTemplate>(GetCoordFromPoint), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getHeight"), NanNew<v8::FunctionTemplate>(GetHeight), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getTextureData"), NanNew<v8::FunctionTemplate>(GetTextureData), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getWidth"), NanNew<v8::FunctionTemplate>(GetWidth), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isAllocated"), NanNew<v8::FunctionTemplate>(IsAllocated), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("loadData"), NanNew<v8::FunctionTemplate>(LoadData), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("loadScreenData"), NanNew<v8::FunctionTemplate>(LoadScreenData), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("readToPixels"), NanNew<v8::FunctionTemplate>(ReadToPixels), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setAnchorPoint"), NanNew<v8::FunctionTemplate>(SetAnchorPoint), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setCompression"), NanNew<v8::FunctionTemplate>(SetCompression), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setRGToRGBASwizzles"), NanNew<v8::FunctionTemplate>(SetRGToRGBASwizzles), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setTextureMinMagFilter"), NanNew<v8::FunctionTemplate>(SetTextureMinMagFilter), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setTextureWrap"), NanNew<v8::FunctionTemplate>(SetTextureWrap), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setUseExternalTextureID"), NanNew<v8::FunctionTemplate>(SetUseExternalTextureID), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFTEXTURE), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofTexture"), tpl->GetFunction());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::Allocate)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();

			if (args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFTEXTUREDATA)
			{
				self->allocate(*ObjectWrap::Unwrap<nofx::OfTextureData::OfTextureDataWrap>(args[0]->ToObject())->GetWrapped());
			}
			else if (args.Length() == 1)
			{
				self->allocate(*ObjectWrap::Unwrap<nofx::OfPixels::OfPixelsWrap>(args[0]->ToObject())->GetWrapped());
			}
			else if (args.Length() == 2)
			{
				self->allocate(*ObjectWrap::Unwrap<nofx::OfPixels::OfPixelsWrap>(args[0]->ToObject())->GetWrapped(), args[1]->BooleanValue());
			}
			else if (args.Length() == 3)
			{
				self->allocate(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value());
			}
			else if (args.Length() == 4)
			{
				self->allocate(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value(), args[3]->BooleanValue());
			}
			else if (args.Length() == 5)
			{
				self->allocate(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value(), args[3]->BooleanValue(), args[4]->Int32Value());
			}
			else if (args.Length() == 6)
			{
				self->allocate(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value(), args[3]->BooleanValue(), args[4]->Int32Value(), args[5]->Int32Value());
			}

			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::BAllocated)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			NanReturnValue(self->bAllocated());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::Clear)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			self->clear();
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::Draw)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();

			if (args.Length() == 1)
			{
				if (args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFRECTANGLE)
				{
					self->draw(*ObjectWrap::Unwrap<nofx::OfRectangle::OfRectangleWrap>(args[0]->ToObject())->GetWrapped());
				}
				else
				{
					self->draw(*ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(args[0]->ToObject())->GetWrapped());
				}
			}
			else if (args.Length() == 2)
			{
				self->draw(args[0]->NumberValue(), args[1]->NumberValue());
			}
			else if (args.Length() == 3)
			{
				if (args[0]->IsNumber())
				{
					self->draw(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
				}
				else
				{
					self->draw(*ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(args[0]->ToObject())->GetWrapped()
						, args[1]->NumberValue(), args[2]->NumberValue());
				}
			}
			else if (args.Length() == 4)
			{
				if (args[0]->IsNumber())
				{
					self->draw(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
				}
				else
				{
					self->draw(
						*ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
						*ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(args[1]->ToObject())->GetWrapped(),
						*ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(args[2]->ToObject())->GetWrapped(),
						*ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(args[3]->ToObject())->GetWrapped());
				}
			}
			else if (args.Length() == 5)
			{
				self->draw(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue(), args[4]->NumberValue());
			}

			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::DrawSubsection)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();

			if (args.Length() == 6)
			{
				self->drawSubsection(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue(),
					args[3]->NumberValue(),
					args[4]->NumberValue(),
					args[5]->NumberValue());
			}
			else if (args.Length() == 7)
			{
				self->drawSubsection(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue(),
					args[3]->NumberValue(),
					args[4]->NumberValue(),
					args[5]->NumberValue(),
					args[6]->NumberValue());
			}
			else if (args.Length() == 8)
			{
				self->drawSubsection(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue(),
					args[3]->NumberValue(),
					args[4]->NumberValue(),
					args[5]->NumberValue(),
					args[6]->NumberValue(),
					args[7]->NumberValue());
			}
			else
			{
				self->drawSubsection(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue(),
					args[3]->NumberValue(),
					args[4]->NumberValue(),
					args[5]->NumberValue(),
					args[6]->NumberValue(),
					args[7]->NumberValue(),
					args[8]->NumberValue());
			}

			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::GetCoordFromPercent)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			auto JsVec = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(JsVec->ToObject())->SetWrapped(
				self->getCoordFromPercent(args[0]->NumberValue(), args[1]->NumberValue()));
			NanReturnValue(JsVec);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::GetCoordFromPoint)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			auto JsVec = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(JsVec->ToObject())->SetWrapped(
				self->getCoordFromPoint(args[0]->NumberValue(), args[1]->NumberValue()));
			NanReturnValue(JsVec);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::GetHeight)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getHeight());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::GetTextureData)
		{
			const auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			auto JsTexData = DepNewInstance(DEP_ofTextureData);
			ObjectWrap::Unwrap<nofx::OfTextureData::OfTextureDataWrap>(JsTexData->ToObject())->SetWrapped(self->getTextureData());
			NanReturnValue(JsTexData);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::GetWidth)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getWidth());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::IsAllocated)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			NanReturnValue(self->isAllocated());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::LoadData)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			if (args.Length() == 1)
			{
				self->loadData(*ObjectWrap::Unwrap<nofx::OfPixels::OfPixelsWrap>(args[0]->ToObject())->GetWrapped());
			}
			else if (args.Length() == 2)
			{
				self->loadData(*ObjectWrap::Unwrap<nofx::OfPixels::OfPixelsWrap>(args[0]->ToObject())->GetWrapped(), args[1]->Int32Value());
			}
			else
			{
				if (args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::FLOATPTR)
				{
					self->loadData(ObjectWrap::Unwrap<nofx::Pointer::RawPointerWrap<float>>(args[0]->ToObject())->GetWrapped(),
						args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value());
				}
				else if (args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::UNSIGNEDCHARPTR)
				{
					self->loadData(ObjectWrap::Unwrap<nofx::Pointer::RawPointerWrap<unsigned char>>(args[0]->ToObject())->GetWrapped(),
						args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value());
				}
				else if (args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::UNSIGNEDSHORTPTR)
				{
					self->loadData(ObjectWrap::Unwrap<nofx::Pointer::RawPointerWrap<unsigned short>>(args[0]->ToObject())->GetWrapped(),
						args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value());
				}
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::LoadScreenData)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			self->loadScreenData(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::ReadToPixels)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			self->readToPixels(*ObjectWrap::Unwrap<nofx::OfPixels::OfPixelsWrap>(args[0]->ToObject())->GetWrapped());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::SetAnchorPoint)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			self->setAnchorPoint(args[0]->NumberValue(), args[1]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::SetCompression)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			self->setCompression(static_cast<ofTexCompression>(args[0]->Int32Value()));
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::SetRGToRGBASwizzles)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			self->setRGToRGBASwizzles(args[0]->BooleanValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::SetTextureMinMagFilter)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			self->setTextureMinMagFilter(static_cast<GLint>(args[0]->Int32Value()), static_cast<GLint>(args[1]->Int32Value()));
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::SetTextureWrap)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			self->setTextureWrap(static_cast<GLint>(args[0]->Int32Value()), static_cast<GLint>(args[1]->Int32Value()));
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfTextureWrap::SetUseExternalTextureID)
		{
			auto self = ObjectWrap::Unwrap<OfTextureWrap>(args.This())->GetWrapped();
			self->setUseExternalTextureID(static_cast<GLuint>(args[0]->Int32Value()));
			NanReturnUndefined();
		}

	} //!namespace OfTexture
} //!namespace nofx
#include "nofx_ofImage.h"
#include "..\nofx\nofx_types.h"
#include "..\nofx_ofColor\nofx_ofColor.h"
#include "..\nofx_ofPixels\nofx_ofPixels.h"
#include "..\nofx_ofTexture\nofx_ofTexture.h"
#include "..\nofx_ofFile\nofx_ofFile.h"
#include "..\nofx_ofVec3f\nofx_ofVec3f.h"
#include "..\nofx_ofRectangle\nofx_ofRectangle.h"
#include "..\nofx_pointer\nofx_pointer.h"
#include "..\nofx_ofBuffer\nofx_ofBuffer.h"

namespace nofx
{
	namespace ClassWrappers
	{
		using node::ObjectWrap;

		Persistent<Function> OfImageWrap::constructor;

		NAN_METHOD(OfImageWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfImageWrap* obj;
				if (args[0]->IsNull())
				{
					obj = new OfImageWrap(nullptr);
				}
				else if (args.Length() == 0)
				{
					obj = new OfImageWrap();
				}
				else if (args.Length() == 1)
				{
					if (args[0]->IsString())
					{
						obj = new OfImageWrap(new ofImage(*NanUtf8String(args[0])));
					}
					else if (args[0]->IsObject() && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFFILE)
					{
						obj = new OfImageWrap(new ofImage(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfFileWrap>(args[0]->ToObject())->GetWrapped()));
					}
					else if (args[0]->IsObject() && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFPIXELS)
					{
						obj = new OfImageWrap(new ofImage(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfPixelsWrap>(args[0]->ToObject())->GetWrapped()));
					}
					else if (args[0]->IsObject() && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFIMAGE)
					{
						obj = new OfImageWrap(ObjectWrap::Unwrap<OfImageWrap>(args[0]->ToObject())->GetWrapped());
					}
				}
				else
				{
					//copy constructor
					obj = new OfImageWrap(ObjectWrap::Unwrap<OfImageWrap>(args[0]->ToObject())->GetWrapped());
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
		void OfImageWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofImage"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);


			inst->SetAccessor(NanNew("bpp"), OfImageWrap::GetBpp, OfImageWrap::SetBpp);
			inst->SetAccessor(NanNew("height"), OfImageWrap::GetHeight, OfImageWrap::SetHeight);
			inst->SetAccessor(NanNew("type"), OfImageWrap::GetType, OfImageWrap::SetType);
			inst->SetAccessor(NanNew("width"), OfImageWrap::GetWidth, OfImageWrap::SetWidth);

			NanSetPrototypeTemplate(tpl, NanNew("allocate"), NanNew<v8::FunctionTemplate>(Allocate), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("bAllocated"), NanNew<v8::FunctionTemplate>(BAllocated), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("bind"), NanNew<v8::FunctionTemplate>(Bind), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("clear"), NanNew<v8::FunctionTemplate>(Clear), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("clone"), NanNew<v8::FunctionTemplate>(Clone), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("crop"), NanNew<v8::FunctionTemplate>(Crop), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("cropFrom"), NanNew<v8::FunctionTemplate>(CropFrom), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("draw"), NanNew<v8::FunctionTemplate>(Draw), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("drawSubsection"), NanNew<v8::FunctionTemplate>(DrawSubsection), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getColor"), NanNew<v8::FunctionTemplate>(GetColor), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getHeight"), NanNew<v8::FunctionTemplate>(GetHeight), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPixels"), NanNew<v8::FunctionTemplate>(GetPixels), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPixelsRef"), NanNew<v8::FunctionTemplate>(GetPixelsRef), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getTextureReference"), NanNew<v8::FunctionTemplate>(GetTextureReference), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getWidth"), NanNew<v8::FunctionTemplate>(GetWidth), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("grabScreen"), NanNew<v8::FunctionTemplate>(GrabScreen), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isAllocated"), NanNew<v8::FunctionTemplate>(IsAllocated), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isUsingTexture"), NanNew<v8::FunctionTemplate>(IsUsingTexture), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("loadImage"), NanNew<v8::FunctionTemplate>(LoadImage), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("mirror"), NanNew<v8::FunctionTemplate>(Mirror), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("reloadTexture"), NanNew<v8::FunctionTemplate>(ReloadTexture), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("resetAnchor"), NanNew<v8::FunctionTemplate>(ResetAnchor), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("resize"), NanNew<v8::FunctionTemplate>(Resize), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("rotate90"), NanNew<v8::FunctionTemplate>(Rotate90), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("saveImage"), NanNew<v8::FunctionTemplate>(SaveImage), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setAnchorPercent"), NanNew<v8::FunctionTemplate>(SetAnchorPercent), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setAnchorPoint"), NanNew<v8::FunctionTemplate>(SetAnchorPoint), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setColor"), NanNew<v8::FunctionTemplate>(SetColor), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setCompression"), NanNew<v8::FunctionTemplate>(SetCompression), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setFromPixels"), NanNew<v8::FunctionTemplate>(SetFromPixels), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setImageType"), NanNew<v8::FunctionTemplate>(SetImageType), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setUseTexture"), NanNew<v8::FunctionTemplate>(SetUseTexture), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("unbind"), NanNew<v8::FunctionTemplate>(Unbind), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("update"), NanNew<v8::FunctionTemplate>(Update), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFIMAGE), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofImage"), tpl->GetFunction());
		}


		NAN_GETTER(OfImageWrap::GetBpp)
		{
			const auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			NanReturnValue(self->bpp);
		}
		//----------------------------------------------------

		NAN_GETTER(OfImageWrap::GetHeight)
		{
			const auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			NanReturnValue(self->height);
		}
		//----------------------------------------------------

		NAN_GETTER(OfImageWrap::GetType)
		{
			const auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			NanReturnValue(self->type);
		}
		//----------------------------------------------------

		NAN_GETTER(OfImageWrap::GetWidth)
		{
			const auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			NanReturnValue(self->width);
		}
		//----------------------------------------------------


		NAN_SETTER(OfImageWrap::SetBpp)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->bpp = value->Int32Value();
		}
		//----------------------------------------------------

		NAN_SETTER(OfImageWrap::SetHeight)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->height = value->Int32Value();
		}
		//----------------------------------------------------

		NAN_SETTER(OfImageWrap::SetType)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->type = value->Int32Value();
		}
		//----------------------------------------------------

		NAN_SETTER(OfImageWrap::SetWidth)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->width = value->Int32Value();
		}
		//----------------------------------------------------


		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::Allocate)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->allocate(args[0]->Int32Value(), args[1]->Int32Value(), static_cast<ofImageType>(args[2]->Int32Value()));
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::BAllocated)
		{
			const auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			NanReturnValue(self->bAllocated());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::Bind)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->bind( args[0]->IsUndefined() ? 0 : args[0]->Int32Value() );
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::Clear)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->clear();
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::Clone)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->clone(*ObjectWrap::Unwrap<OfImageWrap>(args[0]->ToObject())->GetWrapped());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::Crop)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->crop(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::CropFrom)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->cropFrom(*ObjectWrap::Unwrap<OfImageWrap>(args[0]->ToObject())->GetWrapped(),
				args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value(), args[4]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::Draw)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			if (args.Length() == 1)
			{
				if (args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFRECTANGLE)
				{
					self->draw(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfRectangleWrap>(args[0]->ToObject())->GetWrapped());
				}
				else
				{
					self->draw(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped());
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
					self->draw(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped()
						, args[1]->NumberValue(), args[2]->NumberValue());
				}
			}
			else if (args.Length() == 4)
			{
				self->draw(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
			}
			else if (args.Length() == 5)
			{
				self->draw(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue(), args[4]->NumberValue());
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::DrawSubsection)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
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
		NAN_METHOD(OfImageWrap::GetColor)
		{
			const auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			auto JsColor = DepNewInstance(DEP_ofColor);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfColorWrap>(JsColor->ToObject())->SetWrapped(self->getColor(
				args[0]->Int32Value(), args[1]->Int32Value()));
			NanReturnValue(JsColor);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::GetHeight)
		{
			const auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getHeight());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::GetPixels)
		{
			const auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			auto JsPtr = DepNewInstance(DEP_unsignedCharPtr);
			ObjectWrap::Unwrap<nofx::Pointer::RawPointerWrap<unsigned char>>(JsPtr->ToObject())->SetWrapped(self->getPixels());
			NanReturnValue(JsPtr);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::GetPixelsRef)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			auto JsPixels = DepNewInstance(DEP_ofPixels);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfPixelsWrap>(JsPixels->ToObject())->SetWrapped(self->getPixelsRef());
			NanReturnValue(JsPixels);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::GetTextureReference)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			auto JsTexture = DepNewInstance(DEP_ofTexture);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfTextureWrap>(JsTexture->ToObject())->SetWrapped(self->getTextureReference());
			NanReturnValue(JsTexture);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::GetWidth)
		{
			const auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getWidth());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::GrabScreen)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->grabScreen(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::IsAllocated)
		{
			const auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			NanReturnValue(self->isAllocated());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::IsUsingTexture)
		{
			const auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			NanReturnValue(self->isUsingTexture());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::LoadImage)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			bool result = false;
			if (args[0]->IsString())
			{
				result = self->loadImage(*NanUtf8String(args[0]));
			}
			else if (args[0]->IsObject() && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFFILE)
			{
				result = self->loadImage(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfFileWrap>(args[0]->ToObject())->GetWrapped());
			}
			else if (args[0]->IsObject() && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFBUFFER)
			{
				result = self->loadImage(*ObjectWrap::Unwrap<nofx::OfBuffer::OfBufferWrap>(args[0]->ToObject())->GetWrapped());
			}
			NanReturnValue(result);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::Mirror)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->mirror(args[0]->BooleanValue(), args[1]->BooleanValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::ReloadTexture)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->reloadTexture();
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::ResetAnchor)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->resetAnchor();
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::Resize)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->resize(args[0]->Int32Value(), args[1]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::Rotate90)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->rotate90(args[0]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::SaveImage)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			ofImageQualityType type = args[1]->IsUndefined() ? OF_IMAGE_QUALITY_BEST : static_cast<ofImageQualityType>(args[1]->Int32Value());
			if (args[0]->IsString())
			{
				self->saveImage(*NanUtf8String(args[0]), type);
			}
			else if (args[0]->IsObject() && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFFILE)
			{
				self->saveImage(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfFileWrap>(args[0]->ToObject())->GetWrapped(), type);
			}
			else if (args[0]->IsObject() && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFBUFFER)
			{
				self->saveImage(*ObjectWrap::Unwrap<nofx::OfBuffer::OfBufferWrap>(args[0]->ToObject())->GetWrapped(), type);
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::SetAnchorPercent)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->setAnchorPercent(args[0]->NumberValue(), args[1]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::SetAnchorPoint)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->setAnchorPoint(args[0]->NumberValue(), args[1]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::SetColor)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			if (args.Length() == 1)
			{
				self->setColor(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfColorWrap>(args[0]->ToObject())->GetWrapped());
			}
			else if (args.Length() == 2)
			{
				self->setColor(args[0]->Int32Value(),
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfColorWrap>(args[1]->ToObject())->GetWrapped());
			}
			else {
				self->setColor(args[0]->Int32Value(), args[1]->Int32Value(),
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfColorWrap>(args[2]->ToObject())->GetWrapped());
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::SetCompression)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->setCompression(static_cast<ofTexCompression>(args[0]->Int32Value()));
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::SetFromPixels)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			if (args.Length() == 1)
			{
				self->setFromPixels(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfPixelsWrap>(args[0]->ToObject())->GetWrapped());
			}
			else
			{
				self->setFromPixels(ObjectWrap::Unwrap<nofx::Pointer::RawPointerWrap<unsigned char>>(args[0]->ToObject())->GetWrapped(),
					args[1]->Int32Value(), args[2]->Int32Value(), static_cast<ofImageType>(args[3]->Int32Value()), args[4]->BooleanValue());
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::SetImageType)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->setImageType(static_cast<ofImageType>(args[0]->Int32Value()));
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::SetUseTexture)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->setUseTexture(args[0]->BooleanValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::Unbind)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->unbind(args[0]->IsUndefined() ? 0 : args[0]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfImageWrap::Update)
		{
			auto self = ObjectWrap::Unwrap<OfImageWrap>(args.This())->GetWrapped();
			self->update();
			NanReturnUndefined();
		}

	} //!namespace ClassWrappers
} //!namespace nofx
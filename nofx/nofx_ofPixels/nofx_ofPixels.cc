#include "nofx_ofPixels.h"
#include "..\nofx\nofx_types.h"
#include "..\nofx_ofColor\nofx_ofColor.h"
#include "..\nofx_pointer\nofx_pointer.h"

namespace nofx
{
	namespace OfPixels
	{
		using node::ObjectWrap;

		Persistent<Function> OfPixelsWrap::constructor;

		OfPixelsWrap::OfPixelsWrap()
			: internal_(nullptr)
		{}

		//--------------------------------------------------------------
		OfPixelsWrap::OfPixelsWrap(ofPixels* aInternal)
			: internal_(aInternal)
		{}

		//--------------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfPixelsWrap* obj;
				if (args[0]->IsNull())
				{
					obj = new OfPixelsWrap(nullptr);
				}
				else if (args.Length() == 0) {
					obj = new OfPixelsWrap(new ofPixels());
				}
				else
				{
					//copy constructor
					obj = new OfPixelsWrap(ObjectWrap::Unwrap<OfPixelsWrap>(args[0]->ToObject())->GetWrapped());
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
		void OfPixelsWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofPixels"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);

			NanSetPrototypeTemplate(tpl, NanNew("allocate"), NanNew<v8::FunctionTemplate>(Allocate), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("clear"), NanNew<v8::FunctionTemplate>(Clear), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("crop"), NanNew<v8::FunctionTemplate>(Crop), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("cropTo"), NanNew<v8::FunctionTemplate>(CropTo), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getBitsPerChannel"), NanNew<v8::FunctionTemplate>(GetBitsPerChannel), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getBitsPerPixel"), NanNew<v8::FunctionTemplate>(GetBitsPerPixel), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getBytesPerChannel"), NanNew<v8::FunctionTemplate>(GetBytesPerChannel), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getBytesPerPixel"), NanNew<v8::FunctionTemplate>(GetBytesPerPixel), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getChannel"), NanNew<v8::FunctionTemplate>(GetChannel), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getColor"), NanNew<v8::FunctionTemplate>(GetColor), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getHeight"), NanNew<v8::FunctionTemplate>(GetHeight), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getImageType"), NanNew<v8::FunctionTemplate>(GetImageType), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getNumChannels"), NanNew<v8::FunctionTemplate>(GetNumChannels), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPixelIndex"), NanNew<v8::FunctionTemplate>(GetPixelIndex), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPixels"), NanNew<v8::FunctionTemplate>(GetPixels), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getWidth"), NanNew<v8::FunctionTemplate>(GetWidth), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isAllocated"), NanNew<v8::FunctionTemplate>(IsAllocated), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("mirror"), NanNew<v8::FunctionTemplate>(Mirror), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("mirrorTo"), NanNew<v8::FunctionTemplate>(MirrorTo), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("pasteInto"), NanNew<v8::FunctionTemplate>(PasteInto), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("resize"), NanNew<v8::FunctionTemplate>(Resize), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("resizeTo"), NanNew<v8::FunctionTemplate>(ResizeTo), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("rotate90"), NanNew<v8::FunctionTemplate>(Rotate90), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("rotate90To"), NanNew<v8::FunctionTemplate>(Rotate90To), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("set"), NanNew<v8::FunctionTemplate>(Set), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setChannel"), NanNew<v8::FunctionTemplate>(SetChannel), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setColor"), NanNew<v8::FunctionTemplate>(SetColor), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setFromAlignedPixels"), NanNew<v8::FunctionTemplate>(SetFromAlignedPixels), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setFromExternalPixels"), NanNew<v8::FunctionTemplate>(SetFromExternalPixels), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setFromPixels"), NanNew<v8::FunctionTemplate>(SetFromPixels), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setImageType"), NanNew<v8::FunctionTemplate>(SetImageType), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setNumChannels"), NanNew<v8::FunctionTemplate>(SetNumChannels), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("size"), NanNew<v8::FunctionTemplate>(Size), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("swap"), NanNew<v8::FunctionTemplate>(Swap), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("swapRgb"), NanNew<v8::FunctionTemplate>(SwapRgb), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFPIXELS), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofPixels"), tpl->GetFunction());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::Allocate)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			self->allocate(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::Clear)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			self->clear();
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::Crop)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			self->crop(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::CropTo)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfPixelsWrap>(args[0]->ToObject())->GetWrapped();
			self->cropTo(*target, args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value(), args[4]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::GetBitsPerChannel)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getBitsPerChannel());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::GetBitsPerPixel)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getBitsPerPixel());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::GetBytesPerChannel)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getBytesPerChannel());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::GetBytesPerPixel)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getBytesPerPixel());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::GetChannel)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			auto JsPixels = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfPixelsWrap>(JsPixels)->SetWrapped(self->getChannel(args[0]->Int32Value()));
			NanReturnValue(JsPixels);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::GetColor)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			auto JsColor = DepNewInstance(DEP_ofColor);
			ObjectWrap::Unwrap<nofx::OfColor::OfColorWrap>(JsColor->ToObject())->SetWrapped(self->getColor(args[0]->Int32Value(), args[1]->Int32Value()));
			NanReturnValue(JsColor);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::GetHeight)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getHeight());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::GetImageType)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getImageType());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::GetNumChannels)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getNumChannels());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::GetPixelIndex)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getPixelIndex(args[0]->Int32Value(), args[1]->Int32Value()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::GetPixels)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			auto JsUcharPtr = DepNewInstance(DEP_unsignedCharPtr);
			auto JsPtrWrapped = ObjectWrap::Unwrap<nofx::Pointer::NumberPointerWrap<unsigned char>>(JsUcharPtr->ToObject());
			JsPtrWrapped->SetDisplayLength(sizeof(self->getPixels()) / sizeof(self->getPixels()[0]));
			JsPtrWrapped->SetWrapped(self->getPixels());
			NanReturnValue(JsUcharPtr);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::GetWidth)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getWidth());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::IsAllocated)
		{
			const auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			NanReturnValue(self->isAllocated());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::Mirror)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			self->mirror(args[0]->BooleanValue(), args[1]->BooleanValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::MirrorTo)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfPixelsWrap>(args[0]->ToObject())->GetWrapped();
			self->mirrorTo(*target, args[1]->BooleanValue(), args[2]->BooleanValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::PasteInto)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfPixelsWrap>(args[0]->ToObject())->GetWrapped();
			self->pasteInto(*target, args[1]->Int32Value(), args[2]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::Resize)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			NanReturnValue(self->resize(args[0]->Int32Value(), args[1]->Int32Value(), 
				args[2]->IsUndefined() ? OF_INTERPOLATE_NEAREST_NEIGHBOR : static_cast<ofInterpolationMethod>(args[2]->Uint32Value())));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::ResizeTo)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfPixelsWrap>(args[0]->ToObject())->GetWrapped();
			NanReturnValue(self->resizeTo(*target,
				args[2]->IsUndefined() ? OF_INTERPOLATE_NEAREST_NEIGHBOR : static_cast<ofInterpolationMethod>(args[2]->Uint32Value())));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::Rotate90)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			self->rotate90(args[0]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::Rotate90To)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfPixelsWrap>(args[0]->ToObject())->GetWrapped();
			self->rotate90To(*target, args[0]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::Set)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			if (args.Length() == 1)
			{
				self->set(args[0]->Uint32Value());
			}
			else
			{
				self->set(args[0]->Int32Value(), args[1]->Uint32Value());
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::SetChannel)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfPixelsWrap>(args[1]->ToObject())->GetWrapped();
			self->setChannel(args[0]->Int32Value(), *target);
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::SetColor)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<nofx::OfColor::OfColorWrap>(args[args.Length() - 1]->ToObject())->GetWrapped();
			if (args.Length() == 1)
			{
				self->setColor(*target);
			}
			else if (args.Length() == 2)
			{
				self->setColor(args[0]->Int32Value(), *target);
			}
			else
			{
				self->setColor(args[0]->Int32Value(), args[1]->Int32Value(), *target);
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::SetFromAlignedPixels)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			self->setFromAlignedPixels(
				ObjectWrap::Unwrap<nofx::Pointer::NumberPointerWrap<unsigned char>>(args[0]->ToObject())->GetWrapped(),
				args[1]->Int32Value(),
				args[2]->Int32Value(),
				args[3]->Int32Value(),
				args[4]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::SetFromExternalPixels)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			self->setFromExternalPixels(
				ObjectWrap::Unwrap<nofx::Pointer::NumberPointerWrap<unsigned char>>(args[0]->ToObject())->GetWrapped(),
				args[1]->Int32Value(),
				args[2]->Int32Value(),
				args[3]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::SetFromPixels)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			self->setFromPixels(
				ObjectWrap::Unwrap<nofx::Pointer::NumberPointerWrap<unsigned char>>(args[0]->ToObject())->GetWrapped(),
				args[1]->Int32Value(),
				args[2]->Int32Value(),
				args[2]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::SetImageType)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			self->setImageType(static_cast<ofImageType>(args[0]->Int32Value()));
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::SetNumChannels)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			self->setNumChannels(args[0]->Int32Value());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::Size)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			NanReturnValue(self->size());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::Swap)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfPixelsWrap>(args[0]->ToObject())->GetWrapped();
			self->swap(*target);
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfPixelsWrap::SwapRgb)
		{
			auto self = ObjectWrap::Unwrap<OfPixelsWrap>(args.This())->GetWrapped();
			self->swapRgb();
			NanReturnUndefined();
		}

	} //!namespace OfPixels
} //!namespace nofx
#include "nofx_ofBuffer.h"
#include "..\nofx\nofx_types.h"
#include "..\nofx_pointer\nofx_pointer.h"

namespace nofx
{
	namespace OfBuffer
	{
		using node::ObjectWrap;

		Persistent<Function> OfBufferWrap::constructor;

		NAN_METHOD(OfBufferWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfBufferWrap* obj;
				if (args[0]->IsNull())
				{
					obj = new OfBufferWrap(nullptr);
				}
				else if (args.Length() == 0)
				{
					obj = new OfBufferWrap();
				}
				else if (args.Length() == 1 && args[0]->IsString())
				{
					obj = new OfBufferWrap(new ofBuffer(*NanUtf8String(args[0])));
				}
				else if (args.Length() == 2)
				{
					obj = new OfBufferWrap(new ofBuffer(*NanUtf8String(args[0]), args[1]->Uint32Value()));
				}
				else
				{
					//copy constructor
					obj = new OfBufferWrap(ObjectWrap::Unwrap<OfBufferWrap>(args[0]->ToObject())->GetWrapped());
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
		void OfBufferWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofBuffer"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);

			NanSetPrototypeTemplate(tpl, NanNew("allocate"), NanNew<v8::FunctionTemplate>(Allocate), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("append"), NanNew<v8::FunctionTemplate>(Append), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("clear"), NanNew<v8::FunctionTemplate>(Clear), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getBinaryBuffer"), NanNew<v8::FunctionTemplate>(GetBinaryBuffer), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getFirstLine"), NanNew<v8::FunctionTemplate>(GetFirstLine), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getNextLine"), NanNew<v8::FunctionTemplate>(GetNextLine), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getText"), NanNew<v8::FunctionTemplate>(GetText), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isLastLine"), NanNew<v8::FunctionTemplate>(IsLastLine), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("resetLineReader"), NanNew<v8::FunctionTemplate>(ResetLineReader), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("set"), NanNew<v8::FunctionTemplate>(Set), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("size"), NanNew<v8::FunctionTemplate>(Size), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("writeTo"), NanNew<v8::FunctionTemplate>(WriteTo), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFBUFFER), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofBuffer"), tpl->GetFunction());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfBufferWrap::Allocate)
		{
			auto self = ObjectWrap::Unwrap<OfBufferWrap>(args.This())->GetWrapped();
			self->allocate(args[0]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfBufferWrap::Append)
		{
			auto self = ObjectWrap::Unwrap<OfBufferWrap>(args.This())->GetWrapped();
			if (args.Length() == 1)
			{
				self->append(*NanUtf8String(args[0]));
			}
			else
			{
				self->append(*NanUtf8String(args[0]), args[1]->Uint32Value());
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfBufferWrap::Clear)
		{
			auto self = ObjectWrap::Unwrap<OfBufferWrap>(args.This())->GetWrapped();
			self->clear();
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfBufferWrap::GetBinaryBuffer)
		{
			const auto self = ObjectWrap::Unwrap<OfBufferWrap>(args.This())->GetWrapped();
			auto JsPtr = DepNewInstance(DEP_charPtr);
			ObjectWrap::Unwrap<nofx::Pointer::RawPointerWrap<char>>(JsPtr->ToObject())->SetWrapped(self->getBinaryBuffer());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfBufferWrap::GetFirstLine)
		{
			const auto self = ObjectWrap::Unwrap<OfBufferWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getFirstLine().c_str());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfBufferWrap::GetNextLine)
		{
			const auto self = ObjectWrap::Unwrap<OfBufferWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getNextLine().c_str());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfBufferWrap::GetText)
		{
			const auto self = ObjectWrap::Unwrap<OfBufferWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getText().c_str());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfBufferWrap::IsLastLine)
		{
			const auto self = ObjectWrap::Unwrap<OfBufferWrap>(args.This())->GetWrapped();
			NanReturnValue(self->isLastLine());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfBufferWrap::ResetLineReader)
		{
			auto self = ObjectWrap::Unwrap<OfBufferWrap>(args.This())->GetWrapped();
			self->resetLineReader();
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfBufferWrap::Set)
		{
			auto self = ObjectWrap::Unwrap<OfBufferWrap>(args.This())->GetWrapped();
			if (args.Length() == 1)
			{
				self->set(*NanUtf8String(args[0]));
			}
			else
			{
				self->set(*NanUtf8String(args[0]), args[1]->Uint32Value());
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfBufferWrap::Size)
		{
			const auto self = ObjectWrap::Unwrap<OfBufferWrap>(args.This())->GetWrapped();
			NanReturnValue(self->size());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfBufferWrap::WriteTo)
		{
			auto self = ObjectWrap::Unwrap<OfBufferWrap>(args.This())->GetWrapped();
			NanThrowError("OfBufferWrap::WriteTo requires ostream. ostream is not implemented yet.");
			NanReturnUndefined();
		}

	} //!namespace OfBuffer
} //!namespace nofx
#include "nofx_ofFile.h"
#include "..\nofx\nofx_types.h"
#include "..\nofx_ofBuffer\nofx_ofBuffer.h"

namespace nofx
{
	namespace OfFile
	{
		using node::ObjectWrap;

		Persistent<Function> OfFileWrap::constructor;

		NAN_METHOD(OfFileWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfFileWrap* obj;
				if (args[0]->IsNull())
				{
					obj = new OfFileWrap(nullptr);
				}
				else if (args.Length() == 0)
				{
					obj = new OfFileWrap();
				}
				else if ((args.Length() == 1 && args[0]->IsString()) || args.Length() > 1)
				{
					ofFile::Mode m = args[1]->IsUndefined() ? ofFile::ReadOnly : static_cast<ofFile::Mode>(args[1]->Int32Value());
					bool b = args[2]->IsUndefined() ? false : args[2]->BooleanValue();
					obj = new OfFileWrap(new ofFile(*NanUtf8String(args[0]), m, b));
				}
				else
				{
					//copy constructor
					obj = new OfFileWrap(ObjectWrap::Unwrap<OfFileWrap>(args[0]->ToObject())->GetWrapped());
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
		void OfFileWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofFile"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);

			NanSetPrototypeTemplate(tpl, NanNew("canExecute"), NanNew<v8::FunctionTemplate>(CanExecute), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("canRead"), NanNew<v8::FunctionTemplate>(CanRead), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("canWrite"), NanNew<v8::FunctionTemplate>(CanWrite), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("changeMode"), NanNew<v8::FunctionTemplate>(ChangeMode), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("close"), NanNew<v8::FunctionTemplate>(Close), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("copyFromTo"), NanNew<v8::FunctionTemplate>(CopyFromTo), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("copyTo"), NanNew<v8::FunctionTemplate>(CopyTo), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("create"), NanNew<v8::FunctionTemplate>(Create), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("doesFileExist"), NanNew<v8::FunctionTemplate>(DoesFileExist), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("exists"), NanNew<v8::FunctionTemplate>(Exists), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getAbsolutePath"), NanNew<v8::FunctionTemplate>(GetAbsolutePath), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getBaseName"), NanNew<v8::FunctionTemplate>(GetBaseName), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getEnclosingDirectory"), NanNew<v8::FunctionTemplate>(GetEnclosingDirectory), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getExtension"), NanNew<v8::FunctionTemplate>(GetExtension), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getFileBuffer"), NanNew<v8::FunctionTemplate>(GetFileBuffer), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getFileName"), NanNew<v8::FunctionTemplate>(GetFileName), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPocoFile"), NanNew<v8::FunctionTemplate>(GetPocoFile), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getSize"), NanNew<v8::FunctionTemplate>(GetSize), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isDevice"), NanNew<v8::FunctionTemplate>(IsDevice), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isDirectory"), NanNew<v8::FunctionTemplate>(IsDirectory), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isFile"), NanNew<v8::FunctionTemplate>(IsFile), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isHidden"), NanNew<v8::FunctionTemplate>(IsHidden), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isLink"), NanNew<v8::FunctionTemplate>(IsLink), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("moveFromTo"), NanNew<v8::FunctionTemplate>(MoveFromTo), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("moveTo"), NanNew<v8::FunctionTemplate>(MoveTo), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("open"), NanNew<v8::FunctionTemplate>(Open), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("path"), NanNew<v8::FunctionTemplate>(Path), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("readToBuffer"), NanNew<v8::FunctionTemplate>(ReadToBuffer), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("remove"), NanNew<v8::FunctionTemplate>(Remove), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("removeFile"), NanNew<v8::FunctionTemplate>(RemoveFile), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("renameTo"), NanNew<v8::FunctionTemplate>(RenameTo), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setExecutable"), NanNew<v8::FunctionTemplate>(SetExecutable), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setReadOnly"), NanNew<v8::FunctionTemplate>(SetReadOnly), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setWriteable"), NanNew<v8::FunctionTemplate>(SetWriteable), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("writeFromBuffer"), NanNew<v8::FunctionTemplate>(WriteFromBuffer), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFFILE), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofFile"), tpl->GetFunction());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::CanExecute)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(self->canExecute());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::CanRead)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(self->canRead());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::CanWrite)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(self->canWrite());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::ChangeMode)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			bool b = args[1]->IsUndefined() ? false : args[1]->BooleanValue();
			NanReturnValue(self->changeMode(static_cast<ofFile::Mode>(args[1]->Int32Value()), b));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::Close)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			self->close();
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::CopyFromTo)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			bool b1 = args[2]->IsUndefined() ? false : args[2]->BooleanValue();
			bool b2 = args[3]->IsUndefined() ? false : args[3]->BooleanValue();
			NanReturnValue(ofFile::copyFromTo(*NanUtf8String(args[0]), *NanUtf8String(args[1]), b1, b2));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::CopyTo)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			bool b1 = args[1]->IsUndefined() ? false : args[1]->BooleanValue();
			bool b2 = args[2]->IsUndefined() ? false : args[2]->BooleanValue();
			NanReturnValue(self->copyTo(*NanUtf8String(args[0]), b1, b2));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::Create)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(self->create());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::DoesFileExist)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			bool b1 = args[1]->IsUndefined() ? false : args[1]->BooleanValue();
			NanReturnValue(ofFile::doesFileExist(*NanUtf8String(args[0]), b1));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::Exists)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(self->exists());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::GetAbsolutePath)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(NanNew(self->getAbsolutePath()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::GetBaseName)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(NanNew(self->getBaseName()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::GetEnclosingDirectory)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(NanNew(self->getEnclosingDirectory()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::GetExtension)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(NanNew(self->getExtension()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::GetFileBuffer)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanThrowError("OfFileWrap::GetFileBuffer requires std::filebuf. std::filebuf is not implemented yet.");
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::GetFileName)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(NanNew(self->getFileName()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::GetPocoFile)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanThrowError("OfFileWrap::GetPocoFile requires Poco::File. Poco::File is not implemented yet.");
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::GetSize)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(static_cast<double>(self->getSize()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::IsDevice)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(self->isDevice());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::IsDirectory)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(self->isDirectory());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::IsFile)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(self->isFile());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::IsHidden)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(self->isHidden());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::IsLink)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(self->isLink());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::MoveFromTo)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			bool b1 = args[2]->IsUndefined() ? false : args[2]->BooleanValue();
			bool b2 = args[3]->IsUndefined() ? false : args[3]->BooleanValue();
			NanReturnValue(ofFile::moveFromTo(*NanUtf8String(args[0]), *NanUtf8String(args[1]), b1, b2));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::MoveTo)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			bool b1 = args[1]->IsUndefined() ? false : args[1]->BooleanValue();
			bool b2 = args[2]->IsUndefined() ? false : args[2]->BooleanValue();
			NanReturnValue(self->moveTo(*NanUtf8String(args[0]), b1, b2));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::Open)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			ofFile::Mode m = args[1]->IsUndefined() ? ofFile::ReadOnly : static_cast<ofFile::Mode>(args[1]->Int32Value());
			bool b2 = args[2]->IsUndefined() ? false : args[2]->BooleanValue();
			NanReturnValue(self->open(*NanUtf8String(args[0]), m, b2));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::Path)
		{
			const auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			NanReturnValue(NanNew(self->path()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::ReadToBuffer)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			auto JsBuffer = DepNewInstance(DEP_ofBuffer);
			ObjectWrap::Unwrap<nofx::OfBuffer::OfBufferWrap>(JsBuffer->ToObject())->SetWrapped(self->readToBuffer());
			NanReturnValue(JsBuffer);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::Remove)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			bool b1 = args[0]->IsUndefined() ? false : args[0]->BooleanValue();
			NanReturnValue(self->remove(b1));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::RemoveFile)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			bool b1 = args[1]->IsUndefined() ? true : args[1]->BooleanValue();
			NanReturnValue(self->removeFile(*NanUtf8String(args[0]),b1));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::RenameTo)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			bool b1 = args[1]->IsUndefined() ? true : args[1]->BooleanValue();
			bool b2 = args[2]->IsUndefined() ? true : args[2]->BooleanValue();
			NanReturnValue(self->renameTo(*NanUtf8String(args[0]), b1, b2));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::SetExecutable)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			self->setExecutable(args[0]->BooleanValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::SetReadOnly)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			self->setReadOnly(args[0]->BooleanValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::SetWriteable)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			self->setWriteable(args[0]->BooleanValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfFileWrap::WriteFromBuffer)
		{
			auto self = ObjectWrap::Unwrap<OfFileWrap>(args.This())->GetWrapped();
			self->writeFromBuffer(*ObjectWrap::Unwrap<nofx::OfBuffer::OfBufferWrap>(args[0]->ToObject())->GetWrapped());
			NanReturnUndefined();
		}

	} //!namespace OfFile
} //!namespace nofx
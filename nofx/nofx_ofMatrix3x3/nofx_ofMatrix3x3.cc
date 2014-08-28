#include "nofx_ofMatrix3x3.h"
#include "..\nofx\nofx_types.h"

namespace nofx
{
	namespace ClassWrappers
	{
		using node::ObjectWrap;

		Persistent<Function> OfMatrix3x3Wrap::constructor;

		//--------------------------------------------------------------
		NAN_METHOD(OfMatrix3x3Wrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfMatrix3x3Wrap* obj;
				if (args[0]->IsNull())
				{
					obj = new OfMatrix3x3Wrap(nullptr);
				}
				else if (args.Length() == 0 || args[0]->IsNumber())
				{
					auto a = args[0]->IsUndefined() ? 0.0f : args[0]->NumberValue();
					auto b = args[1]->IsUndefined() ? 0.0f : args[1]->NumberValue();
					auto c = args[2]->IsUndefined() ? 0.0f : args[2]->NumberValue();
					auto d = args[3]->IsUndefined() ? 0.0f : args[3]->NumberValue();
					auto e = args[4]->IsUndefined() ? 0.0f : args[4]->NumberValue();
					auto f = args[5]->IsUndefined() ? 0.0f : args[5]->NumberValue();
					auto g = args[6]->IsUndefined() ? 0.0f : args[6]->NumberValue();
					auto h = args[7]->IsUndefined() ? 0.0f : args[7]->NumberValue();
					auto i = args[8]->IsUndefined() ? 0.0f : args[8]->NumberValue();
					obj = new OfMatrix3x3Wrap(new ofMatrix3x3(a, b, c, d, e, f, g, h, i));
				}
				else
				{
					//copy constructor
					obj = new OfMatrix3x3Wrap(ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args[0]->ToObject())->GetWrapped());
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
		void OfMatrix3x3Wrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofMatrix3x3"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);

			inst->SetIndexedPropertyHandler(OfMatrix3x3Wrap::IndexGetter, OfMatrix3x3Wrap::IndexSetter);

			inst->SetAccessor(NanNew("a"), OfMatrix3x3Wrap::GetA, OfMatrix3x3Wrap::SetA);
			inst->SetAccessor(NanNew("b"), OfMatrix3x3Wrap::GetB, OfMatrix3x3Wrap::SetB);
			inst->SetAccessor(NanNew("c"), OfMatrix3x3Wrap::GetC, OfMatrix3x3Wrap::SetC);
			inst->SetAccessor(NanNew("d"), OfMatrix3x3Wrap::GetD, OfMatrix3x3Wrap::SetD);
			inst->SetAccessor(NanNew("e"), OfMatrix3x3Wrap::GetE, OfMatrix3x3Wrap::SetE);
			inst->SetAccessor(NanNew("f"), OfMatrix3x3Wrap::GetF, OfMatrix3x3Wrap::SetF);
			inst->SetAccessor(NanNew("g"), OfMatrix3x3Wrap::GetG, OfMatrix3x3Wrap::SetG);
			inst->SetAccessor(NanNew("h"), OfMatrix3x3Wrap::GetH, OfMatrix3x3Wrap::SetH);
			inst->SetAccessor(NanNew("i"), OfMatrix3x3Wrap::GetI, OfMatrix3x3Wrap::SetI);

			NanSetPrototypeTemplate(tpl, NanNew("determinant"), NanNew<v8::FunctionTemplate>(Determinant), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("entrywiseTimes"), NanNew<v8::FunctionTemplate>(EntrywiseTimes), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("inverse"), NanNew<v8::FunctionTemplate>(Inverse), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("invert"), NanNew<v8::FunctionTemplate>(Invert), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("set"), NanNew<v8::FunctionTemplate>(Set), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("transpose"), NanNew<v8::FunctionTemplate>(Transpose), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFMATRIX3X3), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofMatrix3x3"), tpl->GetFunction());
		}

		NAN_INDEX_GETTER(OfMatrix3x3Wrap::IndexGetter)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			NanReturnValue( (*self)[index] );
		}
		NAN_INDEX_SETTER(OfMatrix3x3Wrap::IndexSetter)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			(*self)[index] = value->NumberValue();
		}

		NAN_GETTER(OfMatrix3x3Wrap::GetA)
		{
			const auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			NanReturnValue(self->a);
		}
		//----------------------------------------------------

		NAN_GETTER(OfMatrix3x3Wrap::GetB)
		{
			const auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			NanReturnValue(self->b);
		}
		//----------------------------------------------------

		NAN_GETTER(OfMatrix3x3Wrap::GetC)
		{
			const auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			NanReturnValue(self->c);
		}
		//----------------------------------------------------

		NAN_GETTER(OfMatrix3x3Wrap::GetD)
		{
			const auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			NanReturnValue(self->d);
		}
		//----------------------------------------------------

		NAN_GETTER(OfMatrix3x3Wrap::GetE)
		{
			const auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			NanReturnValue(self->e);
		}
		//----------------------------------------------------

		NAN_GETTER(OfMatrix3x3Wrap::GetF)
		{
			const auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			NanReturnValue(self->f);
		}
		//----------------------------------------------------

		NAN_GETTER(OfMatrix3x3Wrap::GetG)
		{
			const auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			NanReturnValue(self->g);
		}
		//----------------------------------------------------

		NAN_GETTER(OfMatrix3x3Wrap::GetH)
		{
			const auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			NanReturnValue(self->h);
		}
		//----------------------------------------------------

		NAN_GETTER(OfMatrix3x3Wrap::GetI)
		{
			const auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			NanReturnValue(self->i);
		}
		//----------------------------------------------------


		NAN_SETTER(OfMatrix3x3Wrap::SetA)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			self->a = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfMatrix3x3Wrap::SetB)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			self->b = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfMatrix3x3Wrap::SetC)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			self->c = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfMatrix3x3Wrap::SetD)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			self->d = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfMatrix3x3Wrap::SetE)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			self->e = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfMatrix3x3Wrap::SetF)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			self->f = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfMatrix3x3Wrap::SetG)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			self->g = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfMatrix3x3Wrap::SetH)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			self->h = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfMatrix3x3Wrap::SetI)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			self->i = value->NumberValue();
		}
		//----------------------------------------------------


		//---------------------------------------------------------
		NAN_METHOD(OfMatrix3x3Wrap::Determinant)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			if (args.Length() == 0)
			{
				NanReturnValue(self->determinant());
			}
			else
			{
				auto target = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args[0]->ToObject())->GetWrapped();
				NanReturnValue(self->determinant(*target));
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix3x3Wrap::EntrywiseTimes)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args[0]->ToObject())->GetWrapped();
			self->entrywiseTimes(*target);
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix3x3Wrap::Inverse)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args[0]->ToObject())->GetWrapped();
			self->inverse(*target);
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix3x3Wrap::Invert)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			self->invert();
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix3x3Wrap::Set)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			auto a = args[0]->IsUndefined() ? 0.0f : args[0]->NumberValue();
			auto b = args[1]->IsUndefined() ? 0.0f : args[1]->NumberValue();
			auto c = args[2]->IsUndefined() ? 0.0f : args[2]->NumberValue();
			auto d = args[3]->IsUndefined() ? 0.0f : args[3]->NumberValue();
			auto e = args[4]->IsUndefined() ? 0.0f : args[4]->NumberValue();
			auto f = args[5]->IsUndefined() ? 0.0f : args[5]->NumberValue();
			auto g = args[6]->IsUndefined() ? 0.0f : args[6]->NumberValue();
			auto h = args[7]->IsUndefined() ? 0.0f : args[7]->NumberValue();
			auto i = args[8]->IsUndefined() ? 0.0f : args[8]->NumberValue();
			self->set(a, b, c, d, e, f, g, h, i);
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfMatrix3x3Wrap::Transpose)
		{
			auto self = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args.This())->GetWrapped();
			if (args.Length() == 0)
			{
				self->transpose();
			}
			else
			{
				auto target = ObjectWrap::Unwrap<OfMatrix3x3Wrap>(args[0]->ToObject())->GetWrapped();
				self->transpose(*target);
			}
			NanReturnUndefined();
		}

	} //!namespace ClassWrappers
} //!namespace nofx
#include "nofx_ofQuaternion.h"
#include "..\nofx\nofx_types.h"
#include "..\nofx_ofVec4f\nofx_ofVec4f.h"
#include "..\nofx_ofVec3f\nofx_ofVec3f.h"

namespace nofx
{
	namespace OfQuaternion
	{
		using node::ObjectWrap;

		Persistent<Function> OfQuaternionWrap::constructor;

		//--------------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfQuaternionWrap* obj;
				if (args[0]->IsNull())
				{
					obj = new OfQuaternionWrap(nullptr);
				}
				else if (args.Length() == 0)
				{
					obj = new OfQuaternionWrap(new ofQuaternion());
				}
				else if (args.Length() == 1 &&
					(args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFVEC4F))
				{
					obj = new OfQuaternionWrap(new ofQuaternion(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec4fWrap>(args[0]->ToObject())->GetWrapped()));
				}
				else if (args.Length() == 2 &&
					(args[1]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFVEC3F))
				{
					obj = new OfQuaternionWrap(new ofQuaternion(args[0]->NumberValue(), *ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[1]->ToObject())->GetWrapped()));
				}
				else if (args.Length() == 4)
				{
					obj = new OfQuaternionWrap(new ofQuaternion(
						args[0]->NumberValue(),
						args[1]->NumberValue(),
						args[2]->NumberValue(),
						args[3]->NumberValue()
						));
				}
				else if (args.Length() == 6)
				{
					obj = new OfQuaternionWrap(new ofQuaternion(
						args[0]->NumberValue(),
						*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[1]->ToObject())->GetWrapped(),
						args[2]->NumberValue(),
						*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[3]->ToObject())->GetWrapped(),
						args[4]->NumberValue(),
						*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[5]->ToObject())->GetWrapped()
						));
				}
				else
				{
					//copy constructor
					obj = new OfQuaternionWrap(ObjectWrap::Unwrap<OfQuaternionWrap>(args[0]->ToObject())->GetWrapped());
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
		void OfQuaternionWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofQuaternion"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);


			inst->SetAccessor(NanNew("_v"), OfQuaternionWrap::Get_v, OfQuaternionWrap::Set_v);

			NanSetPrototypeTemplate(tpl, NanNew("asVec3"), NanNew<v8::FunctionTemplate>(AsVec3), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("asVec4"), NanNew<v8::FunctionTemplate>(AsVec4), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("conj"), NanNew<v8::FunctionTemplate>(Conj), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("get"), NanNew<v8::FunctionTemplate>(Get), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getEuler"), NanNew<v8::FunctionTemplate>(GetEuler), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getRotate"), NanNew<v8::FunctionTemplate>(GetRotate), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("inverse"), NanNew<v8::FunctionTemplate>(Inverse), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("length"), NanNew<v8::FunctionTemplate>(Length), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("length2"), NanNew<v8::FunctionTemplate>(Length2), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("makeRotate"), NanNew<v8::FunctionTemplate>(MakeRotate), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("normalize"), NanNew<v8::FunctionTemplate>(Normalize), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("set"), NanNew<v8::FunctionTemplate>(Set), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("slerp"), NanNew<v8::FunctionTemplate>(Slerp), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("w"), NanNew<v8::FunctionTemplate>(W), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("x"), NanNew<v8::FunctionTemplate>(X), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("y"), NanNew<v8::FunctionTemplate>(Y), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("z"), NanNew<v8::FunctionTemplate>(Z), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("zeroRotation"), NanNew<v8::FunctionTemplate>(ZeroRotation), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFQUATERNION), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofQuaternion"), tpl->GetFunction());
		}


		NAN_GETTER(OfQuaternionWrap::Get_v)
		{
			const auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			auto JsVec4f = DepNewInstance(DEP_ofVec4f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec4fWrap>(JsVec4f->ToObject())->SetWrapped(self->_v);
			NanReturnValue(JsVec4f);
		}
		//----------------------------------------------------


		NAN_SETTER(OfQuaternionWrap::Set_v)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			self->_v.set( *ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec4fWrap>(value->ToObject())->GetWrapped() );
		}


		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::AsVec3)
		{
			const auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			auto JsVec3f = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(JsVec3f->ToObject())->SetWrapped(self->asVec3());
			NanReturnValue(JsVec3f);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::AsVec4)
		{
			const auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			auto JsVec4f = DepNewInstance(DEP_ofVec4f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec4fWrap>(JsVec4f->ToObject())->SetWrapped(self->asVec4());
			NanReturnValue(JsVec4f);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::Conj)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			auto toRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfQuaternionWrap>(toRet)->SetWrapped(self->conj());
			NanReturnValue(toRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::Get)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			// depends on ofMatrix4x4
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::GetEuler)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			auto toRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(toRet)->SetWrapped( self->getEuler() );
			NanReturnValue(toRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::GetRotate)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			float angle = 0;
			ofVec3f vec;
			self->getRotate(angle, vec);
			auto lVec3 = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(lVec3->ToObject())->SetWrapped(vec);
			auto toRet = NanNew<v8::Object>();
			toRet->Set(NanNew("angle"), NanNew(angle));
			toRet->Set(NanNew("vec"), NanNew(lVec3));
			NanReturnValue(toRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::Inverse)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			auto toRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfQuaternionWrap>(toRet)->SetWrapped( self->inverse() );
			NanReturnValue(toRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::Length)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			NanReturnValue(self->length());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::Length2)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			NanReturnValue(self->length2());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::MakeRotate)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			if (args.Length() == 4)
			{
				self->makeRotate(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue(),
					args[3]->NumberValue()
					);
			}
			else if (args.Length() == 2 && args[0]->IsNumber())
			{
				self->makeRotate(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[1]->ToObject())->GetWrapped()
					);
			}
			else if (args.Length() == 2 && args[0]->IsObject())
			{
				self->makeRotate(
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[1]->ToObject())->GetWrapped()
					);
			}
			else
			{
				self->makeRotate(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[1]->ToObject())->GetWrapped(),
					args[2]->NumberValue(),
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[3]->ToObject())->GetWrapped(),
					args[4]->NumberValue(),
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[5]->ToObject())->GetWrapped()
					);
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::Normalize)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			self->normalize();
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::Set)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			if (args.Length() == 4)
			{
				self->set(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue(),
					args[3]->NumberValue()
					);
			}
			else if (args.Length() == 1 && (args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFVEC4F))
			{
				self->set(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec4fWrap>(args[0]->ToObject())->GetWrapped());
			}
			else
			{
				//depends on Matrix4x4
				//self->set(ObjectWrap::Unwrap<nofx::OfMatrix4x4::OfMatrix4x4Wrap>(args[0]->ToObject())->GetWrapped());
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::Slerp)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			self->slerp(args[0]->NumberValue(),
				*ObjectWrap::Unwrap<OfQuaternionWrap>(args[1]->ToObject())->GetWrapped(),
				*ObjectWrap::Unwrap<OfQuaternionWrap>(args[2]->ToObject())->GetWrapped());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::W)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			NanReturnValue(self->w());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::X)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			NanReturnValue(self->x());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::Y)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			NanReturnValue(self->y());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::Z)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			NanReturnValue(self->z());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfQuaternionWrap::ZeroRotation)
		{
			auto self = ObjectWrap::Unwrap<OfQuaternionWrap>(args.This())->GetWrapped();
			NanReturnValue(self->zeroRotation());
		}

	} //!namespace OfQuaternion
} //!namespace nofx
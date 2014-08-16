#include "nofx_ofVec4f.h"
#include "..\nofx\nofx_types.h"
#include "..\nofx_ofVec2f\nofx_ofVec2f.h"
#include "..\nofx_ofVec3f\nofx_ofVec3f.h"
#include "..\nofx_pointer\nofx_pointer.h"

namespace nofx
{
	namespace OfVec4f
	{
		using node::ObjectWrap;

		Persistent<Function> OfVec4fWrap::constructor;

		OfVec4fWrap::OfVec4fWrap()
			: internal_(nullptr)
		{}

		//--------------------------------------------------------------
		OfVec4fWrap::OfVec4fWrap(ofVec4f* aInternal)
			: internal_(aInternal)
		{}

		//--------------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfVec4fWrap* obj;
				if (args[0]->IsNull())
				{
					obj = new OfVec4fWrap(nullptr);
				}
				else if (args.Length() == 0)
				{
					obj = new OfVec4fWrap(new ofVec4f());
				}
				else if (args.Length() == 1)
				{
					if (args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() == NOFX_TYPES::OFVEC2F)
					{
						obj = new OfVec4fWrap(new ofVec4f(*ObjectWrap::Unwrap<nofx::OfVec2f::OfVec2fWrap>(args[0]->ToObject())->GetWrapped()));
					}
					else if (args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() == NOFX_TYPES::OFVEC3F)
					{
						obj = new OfVec4fWrap(new ofVec4f(*ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(args[0]->ToObject())->GetWrapped()));
					}
					else
					{
						obj = new OfVec4fWrap(new ofVec4f(args[0]->NumberValue()));
					}
				}
				else if (args.Length() == 4)
				{
					obj = new OfVec4fWrap(new ofVec4f(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue()));
				}
				else if (args[0]->IsNull())
				{
					obj = new OfVec4fWrap(nullptr);
				}
				else
				{
					//copy constructor
					obj = new OfVec4fWrap(ObjectWrap::Unwrap<OfVec4fWrap>(args[0]->ToObject())->GetWrapped());
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
		void OfVec4fWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofVec4f"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);


			inst->SetAccessor(NanNew("DIM"), OfVec4fWrap::GetDIM, 0, v8::Handle<v8::Value>(), v8::PROHIBITS_OVERWRITING);
			inst->SetAccessor(NanNew("w"), OfVec4fWrap::GetW, OfVec4fWrap::SetW);
			inst->SetAccessor(NanNew("x"), OfVec4fWrap::GetX, OfVec4fWrap::SetX);
			inst->SetAccessor(NanNew("y"), OfVec4fWrap::GetY, OfVec4fWrap::SetY);
			inst->SetAccessor(NanNew("z"), OfVec4fWrap::GetZ, OfVec4fWrap::SetZ);
			inst->SetIndexedPropertyHandler(OfVec4fWrap::IndexGetter, OfVec4fWrap::IndexSetter);

			NanSetPrototypeTemplate(tpl, NanNew("average"), NanNew<v8::FunctionTemplate>(Average), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("distance"), NanNew<v8::FunctionTemplate>(Distance), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("distanceSquared"), NanNew<v8::FunctionTemplate>(DistanceSquared), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("dot"), NanNew<v8::FunctionTemplate>(Dot), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getInterpolated"), NanNew<v8::FunctionTemplate>(GetInterpolated), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getLimited"), NanNew<v8::FunctionTemplate>(GetLimited), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getMiddle"), NanNew<v8::FunctionTemplate>(GetMiddle), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getNormalized"), NanNew<v8::FunctionTemplate>(GetNormalized), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPtr"), NanNew<v8::FunctionTemplate>(GetPtr), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getScaled"), NanNew<v8::FunctionTemplate>(GetScaled), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("interpolate"), NanNew<v8::FunctionTemplate>(Interpolate), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("length"), NanNew<v8::FunctionTemplate>(Length), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("lengthSquared"), NanNew<v8::FunctionTemplate>(LengthSquared), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("limit"), NanNew<v8::FunctionTemplate>(Limit), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("match"), NanNew<v8::FunctionTemplate>(Match), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("middle"), NanNew<v8::FunctionTemplate>(Middle), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("normalize"), NanNew<v8::FunctionTemplate>(Normalize), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("one"), NanNew<v8::FunctionTemplate>(One), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("scale"), NanNew<v8::FunctionTemplate>(Scale), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("set"), NanNew<v8::FunctionTemplate>(Set), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("squareDistance"), NanNew<v8::FunctionTemplate>(SquareDistance), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("zero"), NanNew<v8::FunctionTemplate>(Zero), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFVEC4F), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofVec4f"), tpl->GetFunction());
		}

		NAN_INDEX_GETTER(OfVec4fWrap::IndexGetter)
		{
			NanReturnValue(ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped()->getPtr()[index]);
		}
		NAN_INDEX_SETTER(OfVec4fWrap::IndexSetter)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			self->getPtr()[index] = value->NumberValue();
		}

		NAN_GETTER(OfVec4fWrap::GetDIM)
		{
			const auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->DIM);
		}
		//----------------------------------------------------

		NAN_GETTER(OfVec4fWrap::GetW)
		{
			const auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->w);
		}
		//----------------------------------------------------

		NAN_GETTER(OfVec4fWrap::GetX)
		{
			const auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->x);
		}
		//----------------------------------------------------

		NAN_GETTER(OfVec4fWrap::GetY)
		{
			const auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->y);
		}
		//----------------------------------------------------

		NAN_GETTER(OfVec4fWrap::GetZ)
		{
			const auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->z);
		}
		//----------------------------------------------------

		NAN_SETTER(OfVec4fWrap::SetW)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			self->w = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfVec4fWrap::SetX)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			self->x = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfVec4fWrap::SetY)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			self->y = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfVec4fWrap::SetZ)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			self->z = value->NumberValue();
		}
		//----------------------------------------------------


		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::Average)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			auto& points = args[0]->ToObject();
			auto& props = points->GetPropertyNames();

			if (props->Length() == 0)
			{
				NanReturnUndefined();
			}

			std::vector<ofVec4f> points_to_pass;
			points_to_pass.reserve(props->Length());

			for (auto it = 0; it < props->Length(); ++it)
			{
				points_to_pass.push_back(*ObjectWrap::Unwrap<OfVec4fWrap>(points->Get(props->Get(it))->ToObject())->GetWrapped());
			}

			self->average(&points_to_pass[0], points_to_pass.size());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::Distance)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->distance(*ObjectWrap::Unwrap<OfVec4fWrap>(args[0]->ToObject())->GetWrapped()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::DistanceSquared)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->distanceSquared(*ObjectWrap::Unwrap<OfVec4fWrap>(args[0]->ToObject())->GetWrapped()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::Dot)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->dot(*ObjectWrap::Unwrap<OfVec4fWrap>(args[0]->ToObject())->GetWrapped()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::GetInterpolated)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec4fWrap>(newInst)->SetWrapped(
				self->getInterpolated(
				*ObjectWrap::Unwrap<OfVec4fWrap>(
				args[0]->ToObject())->GetWrapped(), args[1]->NumberValue()));
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::GetLimited)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec4fWrap>(newInst)->SetWrapped(
				self->getLimited(args[0]->NumberValue()));
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::GetMiddle)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec4fWrap>(newInst)->SetWrapped(self->getMiddle(*ObjectWrap::Unwrap<OfVec4fWrap>(args[0]->ToObject())->GetWrapped()));
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::GetNormalized)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec4fWrap>(newInst)->SetWrapped(self->getNormalized());
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::GetPtr)
		{
			auto JsFloatPtr = DepNewInstance(DEP_floatPtr);
			auto PtrSelf = ObjectWrap::Unwrap<nofx::Pointer::PointerWrap<float>>(JsFloatPtr->ToObject());
			PtrSelf->SetDisplayLength(3);
			PtrSelf->SetWrapped(ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped()->getPtr());
			NanReturnValue(JsFloatPtr);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::GetScaled)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			ObjectWrap::Unwrap<OfVec4fWrap>(newInst)->SetWrapped(self->getScaled(
				args[0]->NumberValue()
				));

			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::Interpolate)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			self->interpolate(*ObjectWrap::Unwrap<OfVec4fWrap>(args[0]->ToObject())->GetWrapped(), args[1]->NumberValue());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::Length)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->length());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::LengthSquared)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->lengthSquared());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::Limit)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			self->limit(args[0]->NumberValue());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::Match)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec4fWrap>(args[0]->ToObject())->GetWrapped();
			if (args.Length() == 1) {
				NanReturnValue(self->match(*target));
			}
			else
			{
				NanReturnValue(self->match(*target, args[1]->NumberValue()));
			};
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::Middle)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			self->middle(
				*ObjectWrap::Unwrap<OfVec4fWrap>(args[0]->ToObject())->GetWrapped()
				);
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::Normalize)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			self->normalize();
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::One)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			ObjectWrap::Unwrap<OfVec4fWrap>(newInst)->SetWrapped(ofVec4f::one());

			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::Scale)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			self->scale(args[0]->NumberValue());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::Set)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();

			if (args.Length() == 1 && args[0]->IsNumber())
			{
				//self->set(args[0]->NumberValue()); //this exists in OF headers but not implemented? :|
			}
			else if (args.Length() == 3)
			{
				self->set(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
			}
			else
			{
				//copy constructor
				self->set(*ObjectWrap::Unwrap<OfVec4fWrap>(args[0]->ToObject())->GetWrapped());
			}

			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::SquareDistance)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->squareDistance(*ObjectWrap::Unwrap<OfVec4fWrap>(args[0]->ToObject())->GetWrapped()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec4fWrap::Zero)
		{
			auto self = ObjectWrap::Unwrap<OfVec4fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			ObjectWrap::Unwrap<OfVec4fWrap>(newInst)->SetWrapped(ofVec4f::zero());

			NanReturnValue(newInst);
		}

	} //!namespace OfVec4f
} //!namespace nofx
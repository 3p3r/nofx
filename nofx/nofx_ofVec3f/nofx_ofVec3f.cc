#include "nofx_ofVec3f.h"
#include "..\nofx\nofx_types.h"
#include "..\nofx_pointer\nofx_pointer.h"
#include "..\nofx_ofVec2f\nofx_ofVec2f.h"
#include "..\nofx_ofVec4f\nofx_ofVec4f.h"

namespace nofx
{
	namespace OfVec3f
	{
		using node::ObjectWrap;

		Persistent<Function> OfVec3fWrap::constructor;

		OfVec3fWrap::OfVec3fWrap()
			: internal_(nullptr)
		{}

		//--------------------------------------------------------------
		OfVec3fWrap::OfVec3fWrap(ofVec3f* aInternal)
			: internal_(aInternal)
		{}

		//--------------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfVec3fWrap* obj;

				if (args[0]->IsNull())
				{
					obj = new OfVec3fWrap(nullptr);
				}
				else if (args.Length() == 0)
				{
					obj = new OfVec3fWrap(new ofVec3f());
				}
				else if (args.Length() == 1)
				{
					if (args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() == NOFX_TYPES::OFVEC2F)
					{
						obj = new OfVec3fWrap(new ofVec3f(*ObjectWrap::Unwrap<nofx::OfVec2f::OfVec2fWrap>(args[0]->ToObject())->GetWrapped()));
					}
					else if (args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() == NOFX_TYPES::OFVEC4F)
					{
						obj = new OfVec3fWrap(new ofVec3f(*ObjectWrap::Unwrap<nofx::OfVec4f::OfVec4fWrap>(args[0]->ToObject())->GetWrapped()));
					}
					else
					{
						obj = new OfVec3fWrap(new ofVec3f(args[0]->NumberValue()));
					}
				}
				else if (args.Length() == 2)
				{
					obj = new OfVec3fWrap(new ofVec3f(args[0]->NumberValue(), args[1]->NumberValue(), 0));
				}
				else if (args.Length() == 3)
				{
					obj = new OfVec3fWrap(new ofVec3f(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()));
				}
				else if (args[0]->IsNull())
				{
					obj = new OfVec3fWrap(nullptr);
				}
				else
				{
					//copy constructor
					obj = new OfVec3fWrap(ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped());
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
		void OfVec3fWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofVec3f"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);

			inst->SetAccessor(NanNew("DIM"), OfVec3fWrap::GetDIM, 0, v8::Handle<v8::Value>(), v8::PROHIBITS_OVERWRITING);
			inst->SetAccessor(NanNew("x"), OfVec3fWrap::GetX, OfVec3fWrap::SetX);
			inst->SetAccessor(NanNew("y"), OfVec3fWrap::GetY, OfVec3fWrap::SetY);
			inst->SetAccessor(NanNew("z"), OfVec3fWrap::GetZ, OfVec3fWrap::SetZ);
			inst->SetIndexedPropertyHandler(OfVec3fWrap::IndexGetter, OfVec3fWrap::IndexSetter);

			NanSetPrototypeTemplate(tpl, NanNew("align"), NanNew<v8::FunctionTemplate>(Align), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("alignRad"), NanNew<v8::FunctionTemplate>(AlignRad), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("angle"), NanNew<v8::FunctionTemplate>(Angle), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("angleRad"), NanNew<v8::FunctionTemplate>(AngleRad), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("average"), NanNew<v8::FunctionTemplate>(Average), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("cross"), NanNew<v8::FunctionTemplate>(Cross), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("distance"), NanNew<v8::FunctionTemplate>(Distance), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("dot"), NanNew<v8::FunctionTemplate>(Dot), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getCrossed"), NanNew<v8::FunctionTemplate>(GetCrossed), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getInterpolated"), NanNew<v8::FunctionTemplate>(GetInterpolated), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getLimited"), NanNew<v8::FunctionTemplate>(GetLimited), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getMapped"), NanNew<v8::FunctionTemplate>(GetMapped), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getMiddle"), NanNew<v8::FunctionTemplate>(GetMiddle), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getNormalized"), NanNew<v8::FunctionTemplate>(GetNormalized), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPerpendicular"), NanNew<v8::FunctionTemplate>(GetPerpendicular), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPtr"), NanNew<v8::FunctionTemplate>(GetPtr), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getRotated"), NanNew<v8::FunctionTemplate>(GetRotated), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getRotatedRad"), NanNew<v8::FunctionTemplate>(GetRotatedRad), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getScaled"), NanNew<v8::FunctionTemplate>(GetScaled), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("interpolate"), NanNew<v8::FunctionTemplate>(Interpolate), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isAligned"), NanNew<v8::FunctionTemplate>(IsAligned), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isAlignedRad"), NanNew<v8::FunctionTemplate>(IsAlignedRad), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("length"), NanNew<v8::FunctionTemplate>(Length), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("limit"), NanNew<v8::FunctionTemplate>(Limit), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("map"), NanNew<v8::FunctionTemplate>(Map), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("match"), NanNew<v8::FunctionTemplate>(Match), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("middle"), NanNew<v8::FunctionTemplate>(Middle), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("normalize"), NanNew<v8::FunctionTemplate>(Normalize), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("one"), NanNew<v8::FunctionTemplate>(One), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("perpendicular"), NanNew<v8::FunctionTemplate>(Perpendicular), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("rotate"), NanNew<v8::FunctionTemplate>(Rotate), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("rotateRad"), NanNew<v8::FunctionTemplate>(RotateRad), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("scale"), NanNew<v8::FunctionTemplate>(Scale), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("set"), NanNew<v8::FunctionTemplate>(Set), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("squareDistance"), NanNew<v8::FunctionTemplate>(SquareDistance), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("zero"), NanNew<v8::FunctionTemplate>(Zero), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFVEC3F), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofVec3f"), tpl->GetFunction());
		}

		NAN_INDEX_GETTER(OfVec3fWrap::IndexGetter)
		{
			NanReturnValue(ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped()->getPtr()[index]);
		}
		NAN_INDEX_SETTER(OfVec3fWrap::IndexSetter)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			self->getPtr()[index] = value->NumberValue();
		}

		NAN_GETTER(OfVec3fWrap::GetDIM)
		{
			const auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->DIM);
		}
		//----------------------------------------------------

		NAN_GETTER(OfVec3fWrap::GetX)
		{
			const auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->x);
		}
		//----------------------------------------------------

		NAN_GETTER(OfVec3fWrap::GetY)
		{
			const auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->y);
		}
		//----------------------------------------------------

		NAN_GETTER(OfVec3fWrap::GetZ)
		{
			const auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->z);
		}
		//----------------------------------------------------

		NAN_SETTER(OfVec3fWrap::SetX)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			self->x = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfVec3fWrap::SetY)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			self->y = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfVec3fWrap::SetZ)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			self->z = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_METHOD(OfVec3fWrap::Align)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped();
			if (args.Length() == 1) {
				NanReturnValue(self->align(*target));
			}
			else
			{
				NanReturnValue(self->align(*target, args[1]->NumberValue()));
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::AlignRad)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped();
			if (args.Length() == 1) {
				NanReturnValue(self->alignRad(*target));
			}
			else
			{
				NanReturnValue(self->alignRad(*target, args[1]->NumberValue()));
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Angle)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped();
			NanReturnValue(self->angle(*target));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::AngleRad)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped();
			NanReturnValue(self->angleRad(*target));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Average)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			auto& points = args[0]->ToObject();
			auto& props = points->GetPropertyNames();

			if (props->Length() == 0)
			{
				NanReturnUndefined();
			}

			std::vector<ofVec3f> points_to_pass;
			points_to_pass.reserve(props->Length());

			for (auto it = 0; it < props->Length(); ++it)
			{
				points_to_pass.push_back(*ObjectWrap::Unwrap<OfVec3fWrap>(points->Get(props->Get(it))->ToObject())->GetWrapped());
			}

			self->average(&points_to_pass[0], points_to_pass.size());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Cross)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			self->cross(*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Distance)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->distance(*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Dot)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->dot(*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetCrossed)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(self->getCrossed(*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped()));
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetInterpolated)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(
				self->getInterpolated(
				*ObjectWrap::Unwrap<OfVec3fWrap>(
				args[0]->ToObject())->GetWrapped(), args[1]->NumberValue()));
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetLimited)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(
				self->getLimited(args[0]->NumberValue()));
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetMapped)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(
				self->getMapped(
				*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
				*ObjectWrap::Unwrap<OfVec3fWrap>(args[1]->ToObject())->GetWrapped(),
				*ObjectWrap::Unwrap<OfVec3fWrap>(args[2]->ToObject())->GetWrapped(),
				*ObjectWrap::Unwrap<OfVec3fWrap>(args[3]->ToObject())->GetWrapped()
				));
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetMiddle)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(self->getMiddle(*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped()));
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetNormalized)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(self->getNormalized());
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetPerpendicular)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(self->getPerpendicular(*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped()));
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetPtr)
		{
			auto JsFloatPtr = DepNewInstance(DEP_floatPtr);
			auto PtrSelf = ObjectWrap::Unwrap<nofx::Pointer::NumberPointerWrap<float>>(JsFloatPtr->ToObject());
			PtrSelf->SetDisplayLength(3);
			PtrSelf->SetWrapped(ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped()->getPtr());
			NanReturnValue(JsFloatPtr);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetRotated)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			if (args.Length() == 2)
			{
				ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(self->getRotated(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<OfVec3fWrap>(args[1]->ToObject())->GetWrapped()
					));
			}
			else if (args[1]->IsNumber())
			{
				ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(self->getRotated(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue()
					));
			}
			else
			{
				ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(self->getRotated(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<OfVec3fWrap>(args[1]->ToObject())->GetWrapped(),
					*ObjectWrap::Unwrap<OfVec3fWrap>(args[2]->ToObject())->GetWrapped()
					));
			}

			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetRotatedRad)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			if (args.Length() == 2)
			{
				ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(self->getRotatedRad(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<OfVec3fWrap>(args[1]->ToObject())->GetWrapped()
					));
			}
			else if (args[1]->IsNumber())
			{
				ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(self->getRotatedRad(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue()
					));
			}
			else
			{
				ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(self->getRotatedRad(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<OfVec3fWrap>(args[1]->ToObject())->GetWrapped(),
					*ObjectWrap::Unwrap<OfVec3fWrap>(args[2]->ToObject())->GetWrapped()
					));
			}

			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetScaled)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(self->getScaled(
				args[0]->NumberValue()
				));

			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Interpolate)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			self->interpolate(*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped(), args[1]->NumberValue());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::IsAligned)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped();
			if (args.Length() == 1) {
				NanReturnValue(self->isAligned(*target));
			}
			else
			{
				NanReturnValue(self->isAligned(*target, args[1]->NumberValue()));
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::IsAlignedRad)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped();
			if (args.Length() == 1) {
				NanReturnValue(self->isAlignedRad(*target));
			}
			else
			{
				NanReturnValue(self->isAlignedRad(*target, args[1]->NumberValue()));
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Length)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->length());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Limit)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			self->limit(args[0]->NumberValue());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Map)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			self->map(
				*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
				*ObjectWrap::Unwrap<OfVec3fWrap>(args[1]->ToObject())->GetWrapped(),
				*ObjectWrap::Unwrap<OfVec3fWrap>(args[2]->ToObject())->GetWrapped(),
				*ObjectWrap::Unwrap<OfVec3fWrap>(args[3]->ToObject())->GetWrapped()
				);
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Match)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped();
			if (args.Length() == 1) {
				NanReturnValue(self->match(*target));
			}
			else
			{
				NanReturnValue(self->match(*target, args[1]->NumberValue()));
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Middle)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			self->middle(
				*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped()
				);
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Normalize)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			self->normalize();
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::One)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(ofVec3f::one());

			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Perpendicular)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			self->perpendicular(
				*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped()
				);
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Rotate)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			if (args.Length() == 2)
			{
				self->rotate(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<OfVec3fWrap>(args[1]->ToObject())->GetWrapped()
					);
			}
			else if (args[1]->IsNumber())
			{
				self->rotate(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue()
					);
			}
			else
			{
				self->rotate(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<OfVec3fWrap>(args[1]->ToObject())->GetWrapped(),
					*ObjectWrap::Unwrap<OfVec3fWrap>(args[2]->ToObject())->GetWrapped()
					);
			}

			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::RotateRad)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			if (args.Length() == 2)
			{
				self->rotateRad(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<OfVec3fWrap>(args[1]->ToObject())->GetWrapped()
					);
			}
			else if (args[1]->IsNumber())
			{
				self->rotateRad(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue()
					);
			}
			else
			{
				self->rotateRad(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<OfVec3fWrap>(args[1]->ToObject())->GetWrapped(),
					*ObjectWrap::Unwrap<OfVec3fWrap>(args[2]->ToObject())->GetWrapped()
					);
			}

			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Scale)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			self->scale(args[0]->NumberValue());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Set)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();

			if (args.Length() == 1 && args[0]->IsNumber())
			{
				self->set(args[0]->NumberValue());
			}
			else if (args.Length() == 3)
			{
				self->set(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
			}
			else
			{
				//copy constructor
				self->set(*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped());
			}

			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::SquareDistance)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->squareDistance(*ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Zero)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			ObjectWrap::Unwrap<OfVec3fWrap>(newInst)->SetWrapped(ofVec3f::zero());

			NanReturnValue(newInst);
		}

	} //!namespace OfVec3f
} //!namespace nofx
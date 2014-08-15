#include "nofx_ofVec2f.h"
#include "..\nofx\nofx_types.h"
#include "..\nofx_pointer\nofx_pointer.h"
#include "..\nofx_ofVec3f\nofx_ofVec3f.h"

namespace nofx
{
	namespace OfVec2f
	{
		using node::ObjectWrap;

		Persistent<Function> OfVec2fWrap::constructor;

		OfVec2fWrap::OfVec2fWrap()
			: internal_(nullptr)
		{}

		//--------------------------------------------------------------
		OfVec2fWrap::OfVec2fWrap(ofVec2f* aInternal)
			: internal_(aInternal)
		{}

		//--------------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfVec2fWrap* obj;

				//depends on ofVec4f
				if (args.Length() == 0)
				{
					obj = new OfVec2fWrap(new ofVec2f());
				}
				else if (args.Length() == 1)
				{
					if (args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() == NOFX_TYPES::OFVEC3F)
					{
						obj = new OfVec2fWrap(new ofVec2f(*ObjectWrap::Unwrap<nofx::OfVec3f::OfVec3fWrap>(args[0]->ToObject())->GetWrapped()));
					}
					else
					{
						obj = new OfVec2fWrap(new ofVec2f(args[0]->NumberValue()));
					}
				}
				else if (args.Length() == 2)
				{
					obj = new OfVec2fWrap(new ofVec2f(args[0]->NumberValue(), args[1]->NumberValue()));
				}
				else if (args[0]->IsNull())
				{
					obj = new OfVec2fWrap(nullptr);
				}
				else
				{
					//copy constructor
					obj = new OfVec2fWrap(ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped());
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
		void OfVec2fWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofVec2f"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);


			inst->SetAccessor(NanNew("DIM"), OfVec2fWrap::GetDIM, 0, v8::Handle<v8::Value>(), v8::PROHIBITS_OVERWRITING);
			inst->SetAccessor(NanNew("x"), OfVec2fWrap::GetX, OfVec2fWrap::SetX);
			inst->SetAccessor(NanNew("y"), OfVec2fWrap::GetY, OfVec2fWrap::SetY);
			inst->SetIndexedPropertyHandler(OfVec2fWrap::IndexGetter, OfVec2fWrap::IndexSetter);

			NanSetPrototypeTemplate(tpl, NanNew("align"), NanNew<v8::FunctionTemplate>(Align), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("alignRad"), NanNew<v8::FunctionTemplate>(AlignRad), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("angle"), NanNew<v8::FunctionTemplate>(Angle), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("angleRad"), NanNew<v8::FunctionTemplate>(AngleRad), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("average"), NanNew<v8::FunctionTemplate>(Average), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("distance"), NanNew<v8::FunctionTemplate>(Distance), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("dot"), NanNew<v8::FunctionTemplate>(Dot), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getInterpolated"), NanNew<v8::FunctionTemplate>(GetInterpolated), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getLimited"), NanNew<v8::FunctionTemplate>(GetLimited), v8::ReadOnly);
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

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFVEC2F), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofVec2f"), tpl->GetFunction());
		}

		NAN_INDEX_GETTER(OfVec2fWrap::IndexGetter)
		{
			NanReturnValue(ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped()->getPtr()[index]);
		}
		NAN_INDEX_SETTER(OfVec2fWrap::IndexSetter)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			self->getPtr()[index] = value->NumberValue();
		}

		NAN_GETTER(OfVec2fWrap::GetDIM)
		{
			const auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->DIM);
		}
		//----------------------------------------------------

		NAN_GETTER(OfVec2fWrap::GetX)
		{
			const auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->x);
		}
		//----------------------------------------------------

		NAN_GETTER(OfVec2fWrap::GetY)
		{
			const auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->y);
		}
		//----------------------------------------------------

		NAN_SETTER(OfVec2fWrap::SetX)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			self->x = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfVec2fWrap::SetY)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			self->y = value->NumberValue();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Align)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped();
			if (args.Length() == 1) {
				NanReturnValue(self->align(*target));
			}
			else
			{
				NanReturnValue(self->align(*target, args[1]->NumberValue()));
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::AlignRad)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped();
			if (args.Length() == 1) {
				NanReturnValue(self->alignRad(*target));
			}
			else
			{
				NanReturnValue(self->alignRad(*target, args[1]->NumberValue()));
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Angle)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped();
			NanReturnValue(self->angle(*target));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::AngleRad)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped();
			NanReturnValue(self->angleRad(*target));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Average)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			auto& points = args[0]->ToObject();
			auto& props = points->GetPropertyNames();

			if (props->Length() == 0)
			{
				NanReturnUndefined();
			}

			std::vector<ofVec2f> points_to_pass;
			points_to_pass.reserve(props->Length());

			for (auto it = 0; it < props->Length(); ++it)
			{
				points_to_pass.push_back(*ObjectWrap::Unwrap<OfVec2fWrap>(points->Get(props->Get(it))->ToObject())->GetWrapped());
			}

			self->average(&points_to_pass[0], points_to_pass.size());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Distance)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->distance(*ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Dot)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->dot(*ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::GetInterpolated)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec2fWrap>(newInst)->SetWrapped(
				self->getInterpolated(
				*ObjectWrap::Unwrap<OfVec2fWrap>(
				args[0]->ToObject())->GetWrapped(), args[1]->NumberValue()));
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::GetLimited)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec2fWrap>(newInst)->SetWrapped(
				self->getLimited(args[0]->NumberValue()));
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::GetMiddle)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec2fWrap>(newInst)->SetWrapped(self->getMiddle(*ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped()));
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::GetNormalized)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec2fWrap>(newInst)->SetWrapped(self->getNormalized());
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::GetPerpendicular)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);
			ObjectWrap::Unwrap<OfVec2fWrap>(newInst)->SetWrapped(self->getPerpendicular());
			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::GetPtr)
		{
			auto JsFloatPtr = DepNewInstance(DEP_floatPtr);
			auto PtrSelf = ObjectWrap::Unwrap<nofx::Pointer::PointerWrap<float>>(JsFloatPtr->ToObject());
			PtrSelf->SetDisplayLength(2);
			PtrSelf->SetWrapped(ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped()->getPtr());
			NanReturnValue(JsFloatPtr);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::GetRotated)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			if (args.Length() == 1)
			{
				ObjectWrap::Unwrap<OfVec2fWrap>(newInst)->SetWrapped(self->getRotated(
					args[0]->NumberValue()
					));
			}
			else
			{
				ObjectWrap::Unwrap<OfVec2fWrap>(newInst)->SetWrapped(self->getRotated(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<OfVec2fWrap>(args[1]->ToObject())->GetWrapped()
					));
			}

			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::GetRotatedRad)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			if (args.Length() == 1)
			{
				ObjectWrap::Unwrap<OfVec2fWrap>(newInst)->SetWrapped(self->getRotatedRad(
					args[0]->NumberValue()
					));
			}
			else
			{
				ObjectWrap::Unwrap<OfVec2fWrap>(newInst)->SetWrapped(self->getRotatedRad(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<OfVec2fWrap>(args[1]->ToObject())->GetWrapped()
					));
			}

			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::GetScaled)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			ObjectWrap::Unwrap<OfVec2fWrap>(newInst)->SetWrapped(self->getScaled(
				args[0]->NumberValue()
				));

			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Interpolate)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			self->interpolate(*ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped(), args[1]->NumberValue());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::IsAligned)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped();
			if (args.Length() == 1) {
				NanReturnValue(self->isAligned(*target));
			}
			else
			{
				NanReturnValue(self->isAligned(*target, args[1]->NumberValue()));
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::IsAlignedRad)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped();
			if (args.Length() == 1) {
				NanReturnValue(self->isAlignedRad(*target));
			}
			else
			{
				NanReturnValue(self->isAlignedRad(*target, args[1]->NumberValue()));
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Length)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->length());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Limit)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			self->limit(args[0]->NumberValue());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Map)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			self->map(
				*ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped(),
				*ObjectWrap::Unwrap<OfVec2fWrap>(args[1]->ToObject())->GetWrapped(),
				*ObjectWrap::Unwrap<OfVec2fWrap>(args[2]->ToObject())->GetWrapped()
				);
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Match)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			auto target = ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped();
			if (args.Length() == 1) {
				NanReturnValue(self->match(*target));
			}
			else
			{
				NanReturnValue(self->match(*target, args[1]->NumberValue()));
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Middle)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			self->middle(
				*ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped()
				);
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Normalize)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			self->normalize();
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::One)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			ObjectWrap::Unwrap<OfVec2fWrap>(newInst)->SetWrapped(ofVec2f::one());

			NanReturnValue(newInst);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Perpendicular)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			self->perpendicular();
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Rotate)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			if (args.Length() == 1)
			{
				self->rotate(
					args[0]->NumberValue()
					);
			}
			else
			{
				self->rotate(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<OfVec2fWrap>(args[1]->ToObject())->GetWrapped()
					);
			}

			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::RotateRad)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			if (args.Length() == 1)
			{
				self->rotateRad(
					args[0]->NumberValue()
					);
			}
			else
			{
				self->rotateRad(
					args[0]->NumberValue(),
					*ObjectWrap::Unwrap<OfVec2fWrap>(args[1]->ToObject())->GetWrapped()
					);
			}

			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Scale)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			self->scale(args[0]->NumberValue());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Set)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();

			if (args.Length() == 1 && args[0]->IsNumber())
			{
				self->set(args[0]->NumberValue());
			}
			else if (args.Length() == 2)
			{
				self->set(args[0]->NumberValue(), args[1]->NumberValue());
			}
			else
			{
				//copy constructor
				self->set(*ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped());
			}

			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::SquareDistance)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			NanReturnValue(self->squareDistance(*ObjectWrap::Unwrap<OfVec2fWrap>(args[0]->ToObject())->GetWrapped()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec2fWrap::Zero)
		{
			auto self = ObjectWrap::Unwrap<OfVec2fWrap>(args.This())->GetWrapped();
			Local<Value> argv[] = { v8::Null(v8::Isolate::GetCurrent()) };
			auto newInst = NanNew(Factory())->NewInstance(1, argv);

			ObjectWrap::Unwrap<OfVec2fWrap>(newInst)->SetWrapped(ofVec2f::zero());

			NanReturnValue(newInst);
		}

	} //!namespace OfVec2f
} //!namespace nofx
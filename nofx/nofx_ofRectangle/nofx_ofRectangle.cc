#include "nofx_ofRectangle.h"
#include "..\nofx\nofx_types.h"
#include "..\nofx_ofVec3f\nofx_ofVec3f.h"

namespace nofx
{
	namespace OfRectangle
	{
		using node::ObjectWrap;

		Persistent<Function> OfRectangleWrap::constructor;

		//--------------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfRectangleWrap* obj;
				if (args[0]->IsNull())
				{
					obj = new OfRectangleWrap(nullptr);
				}
				else if (args.Length() == 0)
				{
					obj = new OfRectangleWrap(new ofRectangle());
				}
				else if (args.Length() == 2)
				{
					obj = new OfRectangleWrap(new ofRectangle(
						*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
						*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[1]->ToObject())->GetWrapped()
						));
				}
				else if (args.Length() == 3)
				{
					obj = new OfRectangleWrap(new ofRectangle(
						*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
						args[1]->NumberValue(),
						args[2]->NumberValue()
						));
				}
				else if (args.Length() == 4)
				{
					obj = new OfRectangleWrap(new ofRectangle(
						args[0]->NumberValue(),
						args[1]->NumberValue(),
						args[2]->NumberValue(),
						args[3]->NumberValue()
						));
				}
				else
				{
					//copy constructor
					obj = new OfRectangleWrap(ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped());
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
		void OfRectangleWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofRectangle"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);


			inst->SetAccessor(NanNew("height"), OfRectangleWrap::GetHeight, OfRectangleWrap::SetHeight);
			inst->SetAccessor(NanNew("position"), OfRectangleWrap::GetPosition, OfRectangleWrap::SetPosition);
			inst->SetAccessor(NanNew("width"), OfRectangleWrap::GetWidth, OfRectangleWrap::SetWidth);
			inst->SetAccessor(NanNew("x"), OfRectangleWrap::GetX, OfRectangleWrap::SetX);
			inst->SetAccessor(NanNew("y"), OfRectangleWrap::GetY, OfRectangleWrap::SetY);

			NanSetPrototypeTemplate(tpl, NanNew("alignTo"), NanNew<v8::FunctionTemplate>(AlignTo), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("alignToHorz"), NanNew<v8::FunctionTemplate>(AlignToHorz), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("alignToVert"), NanNew<v8::FunctionTemplate>(AlignToVert), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getArea"), NanNew<v8::FunctionTemplate>(GetArea), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getAspectRatio"), NanNew<v8::FunctionTemplate>(GetAspectRatio), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getBottom"), NanNew<v8::FunctionTemplate>(GetBottom), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getBottomLeft"), NanNew<v8::FunctionTemplate>(GetBottomLeft), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getBottomRight"), NanNew<v8::FunctionTemplate>(GetBottomRight), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getCenter"), NanNew<v8::FunctionTemplate>(GetCenter), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getHeight"), NanNew<v8::FunctionTemplate>(GetHeight), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getHorzAnchor"), NanNew<v8::FunctionTemplate>(GetHorzAnchor), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getIntersection"), NanNew<v8::FunctionTemplate>(GetIntersection), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getLeft"), NanNew<v8::FunctionTemplate>(GetLeft), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getMax"), NanNew<v8::FunctionTemplate>(GetMax), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getMaxX"), NanNew<v8::FunctionTemplate>(GetMaxX), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getMaxY"), NanNew<v8::FunctionTemplate>(GetMaxY), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getMin"), NanNew<v8::FunctionTemplate>(GetMin), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getMinX"), NanNew<v8::FunctionTemplate>(GetMinX), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getMinY"), NanNew<v8::FunctionTemplate>(GetMinY), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPerimeter"), NanNew<v8::FunctionTemplate>(GetPerimeter), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPosition"), NanNew<v8::FunctionTemplate>(GetPosition), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPositionRef"), NanNew<v8::FunctionTemplate>(GetPositionRef), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getRight"), NanNew<v8::FunctionTemplate>(GetRight), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getStandardized"), NanNew<v8::FunctionTemplate>(GetStandardized), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getTop"), NanNew<v8::FunctionTemplate>(GetTop), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getTopLeft"), NanNew<v8::FunctionTemplate>(GetTopLeft), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getTopRight"), NanNew<v8::FunctionTemplate>(GetTopRight), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getUnion"), NanNew<v8::FunctionTemplate>(GetUnion), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getVertAnchor"), NanNew<v8::FunctionTemplate>(GetVertAnchor), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getWidth"), NanNew<v8::FunctionTemplate>(GetWidth), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getX"), NanNew<v8::FunctionTemplate>(GetX), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getY"), NanNew<v8::FunctionTemplate>(GetY), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("growToInclude"), NanNew<v8::FunctionTemplate>(GrowToInclude), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("inside"), NanNew<v8::FunctionTemplate>(Inside), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("intersects"), NanNew<v8::FunctionTemplate>(Intersects), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isEmpty"), NanNew<v8::FunctionTemplate>(IsEmpty), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isStandardized"), NanNew<v8::FunctionTemplate>(IsStandardized), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("scale"), NanNew<v8::FunctionTemplate>(Scale), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("scaleFromCenter"), NanNew<v8::FunctionTemplate>(ScaleFromCenter), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("scaleHeight"), NanNew<v8::FunctionTemplate>(ScaleHeight), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("scaleTo"), NanNew<v8::FunctionTemplate>(ScaleTo), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("scaleWidth"), NanNew<v8::FunctionTemplate>(ScaleWidth), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("set"), NanNew<v8::FunctionTemplate>(Set), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setFromCenter"), NanNew<v8::FunctionTemplate>(SetFromCenter), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setHeight"), NanNew<v8::FunctionTemplate>(SetHeight), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setPosition"), NanNew<v8::FunctionTemplate>(SetPosition), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setWidth"), NanNew<v8::FunctionTemplate>(SetWidth), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setX"), NanNew<v8::FunctionTemplate>(SetX), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setY"), NanNew<v8::FunctionTemplate>(SetY), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("standardize"), NanNew<v8::FunctionTemplate>(Standardize), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("translate"), NanNew<v8::FunctionTemplate>(Translate), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("translateX"), NanNew<v8::FunctionTemplate>(TranslateX), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("translateY"), NanNew<v8::FunctionTemplate>(TranslateY), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFRECTANGLE), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofRectangle"), tpl->GetFunction());
		}


		NAN_GETTER(OfRectangleWrap::GetHeight)
		{
			const auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->height);
		}
		//----------------------------------------------------

		NAN_GETTER(OfRectangleWrap::GetPosition)
		{
			const auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto JsVec3f = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(JsVec3f->ToObject())->SetWrapped(self->position);
			NanReturnValue( JsVec3f );
		}
		//----------------------------------------------------

		NAN_GETTER(OfRectangleWrap::GetWidth)
		{
			const auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->width);
		}
		//----------------------------------------------------

		NAN_GETTER(OfRectangleWrap::GetX)
		{
			const auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->x);
		}
		//----------------------------------------------------

		NAN_GETTER(OfRectangleWrap::GetY)
		{
			const auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->y);
		}
		//----------------------------------------------------


		NAN_SETTER(OfRectangleWrap::SetHeight)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->height = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfRectangleWrap::SetPosition)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->position.set(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(value->ToObject())->GetWrapped());
		}
		//----------------------------------------------------

		NAN_SETTER(OfRectangleWrap::SetWidth)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->width = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfRectangleWrap::SetX)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->x = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfRectangleWrap::SetY)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->y = value->NumberValue();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::AlignTo)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();

			if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFVEC3F)
			{
				ofAlignHorz thisHorzAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_HORZ_CENTER : (ofAlignHorz)args[1]->Uint32Value();
				ofAlignVert thisVertAnchor = (args[2]->IsUndefined()) ? OF_ALIGN_VERT_CENTER : (ofAlignVert)args[2]->Uint32Value();
				self->alignTo(
					*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
					thisHorzAnchor,
					thisVertAnchor
					);
			}
			else if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFRECTANGLE)
			{
				ofAlignHorz thisHorzAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_HORZ_CENTER : (ofAlignHorz)args[1]->Uint32Value();
				ofAlignVert thisVertAnchor = (args[2]->IsUndefined()) ? OF_ALIGN_VERT_CENTER : (ofAlignVert)args[2]->Uint32Value();
				self->alignTo(
					*node::ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped(),
					thisHorzAnchor,
					thisVertAnchor
					);
			}
			else
			{
				ofAlignHorz targetHorzAnchor = (ofAlignHorz)args[1]->Uint32Value();
				ofAlignVert targetVertAnchor = (ofAlignVert)args[2]->Uint32Value();
				ofAlignHorz thisHorzAnchor = (ofAlignHorz)args[3]->Uint32Value();
				ofAlignVert thisVertAnchor = (ofAlignVert)args[4]->Uint32Value();
				self->alignTo(
					*node::ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped(),
					targetHorzAnchor,
					targetVertAnchor,
					thisHorzAnchor,
					thisVertAnchor
					);
			}

			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::AlignToHorz)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();

			if (args.Length() == 1 && args[0]->IsNumber())
			{
				ofAlignHorz thisHorzAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_HORZ_CENTER : (ofAlignHorz)args[1]->Uint32Value();
				self->alignToHorz(
					args[0]->NumberValue(),
					thisHorzAnchor
					);
			}
			else if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFRECTANGLE)
			{
				ofAlignHorz thisHorzAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_HORZ_CENTER : (ofAlignHorz)args[1]->Uint32Value();
				self->alignToHorz(
					*node::ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped(),
					thisHorzAnchor
					);
			}
			else
			{
				ofAlignHorz targetHorzAnchor = (ofAlignHorz)args[1]->Uint32Value();
				ofAlignHorz thisHorzAnchor = (ofAlignHorz)args[2]->Uint32Value();
				self->alignToHorz(
					*node::ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped(),
					targetHorzAnchor,
					thisHorzAnchor
					);
			}

			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::AlignToVert)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			if (args.Length() == 1 && args[0]->IsNumber())
			{
				ofAlignVert sharedAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_VERT_CENTER : (ofAlignVert)args[1]->Uint32Value();
				self->alignToVert(
					args[0]->NumberValue(),
					sharedAnchor
					);
			}
			else if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFRECTANGLE)
			{
				ofAlignVert sharedAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_VERT_CENTER : (ofAlignVert)args[1]->Uint32Value();
				self->alignToVert(
					*node::ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped(),
					sharedAnchor
					);
			}
			else
			{
				ofAlignVert targetVertAnchor = (ofAlignVert)args[1]->Uint32Value();
				ofAlignVert thisVertAnchor = (ofAlignVert)args[2]->Uint32Value();
				self->alignToVert(
					*node::ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped(),
					targetVertAnchor,
					thisVertAnchor
					);
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetArea)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getArea());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetAspectRatio)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getAspectRatio());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetBottom)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getBottom());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetBottomLeft)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto JsVec3f = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(JsVec3f->ToObject())->SetWrapped(self->getBottomLeft());
			NanReturnValue(JsVec3f);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetBottomRight)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto JsVec3f = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(JsVec3f->ToObject())->SetWrapped(self->getBottomRight());
			NanReturnValue(JsVec3f);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetCenter)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto JsVec3f = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(JsVec3f->ToObject())->SetWrapped(self->getCenter());
			NanReturnValue(JsVec3f);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetHeight)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getHeight());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetHorzAnchor)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getHorzAnchor((ofAlignHorz)args[0]->Uint32Value()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetIntersection)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto lToRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfRectangleWrap>(lToRet)->SetWrapped( self->getIntersection(*node::ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped()) );
			NanReturnValue(lToRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetLeft)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getLeft());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetMax)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto JsVec3f = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(JsVec3f->ToObject())->SetWrapped(self->getMax());
			NanReturnValue(JsVec3f);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetMaxX)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getMaxX());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetMaxY)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getMaxY());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetMin)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto JsVec3f = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(JsVec3f->ToObject())->SetWrapped(self->getMin());
			NanReturnValue(JsVec3f);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetMinX)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getMinX());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetMinY)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getMinY());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetPerimeter)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getPerimeter());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetPosition)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto JsVec3f = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(JsVec3f->ToObject())->SetWrapped(self->getPosition());
			NanReturnValue(JsVec3f);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetPositionRef)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto JsVec3f = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(JsVec3f->ToObject())->SetWrapped(self->getPositionRef());
			NanReturnValue(JsVec3f);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetRight)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getRight());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetStandardized)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto lToRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfRectangleWrap>(lToRet)->SetWrapped(self->getStandardized());
			NanReturnValue(lToRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetTop)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getTop());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetTopLeft)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto JsVec3f = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(JsVec3f->ToObject())->SetWrapped(self->getTopLeft());
			NanReturnValue(JsVec3f);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetTopRight)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto JsVec3f = DepNewInstance(DEP_ofVec3f);
			ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(JsVec3f->ToObject())->SetWrapped(self->getTopRight());
			NanReturnValue(JsVec3f);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetUnion)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			auto lToRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfRectangleWrap>(lToRet)->SetWrapped(self->getUnion(*ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped()));
			NanReturnValue(lToRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetVertAnchor)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getVertAnchor((ofAlignVert)args[0]->Uint32Value()));
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetWidth)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getWidth());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetX)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getX());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GetY)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getY());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::GrowToInclude)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFVEC3F)
			{
				self->growToInclude(*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped());
			}
			else if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFRECTANGLE)
			{
				self->growToInclude(*node::ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped());
			}
			else if (args.Length() == 2 && args[0]->IsNumber())
			{
				self->growToInclude(
					args[0]->NumberValue(),
					args[1]->NumberValue()
					);
			}
			else
			{
				self->growToInclude(
					*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
					*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[1]->ToObject())->GetWrapped()
					);
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::Inside)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			bool result = false;
			if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFVEC3F)
			{
				result = self->inside(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped());
			}
			else if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFRECTANGLE)
			{
				result = self->inside(*ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped());
			}
			else if (args.Length() == 2 && args[0]->IsNumber())
			{
				result = self->inside(
					args[0]->NumberValue(),
					args[1]->NumberValue()
					);
			}
			else
			{
				result = self->inside(
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[1]->ToObject())->GetWrapped()
					);
			}
			NanReturnValue(result);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::Intersects)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			bool result = false;
			if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFRECTANGLE)
			{
				result = self->intersects(*ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped());
			}
			else
			{
				result = self->intersects(
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[1]->ToObject())->GetWrapped()
					);
			}
			NanReturnValue(result);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::IsEmpty)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->isEmpty());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::IsStandardized)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			NanReturnValue(self->isStandardized());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::Scale)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFVEC3F)
			{
				self->scale(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped());
			}
			else if (args.Length() == 1)
			{
				self->scale(args[0]->NumberValue());
			}
			else
			{
				self->scale(args[0]->NumberValue(), args[1]->NumberValue());
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::ScaleFromCenter)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFVEC3F)
			{
				self->scaleFromCenter(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped());
			}
			else if (args.Length() == 1)
			{
				self->scaleFromCenter(args[0]->NumberValue());
			}
			else
			{
				self->scaleFromCenter(args[0]->NumberValue(), args[1]->NumberValue());
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::ScaleHeight)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->scaleHeight(args[0]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::ScaleTo)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			if (args.Length() >= 1 && args[0]->ToObject()->Get(NanNew("NOFX_TYPE"))->Uint32Value() & NOFX_TYPES::OFRECTANGLE)
			{
				ofScaleMode  scaleMode = (args[1]->IsUndefined()) ? OF_SCALEMODE_FIT : (ofScaleMode)args[1]->Uint32Value();
				self->scaleTo(
					*ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped(),
					scaleMode
					);
			}
			else if (args.Length() >= 2 && args.Length() <= 4 && args[0]->ToObject()->Get(NanNew("NOFX_TYPES"))->Uint32Value() & NOFX_TYPES::OFRECTANGLE)
			{
				ofAlignHorz sharedHorzAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_HORZ_CENTER : (ofAlignHorz)args[1]->Uint32Value();
				ofAlignVert sharedVertAnchor = (args[2]->IsUndefined()) ? OF_ALIGN_VERT_CENTER : (ofAlignVert)args[2]->Uint32Value();
				self->scaleTo(
					*ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped(),
					(ofAspectRatioMode)args[1]->Uint32Value(),
					sharedHorzAnchor,
					sharedVertAnchor
					);
			}
			else
			{
				self->scaleTo(
					*ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped(),
					(ofAspectRatioMode)args[1]->Uint32Value(),
					(ofAlignHorz)args[2]->Uint32Value(),
					(ofAlignVert)args[3]->Uint32Value(),
					(ofAlignHorz)args[4]->Uint32Value(),
					(ofAlignVert)args[5]->Uint32Value()
					);
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::ScaleWidth)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->scaleWidth(args[0]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::Set)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			
			if (args.Length() == 2)
			{
				self->set(
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[1]->ToObject())->GetWrapped()
					);
			}
			else if (args.Length() == 3)
			{
				self->set(
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
					args[1]->NumberValue(),
					args[2]->NumberValue()
					);
			}
			else if (args.Length() == 4)
			{
				self->set(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue(),
					args[3]->NumberValue()
					);
			}
			else
			{
				//copy constructor
				self->set(*ObjectWrap::Unwrap<OfRectangleWrap>(args[0]->ToObject())->GetWrapped());
			}

			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::SetFromCenter)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			
			if (args.Length() == 3)
			{
				self->setFromCenter(
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
					args[1]->NumberValue(),
					args[2]->NumberValue()
					);
			}
			else if (args.Length() == 4)
			{
				self->setFromCenter(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					args[2]->NumberValue(),
					args[3]->NumberValue()
					);
			}

			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::SetHeight)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->setHeight(args[0]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::SetPosition)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			if (args.Length() == 2)
			{
				self->setPosition(
					args[1]->NumberValue(),
					args[2]->NumberValue()
					);
			}
			else if (args.Length() == 4)
			{
				self->setPosition(
					*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped()
					);
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::SetWidth)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->setWidth(args[0]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::SetX)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->setX(args[0]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::SetY)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->setY(args[0]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::Standardize)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->standardize();
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::Translate)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			if (args.Length() == 2)
			{
				self->translate(args[0]->NumberValue(), args[1]->NumberValue());
			}
			else
			{
				self->translate(*ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args.This())->GetWrapped());
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::TranslateX)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->translateX(args[0]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfRectangleWrap::TranslateY)
		{
			auto self = ObjectWrap::Unwrap<OfRectangleWrap>(args.This())->GetWrapped();
			self->translateY(args[0]->NumberValue());
			NanReturnUndefined();
		}

	} //!namespace OfRectangle
} //!namespace nofx
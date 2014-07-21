#include "ofxNode_wrapper_ofRectangle.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
	v8::Persistent<v8::Function> ofxNode_ofRectangle::constructor;

	ofxNode_ofRectangle::ofxNode_ofRectangle(ofRectangle& aOfRectangle)
		: internal_(aOfRectangle)
	{}

	ofxNode_ofRectangle::~ofxNode_ofRectangle()
	{}

	NAN_METHOD(ofxNode_ofRectangle::New)
	{
		NanScope();
		if (args.IsConstructCall()) {
			ofxNode_ofRectangle* obj;
			if (args.Length() == 0)
			{
				obj = new ofxNode_ofRectangle(ofRectangle());
			}
			else if (args.Length() == 2)
			{
				obj = new ofxNode_ofRectangle(ofRectangle(
					node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
					node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self()
					));
			}
			else if (args.Length() == 3)
			{
				obj = new ofxNode_ofRectangle(ofRectangle(
					node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
					V8_ARG_NUMBER(args[1]),
					V8_ARG_NUMBER(args[2])
					));
			}
			else if (args.Length() == 4)
			{
				obj = new ofxNode_ofRectangle(ofRectangle(
					V8_ARG_NUMBER(args[0]),
					V8_ARG_NUMBER(args[1]),
					V8_ARG_NUMBER(args[2]),
					V8_ARG_NUMBER(args[3])
					));
			}
			else
			{
				//copy constructor like a BOSS!
				obj = new ofxNode_ofRectangle(ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self());
			}
			obj->Wrap(args.This());
			NanReturnValue(args.This());
		} else {
			// Invoked as plain function `MyObject(...)`, turn into construct call.
			std::vector<v8::Handle<v8::Value>> lArgvVec;
			for (int i = 0; i < args.Length(); ++i) {lArgvVec.push_back(args[i]);}
			NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(lArgvVec.size(), (lArgvVec.size()==0) ? nullptr : &lArgvVec[0]));
		}
	}

	void ofxNode_ofRectangle::Init(v8::Handle<v8::Object> exports)
	{
		// Prepare constructor template
		auto tpl = NanNew<v8::FunctionTemplate>(New);
		tpl->SetClassName(NanNew("ofRectangle"));
		
		auto inst = tpl->InstanceTemplate();
		inst->SetInternalFieldCount(1);
		inst->SetAccessor(NanNew("x")    , GetX , SetX);
		inst->SetAccessor(NanNew("y")    , GetY , SetY);
		inst->SetAccessor(NanNew("position")    , GetPosition , SetPosition);
		inst->SetAccessor(NanNew("width")    , GetWidth , SetWidth);
		inst->SetAccessor(NanNew("height")    , GetHeight , SetHeight);


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
		
		NanSetPrototypeTemplate(tpl, NanNew("toString"), NanNew<v8::FunctionTemplate>(ToString), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("plus"), NanNew<v8::FunctionTemplate>(Plus), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("equals"), NanNew<v8::FunctionTemplate>(Equals), v8::ReadOnly);

		NanSetPrototypeTemplate(tpl, NanNew("OFXNODE_TYPE"), NanNew(OFXNODE_TYPES::OFRECTANGLE), v8::DontEnum);
		NanAssignPersistent(constructor, tpl->GetFunction());
		exports->Set(NanNew<v8::String>("ofRectangle"), tpl->GetFunction());
	}

	NAN_METHOD(ofxNode_ofRectangle::Equals)
	{
		const auto& self = ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		if (args[0]->IsArray())
		{
			bool result = true;
			bool ranAtLeastOnce = false;
			const auto lProps = args[0]->ToObject()->GetPropertyNames();
			for (int i = 0; i < lProps->Length(); ++i)
			{
				const auto lKey = lProps->Get(i);
				const auto lVal = args[0]->ToObject()->Get(i);

				if(lVal->ToObject()->Has(NanNew("OFXNODE_TYPE")) && lVal->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() == OFXNODE_TYPES::OFRECTANGLE)
				{
					ranAtLeastOnce = true;
					result = result && (self == ObjectWrap::Unwrap<ofxNode_ofRectangle>(lVal->ToObject())->self());
				}
			}

			NanReturnValue( (NanNew(result && ranAtLeastOnce)) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self();
			NanReturnValue( (NanNew(self == lArgVec)) );
		}
	}

	NAN_METHOD(ofxNode_ofRectangle::Plus)
	{
		auto& self = ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->internal_;
		const int lArgc = 4;
		const auto& lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self();
		const auto result = self + lArgVec;
		v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.width), NanNew(result.height)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofRectangle::ToString)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		std::ostringstream out;
		out << self;
		NanReturnValue( NanNew(out.str().c_str()) );
	}
	//----------------------------------------------------------

	NAN_GETTER(ofxNode_ofRectangle::GetX)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.x));
	}
	NAN_SETTER(ofxNode_ofRectangle::SetX)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.x = value->NumberValue();
	}
	//----------------------------------------------------------
	NAN_GETTER(ofxNode_ofRectangle::GetY)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.y));
	}
	NAN_SETTER(ofxNode_ofRectangle::SetY)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.y = value->NumberValue();
	}
	//----------------------------------------------------------
	NAN_GETTER(ofxNode_ofRectangle::GetWidth)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.width));
	}
	NAN_SETTER(ofxNode_ofRectangle::SetWidth)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.width = value->NumberValue();
	}
	//----------------------------------------------------------
	NAN_GETTER(ofxNode_ofRectangle::GetHeight)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.y));
	}
	NAN_SETTER(ofxNode_ofRectangle::SetHeight)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.height = value->NumberValue();
	}
	//----------------------------------------------------------
	NAN_GETTER(ofxNode_ofRectangle::GetPosition)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		v8::Local<v8::Value> lArgv[] = {NanNew(self.position.x), NanNew(self.position.y), NanNew(self.position.z)};
		NanReturnValue(NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv));
	}
	NAN_SETTER(ofxNode_ofRectangle::SetPosition)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.position = node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(value->ToObject())->self();
	}
	//----------------------------------------------------------


	NAN_METHOD(ofxNode_ofRectangle::AlignTo)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)
		{
			ofAlignHorz thisHorzAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_HORZ_CENTER : (ofAlignHorz)args[1]->Uint32Value();
			ofAlignVert thisVertAnchor = (args[2]->IsUndefined()) ? OF_ALIGN_VERT_CENTER : (ofAlignVert)args[2]->Uint32Value();
			self.alignTo(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				thisHorzAnchor,
				thisVertAnchor
				);
		}
		else if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFRECTANGLE)
		{
			ofAlignHorz thisHorzAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_HORZ_CENTER : (ofAlignHorz)args[1]->Uint32Value();
			ofAlignVert thisVertAnchor = (args[2]->IsUndefined()) ? OF_ALIGN_VERT_CENTER : (ofAlignVert)args[2]->Uint32Value();
			self.alignTo(
				node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self(),
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
			self.alignTo(
				node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self(),
				targetHorzAnchor,
				targetVertAnchor,
				thisHorzAnchor,
				thisVertAnchor
				);
		}
		NanReturnValue(NanNew(args.This()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::AlignToHorz)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		if (args.Length() == 1 && args[0]->IsNumber())
		{
			ofAlignHorz thisHorzAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_HORZ_CENTER : (ofAlignHorz)args[1]->Uint32Value();
			self.alignToHorz(
				V8_ARG_NUMBER(args[0]),
				thisHorzAnchor
				);
		}
		else if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFRECTANGLE)
		{
			ofAlignHorz thisHorzAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_HORZ_CENTER : (ofAlignHorz)args[1]->Uint32Value();
			self.alignToHorz(
				node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self(),
				thisHorzAnchor
				);
		}
		else
		{
			ofAlignHorz targetHorzAnchor = (ofAlignHorz)args[1]->Uint32Value();
			ofAlignHorz thisHorzAnchor = (ofAlignHorz)args[2]->Uint32Value();
			self.alignToHorz(
				node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self(),
				targetHorzAnchor,
				thisHorzAnchor
				);
		}
		NanReturnValue(NanNew(args.This()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::AlignToVert)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		if (args.Length() == 1 && args[0]->IsNumber())
		{
			ofAlignVert sharedAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_VERT_CENTER : (ofAlignVert)args[1]->Uint32Value();
			self.alignToVert(
				V8_ARG_NUMBER(args[0]),
				sharedAnchor
				);
		}
		else if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFRECTANGLE)
		{
			ofAlignVert sharedAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_VERT_CENTER : (ofAlignVert)args[1]->Uint32Value();
			self.alignToVert(
				node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self(),
				sharedAnchor
				);
		}
		else
		{
			ofAlignVert targetVertAnchor = (ofAlignVert )args[1]->Uint32Value();
			ofAlignVert thisVertAnchor = (ofAlignVert )args[2]->Uint32Value();
			self.alignToVert(
				node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self(),
				targetVertAnchor,
				thisVertAnchor
				);
		}
		NanReturnValue(NanNew(args.This()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetArea)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getArea()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetAspectRatio)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getAspectRatio()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetBottom)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getBottom()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetBottomLeft)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		v8::Local<v8::Value> lArgv[] = {NanNew(self.getBottomLeft().x), NanNew(self.getBottomLeft().y), NanNew(self.getBottomLeft().z)};
		NanReturnValue(NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetBottomRight)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		v8::Local<v8::Value> lArgv[] = {NanNew(self.getBottomRight().x), NanNew(self.getBottomRight().y), NanNew(self.getBottomRight().z)};
		NanReturnValue(NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetCenter)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		v8::Local<v8::Value> lArgv[] = {NanNew(self.getCenter().x), NanNew(self.getCenter().y), NanNew(self.getCenter().z)};
		NanReturnValue(NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetHeight)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getHeight()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetHorzAnchor)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getHorzAnchor((ofAlignHorz )args[0]->Uint32Value())));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetIntersection)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		const auto result = self.getIntersection(node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self());
		v8::Local<v8::Value> lArgv[] = {
			NanNew(result.x),
			NanNew(result.y),
			NanNew(result.width),
			NanNew(result.height)
		};
		NanReturnValue(NanNew(ofxNode_ofRectangle::factory())->CallAsConstructor(4, lArgv));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetLeft)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getLeft()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetMax)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		v8::Local<v8::Value> lArgv[] = {NanNew(self.getMax().x), NanNew(self.getMax().y), NanNew(self.getMax().z)};
		NanReturnValue(NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetMaxX)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getMaxX()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetMaxY)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getMaxY()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetMin)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		v8::Local<v8::Value> lArgv[] = {NanNew(self.getMin().x), NanNew(self.getMin().y), NanNew(self.getMin().z)};
		NanReturnValue(NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetMinX)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getMinY()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetMinY)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getMinY()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetPerimeter)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getPerimeter()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetPosition)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		v8::Local<v8::Value> lArgv[] = {NanNew(self.getPosition().x), NanNew(self.getPosition().y), NanNew(self.getPosition().z)};
		NanReturnValue(NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetPositionRef)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		v8::Local<v8::Value> lArgv[] = {NanNew(self.getPosition().x), NanNew(self.getPosition().y), NanNew(self.getPosition().z)};
		NanReturnValue(NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetRight)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getRight()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetStandardized)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		const auto result = self.getStandardized();
		v8::Local<v8::Value> lArgv[] = {
			NanNew(result.x),
			NanNew(result.y),
			NanNew(result.width),
			NanNew(result.height)
		};
		NanReturnValue(NanNew(ofxNode_ofRectangle::factory())->CallAsConstructor(4, lArgv));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetTop)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getTop()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetTopLeft)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		v8::Local<v8::Value> lArgv[] = {NanNew(self.getTopLeft().x), NanNew(self.getTopLeft().y), NanNew(self.getTopLeft().z)};
		NanReturnValue(NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetTopRight)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		v8::Local<v8::Value> lArgv[] = {NanNew(self.getTopRight().x), NanNew(self.getTopRight().y), NanNew(self.getTopRight().z)};
		NanReturnValue(NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetUnion)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		const auto result = self.getUnion(node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self());
		v8::Local<v8::Value> lArgv[] = {
			NanNew(result.x),
			NanNew(result.y),
			NanNew(result.width),
			NanNew(result.height)
		};
		NanReturnValue(NanNew(ofxNode_ofRectangle::factory())->CallAsConstructor(4, lArgv));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetVertAnchor)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getVertAnchor((ofAlignVert)args[0]->Uint32Value())));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetWidth)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getWidth()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetX)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getX()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GetY)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.getY()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::GrowToInclude)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)
		{
			self.growToInclude(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFRECTANGLE)
		{
			self.growToInclude(node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 2 && args[0]->IsNumber())
		{
			self.growToInclude(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1])
				);
		}
		else
		{
			self.growToInclude(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self()
				);
		}
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::Inside)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		bool result = false;
		if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)
		{
			result = self.inside(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFRECTANGLE)
		{
			result = self.inside(node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 2 && args[0]->IsNumber())
		{
			result = self.inside(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1])
				);
		}
		else
		{
			result = self.inside(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self()
				);
		}
		NanReturnValue(NanNew(result));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::Intersects)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		bool result = false;
		if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFRECTANGLE)
		{
			result = self.intersects(node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self());
		}
		else
		{
			result = self.intersects(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self()
				);
		}
		NanReturnValue(NanNew(result));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::IsEmpty)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.isEmpty()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::IsStandardized)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		NanReturnValue(NanNew(self.isStandardized()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::Scale)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)
		{
			self.scale(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 1)
		{
			self.scale(V8_ARG_NUMBER(args[0]));
		}
		else
		{
			self.scale(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]));
		}
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::ScaleFromCenter)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)
		{
			self.scaleFromCenter(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 1)
		{
			self.scaleFromCenter(V8_ARG_NUMBER(args[0]));
		}
		else
		{
			self.scaleFromCenter(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]));
		}
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::ScaleHeight)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.scaleHeight(V8_ARG_NUMBER(args[0]));
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::ScaleTo)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		if (args.Length() >= 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFRECTANGLE)
		{
			ofScaleMode  scaleMode = (args[1]->IsUndefined()) ? OF_SCALEMODE_FIT : (ofScaleMode )args[1]->Uint32Value();
			self.scaleTo(
				node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self(),
				scaleMode
				);
		}
		else if (args.Length() >= 2 && args.Length() <= 4 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFRECTANGLE)
		{
			ofAlignHorz sharedHorzAnchor = (args[1]->IsUndefined()) ? OF_ALIGN_HORZ_CENTER : (ofAlignHorz)args[1]->Uint32Value();
			ofAlignVert sharedVertAnchor = (args[2]->IsUndefined()) ? OF_ALIGN_VERT_CENTER : (ofAlignVert)args[2]->Uint32Value();
			self.scaleTo(
				node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self(),
				(ofAspectRatioMode)args[1]->Uint32Value(),
				sharedHorzAnchor,
				sharedVertAnchor
				);
		}
		else
		{
			self.scaleTo(
				node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self(),
				(ofAspectRatioMode)args[1]->Uint32Value(),
				(ofAlignHorz )args[2]->Uint32Value(),
				(ofAlignVert )args[3]->Uint32Value(),
				(ofAlignHorz )args[4]->Uint32Value(),
				(ofAlignVert )args[5]->Uint32Value()
				);
		}
		NanReturnValue(NanNew(args.This()));
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::ScaleWidth)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.scaleWidth(V8_ARG_NUMBER(args[0]));
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::Set)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		if (args.Length() == 2)
		{
			self.set(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self()
				);
		}
		else if (args.Length() == 3)
		{
			self.set(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2])
				);
		}
		else if (args.Length() == 4)
		{
			self.set(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3])
				);
		}
		else
		{
			//copy constructor like a BOSS!
			self.set(ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self());
		}
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::SetFromCenter)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		if (args.Length() == 3)
		{
			self.setFromCenter(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2])
				);
		}
		else if (args.Length() == 4)
		{
			self.setFromCenter(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3])
				);
		}
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::SetHeight)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.setHeight(V8_ARG_NUMBER(args[0]));
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::SetPosition)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		if (args.Length() == 2)
		{
			self.setPosition(
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2])
				);
		}
		else if (args.Length() == 4)
		{
			self.setPosition(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self()
				);
		}
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::SetWidth)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.setWidth(V8_ARG_NUMBER(args[0]));
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::SetX)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.setX(V8_ARG_NUMBER(args[0]));
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::SetY)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.setY(V8_ARG_NUMBER(args[0]));
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::Standardize)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.standardize();
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::Translate)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		if (args.Length() == 2)
		{
			self.translate(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]));
		}
		else
		{
			self.translate(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->self());
		}
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::TranslateX)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.translateX(V8_ARG_NUMBER(args[0]));
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
	NAN_METHOD(ofxNode_ofRectangle::TranslateY)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args.This())->self();
		self.translateY(V8_ARG_NUMBER(args[0]));
		NanReturnValue(args.This());
	}
	//----------------------------------------------------------
} // !namespace ofxNode
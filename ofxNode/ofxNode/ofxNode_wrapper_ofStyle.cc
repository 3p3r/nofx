#include "ofxNode_wrapper_ofStyle.h"

namespace ofxNode
{
	v8::Persistent<v8::Function> ofxNode_ofStyle::constructor;

	ofxNode_ofStyle::ofxNode_ofStyle(ofStyle& aOfStyle)
		: internal_(aOfStyle)
	{}

	ofxNode_ofStyle::~ofxNode_ofStyle()
	{}

	NAN_METHOD(ofxNode_ofStyle::New)
	{
		NanScope();
		if (args.IsConstructCall()) {
			// Invoked as constructor: `new ofStyle(...)`
			ofxNode_ofStyle* obj;
			if (args.Length() == 0)
			{
				obj = new ofxNode_ofStyle(ofStyle());
			}
			else
			{
				//copy constructor like a BOSS!
				obj = new ofxNode_ofStyle(ObjectWrap::Unwrap<ofxNode_ofStyle>(args[0]->ToObject())->self());
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

	void ofxNode_ofStyle::Init(v8::Handle<v8::Object> exports)
	{
		// Prepare constructor template
		auto tpl = NanNew<v8::FunctionTemplate>(New);
		tpl->SetClassName(NanNew("ofStyle"));
		
		auto inst = tpl->InstanceTemplate();
		inst->SetInternalFieldCount(1);
		inst->SetAccessor(NanNew("bFill")    , GetBFill , SetBFill);
		inst->SetAccessor(NanNew("bgColor")    , GetBgColor , SetBgColor);
		inst->SetAccessor(NanNew("blendingMode")    , GetBlendingMode , SetBlendingMode);
		inst->SetAccessor(NanNew("circleResolution")    , GetCircleResolution , SetCircleResolution);
		inst->SetAccessor(NanNew("color")    , GetColor , SetColor);
		inst->SetAccessor(NanNew("curveResolution")    , GetCurveResolution , SetCurveResolution);
		inst->SetAccessor(NanNew("drawBitmapMode")    , GetDrawBitmapMode , SetDrawBitmapMode);
		inst->SetAccessor(NanNew("lineWidth")    , GetLineWidth , SetLineWidth);
		inst->SetAccessor(NanNew("polyMode")    , GetPolyMode , SetPolyMode);
		inst->SetAccessor(NanNew("rectMode")    , GetRectMode , SetRectMode);
		inst->SetAccessor(NanNew("smoothing")    , GetSmoothing , SetSmoothing);
		inst->SetAccessor(NanNew("sphereResolution")    , GetSphereResolution , SetSphereResolution);

		NanSetPrototypeTemplate(tpl, NanNew("OFXNODE_TYPE"), NanNew(OFXNODE_TYPES::OFSTYLE), v8::DontEnum);
		NanAssignPersistent(constructor, tpl->GetFunction());
		exports->Set(NanNew<v8::String>("ofStyle"), tpl->GetFunction());
	}

	NAN_GETTER(ofxNode_ofStyle::GetBFill)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		NanReturnValue(NanNew(self.bFill));
	}
	NAN_SETTER(ofxNode_ofStyle::SetBFill)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self().bFill = value->BooleanValue();
	}
	//-----------------------------------------------------
	NAN_GETTER(ofxNode_ofStyle::GetBgColor)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		v8::Local<v8::Value> lArgv[] = {NanNew(self.bgColor.r), NanNew(self.bgColor.g), NanNew(self.bgColor.b), NanNew(self.bgColor.a)};
		NanReturnValue(NanNew(ofxNode_ofColor::factory())->CallAsConstructor(4, lArgv));
	}
	NAN_SETTER(ofxNode_ofStyle::SetBgColor)
	{
		const auto &aNewColor = node::ObjectWrap::Unwrap<ofxNode_ofColor>(value->ToObject())->self();
		node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self().bgColor.set(aNewColor);
	}
	//-----------------------------------------------------
	NAN_GETTER(ofxNode_ofStyle::GetBlendingMode)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		NanReturnValue(NanNew(self.blendingMode));
	}
	NAN_SETTER(ofxNode_ofStyle::SetBlendingMode)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		self.blendingMode = (ofBlendMode)value->Uint32Value();
	}
	//-----------------------------------------------------
	NAN_GETTER(ofxNode_ofStyle::GetCircleResolution)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		NanReturnValue(NanNew(self.circleResolution));
	}
	NAN_SETTER(ofxNode_ofStyle::SetCircleResolution)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		self.circleResolution = value->NumberValue();
	}
	//-----------------------------------------------------
	NAN_GETTER(ofxNode_ofStyle::GetColor)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		v8::Local<v8::Value> lArgv[] = {NanNew(self.color.r), NanNew(self.color.g), NanNew(self.color.b), NanNew(self.color.a)};
		NanReturnValue(NanNew(ofxNode_ofColor::factory())->CallAsConstructor(4, lArgv));
	}
	NAN_SETTER(ofxNode_ofStyle::SetColor)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		self.color.set(node::ObjectWrap::Unwrap<ofxNode_ofColor>(value->ToObject())->self());
	}
	//-----------------------------------------------------
	NAN_GETTER(ofxNode_ofStyle::GetCurveResolution)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		NanReturnValue(NanNew(self.curveResolution));
	}
	NAN_SETTER(ofxNode_ofStyle::SetCurveResolution)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		self.curveResolution = value->Uint32Value();
	}
	//-----------------------------------------------------
	NAN_GETTER(ofxNode_ofStyle::GetDrawBitmapMode)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		NanReturnValue(NanNew(self.drawBitmapMode));
	}
	NAN_SETTER(ofxNode_ofStyle::SetDrawBitmapMode)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		self.drawBitmapMode = (ofDrawBitmapMode)value->Uint32Value();
	}
	//-----------------------------------------------------
	NAN_GETTER(ofxNode_ofStyle::GetLineWidth)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		NanReturnValue(NanNew(self.lineWidth));
	}
	NAN_SETTER(ofxNode_ofStyle::SetLineWidth)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		self.lineWidth = value->NumberValue();
	}
	//-----------------------------------------------------
	NAN_GETTER(ofxNode_ofStyle::GetPolyMode)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		NanReturnValue(NanNew(self.polyMode));
	}
	NAN_SETTER(ofxNode_ofStyle::SetPolyMode)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		self.polyMode = (ofPolyWindingMode)value->Uint32Value();
	}
	//-----------------------------------------------------
	NAN_GETTER(ofxNode_ofStyle::GetRectMode)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		NanReturnValue(NanNew(self.rectMode));
	}
	NAN_SETTER(ofxNode_ofStyle::SetRectMode)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		self.rectMode = (ofRectMode)value->Uint32Value();
	}
	//-----------------------------------------------------
	NAN_GETTER(ofxNode_ofStyle::GetSmoothing)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		NanReturnValue(NanNew(self.smoothing));
	}
	NAN_SETTER(ofxNode_ofStyle::SetSmoothing)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		self.smoothing = value->BooleanValue();
	}
	//-----------------------------------------------------
	NAN_GETTER(ofxNode_ofStyle::GetSphereResolution)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		NanReturnValue(NanNew(self.sphereResolution));
	}
	NAN_SETTER(ofxNode_ofStyle::SetSphereResolution)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofStyle>(args.This())->self();
		self.sphereResolution = value->Uint32Value();
	}
	//-----------------------------------------------------

} // !namespace ofxNode
#include "ofxNode_wrapper_ofImage.h"

namespace ofxNode
{
	v8::Persistent<v8::Function> ofxNode_ofImage::constructor;

	ofxNode_ofImage::ofxNode_ofImage(ofImage& aOfImage)
		: internal_(aOfImage)
	{}

	ofxNode_ofImage::~ofxNode_ofImage()
	{}

	NAN_METHOD(ofxNode_ofImage::New)
	{
		NanScope();
		if (args.IsConstructCall()) {
			// Invoked as constructor: `new ofTrueTypeFont(...)`
			//TODO(sepehr) full implementation of this constructor based on ofImage
			ofxNode_ofImage* obj;
			if (args.Length() == 0)
			{
				obj = new ofxNode_ofImage(ofImage());
			}
			else if (args.Length() == 1)
			{
				obj = new ofxNode_ofImage(ofImage(NanCString(args[0], nullptr)));
			}
			else
			{
				//copy constructor like a BOSS!
				obj = new ofxNode_ofImage(ObjectWrap::Unwrap<ofxNode_ofImage>(args[0]->ToObject())->self());
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

	void ofxNode_ofImage::Init(v8::Handle<v8::Object> exports)
	{
		// Prepare constructor template
		auto tpl = NanNew<v8::FunctionTemplate>(New);
		tpl->SetClassName(NanNew("ofImage"));
		
		auto inst = tpl->InstanceTemplate();
		inst->SetInternalFieldCount(1);

		inst->SetAccessor(NanNew("bpp")    , GetBpp , SetBpp);
		inst->SetAccessor(NanNew("height")    , GetHeight , SetHeight);
		inst->SetAccessor(NanNew("type")    , GetType , SetType);
		inst->SetAccessor(NanNew("width")    , GetWidth , SetWidth);

		NanSetPrototypeTemplate(tpl, NanNew("allocate"), NanNew<v8::FunctionTemplate>(Allocate), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("bAllocated"), NanNew<v8::FunctionTemplate>(BAllocated), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("bind"), NanNew<v8::FunctionTemplate>(Bind), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("clear"), NanNew<v8::FunctionTemplate>(Clear), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("clone"), NanNew<v8::FunctionTemplate>(Clone), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("crop"), NanNew<v8::FunctionTemplate>(Crop), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("cropFrom"), NanNew<v8::FunctionTemplate>(CropFrom), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("draw"), NanNew<v8::FunctionTemplate>(Draw), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("drawSubsection"), NanNew<v8::FunctionTemplate>(DrawSubsection), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getColor"), NanNew<v8::FunctionTemplate>(GetColor), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getHeight"), NanNew<v8::FunctionTemplate>(GetHeight), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getPixels"), NanNew<v8::FunctionTemplate>(GetPixels), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getPixelsRef"), NanNew<v8::FunctionTemplate>(GetPixelsRef), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getTextureReference"), NanNew<v8::FunctionTemplate>(GetTextureReference), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getWidth"), NanNew<v8::FunctionTemplate>(GetWidth), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("grabScreen"), NanNew<v8::FunctionTemplate>(GrabScreen), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("isAllocated"), NanNew<v8::FunctionTemplate>(IsAllocated), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("isUsingTexture"), NanNew<v8::FunctionTemplate>(IsUsingTexture), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("loadImage"), NanNew<v8::FunctionTemplate>(LoadImage), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("mirror"), NanNew<v8::FunctionTemplate>(Mirror), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("reloadTexture"), NanNew<v8::FunctionTemplate>(ReloadTexture), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("resetAnchor"), NanNew<v8::FunctionTemplate>(ResetAnchor), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("resize"), NanNew<v8::FunctionTemplate>(Resize), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("rotate90"), NanNew<v8::FunctionTemplate>(Rotate90), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("saveImage"), NanNew<v8::FunctionTemplate>(SaveImage), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setAnchorPercent"), NanNew<v8::FunctionTemplate>(SetAnchorPercent), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setAnchorPoint"), NanNew<v8::FunctionTemplate>(SetAnchorPoint), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setColor"), NanNew<v8::FunctionTemplate>(SetColor), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setCompression"), NanNew<v8::FunctionTemplate>(SetCompression), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setFromPixels"), NanNew<v8::FunctionTemplate>(SetFromPixels), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setImageType"), NanNew<v8::FunctionTemplate>(SetImageType), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setUseTexture"), NanNew<v8::FunctionTemplate>(SetUseTexture), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("unbind"), NanNew<v8::FunctionTemplate>(Unbind), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("update"), NanNew<v8::FunctionTemplate>(Update), v8::ReadOnly);

		NanSetPrototypeTemplate(tpl, NanNew("OFXNODE_TYPE"), NanNew(OFXNODE_TYPES::OFIMAGE), v8::DontEnum);
		NanAssignPersistent(constructor, tpl->GetFunction());
		exports->Set(NanNew<v8::String>("ofImage"), tpl->GetFunction());
	}



	NAN_GETTER(ofxNode_ofImage::GetBpp)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		NanReturnValue(NanNew(self.bpp));
	}
	NAN_SETTER(ofxNode_ofImage::SetBpp)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self().bpp = value->NumberValue();
	}
	//-----------------------------------------------------

	NAN_GETTER(ofxNode_ofImage::GetHeight)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		NanReturnValue(NanNew(self.height));
	}
	NAN_SETTER(ofxNode_ofImage::SetHeight)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self().height = value->NumberValue();
	}
	//-----------------------------------------------------

	NAN_GETTER(ofxNode_ofImage::GetType)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		NanReturnValue(NanNew(self.type));
	}
	NAN_SETTER(ofxNode_ofImage::SetType)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self().type = value->NumberValue();
	}
	//-----------------------------------------------------

	NAN_GETTER(ofxNode_ofImage::GetWidth)
	{
		const auto &self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		NanReturnValue(NanNew(self.width));
	}
	NAN_SETTER(ofxNode_ofImage::SetWidth)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self().width = value->NumberValue();
	}
	//-----------------------------------------------------


	NAN_METHOD(ofxNode_ofImage::Allocate)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::BAllocated)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Bind)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Clear)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Clone)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Crop)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::CropFrom)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Draw)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::DrawSubsection)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GetColor)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GetHeight)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GetPixels)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GetPixelsRef)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GetTextureReference)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GetWidth)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GrabScreen)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::IsAllocated)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::IsUsingTexture)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::LoadImage)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Mirror)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::ReloadTexture)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::ResetAnchor)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Resize)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Rotate90)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SaveImage)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetAnchorPercent)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetAnchorPoint)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetColor)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetCompression)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetFromPixels)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetImageType)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetUseTexture)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Unbind)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Update)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------

	NAN_METHOD(ofxNode_ofLoadImage)
	{
		NanReturnValue(args.This());
	}
	NAN_METHOD(ofxNode_ofSaveImage)
	{
		NanReturnValue(args.This());
	}

} // !namespace ofxNode
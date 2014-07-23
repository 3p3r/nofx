#include "ofxNode_wrapper_ofImage.h"
#include "ofxNode_wrapper_ofColor.h"
#include "ofxNode_wrapper_ofRectangle.h"
#include "ofxNode_wrapper_ofVec3f.h"

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
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.allocate(args[0]->Int32Value(), args[1]->Int32Value(), (ofImageType)args[2]->Uint32Value());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::BAllocated)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		NanReturnValue(self.bAllocated());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Bind)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.bind();
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Clear)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.clear();
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Clone)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.clone(node::ObjectWrap::Unwrap<ofxNode_ofImage>(args[0]->ToObject())->self());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Crop)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.crop(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::CropFrom)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.cropFrom(node::ObjectWrap::Unwrap<ofxNode_ofImage>(args[0]->ToObject())->self(), args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value(), args[4]->Int32Value());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Draw)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFRECTANGLE)
		{
			self.draw(node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 1 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)
		{
			self.draw(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 2)
		{
			self.draw(args[0]->NumberValue(), args[1]->NumberValue());
		}
		else if (args.Length() == 3 && args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)
		{
			self.draw(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(), args[1]->NumberValue(), args[2]->NumberValue());
		}
		else if (args.Length() >= 3)
		{
			self.draw(
				args[0]->NumberValue(),
				args[1]->NumberValue(),
				args[2]->NumberValue(),
				args[3]->NumberValue() ? NULL : args[3]->NumberValue(),
				args[4]->NumberValue() ? NULL : args[4]->NumberValue()
				);
		}
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::DrawSubsection)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.drawSubsection(
			args[0]->NumberValue(),
			args[1]->NumberValue(),
			args[2]->NumberValue(),
			args[3]->NumberValue(),
			args[4]->NumberValue(),
			args[5]->NumberValue(),
			args[6]->NumberValue(),
			args[7]->NumberValue(),
			args[8]->NumberValue() ? NULL : args[8]->NumberValue()
			);
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GetColor)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		auto toRet = NanNew(ofxNode_ofColor::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(toRet)->self() = self.getColor(args[0]->Int32Value(), args[1]->Int32Value());
		NanReturnValue(toRet);
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GetHeight)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		NanReturnValue(NanNew(self.getHeight()));
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GetPixels)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		ofLogWarning() << "This method (GetPixels) might not work as expected. Please consult the documentation." << std::endl;
		// We have to copy the data, we can't work with pointers in JS side yet
		const auto data = self.getPixels();
		// Returning it compatible to HTML5 getImageData()
		auto toRet = NanNew<v8::Object>();
		toRet->Set(NanNew("width"), NanNew(self.getWidth()));
		toRet->Set(NanNew("height"), NanNew(self.getHeight()));
		toRet->Set(NanNew("data"), node::Buffer::New((char*)data, sizeof(data)));
		NanReturnValue(toRet);
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GetPixelsRef)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		ofLogWarning() << "This method (GetPixelsRef) might not work as expected. Please consult the documentation." << std::endl;
		// We have to copy the data, we can't work with pointers in JS side yet
		const auto data = self.getPixels();
		// Returning it compatible to HTML5 getImageData()
		auto toRet = NanNew<v8::Object>();
		toRet->Set(NanNew("width"), NanNew(self.getWidth()));
		toRet->Set(NanNew("height"), NanNew(self.getHeight()));
		toRet->Set(NanNew("data"), node::Buffer::New((char*)data, sizeof(data)));
		NanReturnValue(toRet);
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GetTextureReference)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		NanThrowError("Not implemented.");
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GetWidth)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		NanReturnValue(NanNew(self.getWidth()));
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::GrabScreen)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.grabScreen(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::IsAllocated)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		NanReturnValue(self.isAllocated());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::IsUsingTexture)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		NanReturnValue(self.isUsingTexture());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::LoadImage)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//todo(sepehr)
		self.loadImage(NanCString(args[0], nullptr));
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Mirror)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.mirror(args[0]->BooleanValue(), args[1]->BooleanValue());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::ReloadTexture)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.reloadTexture();
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::ResetAnchor)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.resetAnchor();
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Resize)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.resize(args[0]->Int32Value(), args[1]->Int32Value());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Rotate90)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.rotate90(args[0]->Int32Value());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SaveImage)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		//todo(sepehr)
		self.saveImage(NanCString(args[0], nullptr), (ofImageQualityType) args[1]->Uint32Value());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetAnchorPercent)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.setAnchorPercent(args[0]->NumberValue(), args[1]->NumberValue());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetAnchorPoint)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.setAnchorPoint(args[0]->NumberValue(), args[1]->NumberValue());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetColor)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		if (args.Length() == 1)
		{
			self.setColor(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self());
		}
		else if (args.Length() == 2)
		{
			self.setColor(args[0]->Int32Value(), node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[1]->ToObject())->self());
		}
		else
		{
			self.setColor(args[0]->Int32Value(), args[1]->Int32Value(), node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[2]->ToObject())->self());
		}
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetCompression)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.setCompression((ofTexCompression)args[0]->Int32Value());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetFromPixels)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		NanThrowError("Not implemented.");
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetImageType)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.setImageType((ofImageType)args[0]->Uint32Value());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::SetUseTexture)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.setUseTexture(args[0]->BooleanValue());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Unbind)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.unbind();
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofImage::Update)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofImage>(args.This())->self();
		self.update();
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------

	NAN_METHOD(ofxNode_ofLoadImage)
	{
		NanThrowError("Not implemented.");
		NanReturnValue(args.This());
	}
	NAN_METHOD(ofxNode_ofSaveImage)
	{
		NanThrowError("Not implemented.");
		NanReturnValue(args.This());
	}

} // !namespace ofxNode
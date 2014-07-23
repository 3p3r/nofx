#include "ofxNode_wrapper_ofTrueTypeFont.h"
#include "ofxNode_wrapper_ofRectangle.h"

namespace ofxNode
{
	v8::Persistent<v8::Function> ofxNode_ofTrueTypeFont::constructor;

	ofxNode_ofTrueTypeFont::ofxNode_ofTrueTypeFont(ofTrueTypeFont& aOfTrueTypeFont)
		: internal_(aOfTrueTypeFont)
	{}

	ofxNode_ofTrueTypeFont::~ofxNode_ofTrueTypeFont()
	{}

	NAN_METHOD(ofxNode_ofTrueTypeFont::New)
	{
		NanScope();
		if (args.IsConstructCall()) {
			// Invoked as constructor: `new ofTrueTypeFont(...)`
			ofxNode_ofTrueTypeFont* obj;
			if (args.Length() == 0)
			{
				obj = new ofxNode_ofTrueTypeFont(ofTrueTypeFont());
			}
			else
			{
				//copy constructor like a BOSS!
				obj = new ofxNode_ofTrueTypeFont(ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args[0]->ToObject())->self());
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

	void ofxNode_ofTrueTypeFont::Init(v8::Handle<v8::Object> exports)
	{
		// Prepare constructor template
		auto tpl = NanNew<v8::FunctionTemplate>(New);
		tpl->SetClassName(NanNew("ofTrueTypeFont"));
		
		auto inst = tpl->InstanceTemplate();
		inst->SetInternalFieldCount(1);

		NanSetPrototypeTemplate(tpl, NanNew("bind"), NanNew<v8::FunctionTemplate>(Bind), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("drawString"), NanNew<v8::FunctionTemplate>(DrawString), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("drawStringAsShapes"), NanNew<v8::FunctionTemplate>(DrawStringAsShapes), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getCharacterAsPoints"), NanNew<v8::FunctionTemplate>(GetCharacterAsPoints), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getEncoding"), NanNew<v8::FunctionTemplate>(GetEncoding), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getFontTexture"), NanNew<v8::FunctionTemplate>(GetFontTexture), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getLetterSpacing"), NanNew<v8::FunctionTemplate>(GetLetterSpacing), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getLineHeight"), NanNew<v8::FunctionTemplate>(GetLineHeight), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getNumCharacters"), NanNew<v8::FunctionTemplate>(GetNumCharacters), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getSize"), NanNew<v8::FunctionTemplate>(GetSize), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getSpaceSize"), NanNew<v8::FunctionTemplate>(GetSpaceSize), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getStringAsPoints"), NanNew<v8::FunctionTemplate>(GetStringAsPoints), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getStringBoundingBox"), NanNew<v8::FunctionTemplate>(GetStringBoundingBox), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getStringMesh"), NanNew<v8::FunctionTemplate>(GetStringMesh), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("hasFullCharacterSet"), NanNew<v8::FunctionTemplate>(HasFullCharacterSet), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("isAntiAliased"), NanNew<v8::FunctionTemplate>(IsAntiAliased), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("isLoaded"), NanNew<v8::FunctionTemplate>(IsLoaded), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("loadFont"), NanNew<v8::FunctionTemplate>(LoadFont), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setEncoding"), NanNew<v8::FunctionTemplate>(SetEncoding), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setGlobalDpi"), NanNew<v8::FunctionTemplate>(SetGlobalDpi), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setLetterSpacing"), NanNew<v8::FunctionTemplate>(SetLetterSpacing), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setLineHeight"), NanNew<v8::FunctionTemplate>(SetLineHeight), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setSpaceSize"), NanNew<v8::FunctionTemplate>(SetSpaceSize), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("stringHeight"), NanNew<v8::FunctionTemplate>(StringHeight), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("stringWidth"), NanNew<v8::FunctionTemplate>(StringWidth), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("unbind"), NanNew<v8::FunctionTemplate>(Unbind), v8::ReadOnly);

		NanSetPrototypeTemplate(tpl, NanNew("OFXNODE_TYPE"), NanNew(OFXNODE_TYPES::OFTRUETYPEFONT), v8::DontEnum);
		NanAssignPersistent(constructor, tpl->GetFunction());
		exports->Set(NanNew<v8::String>("ofTrueTypeFont"), tpl->GetFunction());
	}


	NAN_METHOD(ofxNode_ofTrueTypeFont::Bind)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		self.bind();
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::DrawString)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		self.drawString(NanCString(args[0], nullptr), args[1]->NumberValue(), args[2]->NumberValue());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::DrawStringAsShapes)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		self.drawStringAsShapes(NanCString(args[0], nullptr), args[1]->NumberValue(), args[2]->NumberValue());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetCharacterAsPoints)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanThrowError("Not implemented.");
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetEncoding)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanReturnValue(NanNew(self.getEncoding()));
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetFontTexture)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanThrowError("Not implemented.");
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetLetterSpacing)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanReturnValue(NanNew(self.getLetterSpacing()));
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetLineHeight)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanReturnValue(NanNew(self.getLineHeight()));
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetNumCharacters)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanReturnValue(NanNew(self.getNumCharacters()));
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetSize)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanReturnValue(NanNew(self.getSize()));
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetSpaceSize)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanReturnValue(NanNew(self.getSpaceSize()));
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetStringAsPoints)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanThrowError("Not implemented.");
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetStringBoundingBox)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		auto toRet = NanNew(ofxNode_ofRectangle::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(toRet)->self() = self.getStringBoundingBox(NanCString(args[0], nullptr), args[1]->NumberValue(), args[2]->NumberValue());
		NanReturnValue(toRet);
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetStringMesh)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanThrowError("not implemented");
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::HasFullCharacterSet)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanReturnValue(self.hasFullCharacterSet());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::IsAntiAliased)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanReturnValue(self.isAntiAliased());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::IsLoaded)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanReturnValue(self.isLoaded());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::LoadFont)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		self.loadFont(NanCString(args[0], nullptr), args[1]->Int32Value(), 
			args[2]->IsUndefined() ? true : args[2]->BooleanValue(),
			args[3]->IsUndefined() ? false : args[3]->BooleanValue(),
			args[4]->IsUndefined() ? false : args[4]->BooleanValue(),
			args[5]->IsUndefined() ? NULL : args[5]->NumberValue(),
			args[6]->IsUndefined() ? 0 : args[6]->Int32Value());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::SetEncoding)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		self.setEncoding((ofTextEncoding)args[0]->Uint32Value());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::SetGlobalDpi)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		self.setGlobalDpi(args[0]->Int32Value());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::SetLetterSpacing)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		self.setLetterSpacing(args[0]->NumberValue());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::SetLineHeight)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		self.setLineHeight(args[0]->NumberValue());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::SetSpaceSize)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		self.setSpaceSize(args[0]->NumberValue());
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::StringHeight)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanReturnValue(NanNew(self.stringHeight(NanCString(args[0], nullptr))));
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::StringWidth)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		NanReturnValue(NanNew(self.stringWidth(NanCString(args[0], nullptr))));
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::Unbind)
	{
		auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		self.unbind();
		NanReturnValue(args.This());
	}
} // !namespace ofxNode
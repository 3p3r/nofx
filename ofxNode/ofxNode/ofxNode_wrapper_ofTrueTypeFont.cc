#include "ofxNode_wrapper_ofTrueTypeFont.h"

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
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::DrawString)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::DrawStringAsShapes)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetCharacterAsPoints)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetEncoding)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetFontTexture)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetLetterSpacing)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetLineHeight)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetNumCharacters)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetSize)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetSpaceSize)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetStringAsPoints)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetStringBoundingBox)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::GetStringMesh)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::HasFullCharacterSet)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::IsAntiAliased)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::IsLoaded)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::LoadFont)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::SetEncoding)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::SetGlobalDpi)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::SetLetterSpacing)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::SetLineHeight)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::SetSpaceSize)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::StringHeight)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::StringWidth)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
	//-------------------------------------------------------
	NAN_METHOD(ofxNode_ofTrueTypeFont::Unbind)
	{
		const auto& self = node::ObjectWrap::Unwrap<ofxNode_ofTrueTypeFont>(args.This())->self();
		//implementation
		NanReturnValue(args.This());
	}
} // !namespace ofxNode
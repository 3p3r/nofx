#include "nofx_dependencies.h"

v8::Persistent<v8::Function> DEP_ofColor;
v8::Persistent<v8::Function> DEP_ofPixels;
v8::Persistent<v8::Function> DEP_ofTexture;
v8::Persistent<v8::Function> DEP_unsignedCharPtr;

namespace nofx
{
	namespace ClassWrappers
	{
		NAN_METHOD(nofx_dependencies)
		{

			if (args.Length() != 1)
			{
				NanThrowTypeError("ofImage module has dependencies. Please pass the right dependencies first.");
			}

			NanAssignPersistent(DEP_ofColor, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofColor"))));
			NanAssignPersistent(DEP_ofPixels, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofPixels"))));
			NanAssignPersistent(DEP_ofTexture, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("ofTexture"))));
			NanAssignPersistent(DEP_unsignedCharPtr, v8::Handle<v8::Function>::Cast(
				args[0]->ToObject()->Get(NanNew("unsignedCharPtr"))));

			NanReturnValue(args.This());
		} // !nofx_dependencies
	} // !namespace ClassWrappers
} // !namespace nofx
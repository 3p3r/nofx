#include "nofx_dependencies.h"

v8::Persistent<v8::Function> DEP_ofColor;
v8::Persistent<v8::Function> DEP_ofPixels;
v8::Persistent<v8::Function> DEP_ofTexture;

namespace nofx
{
	namespace OfImage
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

			NanReturnValue(args.This());
		} // !nofx_dependencies
	} // !namespace OfImage
} // !namespace nofx
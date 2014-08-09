#include "globals.h"
#include "nofx_ofRunApp.h"
#include "nofx_ofSetupOpenGL.h"

namespace nofx
{
	using namespace v8;

	void Initialize(v8::Handle<Object> target,
		v8::Handle<Value> unused,
		v8::Handle<Context> context)
	{
		
		target->Set(NanNew<v8::String>("ofRunApp"), NanNew<v8::FunctionTemplate>(nofx_ofRunApp)->GetFunction());
		target->Set(NanNew<v8::String>("ofSetupOpenGL"), NanNew<v8::FunctionTemplate>(nofx_ofSetupOpenGL)->GetFunction());

	} //!Initialize
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx, nofx::Initialize)
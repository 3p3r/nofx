#include "globals.h"
#include "nofx_ofApp.h"
#include "nofx_ofRunApp.h"
#include "nofx_ofSetupOpenGL.h"

using namespace v8;

namespace nofx {
	void Initialize(v8::Handle<Object> target,
		v8::Handle<Value> unused,
		v8::Handle<Context> context)
	{
		OfAppWrap::Initialize(target);
		target->Set(NanNew<v8::String>("ofRunApp"), NanNew<v8::FunctionTemplate>(nofx_ofRunApp)->GetFunction());
		target->Set(NanNew<v8::String>("ofSetupOpenGL"), NanNew<v8::FunctionTemplate>(nofx_ofSetupOpenGL)->GetFunction());
	}

}

NODE_MODULE_CONTEXT_AWARE(nofx, nofx::Initialize)
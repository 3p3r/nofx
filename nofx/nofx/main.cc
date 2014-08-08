#include "globals.h"

namespace nofx {
	void Initialize(v8::Handle<v8::Object> target,
		v8::Handle<v8::Value> unused,
		v8::Handle<v8::Context> context) {
			
	}

}

NODE_MODULE_CONTEXT_AWARE(nofx, nofx::Initialize)
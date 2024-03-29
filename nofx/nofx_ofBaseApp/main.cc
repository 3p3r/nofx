#include "globals.h"
#include "nofx_ofApp.h"

namespace nofx
{
	namespace ClassWrappers
	{
		using namespace v8;

		void Initialize(v8::Handle<Object> target,
			v8::Handle<Value> unused,
			v8::Handle<Context> context)
		{

			OfAppWrap::Initialize(target);

		} //!Initialize
	} //!namespace ClassWrappers
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofBaseApp, nofx::ClassWrappers::Initialize)
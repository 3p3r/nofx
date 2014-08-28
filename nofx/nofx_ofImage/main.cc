#include "globals.h"
#include "nofx_ofImage.h"
#include "nofx_dependencies.h"

namespace nofx
{
	namespace ClassWrappers
	{
		using namespace v8;

		void Initialize(v8::Handle<Object> target,
			v8::Handle<Value> unused,
			v8::Handle<Context> context)
		{

			target->Set(NanNew<v8::String>("dependencies"), NanNew<v8::FunctionTemplate>(nofx_dependencies)->GetFunction());
			OfImageWrap::Initialize(target);

		} //!Initialize
	} //!namespace ClassWrappers
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofImage, nofx::ClassWrappers::Initialize)
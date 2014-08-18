#include "globals.h"
#include "nofx_pointer.h"

namespace nofx
{
	namespace Pointer
	{
		using namespace v8;

		Persistent<Function> NumberPointerWrap<int>::constructor;
		Persistent<Function> NumberPointerWrap<float>::constructor;
		Persistent<Function> NumberPointerWrap<double>::constructor;

		void Initialize(v8::Handle<Object> target,
			v8::Handle<Value> unused,
			v8::Handle<Context> context)
		{

			NumberPointerWrap<int>::Initialize(target, "intPtr");
			NumberPointerWrap<float>::Initialize(target, "floatPtr");
			NumberPointerWrap<double>::Initialize(target, "doublePtr");

		} //!Initialize
	}
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_pointer, nofx::Pointer::Initialize)
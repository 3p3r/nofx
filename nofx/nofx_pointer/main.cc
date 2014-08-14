#include "globals.h"
#include "nofx_pointer.h"

namespace nofx
{
	namespace Pointer
	{
		using namespace v8;

		Persistent<Function> PointerWrap<int>::constructor;
		Persistent<Function> PointerWrap<float>::constructor;
		Persistent<Function> PointerWrap<double>::constructor;

		void Initialize(v8::Handle<Object> target,
			v8::Handle<Value> unused,
			v8::Handle<Context> context)
		{

			PointerWrap<int>::Initialize(target, "intPtr");
			PointerWrap<float>::Initialize(target, "floatPtr");
			PointerWrap<double>::Initialize(target, "doublePtr");

		} //!Initialize
	}
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_pointer, nofx::Pointer::Initialize)
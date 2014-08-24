#include "globals.h"
#include "nofx_pointer.h"

namespace nofx
{
	namespace Pointer
	{
		using namespace v8;

		Persistent<Function> RawPointerWrap<int>::constructor;
		Persistent<Function> RawPointerWrap<float>::constructor;
		Persistent<Function> RawPointerWrap<double>::constructor;
		Persistent<Function> RawPointerWrap<unsigned char>::constructor;
		Persistent<Function> RawPointerWrap<unsigned short>::constructor;
		Persistent<Function> RawPointerWrap<void>::constructor;

		void Initialize(v8::Handle<Object> target,
			v8::Handle<Value> unused,
			v8::Handle<Context> context)
		{

			RawPointerWrap<int>::Initialize(target, "intPtr", NOFX_TYPES::INTPTR);
			RawPointerWrap<float>::Initialize(target, "floatPtr", NOFX_TYPES::FLOATPTR);
			RawPointerWrap<double>::Initialize(target, "doublePtr", NOFX_TYPES::DOUBLEPTR);
			RawPointerWrap<unsigned char>::Initialize(target, "unsignedCharPtr", NOFX_TYPES::UNSIGNEDCHARPTR);
			RawPointerWrap<unsigned short>::Initialize(target, "unsignedShortPtr", NOFX_TYPES::UNSIGNEDSHORTPTR);
			RawPointerWrap<void>::Initialize(target, "voidPtr", NOFX_TYPES::VOIDPTR);

		} //!Initialize
	}
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_pointer, nofx::Pointer::Initialize)
#include "globals.h"
#include "nofx_ofMatrix4x4.h"
#include "nofx_dependencies.h"

namespace nofx
{
    namespace OfMatrix4x4
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

            target->Set(NanNew<v8::String>("dependencies"), NanNew<v8::FunctionTemplate>(nofx_dependencies)->GetFunction());
			OfMatrix4x4Wrap::Initialize(target);

        } //!Initialize
    } //!namespace OfMatrix4x4
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofMatrix4x4, nofx::OfMatrix4x4::Initialize)
#include "globals.h"
#include "nofx_ofBuffer.h"
#include "nofx_dependencies.h"

namespace nofx
{
    namespace OfBuffer
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {
            
            target->Set(NanNew<v8::String>("dependencies"), NanNew<v8::FunctionTemplate>(nofx_dependencies)->GetFunction());
            OfBufferWrap::Initialize(target);

        } //!Initialize
    } //!namespace OfBuffer
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofBuffer, nofx::OfBuffer::Initialize)
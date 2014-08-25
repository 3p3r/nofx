#include "globals.h"
#include "nofx_ofPixels.h"
#include "nofx_dependencies.h"

namespace nofx
{
    namespace OfPixels
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

            target->Set(NanNew<v8::String>("dependencies"), NanNew<v8::FunctionTemplate>(nofx_dependencies)->GetFunction());
            OfPixelsWrap::Initialize(target);

        } //!Initialize
    } //!namespace OfPixels
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofPixels, nofx::OfPixels::Initialize)
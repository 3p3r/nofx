#include "globals.h"
#include "nofx_ofVec2f.h"
#include "nofx_dependencies.h"

namespace nofx
{
    namespace OfVec2f
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

			target->Set(NanNew<v8::String>("dependencies"), NanNew<v8::FunctionTemplate>(nofx_dependencies)->GetFunction());
            OfVec2fWrap::Initialize(target);

        } //!Initialize
    } //!namespace OfVec2f
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofVec2f, nofx::OfVec2f::Initialize)
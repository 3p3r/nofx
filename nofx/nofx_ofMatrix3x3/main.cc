#include "globals.h"
#include "nofx_ofMatrix3x3.h"
//#include "nofx_dependencies.h"

namespace nofx
{
    namespace OfMatrix3x3
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

            //target->Set(NanNew<v8::String>("dependencies"), NanNew<v8::FunctionTemplate>(nofx_dependencies)->GetFunction());
            OfMatrix3x3Wrap::Initialize(target);

        } //!Initialize
    } //!namespace OfMatrix3x3
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofMatrix3x3, nofx::OfMatrix3x3::Initialize)
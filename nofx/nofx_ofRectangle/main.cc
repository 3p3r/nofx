#include "globals.h"
#include "nofx_ofRectangle.h"
#include "nofx_dependencies.h"

namespace nofx
{
    namespace OfRectangle
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

            target->Set(NanNew<v8::String>("dependencies"), NanNew<v8::FunctionTemplate>(nofx_dependencies)->GetFunction());
			OfRectangleWrap::Initialize(target);

        } //!Initialize
    } //!namespace OfRectangle
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofRectangle, nofx::OfRectangle::Initialize)
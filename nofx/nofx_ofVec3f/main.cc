#include "globals.h"
#include "nofx_ofVec3f.h"

namespace nofx
{
    namespace OfVec3f
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

            OfVec3fWrap::Initialize(target);

        } //!Initialize
    } //!namespace OfVec3f
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofVec3f, nofx::OfVec3f::Initialize)
#include "globals.h"
#include "nofx_ofQuaternion.h"

namespace nofx
{
    namespace OfQuaternion
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

            OfQuaternionWrap::Initialize(target);

        } //!Initialize
    } //!namespace OfQuaternion
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofQuaternion, nofx::OfQuaternion::Initialize)
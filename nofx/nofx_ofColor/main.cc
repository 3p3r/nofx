#include "globals.h"
#include "nofx_ofColor.h"

namespace nofx
{
    namespace OfColor
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

            OfColorWrap::Initialize(target);

        } //!Initialize
    } //!namespace OfColor
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofColor, nofx::OfColor::Initialize)
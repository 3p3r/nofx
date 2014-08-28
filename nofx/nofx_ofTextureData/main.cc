#include "globals.h"
#include "nofx_ofTextureData.h"

namespace nofx
{
    namespace ClassWrappers
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

            OfTextureDataWrap::Initialize(target);

        } //!Initialize
    } //!namespace ClassWrappers
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofTextureData, nofx::ClassWrappers::Initialize)
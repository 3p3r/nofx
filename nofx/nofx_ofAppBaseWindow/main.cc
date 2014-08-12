#include "globals.h"
#include "nofx_ofAppBaseWindow.h"

namespace nofx
{
    namespace OfAppBaseWindow
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

            OfAppBaseWindowWrap::Initialize(target);

        } //!Initialize
    } //!namespace OfAppBaseWindow
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofAppBaseWindow, nofx::OfAppBaseWindow::Initialize)
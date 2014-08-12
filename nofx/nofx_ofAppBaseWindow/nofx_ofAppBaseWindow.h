#ifndef _NOFX_OF_APP_BASE_WINDOW_H_
#define _NOFX_OF_APP_BASE_WINDOW_H_

#include "globals.h"
#include "ofAppBaseWindow.h"

using namespace v8;

namespace nofx
{
    namespace OfAppBaseWindow
    {
        class OfAppBaseWindowWrap
            : public node::ObjectWrap
        {
        public:
            static void Initialize(v8::Handle<Object> target);
            ofAppBaseWindow* GetWrapped() const { return internal_.get(); };
            void SetWrapped(ofAppBaseWindow* n)  { internal_.reset(n); };
            static const Persistent<Function>& Factory() { return constructor; }
        private:
            OfAppBaseWindowWrap(ofAppBaseWindow*);
            ~OfAppBaseWindowWrap() {};

            // Methods
            static NAN_METHOD(DisableSetupScreen);
            static NAN_METHOD(DoesHWOrientation);
            static NAN_METHOD(EnableSetupScreen);
            static NAN_METHOD(GetHeight);
            static NAN_METHOD(GetOrientation);
            static NAN_METHOD(GetScreenSize);
            static NAN_METHOD(GetWidth);
            static NAN_METHOD(GetWindowMode);
            static NAN_METHOD(GetWindowPosition);
            static NAN_METHOD(GetWindowSize);
            static NAN_METHOD(HideCursor);
            static NAN_METHOD(InitializeWindow);
            static NAN_METHOD(RunAppViaInfiniteLoop);
            static NAN_METHOD(SetFullscreen);
            static NAN_METHOD(SetOrientation);
            static NAN_METHOD(SetVerticalSync);
            static NAN_METHOD(SetWindowPosition);
            static NAN_METHOD(SetWindowShape);
            static NAN_METHOD(SetWindowTitle);
            static NAN_METHOD(SetupOpenGL);
            static NAN_METHOD(ShowCursor);
            static NAN_METHOD(ToggleFullscreen);

            static Persistent<Function> constructor;
            static NAN_METHOD(New);
            std::shared_ptr<ofAppBaseWindow> internal_;
        }; // !class OfAppBaseWindowWrap
    } //!namespace OfAppBaseWindow
} // !namespace nofx

#endif // !_NOFX_OF_APP_BASE_WINDOW_H_
    
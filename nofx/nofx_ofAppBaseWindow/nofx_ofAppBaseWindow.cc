#include "nofx_ofAppBaseWindow.h"
#include "nofx_noop.h"
#include "..\nofx_ofBaseApp\nofx_ofApp.h"
#include "..\nofx\nofx_types.h"

namespace nofx
{
    namespace OfAppBaseWindow
    {
        Persistent<Function> OfAppBaseWindowWrap::constructor;

		//--------------------------------------------------------------
        OfAppBaseWindowWrap::OfAppBaseWindowWrap(ofAppBaseWindow* aInternal)
            : internal_(aInternal)
        {}

        //--------------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::New)
        {
            NanScope();
            if (args.IsConstructCall()) {
                OfAppBaseWindowWrap* obj;
				
				/************************************************************************/
				/* This class cannot be explicitly instantiated in JS domain.			*/
				/* Does not make sense, this is a very low level class. This wrapper	*/
				/* will only be used to pass stuff and pointers around.					*/
				/************************************************************************/

                if (args[0]->IsNull())
                {
                    obj = new OfAppBaseWindowWrap(nullptr);
                }
                else
                {
                    //copy constructor
                    obj = new OfAppBaseWindowWrap(ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args[0]->ToObject())->GetWrapped());
                }
                obj->Wrap(args.This());
                NanReturnValue(args.This());
            }
            else
            {
                // Invoked as plain function `MyObject(...)`, turn into construct call.
                std::vector<v8::Handle<v8::Value>> lArgvVec;
                for (int i = 0; i < args.Length(); ++i) { lArgvVec.push_back(args[i]); }
                NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(lArgvVec.size(), (lArgvVec.size() == 0) ? nullptr : &lArgvVec[0]));
            }
        }

        //--------------------------------------------------------------
        void OfAppBaseWindowWrap::Initialize(v8::Handle<Object> exports)
        {
            auto tpl = NanNew<v8::FunctionTemplate>(New);
            tpl->SetClassName(NanNew("ofAppBaseWindow"));

            auto inst = tpl->InstanceTemplate();
            inst->SetInternalFieldCount(1);

            NanSetPrototypeTemplate(tpl, NanNew("disableSetupScreen"), NanNew<v8::FunctionTemplate>(DisableSetupScreen), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("doesHWOrientation"), NanNew<v8::FunctionTemplate>(DoesHWOrientation), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("enableSetupScreen"), NanNew<v8::FunctionTemplate>(EnableSetupScreen), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("getHeight"), NanNew<v8::FunctionTemplate>(GetHeight), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("getOrientation"), NanNew<v8::FunctionTemplate>(GetOrientation), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("getScreenSize"), NanNew<v8::FunctionTemplate>(GetScreenSize), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("getWidth"), NanNew<v8::FunctionTemplate>(GetWidth), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("getWindowMode"), NanNew<v8::FunctionTemplate>(GetWindowMode), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("getWindowPosition"), NanNew<v8::FunctionTemplate>(GetWindowPosition), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("getWindowSize"), NanNew<v8::FunctionTemplate>(GetWindowSize), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("hideCursor"), NanNew<v8::FunctionTemplate>(HideCursor), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("initializeWindow"), NanNew<v8::FunctionTemplate>(InitializeWindow), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("runAppViaInfiniteLoop"), NanNew<v8::FunctionTemplate>(RunAppViaInfiniteLoop), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("setFullscreen"), NanNew<v8::FunctionTemplate>(SetFullscreen), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("setOrientation"), NanNew<v8::FunctionTemplate>(SetOrientation), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("setVerticalSync"), NanNew<v8::FunctionTemplate>(SetVerticalSync), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("setWindowPosition"), NanNew<v8::FunctionTemplate>(SetWindowPosition), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("setWindowShape"), NanNew<v8::FunctionTemplate>(SetWindowShape), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("setWindowTitle"), NanNew<v8::FunctionTemplate>(SetWindowTitle), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("setupOpenGL"), NanNew<v8::FunctionTemplate>(SetupOpenGL), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("showCursor"), NanNew<v8::FunctionTemplate>(ShowCursor), v8::ReadOnly);
            NanSetPrototypeTemplate(tpl, NanNew("toggleFullscreen"), NanNew<v8::FunctionTemplate>(ToggleFullscreen), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFAPPBASEWINDOW), v8::ReadOnly);
            NanAssignPersistent(constructor, tpl->GetFunction());
            exports->Set(NanNew<String>("ofAppBaseWindow"), tpl->GetFunction());
        }

        
        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::DisableSetupScreen)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->disableSetupScreen();
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::DoesHWOrientation)
        {
			const auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				NanReturnValue(self->doesHWOrientation());
			}
			NanReturnUndefined();
		}

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::EnableSetupScreen)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->enableSetupScreen();
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::GetHeight)
        {
			const auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				NanReturnValue(self->getHeight());
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::GetOrientation)
        {
			const auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				NanReturnValue(self->getOrientation());
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::GetScreenSize)
        {
			const auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				//depends on ofPoint
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::GetWidth)
        {
			const auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				NanReturnValue(self->getWidth());
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::GetWindowMode)
        {
			const auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				NanReturnValue(self->getWindowMode());
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::GetWindowPosition)
        {
			const auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				//depends on ofPoint
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::GetWindowSize)
        {
			const auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				//depends on ofPoint
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::HideCursor)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->hideCursor();
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::InitializeWindow)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->initializeWindow();
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::RunAppViaInfiniteLoop)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->runAppViaInfiniteLoop(node::ObjectWrap::Unwrap<BaseApp::OfAppWrap>(args[0]->ToObject())->GetWrapped());
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::SetFullscreen)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->setFullscreen(args[0]->BooleanValue());
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::SetOrientation)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->setOrientation(static_cast<ofOrientation>(args[0]->Uint32Value()));
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::SetVerticalSync)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->setVerticalSync(args[0]->BooleanValue());
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::SetWindowPosition)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->setWindowPosition(args[0]->Int32Value(), args[1]->Int32Value());
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::SetWindowShape)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->setWindowShape(args[0]->Int32Value(), args[1]->Int32Value());
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::SetWindowTitle)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->setWindowTitle(*NanUtf8String(args[0]));
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::SetupOpenGL)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->setupOpenGL(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value());
			}
			NanReturnUndefined();
        }

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::ShowCursor)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->showCursor();
			}
			NanReturnUndefined();
		}

        //---------------------------------------------------------
        NAN_METHOD(OfAppBaseWindowWrap::ToggleFullscreen)
        {
			auto self = node::ObjectWrap::Unwrap<OfAppBaseWindowWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				self->toggleFullscreen();
			}
			NanReturnUndefined();
        }

    } //!namespace OfAppBaseWindow
} //!namespace nofx
#include "globals.h"
#include "nofx_dependencies.h"
#include "nofx_ofDoesHWOrientation.h"
#include "nofx_ofExit.h"
#include "nofx_ofGetAppPtr.h"
#include "nofx_ofGetFrameNum.h"
#include "nofx_ofGetFrameRate.h"
#include "nofx_ofGetHeight.h"
#include "nofx_ofGetLastFrameTime.h"
#include "nofx_ofGetOrientation.h"
#include "nofx_ofGetScreenHeight.h"
#include "nofx_ofGetScreenWidth.h"
#include "nofx_ofGetTargetFrameRate.h"
#include "nofx_ofGetWidth.h"
#include "nofx_ofGetWindowHeight.h"
#include "nofx_ofGetWindowMode.h"
#include "nofx_ofGetWindowPositionX.h"
#include "nofx_ofGetWindowPositionY.h"
#include "nofx_ofGetWindowPtr.h"
#include "nofx_ofGetWindowRect.h"
#include "nofx_ofGetWindowSize.h"
#include "nofx_ofGetWindowWidth.h"
#include "nofx_ofHideCursor.h"
#include "nofx_ofRunApp.h"
#include "nofx_ofSetAppPtr.h"
#include "nofx_ofSetFrameRate.h"
#include "nofx_ofSetFullscreen.h"
#include "nofx_ofSetOrientation.h"
#include "nofx_ofSetVerticalSync.h"
#include "nofx_ofSetWindowPosition.h"
#include "nofx_ofSetWindowShape.h"
#include "nofx_ofSetWindowTitle.h"
#include "nofx_ofSetupOpenGL.h"
#include "nofx_ofShowCursor.h"
#include "nofx_ofSleepMillis.h"
#include "nofx_ofToggleFullscreen.h"

namespace nofx
{
	namespace AppRunner
	{
		using namespace v8;

		void Initialize(v8::Handle<Object> target,
			v8::Handle<Value> unused,
			v8::Handle<Context> context)
		{

			target->Set(NanNew<v8::String>("dependencies"), NanNew<v8::FunctionTemplate>(nofx_dependencies)->GetFunction());
			target->Set(NanNew<v8::String>("ofDoesHWOrientation"), NanNew<v8::FunctionTemplate>(nofx_ofDoesHWOrientation)->GetFunction());
			target->Set(NanNew<v8::String>("ofExit"), NanNew<v8::FunctionTemplate>(nofx_ofExit)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetAppPtr"), NanNew<v8::FunctionTemplate>(nofx_ofGetAppPtr)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetFrameNum"), NanNew<v8::FunctionTemplate>(nofx_ofGetFrameNum)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetFrameRate"), NanNew<v8::FunctionTemplate>(nofx_ofGetFrameRate)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetHeight"), NanNew<v8::FunctionTemplate>(nofx_ofGetHeight)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetLastFrameTime"), NanNew<v8::FunctionTemplate>(nofx_ofGetLastFrameTime)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetOrientation"), NanNew<v8::FunctionTemplate>(nofx_ofGetOrientation)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetScreenHeight"), NanNew<v8::FunctionTemplate>(nofx_ofGetScreenHeight)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetScreenWidth"), NanNew<v8::FunctionTemplate>(nofx_ofGetScreenWidth)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetTargetFrameRate"), NanNew<v8::FunctionTemplate>(nofx_ofGetTargetFrameRate)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetWidth"), NanNew<v8::FunctionTemplate>(nofx_ofGetWidth)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetWindowHeight"), NanNew<v8::FunctionTemplate>(nofx_ofGetWindowHeight)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetWindowMode"), NanNew<v8::FunctionTemplate>(nofx_ofGetWindowMode)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetWindowPositionX"), NanNew<v8::FunctionTemplate>(nofx_ofGetWindowPositionX)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetWindowPositionY"), NanNew<v8::FunctionTemplate>(nofx_ofGetWindowPositionY)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetWindowPtr"), NanNew<v8::FunctionTemplate>(nofx_ofGetWindowPtr)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetWindowRect"), NanNew<v8::FunctionTemplate>(nofx_ofGetWindowRect)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetWindowSize"), NanNew<v8::FunctionTemplate>(nofx_ofGetWindowSize)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetWindowWidth"), NanNew<v8::FunctionTemplate>(nofx_ofGetWindowWidth)->GetFunction());
			target->Set(NanNew<v8::String>("ofHideCursor"), NanNew<v8::FunctionTemplate>(nofx_ofHideCursor)->GetFunction());
			target->Set(NanNew<v8::String>("ofRunApp"), NanNew<v8::FunctionTemplate>(nofx_ofRunApp)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetAppPtr"), NanNew<v8::FunctionTemplate>(nofx_ofSetAppPtr)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetFrameRate"), NanNew<v8::FunctionTemplate>(nofx_ofSetFrameRate)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetFullscreen"), NanNew<v8::FunctionTemplate>(nofx_ofSetFullscreen)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetOrientation"), NanNew<v8::FunctionTemplate>(nofx_ofSetOrientation)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetVerticalSync"), NanNew<v8::FunctionTemplate>(nofx_ofSetVerticalSync)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetWindowPosition"), NanNew<v8::FunctionTemplate>(nofx_ofSetWindowPosition)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetWindowShape"), NanNew<v8::FunctionTemplate>(nofx_ofSetWindowShape)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetWindowTitle"), NanNew<v8::FunctionTemplate>(nofx_ofSetWindowTitle)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetupOpenGL"), NanNew<v8::FunctionTemplate>(nofx_ofSetupOpenGL)->GetFunction());
			target->Set(NanNew<v8::String>("ofShowCursor"), NanNew<v8::FunctionTemplate>(nofx_ofShowCursor)->GetFunction());
			target->Set(NanNew<v8::String>("ofSleepMillis"), NanNew<v8::FunctionTemplate>(nofx_ofSleepMillis)->GetFunction());
			target->Set(NanNew<v8::String>("ofToggleFullscreen"), NanNew<v8::FunctionTemplate>(nofx_ofToggleFullscreen)->GetFunction());

		} //!Initialize
	} //!namespace AppRunner
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofAppRunner, nofx::AppRunner::Initialize)

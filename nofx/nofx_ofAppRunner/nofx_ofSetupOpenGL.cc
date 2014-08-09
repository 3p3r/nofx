#include "nofx_ofSetupOpenGL.h"
#include "ofAppRunner.h"

namespace nofx
{
	NAN_METHOD(nofx_ofSetupOpenGL) {
		double lWindowWidth = args[0]->NumberValue();
		double lWindowHeight = args[1]->NumberValue();
		ofWindowMode lOpenGLWindowEnum = args[2]->IsUndefined() ? OF_WINDOW : (ofWindowMode)args[2]->Int32Value();
		ofSetupOpenGL(lWindowWidth, lWindowHeight, lOpenGLWindowEnum);
		NanReturnUndefined();
	} // !nofx_ofSetupOpenGL
} // !namespace nofx
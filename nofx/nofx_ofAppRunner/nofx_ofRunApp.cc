#include "nofx_ofRunApp.h"
#include "ofAppRunner.h"
#include "..\nofx_ofBaseApp\nofx_ofApp.h"

namespace nofx
{
	// Runs a new instance of the OF application
	// In an ideal world, when user calls this function, it should
	// never exit. It'll however print a message at "peaceful exit".
	// currently multiple calls to this function should not happen.
	NAN_METHOD(nofx_ofRunApp) {
		// Attempting to run the OF app
		return ofRunApp(node::ObjectWrap::Unwrap<OfAppWrap>(args[0]->ToObject())->GetWrapped());
	} // ofxNode_ofRunApp
} // namespace nofx
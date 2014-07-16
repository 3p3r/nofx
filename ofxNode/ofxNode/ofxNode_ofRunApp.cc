#include "ofxNode_ofRunApp.h"
#include "ofApp.h"

namespace ofxNode
{
	// Runs a new instance of the OF application
	// In an ideal world, when user calls this function, it should
	// never exit. It'll however print a message at "peaceful exit".
	// currently multiple calls to this function should not happen.
	NAN_METHOD(ofxNode_ofRunApp) {
		ASSERT_FALSE(self_.IsEmpty());
		EXPECT_FALSE(ofxNodeAppIsRunning);

		NanScope();
		
		if (!ofxNodeAppIsRunning)
		{
			// prevent multiple calls
			ofxNodeAppIsRunning = true;
			// Attempting to run the OF app
			ofRunApp(new ofApp(self_));
			// From this point on, OF is in charge of the application's main thread
			NanReturnValue(args.This());
		}
		else
		{
			NanThrowError("You can call ofRunApp only once!");
		}
	} // ofxNode_ofRunApp
} // namespace ofxNode
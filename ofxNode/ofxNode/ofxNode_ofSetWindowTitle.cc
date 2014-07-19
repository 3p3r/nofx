#include "ofxNode_ofSetWindowTitle.h"
#include "ofAppRunner.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofSetWindowTitle) {
		NanScope();

		if (args.Length() == 1)
		{
			ofSetWindowTitle(NanCString(args[0], nullptr));
		}
		else
		{
			NanThrowError("bad args passed to ofSetWindowTitle.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofSetWindowTitle
} // !namespace ofxNode

#include "ofxNode_ofGetElapsedTimef.h"
#include "ofMain.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofGetElapsedTimef) {
		NanReturnValue(NanNew(ofGetElapsedTimef()));
	} // !ofxNode_ofGetElapsedTimef
} // !namespace ofxNode
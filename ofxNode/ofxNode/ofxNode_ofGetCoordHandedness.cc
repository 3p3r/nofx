#include "ofxNode_ofGetCoordHandedness.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofGetCoordHandedness) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		//Insert code here

		NanReturnValue(ofGetCoordHandedness());
	} // !ofxNode_ofGetCoordHandedness
} // !namespace ofxNode
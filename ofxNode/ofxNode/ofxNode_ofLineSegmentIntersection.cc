#include "ofxNode_ofLineSegmentIntersection.h"
#include "ofMath.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofLineSegmentIntersection) {
		NanReturnValue(ofLineSegmentIntersection(
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[2]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[3]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[4]->ToObject())->self()
			));
    } // !ofxNode_ofLineSegmentIntersection
} // !namespace ofxNode
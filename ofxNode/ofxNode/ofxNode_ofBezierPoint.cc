#include "ofxNode_ofBezierPoint.h"
#include "ofMath.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofBezierPoint) {

        auto toRet = NanNew(ofxNode_ofVec3f::factory())->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(toRet)->self() = ofBezierPoint(
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[2]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[3]->ToObject())->self(),
			V8_ARG_NUMBER(args[4])
			);

        NanReturnValue(toRet);
    } // !ofxNode_ofBezierPoint
} // !namespace ofxNode
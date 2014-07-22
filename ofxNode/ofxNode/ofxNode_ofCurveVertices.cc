#include "ofxNode_ofCurveVertices.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofCurveVertices) {
		vector< ofPoint > lCurvePointsToPass;
		const auto lCurvePointsProps = args[0]->ToObject()->GetPropertyNames();
		for (int i = 0; i < lCurvePointsProps->Length(); ++i)
		{
			const auto lVal = args[0]->ToObject()->Get(i)->ToObject();
			lCurvePointsToPass.push_back(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(lVal)->self());
		}

		if (!lCurvePointsToPass.empty())
		{
			ofCurveVertices(lCurvePointsToPass);
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofCurveVertices
} // !namespace ofxNode
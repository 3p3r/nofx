#include "ofxNode_ofVertices.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofVertices) {
		vector< ofPoint > lPolyPointsToPass;
		const auto lpolyPointsProps = args[0]->ToObject()->GetPropertyNames();
		for (int i = 0; i < lpolyPointsProps->Length(); ++i)
		{
			const auto lKey = lpolyPointsProps->Get(i);
			const auto lVal = args[0]->ToObject()->Get(i);

			if (lVal->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)
			{
				lPolyPointsToPass.push_back(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(lVal->ToObject())->self());
			}
		}
		if (lPolyPointsToPass.size() != 0)
		{
			ofVertices(lPolyPointsToPass);
		}
        NanReturnValue(args.This());
    } // !{ofxNode_ofVertices}
} // !namespace ofxNode
#include "ofxNode_ofInsidePoly.h"
#include "ofMath.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofInsidePoly) {
		if (args.Length() == 2)
		{
			std::vector<ofPoint> poly;
			const auto lpolyPointsProps = args[1]->ToObject()->GetPropertyNames();
			for (int i = 0; i < lpolyPointsProps->Length(); ++i)
			{
				const auto lVal = args[1]->ToObject()->Get(i);
				if (lVal->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)
				{
					poly.push_back(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(lVal->ToObject())->self());
				}
				if (poly.size() != 0)
				{
					NanReturnValue(ofInsidePoly(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(), poly));
				}
				else
				{
					NanReturnUndefined();
				}
			}
		}
		else
		{
			std::vector<ofPoint> poly;
			const auto lpolyPointsProps = args[2]->ToObject()->GetPropertyNames();
			for (int i = 0; i < lpolyPointsProps->Length(); ++i)
			{
				const auto lVal = args[2]->ToObject()->Get(i);
				if (lVal->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)
				{
					poly.push_back(node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(lVal->ToObject())->self());
				}
				if (poly.size() != 0)
				{
					NanReturnValue(ofInsidePoly(args[0]->NumberValue(), args[0]->NumberValue(), poly));
				}
				else
				{
					NanReturnUndefined();
				}
			}
		}
	} // !ofxNode_ofInsidePoly
} // !namespace ofxNode
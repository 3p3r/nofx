#include "ofxNode_ofCurveVertices.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofCurveVertices) {
		NanScope();
		
		vector< ofPoint > lCurvePointsToPass;
		//void ofCurveVertices(const vector< ofPoint > &curvePoints)
		if (args.Length() == 1 && args[0]->IsArray())
		{
			const auto lCurvePointsProps = args[0]->ToObject()->GetPropertyNames();
			for (int i = 0; i < lCurvePointsProps->Length(); ++i)
			{
				const auto lKey = lCurvePointsProps->Get(i);
				const auto lVal = args[0]->ToObject()->Get(i);

				if (IS_V8_ARG_2D_OF_POS(lVal))
				{
					lCurvePointsToPass.push_back(ofPoint(V8_POS_X(lVal) , V8_POS_Y(lVal), V8_POS_Z(lVal)));
				}
			}

			if (!lCurvePointsToPass.empty())
			{
				ofCurveVertices(lCurvePointsToPass);
			}
		}
		else
		{
			NanThrowError("wrong arguments passed to ofCurveVertices.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofCurveVertices
} // !namespace ofxNode
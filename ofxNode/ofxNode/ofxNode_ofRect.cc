#include "ofxNode_ofRect.h"
#include "ofGraphics.h"
#include "ofTypes.h"
#include "ofxNode_wrapper_ofVec3f.h"
#include "ofxNode_wrapper_ofRectangle.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofRect) {
		if (args.Length() == 1)
		{
			ofRect(node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[0]->ToObject())->self());
		}
		if (args.Length() == 3)
		{
			if ((args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFPOINT) ||
				(args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F))
			{
				const ofPoint p1 = node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self();
				ofRect(p1, args[1]->NumberValue(), args[2]->NumberValue());
			}
			else
			{
				NanThrowError("bad args passed to ofRect.");
			}
		}
		else if (args.Length() == 4)
		{
			ofRect(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3])
				);
		}
		else
		{
			ofRect(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3]),
				V8_ARG_NUMBER(args[4])
				);
		}
		NanReturnValue(args.This());
	} // !ofxNode_ofRect
} // !namespace ofxNode

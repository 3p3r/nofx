#include "ofxNode_ofLine.h"
#include "ofGraphics.h"
#include "ofTypes.h"
#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofLine) {
		NanScope();

		if (args.Length() == 4)
		{
			ofLine(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3])
				);
		}
		else if (args.Length() == 6)
		{
			ofLine(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3]),
				V8_ARG_NUMBER(args[4]),
				V8_ARG_NUMBER(args[5])
				);
		}
		else if (args.Length() == 2)
		{
			if (((args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFPOINT) ||
				(args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F))
				&&
				((args[1]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFPOINT) ||
				(args[1]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F)))

			{
				const ofPoint p1 = node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self();
				const ofPoint p2 = node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self();
				ofLine(p1, p2);
			}
		}
		else
		{
			NanThrowError("bad args passed to ofLine.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofLine
} // !namespace ofxNode

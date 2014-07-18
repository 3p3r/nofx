#include "ofxNode_wrapper_ofVec2f.h"

namespace ofxNode
{
	v8::Persistent<v8::Function> ofxNode_ofVec2f::constructor;

	ofxNode_ofVec2f::ofxNode_ofVec2f(ofVec2f aOfVec2f)
		: inherited(aOfVec2f)
	{}

	ofxNode_ofVec2f::~ofxNode_ofVec2f()
	{}

	void ofxNode_ofVec2f::Init(v8::Handle<v8::Object> exports)
	{
		// Prepare constructor template
		v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(v8::Isolate::GetCurrent(), New);
		tpl->SetClassName(NanNew("ofVec2f"));
		tpl->InstanceTemplate()->SetInternalFieldCount(5);
		
		// Prototype
		tpl->PrototypeTemplate()->Set(NanNew("align") , v8::FunctionTemplate::New(v8::Isolate::GetCurrent(), Align)->GetFunction());
		tpl->PrototypeTemplate()->Set(NanNew("alignRad") , v8::FunctionTemplate::New(v8::Isolate::GetCurrent(), AlignRad)->GetFunction());
		tpl->PrototypeTemplate()->Set(NanNew("angle") , v8::FunctionTemplate::New(v8::Isolate::GetCurrent(), Angle)->GetFunction());
		tpl->PrototypeTemplate()->Set(NanNew("angleRad") , v8::FunctionTemplate::New(v8::Isolate::GetCurrent(), AngleRad)->GetFunction());
		tpl->PrototypeTemplate()->Set(NanNew("average") , v8::FunctionTemplate::New(v8::Isolate::GetCurrent(), Average)->GetFunction());
		tpl->PrototypeTemplate()->Set(NanNew("length") , v8::FunctionTemplate::New(v8::Isolate::GetCurrent(), Length)->GetFunction());
		
		NanAssignPersistent(constructor, tpl->GetFunction());
		exports->Set(NanNew<v8::String>("ofVec2f"), NanNew<v8::Function>(constructor));
	}

	NAN_METHOD(ofxNode_ofVec2f::New)
	{
		NanScope();
		if (args.IsConstructCall()) {
			// Invoked as constructor: `new ofVec2f(...)`
			ofxNode_ofVec2f* obj;
			if (args.Length() == 2)
			{
				ofVec2f lPoint(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]));
				obj = new ofxNode_ofVec2f(lPoint);
			}
			else
			{
				//copy constructor like a BOSS!
				obj = new ofxNode_ofVec2f(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->getScaled(1));
			}
			obj->Wrap(args.This());
			NanReturnValue(args.This());
		} else {
			// Invoked as plain function `MyObject(...)`, turn into construct call.
			const int argc = 2;
			v8::Local<v8::Value> argv[argc] = { args[0], args[1] };
			NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(argc, argv));
		}
	}

	NAN_METHOD(ofxNode_ofVec2f::Average)
	{
		std::vector<ofVec2f> lPoints;

		const auto lPointsProps = args[0]->ToObject()->GetPropertyNames();
		for (int i = 0; i < lPointsProps->Length(); ++i)
		{
			const auto lKey = lPointsProps->Get(i);
			const auto lVal = args[0]->ToObject()->Get(i);

			lPoints.push_back(ObjectWrap::Unwrap<ofxNode_ofVec2f>(lVal->ToObject())->getScaled(1));
		}

		const ofVec2f* lPointsArr = &lPoints[0];
		const int lPointsArrSize = lPoints.size();

		ofVec2f lAverageResult = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->average(lPointsArr, lPointsArrSize);

		const int argc = 2;
		v8::Local<v8::Value> argv[argc] = { 
			NanNew(lAverageResult.x) ,
			NanNew(lAverageResult.y)
		};

		NanReturnValue(args.This());

	}

	NAN_METHOD(ofxNode_ofVec2f::Angle)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject());
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->angle(lArgVec->getScaled(1)));
	}

	NAN_METHOD(ofxNode_ofVec2f::AngleRad)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject());
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->angleRad(lArgVec->getScaled(1)));
	}

	NAN_METHOD(ofxNode_ofVec2f::Align)
	{
		const auto lAlignWith = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject());
		if (args[1]->IsUndefined())
		{
			NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->align(lAlignWith->getScaled(1)));
		}
		else
		{
			NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->align(lAlignWith->getScaled(1), args[1]->NumberValue()));
		}
	}

	NAN_METHOD(ofxNode_ofVec2f::AlignRad)
	{
		const auto lAlignWith = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject());
		if (args[1]->IsUndefined())
		{
			NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->alignRad(lAlignWith->getScaled(1)));
		}
		else
		{
			NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->alignRad(lAlignWith->getScaled(1), args[1]->NumberValue()));
		}
	}

	NAN_METHOD(ofxNode_ofVec2f::Length)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->length());
	}

} // !namespace ofxNode
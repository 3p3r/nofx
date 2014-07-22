#include "ofxNode_wrapper_ofVec4f.h"

namespace ofxNode
{
	v8::Persistent<v8::Function> ofxNode_ofVec4f::constructor;

	ofxNode_ofVec4f::ofxNode_ofVec4f(ofVec4f& aOfVec4f)
		: internal_(aOfVec4f)
	{}

	ofxNode_ofVec4f::~ofxNode_ofVec4f()
	{}

	void ofxNode_ofVec4f::Init(v8::Handle<v8::Object> exports)
	{
		// Prepare constructor template
		auto tpl = NanNew<v8::FunctionTemplate>(New);
		tpl->SetClassName(NanNew("ofVec4f"));
		tpl->InstanceTemplate()->SetInternalFieldCount(1); //One + number of ofVec4f public methods assigned by NanSetPrototypeTemplate
		
		
		tpl->InstanceTemplate()->SetAccessor(NanNew("DIM")	, ofxNode_ofVec4f::GetDIM, 0, v8::Handle<v8::Value>(), v8::PROHIBITS_OVERWRITING);
		tpl->InstanceTemplate()->SetAccessor(NanNew("x")	, ofxNode_ofVec4f::GetX , ofxNode_ofVec4f::SetX);
		tpl->InstanceTemplate()->SetAccessor(NanNew("y")	, ofxNode_ofVec4f::GetY , ofxNode_ofVec4f::SetY);
		tpl->InstanceTemplate()->SetAccessor(NanNew("z")	, ofxNode_ofVec4f::GetZ , ofxNode_ofVec4f::SetZ);
		tpl->InstanceTemplate()->SetAccessor(NanNew("w")	, ofxNode_ofVec4f::GetW , ofxNode_ofVec4f::SetW);

		// Prototype
		NanSetPrototypeTemplate(tpl, NanNew("average")			, NanNew<v8::FunctionTemplate>(Average)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("distance")			, NanNew<v8::FunctionTemplate>(Distance)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("dot")				, NanNew<v8::FunctionTemplate>(Dot)				, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getInterpolated")	, NanNew<v8::FunctionTemplate>(GetInterpolated)	, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getLimited")		, NanNew<v8::FunctionTemplate>(GetLimited)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getMiddle")		, NanNew<v8::FunctionTemplate>(GetMiddle)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getNormalized")	, NanNew<v8::FunctionTemplate>(GetNormalized)	, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getPtr")			, NanNew<v8::FunctionTemplate>(GetPtr)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getScaled")		, NanNew<v8::FunctionTemplate>(GetScaled)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("interpolate")		, NanNew<v8::FunctionTemplate>(Interpolate)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("length")			, NanNew<v8::FunctionTemplate>(Length)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("limit")			, NanNew<v8::FunctionTemplate>(Limit)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("match")			, NanNew<v8::FunctionTemplate>(Match)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("middle")			, NanNew<v8::FunctionTemplate>(Middle)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("normalize")		, NanNew<v8::FunctionTemplate>(Normalize)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("one")				, NanNew<v8::FunctionTemplate>(One)				, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("scale")			, NanNew<v8::FunctionTemplate>(Scale)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("set")				, NanNew<v8::FunctionTemplate>(Set)				, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("squareDistance")	, NanNew<v8::FunctionTemplate>(SquareDistance)	, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("zero")				, NanNew<v8::FunctionTemplate>(Zero)			, v8::ReadOnly);
		
		// Javascript Primitives
		NanSetPrototypeTemplate(tpl, NanNew("toString")			, NanNew<v8::FunctionTemplate>(ToString)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("plus")				, NanNew<v8::FunctionTemplate>(Plus)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("times")			, NanNew<v8::FunctionTemplate>(Times)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("over")				, NanNew<v8::FunctionTemplate>(Over)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("minus")			, NanNew<v8::FunctionTemplate>(Minus)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("equals")			, NanNew<v8::FunctionTemplate>(Equals)			, v8::ReadOnly);

		NanSetPrototypeTemplate(tpl, NanNew("OFXNODE_TYPE")		, NanNew(OFXNODE_TYPES::OFVEC4F)					, v8::DontEnum);
		NanAssignPersistent(constructor, tpl->GetFunction());
		exports->Set(NanNew<v8::String>("ofVec4f"), tpl->GetFunction());
	}

	NAN_METHOD(ofxNode_ofVec4f::Equals)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_;
		if (args[0]->IsArray())
		{
			bool result = true;
			bool ranAtLeastOnce = false;
			const auto lProps = args[0]->ToObject()->GetPropertyNames();
			for (int i = 0; i < lProps->Length(); ++i)
			{
				const auto lKey = lProps->Get(i);
				const auto lVal = args[0]->ToObject()->Get(i);

				if(lVal->ToObject()->Has(NanNew("OFXNODE_TYPE")) && lVal->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() == OFXNODE_TYPES::OFVEC4F)
				{
					ranAtLeastOnce = true;
					result = result && (self == ObjectWrap::Unwrap<ofxNode_ofVec4f>(lVal->ToObject())->internal_);
				}
			}

			NanReturnValue( (NanNew(result && ranAtLeastOnce)) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->internal_;
			NanReturnValue( (NanNew(self == lArgVec)) );
		}
	}

	NAN_METHOD(ofxNode_ofVec4f::Over)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_;
		const int lArgc = 4;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self / lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z), NanNew(result.w)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->internal_;
			const auto result = self / lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z), NanNew(result.w)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec4f::Times)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_;
		const int lArgc = 4;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self * lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z), NanNew(result.w)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->internal_;
			const auto result = self * lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z), NanNew(result.w)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec4f::Minus)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_;
		const int lArgc = 4;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self - lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z), NanNew(result.w)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->internal_;
			const auto result = self - lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z), NanNew(result.w)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec4f::Plus)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_;
		const int lArgc = 4;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self + lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z), NanNew(result.w)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->internal_;
			const auto result = self + lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z), NanNew(result.w)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec4f::ToString)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_;
		std::ostringstream out;
		out << self;
		NanReturnValue( NanNew(out.str().c_str()) );
	}

	NAN_METHOD(ofxNode_ofVec4f::Set)
	{
		if (args.Length() == 1 &&
			args[0]->IsObject() &&
			args[0]->ToObject()->Has(NanNew("OFXNODE_TYPE")) &&
			args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() == OFXNODE_TYPES::OFVEC4F)
		{
			ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.set(ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->internal_);
		}
		else if(args.Length() == 4)
		{
			ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.set(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		}
		NanReturnValue( args.This() );
	}


	NAN_METHOD(ofxNode_ofVec4f::Scale)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.scale(args[0]->NumberValue());
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec4f::Zero)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.zero();
		const int lArgc = 4;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z), NanNew(lCalculatedVec.w)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec4f::One)
	{
		const int lArgc = 4;
		v8::Handle<v8::Value> lArgv[] = {NanNew(1), NanNew(1), NanNew(1), NanNew(1)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec4f::Normalize)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.normalize();
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec4f::Middle)
	{
		const auto lArgVec1 = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->internal_;
		ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.middle(lArgVec1);
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec4f::Limit)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.limit(args[0]->NumberValue());
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec4f::Match)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->internal_;
		float tolerance = args[1]->IsUndefined() ? 0.0001f : args[1]->NumberValue();
		NanReturnValue( NanNew(ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.match(lArgVec, tolerance)) );
	}

	NAN_METHOD(ofxNode_ofVec4f::GetPtr)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_;
		
		auto lArrToReturn = NanNew<v8::Array>();
		lArrToReturn->Set(0, NanNew(self.x));
		lArrToReturn->Set(1, NanNew(self.y));
		lArrToReturn->Set(2, NanNew(self.z));
		lArrToReturn->Set(2, NanNew(self.w));

		NanReturnValue( lArrToReturn );
	}

	NAN_METHOD(ofxNode_ofVec4f::GetScaled)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.getScaled(args[0]->NumberValue());
		const int lArgc = 4;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z), NanNew(lCalculatedVec.w)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec4f::GetMiddle)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->internal_;
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.getMiddle(lArgVec);
		const int lArgc = 4;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z), NanNew(lCalculatedVec.w)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec4f::GetNormalized)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.getNormalized();
		const int lArgc = 4;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z), NanNew(lCalculatedVec.w)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec4f::GetLimited)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.getLimited(args[0]->NumberValue());
		const int lArgc = 4;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z), NanNew(lCalculatedVec.w)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec4f::Interpolate)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->internal_;
		ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.interpolate(lArgVec, args[1]->NumberValue());
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec4f::GetInterpolated)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->internal_;
		const auto lInterpolated = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.getInterpolated(lArgVec, args[1]->NumberValue());
		const int lArgc = 4;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lInterpolated.x), NanNew(lInterpolated.y), NanNew(lInterpolated.z), NanNew(lInterpolated.w)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec4f::Dot)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject());
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.dot(lArgVec->internal_));
	}

	NAN_METHOD(ofxNode_ofVec4f::SquareDistance)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject());
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.squareDistance(lArgVec->internal_));
	}

	NAN_METHOD(ofxNode_ofVec4f::Distance)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject());
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.distance(lArgVec->internal_));
	}

	NAN_GETTER(ofxNode_ofVec4f::GetDIM)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.DIM);
	}

	NAN_GETTER(ofxNode_ofVec4f::GetX)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.x);
	}

	NAN_SETTER(ofxNode_ofVec4f::SetX)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.x = value->NumberValue();
	}

	NAN_GETTER(ofxNode_ofVec4f::GetY)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.y);
	}

	NAN_SETTER(ofxNode_ofVec4f::SetY)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.y = value->NumberValue();
	}

	NAN_GETTER(ofxNode_ofVec4f::GetZ)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.z);
	}

	NAN_SETTER(ofxNode_ofVec4f::SetZ)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.z = value->NumberValue();
	}

	NAN_GETTER(ofxNode_ofVec4f::GetW)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.w);
	}

	NAN_SETTER(ofxNode_ofVec4f::SetW)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.w = value->NumberValue();
	}

	NAN_METHOD(ofxNode_ofVec4f::New)
	{
		NanScope();
		if (args.IsConstructCall()) {
			// Invoked as constructor: `new ofVec4f(...)`
			ofxNode_ofVec4f* obj;
			if (args.Length() == 4)
			{
				ofVec4f lPoint(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]), V8_ARG_NUMBER(args[3]));
				obj = new ofxNode_ofVec4f(lPoint);
			}
			else
			{
				//copy constructor like a BOSS!
				obj = new ofxNode_ofVec4f(ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->internal_);
			}
			obj->Wrap(args.This());
			NanReturnValue(args.This());
		} else {
			// Invoked as plain function `MyObject(...)`, turn into construct call.
			const int argc = 4;
			v8::Local<v8::Value> argv[argc] = { args[0], args[1], args[2], args[3] };
			NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(argc, argv));
		}
	}

	NAN_METHOD(ofxNode_ofVec4f::Average)
	{
		std::vector<ofVec4f> lPoints;

		const auto lPointsProps = args[0]->ToObject()->GetPropertyNames();
		for (int i = 0; i < lPointsProps->Length(); ++i)
		{
			const auto lKey = lPointsProps->Get(i);
			const auto lVal = args[0]->ToObject()->Get(i);

			lPoints.push_back(ObjectWrap::Unwrap<ofxNode_ofVec4f>(lVal->ToObject())->internal_);
		}

		ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.average(&lPoints[0], lPoints.size());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofVec4f::Length)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec4f>(args.This())->internal_.length());
	}

} // !namespace ofxNode
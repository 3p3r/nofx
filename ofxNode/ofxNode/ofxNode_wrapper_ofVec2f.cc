#include "ofxNode_wrapper_ofVec2f.h"

namespace ofxNode
{
	v8::Persistent<v8::Function> ofxNode_ofVec2f::constructor;

	ofxNode_ofVec2f::ofxNode_ofVec2f(ofVec2f aOfVec2f)
		: internal_(aOfVec2f)
	{}

	ofxNode_ofVec2f::~ofxNode_ofVec2f()
	{}

	void ofxNode_ofVec2f::Init(v8::Handle<v8::Object> exports)
	{
		// Prepare constructor template
		auto tpl = NanNew<v8::FunctionTemplate>(New);
		tpl->SetClassName(NanNew("ofVec2f"));
		tpl->InstanceTemplate()->SetInternalFieldCount(1); //One + number of ofVec2f public methods assigned by NanSetPrototypeTemplate
		
		
		tpl->InstanceTemplate()->SetAccessor(NanNew("DIM")	, ofxNode_ofVec2f::GetDIM, 0, v8::Handle<v8::Value>(), v8::PROHIBITS_OVERWRITING);
		tpl->InstanceTemplate()->SetAccessor(NanNew("x")	, ofxNode_ofVec2f::GetX , ofxNode_ofVec2f::SetX);
		tpl->InstanceTemplate()->SetAccessor(NanNew("y")	, ofxNode_ofVec2f::GetY , ofxNode_ofVec2f::SetY);

		// Prototype
		NanSetPrototypeTemplate(tpl, NanNew("align")			, NanNew<v8::FunctionTemplate>(Align)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("alignRad")			, NanNew<v8::FunctionTemplate>(AlignRad)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("angle")			, NanNew<v8::FunctionTemplate>(Angle)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("angleRad")			, NanNew<v8::FunctionTemplate>(AngleRad)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("average")			, NanNew<v8::FunctionTemplate>(Average)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("distance")			, NanNew<v8::FunctionTemplate>(Distance)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("dot")				, NanNew<v8::FunctionTemplate>(Dot)				, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getInterpolated")	, NanNew<v8::FunctionTemplate>(GetInterpolated)	, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getLimited")		, NanNew<v8::FunctionTemplate>(GetLimited)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getMiddle")		, NanNew<v8::FunctionTemplate>(GetMiddle)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getNormalized")	, NanNew<v8::FunctionTemplate>(GetNormalized)	, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getPerpendicular")	, NanNew<v8::FunctionTemplate>(GetPerpendicular), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getPtr")			, NanNew<v8::FunctionTemplate>(GetPtr)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getRotated")		, NanNew<v8::FunctionTemplate>(GetRotated)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getRotatedRad")	, NanNew<v8::FunctionTemplate>(GetRotatedRad)	, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getScaled")		, NanNew<v8::FunctionTemplate>(GetScaled)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("interpolate")		, NanNew<v8::FunctionTemplate>(Interpolate)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("isAligned")		, NanNew<v8::FunctionTemplate>(IsAligned)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("isAlignedRad")		, NanNew<v8::FunctionTemplate>(IsAlignedRad)	, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("length")			, NanNew<v8::FunctionTemplate>(Length)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("limit")			, NanNew<v8::FunctionTemplate>(Limit)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("map")				, NanNew<v8::FunctionTemplate>(Map)				, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("match")			, NanNew<v8::FunctionTemplate>(Match)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("middle")			, NanNew<v8::FunctionTemplate>(Middle)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("normalize")		, NanNew<v8::FunctionTemplate>(Normalize)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("one")				, NanNew<v8::FunctionTemplate>(One)				, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("perpendicular")	, NanNew<v8::FunctionTemplate>(Perpendicular)	, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("rotate")			, NanNew<v8::FunctionTemplate>(Rotate)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("rotateRad")		, NanNew<v8::FunctionTemplate>(RotateRad)		, v8::ReadOnly);
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

		NanSetPrototypeTemplate(tpl, NanNew("OFXNODE_TYPE")		, NanNew(OFXNODE_TYPES::OFVEC2F)					, v8::DontEnum);
		NanAssignPersistent(constructor, tpl->GetFunction());
		exports->Set(NanNew<v8::String>("ofVec2f"), tpl->GetFunction());
	}

	NAN_METHOD(ofxNode_ofVec2f::Equals)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_;
		if (args[0]->IsArray())
		{
			bool result = true;
			bool ranAtLeastOnce = false;
			const auto lProps = args[0]->ToObject()->GetPropertyNames();
			for (int i = 0; i < lProps->Length(); ++i)
			{
				const auto lKey = lProps->Get(i);
				const auto lVal = args[0]->ToObject()->Get(i);

				if(lVal->ToObject()->Has(NanNew("OFXNODE_TYPE")) && lVal->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() == OFXNODE_TYPES::OFVEC2F)
				{
					ranAtLeastOnce = true;
					result = result && (self == ObjectWrap::Unwrap<ofxNode_ofVec2f>(lVal->ToObject())->internal_);
				}
			}

			NanReturnValue( (NanNew(result && ranAtLeastOnce)) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
			NanReturnValue( (NanNew(self == lArgVec)) );
		}
	}

	NAN_METHOD(ofxNode_ofVec2f::Over)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_;
		const int lArgc = 2;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self / lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
			const auto result = self / lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec2f::Times)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_;
		const int lArgc = 2;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self * lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
			const auto result = self * lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec2f::Minus)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_;
		const int lArgc = 2;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self - lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
			const auto result = self - lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec2f::Plus)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_;
		const int lArgc = 2;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self + lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
			const auto result = self + lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec2f::ToString)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_;
		std::ostringstream out;
		out << self;
		NanReturnValue( NanNew(out.str().c_str()) );
	}

	NAN_METHOD(ofxNode_ofVec2f::Set)
	{
		if (args.Length() == 1 &&
			args[0]->IsObject() &&
			args[0]->ToObject()->Has(NanNew("OFXNODE_TYPE")) &&
			args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() == OFXNODE_TYPES::OFVEC2F)
		{
			ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.set(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_);
		}

		else if (args.Length() == 1 && args[0]->IsNumber())
		{
			ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.set(args[0]->NumberValue());
		}
		else if(args.Length() == 2)
		{
			ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.set(args[0]->NumberValue(), args[1]->NumberValue());
		}
		NanReturnValue( args.This() );
	}


	NAN_METHOD(ofxNode_ofVec2f::Scale)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.scale(args[0]->NumberValue());
		NanReturnValue( args.This() );
	}


	NAN_METHOD(ofxNode_ofVec2f::RotateRad)
	{
		if(!args[1]->IsUndefined())
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[1]->ToObject())->internal_;
			ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.rotateRad(args[0]->NumberValue(), lArgVec);
		}
		else
		{
			ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.rotateRad(args[0]->NumberValue());
		}
		NanReturnValue( args.This() );
	}


	NAN_METHOD(ofxNode_ofVec2f::Rotate)
	{
		if(!args[1]->IsUndefined())
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[1]->ToObject())->internal_;
			ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.rotate(args[0]->NumberValue(), lArgVec);
		}
		else
		{
			ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.rotate(args[0]->NumberValue());
		}
		NanReturnValue( args.This() );
	}


	NAN_METHOD(ofxNode_ofVec2f::Perpendicular)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.perpendicular();
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec2f::Zero)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.zero();
		const int lArgc = 2;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec2f::One)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.one();
		const int lArgc = 2;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec2f::Map)
	{
		const auto lArgVec1 = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
		const auto lArgVec2 = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[1]->ToObject())->internal_;
		const auto lArgVec3 = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[2]->ToObject())->internal_;
		ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.map(lArgVec1, lArgVec2, lArgVec3);
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec2f::Normalize)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.normalize();
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec2f::Middle)
	{
		const auto lArgVec1 = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
		ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.middle(lArgVec1);
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec2f::Limit)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.limit(args[0]->NumberValue());
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec2f::Match)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
		float tolerance = args[1]->IsUndefined() ? 0.0001f : args[1]->NumberValue();
		NanReturnValue( NanNew(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.match(lArgVec, tolerance)) );
	}

	NAN_METHOD(ofxNode_ofVec2f::IsAlignedRad)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
		float tolerance = args[1]->IsUndefined() ? 0.0001f : args[1]->NumberValue();
		NanReturnValue( NanNew(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.isAlignedRad(lArgVec, tolerance)) );
	}

	NAN_METHOD(ofxNode_ofVec2f::IsAligned)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
		float tolerance = args[1]->IsUndefined() ? 0.0001f : args[1]->NumberValue();
		NanReturnValue( NanNew(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.isAligned(lArgVec, tolerance)) );
	}

	NAN_METHOD(ofxNode_ofVec2f::GetPtr)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_;
		
		auto lArrToReturn = NanNew<v8::Array>();
		lArrToReturn->Set(0, NanNew(self.x));
		lArrToReturn->Set(1, NanNew(self.y));

		NanReturnValue( lArrToReturn );
	}

	NAN_METHOD(ofxNode_ofVec2f::GetScaled)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.getScaled(args[0]->NumberValue());
		const int lArgc = 2;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec2f::GetRotatedRad)
	{
		const int lArgc = 2;
		if (!args[1]->IsUndefined())
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[1]->ToObject())->internal_;
			const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.getRotatedRad(args[0]->NumberValue(), lArgVec);
			v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.getRotatedRad(args[0]->NumberValue());
			v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec2f::GetRotated)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.getRotated(args[0]->NumberValue());
		const int lArgc = 2;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec2f::GetPerpendicular)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.getPerpendicular();
		const int lArgc = 2;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec2f::GetMiddle)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.getMiddle(lArgVec);
		const int lArgc = 2;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec2f::GetNormalized)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.getNormalized();
		const int lArgc = 2;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec2f::GetLimited)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.getLimited(args[0]->NumberValue());
		const int lArgc = 2;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec2f::Interpolate)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
		ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.interpolate(lArgVec, args[1]->NumberValue());
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec2f::GetInterpolated)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
		const auto lInterpolated = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.getInterpolated(lArgVec, args[1]->NumberValue());
		const int lArgc = 2;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lInterpolated.x), NanNew(lInterpolated.y)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec2f::Dot)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject());
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.dot(lArgVec->internal_));
	}

	NAN_METHOD(ofxNode_ofVec2f::SquareDistance)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject());
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.squareDistance(lArgVec->internal_));
	}

	NAN_METHOD(ofxNode_ofVec2f::Distance)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject());
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.distance(lArgVec->internal_));
	}

	NAN_GETTER(ofxNode_ofVec2f::GetDIM)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.DIM);
	}

	NAN_GETTER(ofxNode_ofVec2f::GetX)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.x);
	}

	NAN_SETTER(ofxNode_ofVec2f::SetX)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.x = value->NumberValue();
	}

	NAN_GETTER(ofxNode_ofVec2f::GetY)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.y);
	}

	NAN_SETTER(ofxNode_ofVec2f::SetY)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.y = value->NumberValue();
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
				obj = new ofxNode_ofVec2f(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_);
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

			lPoints.push_back(ObjectWrap::Unwrap<ofxNode_ofVec2f>(lVal->ToObject())->internal_);
		}

		ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.average(&lPoints[0], lPoints.size());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofVec2f::Angle)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.angle(lArgVec));
	}

	NAN_METHOD(ofxNode_ofVec2f::AngleRad)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.angleRad(lArgVec));
	}

	NAN_METHOD(ofxNode_ofVec2f::Align)
	{
		const auto lAlignWith = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
		if (args[1]->IsUndefined())
		{
			NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.align(lAlignWith));
		}
		else
		{
			NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.align(lAlignWith, args[1]->NumberValue()));
		}
	}

	NAN_METHOD(ofxNode_ofVec2f::AlignRad)
	{
		const auto lAlignWith = ObjectWrap::Unwrap<ofxNode_ofVec2f>(args[0]->ToObject())->internal_;
		if (args[1]->IsUndefined())
		{
			NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.alignRad(lAlignWith));
		}
		else
		{
			NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.alignRad(lAlignWith, args[1]->NumberValue()));
		}
	}

	NAN_METHOD(ofxNode_ofVec2f::Length)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec2f>(args.This())->internal_.length());
	}

} // !namespace ofxNode
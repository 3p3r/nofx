#include "ofxNode_wrapper_ofVec3f.h"

namespace ofxNode
{
	v8::Persistent<v8::Function> ofxNode_ofVec3f::constructor;

	ofxNode_ofVec3f::ofxNode_ofVec3f(ofVec3f aOfVec3f)
		: internal_(aOfVec3f)
	{}

	ofxNode_ofVec3f::~ofxNode_ofVec3f()
	{}

	void ofxNode_ofVec3f::Init(v8::Handle<v8::Object> exports)
	{
		// Prepare constructor template
		auto tpl = NanNew<v8::FunctionTemplate>(New);
		tpl->SetClassName(NanNew("ofVec3f"));
		tpl->InstanceTemplate()->SetInternalFieldCount(1); //One + number of ofVec3f public methods assigned by NanSetPrototypeTemplate
		
		
		tpl->InstanceTemplate()->SetAccessor(NanNew("DIM")	, ofxNode_ofVec3f::GetDIM, 0, v8::Handle<v8::Value>(), v8::PROHIBITS_OVERWRITING);
		tpl->InstanceTemplate()->SetAccessor(NanNew("x")	, ofxNode_ofVec3f::GetX , ofxNode_ofVec3f::SetX);
		tpl->InstanceTemplate()->SetAccessor(NanNew("y")	, ofxNode_ofVec3f::GetY , ofxNode_ofVec3f::SetY);
		tpl->InstanceTemplate()->SetAccessor(NanNew("z")	, ofxNode_ofVec3f::GetZ , ofxNode_ofVec3f::SetZ);

		// Prototype
		NanSetPrototypeTemplate(tpl, NanNew("align")			, NanNew<v8::FunctionTemplate>(Align)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("alignRad")			, NanNew<v8::FunctionTemplate>(AlignRad)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("angle")			, NanNew<v8::FunctionTemplate>(Angle)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("angleRad")			, NanNew<v8::FunctionTemplate>(AngleRad)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("average")			, NanNew<v8::FunctionTemplate>(Average)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("cross")			, NanNew<v8::FunctionTemplate>(Cross)			, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("distance")			, NanNew<v8::FunctionTemplate>(Distance)		, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("dot")				, NanNew<v8::FunctionTemplate>(Dot)				, v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getCrossed")		, NanNew<v8::FunctionTemplate>(GetCrossed)		, v8::ReadOnly);
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

		NanSetPrototypeTemplate(tpl, NanNew("OFXNODE_TYPE")		, NanNew(OFXNODE_TYPES::OFVEC3F)					, v8::DontEnum);
		NanAssignPersistent(constructor, tpl->GetFunction());
		exports->Set(NanNew<v8::String>("ofVec3f"), tpl->GetFunction());
	}

	NAN_METHOD(ofxNode_ofVec3f::GetCrossed)
	{
		const auto result = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getCrossed(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_);
		const int lArgc = 3;
		v8::Local<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec3f::Cross)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.cross(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofVec3f::Equals)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_;
		if (args[0]->IsArray())
		{
			bool result = true;
			bool ranAtLeastOnce = false;
			const auto lProps = args[0]->ToObject()->GetPropertyNames();
			for (int i = 0; i < lProps->Length(); ++i)
			{
				const auto lKey = lProps->Get(i);
				const auto lVal = args[0]->ToObject()->Get(i);

				if(lVal->ToObject()->Has(NanNew("OFXNODE_TYPE")) && lVal->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() == OFXNODE_TYPES::OFVEC3F)
				{
					ranAtLeastOnce = true;
					result = result && (self == ObjectWrap::Unwrap<ofxNode_ofVec3f>(lVal->ToObject())->internal_);
				}
			}

			NanReturnValue( (NanNew(result && ranAtLeastOnce)) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
			NanReturnValue( (NanNew(self == lArgVec)) );
		}
	}

	NAN_METHOD(ofxNode_ofVec3f::Over)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_;
		const int lArgc = 3;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self / lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
			const auto result = self / lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec3f::Times)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_;
		const int lArgc = 3;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self * lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
			const auto result = self * lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec3f::Minus)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_;
		const int lArgc = 3;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self - lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
			const auto result = self - lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec3f::Plus)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_;
		const int lArgc = 3;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self + lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
			const auto result = self + lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x), NanNew(result.y), NanNew(result.z)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofVec3f::ToString)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_;
		std::ostringstream out;
		out << self;
		NanReturnValue( NanNew(out.str().c_str()) );
	}

	NAN_METHOD(ofxNode_ofVec3f::Set)
	{
		if (args.Length() == 1 &&
			args[0]->IsObject() &&
			args[0]->ToObject()->Has(NanNew("OFXNODE_TYPE")) &&
			args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() == OFXNODE_TYPES::OFVEC3F)
		{
			ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.set(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_);
		}

		else if (args.Length() == 1 && args[0]->IsNumber())
		{
			ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.set(args[0]->NumberValue());
		}
		else if(args.Length() == 3)
		{
			ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.set(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		}
		NanReturnValue( args.This() );
	}


	NAN_METHOD(ofxNode_ofVec3f::Scale)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.scale(args[0]->NumberValue());
		NanReturnValue( args.This() );
	}


	NAN_METHOD(ofxNode_ofVec3f::RotateRad)
	{
		ofVec3f lCalculatedVec;
		if (args.Length() == 2)
		{
			(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.rotateRad(args[0]->NumberValue(),
				ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->internal_));
		}
		else if (args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
		{
			(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.rotateRad(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()));
		}
		else
		{
			(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.rotateRad(args[0]->NumberValue(),
				ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->internal_ ,
				ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[2]->ToObject())->internal_));
		}
		NanReturnValue( args.This() );
	}


	NAN_METHOD(ofxNode_ofVec3f::Rotate)
	{
		ofVec3f lCalculatedVec;
		if (args.Length() == 2)
		{
			(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.rotate(args[0]->NumberValue(),
				ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->internal_));
		}
		else if (args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
		{
			(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.rotate(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()));
		}
		else
		{
			(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.rotate(args[0]->NumberValue(),
				ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->internal_ ,
				ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[2]->ToObject())->internal_));
		}
		NanReturnValue( args.This() );
	}


	NAN_METHOD(ofxNode_ofVec3f::Perpendicular)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.perpendicular(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_);
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec3f::Zero)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.zero();
		const int lArgc = 3;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec3f::One)
	{
		const int lArgc = 3;
		v8::Handle<v8::Value> lArgv[] = {NanNew(1), NanNew(1), NanNew(1)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec3f::Map)
	{
		const auto lArgVec1 = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
		const auto lArgVec2 = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->internal_;
		const auto lArgVec3 = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[2]->ToObject())->internal_;
		const auto lArgVec4 = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[3]->ToObject())->internal_;
		ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.map(lArgVec1, lArgVec2, lArgVec3, lArgVec4);
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec3f::Normalize)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.normalize();
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec3f::Middle)
	{
		const auto lArgVec1 = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
		ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.middle(lArgVec1);
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec3f::Limit)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.limit(args[0]->NumberValue());
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec3f::Match)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
		float tolerance = args[1]->IsUndefined() ? 0.0001f : args[1]->NumberValue();
		NanReturnValue( NanNew(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.match(lArgVec, tolerance)) );
	}

	NAN_METHOD(ofxNode_ofVec3f::IsAlignedRad)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
		float tolerance = args[1]->IsUndefined() ? 0.0001f : args[1]->NumberValue();
		NanReturnValue( NanNew(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.isAlignedRad(lArgVec, tolerance)) );
	}

	NAN_METHOD(ofxNode_ofVec3f::IsAligned)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
		float tolerance = args[1]->IsUndefined() ? 0.0001f : args[1]->NumberValue();
		NanReturnValue( NanNew(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.isAligned(lArgVec, tolerance)) );
	}

	NAN_METHOD(ofxNode_ofVec3f::GetPtr)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_;
		
		auto lArrToReturn = NanNew<v8::Array>();
		lArrToReturn->Set(0, NanNew(self.x));
		lArrToReturn->Set(1, NanNew(self.y));
		lArrToReturn->Set(2, NanNew(self.z));

		NanReturnValue( lArrToReturn );
	}

	NAN_METHOD(ofxNode_ofVec3f::GetScaled)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getScaled(args[0]->NumberValue());
		const int lArgc = 3;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec3f::GetRotatedRad)
	{
		ofVec3f lCalculatedVec;
		if (args.Length() == 2)
		{
			lCalculatedVec.set(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getRotatedRad(args[0]->NumberValue(),
				ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->internal_));
		}
		else if (args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
		{
			lCalculatedVec.set(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getRotatedRad(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()));
		}
		else
		{
			lCalculatedVec.set(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getRotatedRad(args[0]->NumberValue(),
				ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->internal_ ,
				ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[2]->ToObject())->internal_));
		}
		const int lArgc = 3;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec3f::GetRotated)
	{
		ofVec3f lCalculatedVec;
		if (args.Length() == 2)
		{
			lCalculatedVec.set(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getRotated(args[0]->NumberValue(),
				ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->internal_));
		}
		else if (args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
		{
			lCalculatedVec.set(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getRotated(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()));
		}
		else
		{
			lCalculatedVec.set(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getRotated(args[0]->NumberValue(),
				ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->internal_ ,
				ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[2]->ToObject())->internal_));
		}
		const int lArgc = 3;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec3f::GetPerpendicular)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getPerpendicular(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_);
		const int lArgc = 3;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec3f::GetMiddle)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getMiddle(lArgVec);
		const int lArgc = 3;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec3f::GetNormalized)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getNormalized();
		const int lArgc = 3;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec3f::GetLimited)
	{
		const auto lCalculatedVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getLimited(args[0]->NumberValue());
		const int lArgc = 3;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lCalculatedVec.x), NanNew(lCalculatedVec.y), NanNew(lCalculatedVec.z)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec3f::Interpolate)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
		ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.interpolate(lArgVec, args[1]->NumberValue());
		NanReturnValue( args.This() );
	}

	NAN_METHOD(ofxNode_ofVec3f::GetInterpolated)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
		const auto lInterpolated = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.getInterpolated(lArgVec, args[1]->NumberValue());
		const int lArgc = 3;
		v8::Handle<v8::Value> lArgv[] = {NanNew(lInterpolated.x), NanNew(lInterpolated.y), NanNew(lInterpolated.z)};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofVec3f::Dot)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject());
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.dot(lArgVec->internal_));
	}

	NAN_METHOD(ofxNode_ofVec3f::SquareDistance)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject());
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.squareDistance(lArgVec->internal_));
	}

	NAN_METHOD(ofxNode_ofVec3f::Distance)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject());
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.distance(lArgVec->internal_));
	}

	NAN_GETTER(ofxNode_ofVec3f::GetDIM)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.DIM);
	}

	NAN_GETTER(ofxNode_ofVec3f::GetX)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.x);
	}

	NAN_SETTER(ofxNode_ofVec3f::SetX)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.x = value->NumberValue();
	}

	NAN_GETTER(ofxNode_ofVec3f::GetY)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.y);
	}

	NAN_SETTER(ofxNode_ofVec3f::SetY)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.y = value->NumberValue();
	}

	NAN_GETTER(ofxNode_ofVec3f::GetZ)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.z);
	}

	NAN_SETTER(ofxNode_ofVec3f::SetZ)
	{
		ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.z = value->NumberValue();
	}

	NAN_METHOD(ofxNode_ofVec3f::New)
	{
		NanScope();
		if (args.IsConstructCall()) {
			// Invoked as constructor: `new ofVec3f(...)`
			ofxNode_ofVec3f* obj;
			if (args.Length() == 3)
			{
				ofVec3f lPoint(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]));
				obj = new ofxNode_ofVec3f(lPoint);
			}
			else
			{
				//copy constructor like a BOSS!
				obj = new ofxNode_ofVec3f(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_);
			}
			obj->Wrap(args.This());
			NanReturnValue(args.This());
		} else {
			// Invoked as plain function `MyObject(...)`, turn into construct call.
			const int argc = 3;
			v8::Local<v8::Value> argv[argc] = { args[0], args[1], args[2] };
			NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(argc, argv));
		}
	}

	NAN_METHOD(ofxNode_ofVec3f::Average)
	{
		std::vector<ofVec3f> lPoints;

		const auto lPointsProps = args[0]->ToObject()->GetPropertyNames();
		for (int i = 0; i < lPointsProps->Length(); ++i)
		{
			const auto lKey = lPointsProps->Get(i);
			const auto lVal = args[0]->ToObject()->Get(i);

			lPoints.push_back(ObjectWrap::Unwrap<ofxNode_ofVec3f>(lVal->ToObject())->internal_);
		}

		ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.average(&lPoints[0], lPoints.size());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofVec3f::Angle)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.angle(lArgVec));
	}

	NAN_METHOD(ofxNode_ofVec3f::AngleRad)
	{
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.angleRad(lArgVec));
	}

	NAN_METHOD(ofxNode_ofVec3f::Align)
	{
		const auto lAlignWith = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
		if (args[1]->IsUndefined())
		{
			NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.align(lAlignWith));
		}
		else
		{
			NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.align(lAlignWith, args[1]->NumberValue()));
		}
	}

	NAN_METHOD(ofxNode_ofVec3f::AlignRad)
	{
		const auto lAlignWith = ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->internal_;
		if (args[1]->IsUndefined())
		{
			NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.alignRad(lAlignWith));
		}
		else
		{
			NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.alignRad(lAlignWith, args[1]->NumberValue()));
		}
	}

	NAN_METHOD(ofxNode_ofVec3f::Length)
	{
		NanReturnValue(ObjectWrap::Unwrap<ofxNode_ofVec3f>(args.This())->internal_.length());
	}

} // !namespace ofxNode
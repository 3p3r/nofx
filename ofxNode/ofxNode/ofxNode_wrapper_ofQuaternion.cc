#include "ofxNode_wrapper_ofQuaternion.h"
#include "ofxNode_wrapper_ofVec3f.h"
#include "ofxNode_wrapper_ofVec4f.h"

namespace ofxNode
{
	v8::Persistent<v8::Function> ofxNode_ofQuaternion::constructor;

	ofxNode_ofQuaternion::ofxNode_ofQuaternion(ofQuaternion aOfQuaternion)
		: internal_(aOfQuaternion)
	{}

	ofxNode_ofQuaternion::~ofxNode_ofQuaternion()
	{}

	void ofxNode_ofQuaternion::Init(v8::Handle<v8::Object> exports)
	{
		// Prepare constructor template
		auto tpl = NanNew<v8::FunctionTemplate>(New);
		tpl->SetClassName(NanNew("ofQuaternion"));
		
		auto inst = tpl->InstanceTemplate();
		inst->SetInternalFieldCount(1);
		inst->SetAccessor(NanNew("w")	, ofxNode_ofQuaternion::GetW , ofxNode_ofQuaternion::SetW);
		inst->SetAccessor(NanNew("x")	, ofxNode_ofQuaternion::GetX , ofxNode_ofQuaternion::SetX);
		inst->SetAccessor(NanNew("y")	, ofxNode_ofQuaternion::GetY , ofxNode_ofQuaternion::SetY);
		inst->SetAccessor(NanNew("z")	, ofxNode_ofQuaternion::GetZ , ofxNode_ofQuaternion::SetZ);
		inst->SetAccessor(NanNew("_v")	, ofxNode_ofQuaternion::GetV , ofxNode_ofQuaternion::SetV);

		// Prototype
		NanSetPrototypeTemplate(tpl, NanNew("asVec3"), NanNew<v8::FunctionTemplate>(AsVec3), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("asVec4"), NanNew<v8::FunctionTemplate>(AsVec4), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getRotate"), NanNew<v8::FunctionTemplate>(GetRotate), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("conj"), NanNew<v8::FunctionTemplate>(Conj), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getEuler"), NanNew<v8::FunctionTemplate>(GetEuler), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("inverse"), NanNew<v8::FunctionTemplate>(Inverse), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("length"), NanNew<v8::FunctionTemplate>(Length), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("length2"), NanNew<v8::FunctionTemplate>(Length2), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("makeRotate"), NanNew<v8::FunctionTemplate>(MakeRotate), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("normalize"), NanNew<v8::FunctionTemplate>(Normalize), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("set"), NanNew<v8::FunctionTemplate>(Set), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("slerp"), NanNew<v8::FunctionTemplate>(Slerp), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("zeroRotation"), NanNew<v8::FunctionTemplate>(ZeroRotation), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("get"), NanNew<v8::FunctionTemplate>(Get), v8::ReadOnly);

		NanSetPrototypeTemplate(tpl, NanNew("OFXNODE_TYPE"), NanNew(OFXNODE_TYPES::OFQUATERNION), v8::DontEnum);
		NanAssignPersistent(constructor, tpl->GetFunction());
		exports->Set(NanNew<v8::String>("ofQuaternion"), tpl->GetFunction());
	}

	NAN_METHOD(ofxNode_ofQuaternion::Get)
	{
		auto self = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self();
		ofMatrix4x4 toRet;
		self.get(toRet);
		v8::Local<v8::Value> lArgv[] = {
			NanNew(toRet._mat[0][0]),
			NanNew(toRet._mat[0][1]),
			NanNew(toRet._mat[0][2]),
			NanNew(toRet._mat[0][3]),
			NanNew(toRet._mat[1][0]),
			NanNew(toRet._mat[1][1]),
			NanNew(toRet._mat[1][2]),
			NanNew(toRet._mat[1][3]),
			NanNew(toRet._mat[2][0]),
			NanNew(toRet._mat[2][1]),
			NanNew(toRet._mat[2][2]),
			NanNew(toRet._mat[2][3]),
			NanNew(toRet._mat[3][0]),
			NanNew(toRet._mat[3][1]),
			NanNew(toRet._mat[3][2]),
			NanNew(toRet._mat[3][3])
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(16, lArgv));
	}

	NAN_METHOD(ofxNode_ofQuaternion::ZeroRotation)
	{
		NanReturnValue(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().zeroRotation());
	}

	NAN_METHOD(ofxNode_ofQuaternion::Slerp)
	{
		auto self = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self();
		self.slerp(
			V8_ARG_NUMBER(args[0]),
			node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[1]->ToObject())->self(),
			node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[2]->ToObject())->self()
			);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofQuaternion::Set)
	{
		auto self = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self();
		if (args.Length() == 4)
		{
			self.set(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3])
				);
		}
		else if ( args.Length() == 1 && (args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC4F))
		{
			self.set(node::ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->self());
		}
		else
		{
			self.set(node::ObjectWrap::Unwrap<ofxNode_ofMatrix4x4>(args[0]->ToObject())->self());
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofQuaternion::Normalize)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().normalize();
		NanReturnValue(args.This());
	}

	NAN_GETTER(ofxNode_ofQuaternion::GetV) {
		NanScope();
		const ofVec4f lAsVec4 = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self()._v;
		v8::Local<v8::Value> lArgv[] = {NanNew(lAsVec4.x), NanNew(lAsVec4.y), NanNew(lAsVec4.z), NanNew(lAsVec4.w)};
		NanReturnValue(NanNew(ofxNode_ofVec4f::factory())->CallAsConstructor(4, lArgv));
	}
	NAN_GETTER(ofxNode_ofQuaternion::GetW) {NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().w()));}
	NAN_GETTER(ofxNode_ofQuaternion::GetX) {NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().x()));}
	NAN_GETTER(ofxNode_ofQuaternion::GetY) {NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().y()));}
	NAN_GETTER(ofxNode_ofQuaternion::GetZ) {NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().z()));}
	
	NAN_SETTER(ofxNode_ofQuaternion::SetV)
	{
		auto self = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self();
		self._v = node::ObjectWrap::Unwrap<ofxNode_ofVec4f>(value->ToObject())->self();
	}
	NAN_SETTER(ofxNode_ofQuaternion::SetW)
	{
		auto self = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self();
		self._v.w = value->NumberValue();
	}
	NAN_SETTER(ofxNode_ofQuaternion::SetX)
	{
		auto self = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self();
		self._v.x = value->NumberValue();
	}
	NAN_SETTER(ofxNode_ofQuaternion::SetY)
	{
		auto self = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self();
		self._v.y = value->NumberValue();
	}
	NAN_SETTER(ofxNode_ofQuaternion::SetZ)
	{
		auto self = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self();
		self._v.z = value->NumberValue();
	}

	
	
	NAN_METHOD(ofxNode_ofQuaternion::MakeRotate)
	{
		auto self = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This());
		if (args.Length() == 4)
		{
			self->internal_.makeRotate(
				V8_ARG_NUMBER(args[0]),
				V8_ARG_NUMBER(args[1]),
				V8_ARG_NUMBER(args[2]),
				V8_ARG_NUMBER(args[3])
				);
		}
		else if (args.Length() == 2 && args[0]->IsNumber())
		{
			self->internal_.makeRotate(
				V8_ARG_NUMBER(args[0]),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self()
				);
		}
		else if (args.Length() == 2 && args[0]->IsObject())
		{
			self->internal_.makeRotate(
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[0]->ToObject())->self(),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self()
				);
		}
		else
		{
			self->internal_.makeRotate(
				V8_ARG_NUMBER(args[0]),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self(),
				V8_ARG_NUMBER(args[2]),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[3]->ToObject())->self(),
				V8_ARG_NUMBER(args[4]),
				node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[5]->ToObject())->self()
				);
		}
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofQuaternion::Length2)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().length2()));
	}

	NAN_METHOD(ofxNode_ofQuaternion::Length)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().length()));
	}

	NAN_METHOD(ofxNode_ofQuaternion::Inverse)
	{
		NanScope();
		const ofQuaternion lInverse = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().inverse();
		v8::Local<v8::Value> lArgv[] = {NanNew(lInverse.w()), NanNew(lInverse.x()), NanNew(lInverse.y()), NanNew(lInverse.z())};
		NanReturnValue(NanNew(ofxNode_ofQuaternion::factory())->CallAsConstructor(4, lArgv));
	}

	NAN_METHOD(ofxNode_ofQuaternion::Conj)
	{
		NanScope();
		const ofQuaternion lConj = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().conj();
		v8::Local<v8::Value> lArgv[] = {NanNew(lConj.w()), NanNew(lConj.x()), NanNew(lConj.y()), NanNew(lConj.z())};
		NanReturnValue(NanNew(ofxNode_ofQuaternion::factory())->CallAsConstructor(4, lArgv));
	}

	NAN_METHOD(ofxNode_ofQuaternion::AsVec4)
	{
		NanScope();
		const ofVec4f lAsVec4 = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().asVec4();
		v8::Local<v8::Value> lArgv[] = {NanNew(lAsVec4.x), NanNew(lAsVec4.y), NanNew(lAsVec4.z), NanNew(lAsVec4.w)};
		NanReturnValue(NanNew(ofxNode_ofVec4f::factory())->CallAsConstructor(4, lArgv));
	}

	NAN_METHOD(ofxNode_ofQuaternion::Equals)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self();
		if (args[0]->IsArray())
		{
			bool result = true;
			bool ranAtLeastOnce = false;
			const auto lProps = args[0]->ToObject()->GetPropertyNames();
			for (int i = 0; i < lProps->Length(); ++i)
			{
				const auto lKey = lProps->Get(i);
				const auto lVal = args[0]->ToObject()->Get(i);

				if(lVal->ToObject()->Has(NanNew("OFXNODE_TYPE")) && lVal->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() == OFXNODE_TYPES::OFQUATERNION)
				{
					ranAtLeastOnce = true;
					result = result && (self == ObjectWrap::Unwrap<ofxNode_ofQuaternion>(lVal->ToObject())->self());
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

	NAN_METHOD(ofxNode_ofQuaternion::Over)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->internal_;
		const int lArgc = 4;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self / lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result._v.x), NanNew(result._v.y), NanNew(result._v.z), NanNew(result._v.w)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->internal_;
			const auto result = self / lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result._v.x), NanNew(result._v.y), NanNew(result._v.z), NanNew(result._v.w)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofQuaternion::Times)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->internal_;
		const int lArgc = 4;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self * lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x()), NanNew(result.y()), NanNew(result.z()), NanNew(result.w())};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->internal_;
			const auto result = self * lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x()), NanNew(result.y()), NanNew(result.z()), NanNew(result.w())};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofQuaternion::Minus)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->internal_;
		const int lArgc = 4;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->internal_;;
			const auto result = self - lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x()), NanNew(result.y()), NanNew(result.z()), NanNew(result.w())};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->internal_;
			const auto result = self - lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.x()), NanNew(result.y()), NanNew(result.z()), NanNew(result.w())};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofQuaternion::Plus)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->internal_;
		const int lArgc = 4;
		const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->internal_;
		const auto result = self + lArgVec;
		v8::Handle<v8::Value> lArgv[] = {NanNew(result.x()), NanNew(result.y()), NanNew(result.z()), NanNew(result.w())};
		NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
	}

	NAN_METHOD(ofxNode_ofQuaternion::ToString)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->internal_._v;
		std::ostringstream out;
		out << self;
		NanReturnValue( NanNew(out.str().c_str()) );
	}

	NAN_METHOD(ofxNode_ofQuaternion::GetRotate)
	{
		NanScope();
		float angle = 0, x = 0, y = 0, z = 0;
		node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().getRotate(angle, x, y, z);
		v8::Local<v8::Value> lArgv[] = {NanNew(x), NanNew(y), NanNew(z)};
		const auto lVec3 = NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv);
		const auto toRet = NanNew<v8::Object>();
		toRet->Set(NanNew("angle"), NanNew(angle));
		toRet->Set(NanNew("vec"), NanNew(lVec3));
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofQuaternion::GetEuler)
	{
		NanScope();
		const ofVec3f lAsVec3 = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().getEuler();
		v8::Local<v8::Value> lArgv[] = {NanNew(lAsVec3.x), NanNew(lAsVec3.y), NanNew(lAsVec3.z)};
		NanReturnValue(NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv));
	}

	NAN_METHOD(ofxNode_ofQuaternion::AsVec3)
	{
		NanScope();
		const ofVec3f lAsVec3 = node::ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args.This())->self().asVec3();
		v8::Local<v8::Value> lArgv[] = {NanNew(lAsVec3.x), NanNew(lAsVec3.y), NanNew(lAsVec3.z)};
		NanReturnValue(NanNew(ofxNode_ofVec3f::factory())->CallAsConstructor(3, lArgv));
	}

	NAN_METHOD(ofxNode_ofQuaternion::New)
	{
		NanScope();
		if (args.IsConstructCall()) {
			// Invoked as constructor: `new ofVec3f(...)`
			ofxNode_ofQuaternion* obj;
			if (args.Length() == 0)
			{
				obj = new ofxNode_ofQuaternion(ofQuaternion());
			}
			else if (args.Length() == 1 &&
				(args[0]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC4F))
			{
				obj = new ofxNode_ofQuaternion(ofQuaternion(node::ObjectWrap::Unwrap<ofxNode_ofVec4f>(args[0]->ToObject())->self()));
			}
			else if (args.Length() == 2 &&
				(args[1]->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() & OFXNODE_TYPES::OFVEC3F))
			{
				obj = new ofxNode_ofQuaternion(ofQuaternion(args[0]->NumberValue(), node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self()));
			}
			else if (args.Length() == 4)
			{
				obj = new ofxNode_ofQuaternion(ofQuaternion(
					V8_ARG_NUMBER(args[0]),
					V8_ARG_NUMBER(args[1]),
					V8_ARG_NUMBER(args[2]),
					V8_ARG_NUMBER(args[3])
					));
			}
			else if (args.Length() == 6)
			{
				obj = new ofxNode_ofQuaternion(ofQuaternion(
					V8_ARG_NUMBER(args[0]),
					node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[1]->ToObject())->self(),
					V8_ARG_NUMBER(args[2]),
					node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[3]->ToObject())->self(),
					V8_ARG_NUMBER(args[4]),
					node::ObjectWrap::Unwrap<ofxNode_ofVec3f>(args[5]->ToObject())->self()
					));
			}
			else
			{
				//copy constructor like a BOSS!
				obj = new ofxNode_ofQuaternion(ObjectWrap::Unwrap<ofxNode_ofQuaternion>(args[0]->ToObject())->internal_);
			}
			obj->Wrap(args.This());
			NanReturnValue(args.This());
		} else {
			// Invoked as plain function `MyObject(...)`, turn into construct call.
			std::vector<v8::Handle<v8::Value>> lArgvVec;
			for (int i = 0; i < args.Length(); ++i) {lArgvVec.push_back(args[i]);}
			NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(lArgvVec.size(), (lArgvVec.size()==0) ? nullptr : &lArgvVec[0]));
		}
	}
} // !namespace ofxNode
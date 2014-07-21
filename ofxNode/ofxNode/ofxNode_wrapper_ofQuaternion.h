#ifndef _ofxNode_wrapper_ofQuaternion_H_
#define _ofxNode_wrapper_ofQuaternion_H_

#include "globals.h"
#include "ofQuaternion.h"
#include "ofMatrix4x4.h"
#include "ofxNode_wrapper_ofMatrix4x4.h"

namespace ofxNode
{
	class ofxNode_ofQuaternion
		: public node::ObjectWrap
	{
	public:
		static void Init(v8::Handle<v8::Object> exports);
		ofQuaternion& self() {return internal_;}
		static const v8::Persistent<v8::Function>& factory() {return constructor;}
	private:
		// will be used to initialize native OF datatype
		ofQuaternion internal_;

		// C++ constructors
		explicit ofxNode_ofQuaternion(ofQuaternion&);
		~ofxNode_ofQuaternion();

		// JS constructors
		static v8::Persistent<v8::Function> constructor;
		static NAN_METHOD(New);

		// Setters
		static NAN_SETTER(SetW);
		static NAN_SETTER(SetX);
		static NAN_SETTER(SetY);
		static NAN_SETTER(SetZ);
		static NAN_SETTER(SetV);

		// Getters
		static NAN_GETTER(GetW);
		static NAN_GETTER(GetX);
		static NAN_GETTER(GetY);
		static NAN_GETTER(GetZ);
		static NAN_GETTER(GetV);

		//public methods
		static NAN_METHOD(AsVec3);
		static NAN_METHOD(AsVec4);
		static NAN_METHOD(Conj);
		static NAN_METHOD(GetEuler);
		static NAN_METHOD(GetRotate);
		static NAN_METHOD(Inverse);
		static NAN_METHOD(Length);
		static NAN_METHOD(Length2);
		static NAN_METHOD(MakeRotate);
		static NAN_METHOD(Normalize);
		static NAN_METHOD(Set);
		static NAN_METHOD(Slerp);
		static NAN_METHOD(ZeroRotation);
		static NAN_METHOD(Get);

		// Primitives
		static NAN_METHOD(ToString);
		static NAN_METHOD(Plus);
		static NAN_METHOD(Minus);
		static NAN_METHOD(Times);
		static NAN_METHOD(Over);
		static NAN_METHOD(Equals);
	};

} // !namespace ofxNode

#endif // !_ofxNode_wrapper_ofQuaternion_H_
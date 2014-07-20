#ifndef _ofxNode_wrapper_ofVec4f_H_
#define _ofxNode_wrapper_ofVec4f_H_

#include "globals.h"
#include "ofVec4f.h"

namespace ofxNode
{
	class ofxNode_ofVec4f
		: public node::ObjectWrap
	{
	public:
		friend class ofxNode_ofQuaternion;
		static void Init(v8::Handle<v8::Object> exports);
		ofVec4f self() {return internal_;}
		static const v8::Persistent<v8::Function>& factory() {return constructor;}
	private:
		// will be used to initialize native OF datatype
		ofVec4f internal_;

		// C++ constructors
		explicit ofxNode_ofVec4f(ofVec4f);
		~ofxNode_ofVec4f();

		// JS constructors
		static v8::Persistent<v8::Function> constructor;
		static NAN_METHOD(New);

		// setters
		static NAN_SETTER(SetX);
		static NAN_SETTER(SetY);
		static NAN_SETTER(SetZ);
		static NAN_SETTER(SetW);

		// getters
		static NAN_GETTER(GetDIM);
		static NAN_GETTER(GetX);
		static NAN_GETTER(GetY);
		static NAN_GETTER(GetZ);
		static NAN_GETTER(GetW);

		//public methods
		static NAN_METHOD(Average);
		static NAN_METHOD(Distance);
		static NAN_METHOD(Dot);
		static NAN_METHOD(GetInterpolated);
		static NAN_METHOD(GetLimited);
		static NAN_METHOD(GetMiddle);
		static NAN_METHOD(GetNormalized);
		static NAN_METHOD(GetPtr);
		static NAN_METHOD(GetScaled);
		static NAN_METHOD(Interpolate);
		static NAN_METHOD(Length);
		static NAN_METHOD(Limit);
		static NAN_METHOD(Match);
		static NAN_METHOD(Middle);
		static NAN_METHOD(Normalize);
		static NAN_METHOD(One);
		static NAN_METHOD(Scale);
		static NAN_METHOD(Set);
		static NAN_METHOD(SquareDistance);
		static NAN_METHOD(Zero);

		// Primitives
		static NAN_METHOD(ToString);
		static NAN_METHOD(Plus);
		static NAN_METHOD(Minus);
		static NAN_METHOD(Times);
		static NAN_METHOD(Over);
		static NAN_METHOD(Equals);
	};
	
} // !namespace ofxNode

#endif // !_ofxNode_wrapper_ofVec4f_H_
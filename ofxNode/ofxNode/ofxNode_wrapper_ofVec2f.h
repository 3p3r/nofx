#ifndef _ofxNode_wrapper_ofVec2f_H_
#define _ofxNode_wrapper_ofVec2f_H_

#include "globals.h"
#include "ofVec2f.h"

namespace ofxNode
{
	class ofxNode_ofVec2f
		: public node::ObjectWrap
	{
	public:
		static void Init(v8::Handle<v8::Object> exports);
		ofVec2f& self() {return internal_;}
		static const v8::Persistent<v8::Function>& factory() {return constructor;}
	private:
		// will be used to initialize native OF datatype
		ofVec2f internal_;

		// C++ constructors
		explicit ofxNode_ofVec2f(ofVec2f&);
		~ofxNode_ofVec2f();

		// JS constructors
		static v8::Persistent<v8::Function> constructor;
		static NAN_METHOD(New);

		// setters
		static NAN_SETTER(SetX);
		static NAN_SETTER(SetY);

		// getters
		static NAN_GETTER(GetDIM);
		static NAN_GETTER(GetX);
		static NAN_GETTER(GetY);

		//public methods
		static NAN_METHOD(Align);
		static NAN_METHOD(AlignRad);
		static NAN_METHOD(Angle);
		static NAN_METHOD(AngleRad);
		static NAN_METHOD(Average);
		static NAN_METHOD(Distance);
		static NAN_METHOD(Dot);
		static NAN_METHOD(GetInterpolated);
		static NAN_METHOD(GetLimited);
		static NAN_METHOD(GetMiddle);
		static NAN_METHOD(GetNormalized);
		static NAN_METHOD(GetPerpendicular);
		static NAN_METHOD(GetPtr);
		static NAN_METHOD(GetRotated);
		static NAN_METHOD(GetRotatedRad);
		static NAN_METHOD(GetScaled);
		static NAN_METHOD(Interpolate);
		static NAN_METHOD(IsAligned);
		static NAN_METHOD(IsAlignedRad);
		static NAN_METHOD(Length);
		static NAN_METHOD(Limit);
		static NAN_METHOD(Map);
		static NAN_METHOD(Match);
		static NAN_METHOD(Middle);
		static NAN_METHOD(Normalize);
		static NAN_METHOD(One);
		static NAN_METHOD(Perpendicular);
		static NAN_METHOD(Rotate);
		static NAN_METHOD(RotateRad);
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

#endif // !_ofxNode_wrapper_ofVec2f_H_
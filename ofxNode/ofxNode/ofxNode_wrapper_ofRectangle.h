#ifndef _ofxNode_wrapper_ofRectangle_H_
#define _ofxNode_wrapper_ofRectangle_H_

#include "globals.h"
#include "ofTypes.h"
#include "ofRectangle.h"

namespace ofxNode
{
	class ofxNode_ofRectangle
		: public node::ObjectWrap
	{
	public:
		friend class ofxNode_ofRectangle;
		static void Init(v8::Handle<v8::Object> exports);
		ofRectangle& self() {return internal_;}
		static const v8::Persistent<v8::Function>& factory() {return constructor;}
	private:
		// will be used to initialize native OF datatype
		ofRectangle internal_;

		// C++ constructors
		explicit ofxNode_ofRectangle(ofRectangle&);
		~ofxNode_ofRectangle();

		// Mutators
		static NAN_GETTER(GetX);
		static NAN_GETTER(GetY);
		static NAN_GETTER(GetPosition);
		static NAN_GETTER(GetWidth);
		static NAN_GETTER(GetHeight);
		static NAN_SETTER(SetX);
		static NAN_SETTER(SetY);
		static NAN_SETTER(SetPosition);
		static NAN_SETTER(SetWidth);
		static NAN_SETTER(SetHeight);

		// JS constructors
		static v8::Persistent<v8::Function> constructor;
		static NAN_METHOD(New);

		// Methods
		static NAN_METHOD(AlignTo);
		static NAN_METHOD(AlignToHorz);
		static NAN_METHOD(AlignToVert);
		static NAN_METHOD(GetArea);
		static NAN_METHOD(GetAspectRatio);
		static NAN_METHOD(GetBottom);
		static NAN_METHOD(GetBottomLeft);
		static NAN_METHOD(GetBottomRight);
		static NAN_METHOD(GetCenter);
		static NAN_METHOD(GetHeight);
		static NAN_METHOD(GetHorzAnchor);
		static NAN_METHOD(GetIntersection);
		static NAN_METHOD(GetLeft);
		static NAN_METHOD(GetMax);
		static NAN_METHOD(GetMaxX);
		static NAN_METHOD(GetMaxY);
		static NAN_METHOD(GetMin);
		static NAN_METHOD(GetMinX);
		static NAN_METHOD(GetMinY);
		static NAN_METHOD(GetPerimeter);
		static NAN_METHOD(GetPosition);
		static NAN_METHOD(GetPositionRef);
		static NAN_METHOD(GetRight);
		static NAN_METHOD(GetStandardized);
		static NAN_METHOD(GetTop);
		static NAN_METHOD(GetTopLeft);
		static NAN_METHOD(GetTopRight);
		static NAN_METHOD(GetUnion);
		static NAN_METHOD(GetVertAnchor);
		static NAN_METHOD(GetWidth);
		static NAN_METHOD(GetX);
		static NAN_METHOD(GetY);
		static NAN_METHOD(GrowToInclude);
		static NAN_METHOD(Inside);
		static NAN_METHOD(Intersects);
		static NAN_METHOD(IsEmpty);
		static NAN_METHOD(IsStandardized);
		static NAN_METHOD(Scale);
		static NAN_METHOD(ScaleFromCenter);
		static NAN_METHOD(ScaleHeight);
		static NAN_METHOD(ScaleTo);
		static NAN_METHOD(ScaleWidth);
		static NAN_METHOD(Set);
		static NAN_METHOD(SetFromCenter);
		static NAN_METHOD(SetHeight);
		static NAN_METHOD(SetPosition);
		static NAN_METHOD(SetWidth);
		static NAN_METHOD(SetX);
		static NAN_METHOD(SetY);
		static NAN_METHOD(Standardize);
		static NAN_METHOD(Translate);
		static NAN_METHOD(TranslateX);
		static NAN_METHOD(TranslateY);

		// Primitives
		static NAN_METHOD(ToString);
		static NAN_METHOD(Plus);
		static NAN_METHOD(Equals);
	};

} // !namespace ofxNode

#endif // !_ofxNode_wrapper_ofRectangle_H_
#ifndef _ofxNode_wrapper_ofStyle_H_
#define _ofxNode_wrapper_ofStyle_H_

#include "globals.h"
#include "ofColor.h"
#include "ofTypes.h"
#include "ofxNode_wrapper_ofColor.h"

namespace ofxNode
{
	class ofxNode_ofStyle
		: public node::ObjectWrap
	{
	public:
		friend class ofxNode_ofColor;
		static void Init(v8::Handle<v8::Object> exports);
		ofStyle& self() {return internal_;}
		static const v8::Persistent<v8::Function>& factory() {return constructor;}
	private:
		// will be used to initialize native OF datatype
		ofStyle internal_;

		// C++ constructors
		explicit ofxNode_ofStyle(ofStyle&);
		~ofxNode_ofStyle();

		// Mutators
		static NAN_GETTER(GetBFill);
		static NAN_GETTER(GetBgColor);
		static NAN_GETTER(GetBlendingMode);
		static NAN_GETTER(GetCircleResolution);
		static NAN_GETTER(GetColor);
		static NAN_GETTER(GetCurveResolution);
		static NAN_GETTER(GetDrawBitmapMode);
		static NAN_GETTER(GetLineWidth);
		static NAN_GETTER(GetPolyMode);
		static NAN_GETTER(GetRectMode);
		static NAN_GETTER(GetSmoothing);
		static NAN_GETTER(GetSphereResolution);
		static NAN_SETTER(SetBFill);
		static NAN_SETTER(SetBgColor);
		static NAN_SETTER(SetBlendingMode);
		static NAN_SETTER(SetCircleResolution);
		static NAN_SETTER(SetColor);
		static NAN_SETTER(SetCurveResolution);
		static NAN_SETTER(SetDrawBitmapMode);
		static NAN_SETTER(SetLineWidth);
		static NAN_SETTER(SetPolyMode);
		static NAN_SETTER(SetRectMode);
		static NAN_SETTER(SetSmoothing);
		static NAN_SETTER(SetSphereResolution);


		// JS constructors
		static v8::Persistent<v8::Function> constructor;
		static NAN_METHOD(New);
	};

} // !namespace ofxNode

#endif // !_ofxNode_wrapper_ofStyle_H_
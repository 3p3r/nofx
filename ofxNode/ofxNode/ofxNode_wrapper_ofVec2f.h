#ifndef _ofxNode_wrapper_ofVec2f_H_
#define _ofxNode_wrapper_ofVec2f_H_

#include "globals.h"
#include "ofVec2f.h"

namespace ofxNode
{
	class ofxNode_ofVec2f
		: public node::ObjectWrap
		, public ofVec2f
	{
	public:
		static void Init(v8::Handle<v8::Object> exports);
	private:
		typedef ofVec2f inherited;

		explicit ofxNode_ofVec2f(ofVec2f);
		~ofxNode_ofVec2f();

		static v8::Persistent<v8::Function> constructor;
		static NAN_METHOD(New);

		// setters
		static NAN_SETTER(SetX);

		// getters
		static NAN_GETTER(GetX);

		//public methods
		static NAN_METHOD(Align);
		static NAN_METHOD(AlignRad);
		static NAN_METHOD(Angle);
		static NAN_METHOD(AngleRad);
		static NAN_METHOD(Average);
		static NAN_METHOD(Length);
	};
	
} // !namespace ofxNode

#endif // !_ofxNode_wrapper_ofVec2f_H_
#ifndef _ofxNode_wrapper_ofTrueTypeFont_H_
#define _ofxNode_wrapper_ofTrueTypeFont_H_

#include "globals.h"
#include "ofTrueTypeFont.h"

namespace ofxNode
{
	class ofxNode_ofTrueTypeFont
		: public node::ObjectWrap
	{
	public:
		static void Init(v8::Handle<v8::Object> exports);
		ofTrueTypeFont& self() {return internal_;}
		static const v8::Persistent<v8::Function>& factory() {return constructor;}
	private:
		// will be used to initialize native OF datatype
		ofTrueTypeFont internal_;

		// C++ constructors
		explicit ofxNode_ofTrueTypeFont(ofTrueTypeFont&);
		~ofxNode_ofTrueTypeFont();

		// JS constructors
		static v8::Persistent<v8::Function> constructor;
		static NAN_METHOD(New);

		// Methods
		static NAN_METHOD(Bind);
		static NAN_METHOD(DrawString);
		static NAN_METHOD(DrawStringAsShapes);
		static NAN_METHOD(GetCharacterAsPoints);
		static NAN_METHOD(GetEncoding);
		static NAN_METHOD(GetFontTexture);
		static NAN_METHOD(GetLetterSpacing);
		static NAN_METHOD(GetLineHeight);
		static NAN_METHOD(GetNumCharacters);
		static NAN_METHOD(GetSize);
		static NAN_METHOD(GetSpaceSize);
		static NAN_METHOD(GetStringAsPoints);
		static NAN_METHOD(GetStringBoundingBox);
		static NAN_METHOD(GetStringMesh);
		static NAN_METHOD(HasFullCharacterSet);
		static NAN_METHOD(IsAntiAliased);
		static NAN_METHOD(IsLoaded);
		static NAN_METHOD(LoadFont);
		static NAN_METHOD(SetEncoding);
		static NAN_METHOD(SetGlobalDpi);
		static NAN_METHOD(SetLetterSpacing);
		static NAN_METHOD(SetLineHeight);
		static NAN_METHOD(SetSpaceSize);
		static NAN_METHOD(StringHeight);
		static NAN_METHOD(StringWidth);
		static NAN_METHOD(Unbind);
	};

} // !namespace ofxNode

#endif // !_ofxNode_wrapper_ofStyle_H_
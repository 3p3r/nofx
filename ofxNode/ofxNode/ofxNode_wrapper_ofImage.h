#ifndef _ofxNode_wrapper_ofImage_H_
#define _ofxNode_wrapper_ofImage_H_

#include "globals.h"
#include "ofImage.h"

namespace ofxNode
{
	class ofxNode_ofImage
		: public node::ObjectWrap
	{
	public:
		static void Init(v8::Handle<v8::Object> exports);
		ofImage& self() {return internal_;}
		static const v8::Persistent<v8::Function>& factory() {return constructor;}
	private:
		// will be used to initialize native OF datatype
		ofImage internal_;

		// C++ constructors
		explicit ofxNode_ofImage(ofImage&);
		~ofxNode_ofImage();

		// JS constructors
		static v8::Persistent<v8::Function> constructor;
		static NAN_METHOD(New);

		// Mutators
		static NAN_GETTER(GetBpp);
		static NAN_SETTER(SetBpp);
		static NAN_GETTER(GetHeight);
		static NAN_SETTER(SetHeight);
		static NAN_GETTER(GetType);
		static NAN_SETTER(SetType);
		static NAN_GETTER(GetWidth);
		static NAN_SETTER(SetWidth);

		// Methods
		static NAN_METHOD(Allocate);
		static NAN_METHOD(BAllocated);
		static NAN_METHOD(Bind);
		static NAN_METHOD(Clear);
		static NAN_METHOD(Clone);
		static NAN_METHOD(Crop);
		static NAN_METHOD(CropFrom);
		static NAN_METHOD(Draw);
		static NAN_METHOD(DrawSubsection);
		static NAN_METHOD(GetColor);
		static NAN_METHOD(GetHeight);
		static NAN_METHOD(GetPixels);
		static NAN_METHOD(GetPixelsRef);
		static NAN_METHOD(GetTextureReference);
		static NAN_METHOD(GetWidth);
		static NAN_METHOD(GrabScreen);
		static NAN_METHOD(IsAllocated);
		static NAN_METHOD(IsUsingTexture);
		static NAN_METHOD(LoadImage);
		static NAN_METHOD(Mirror);
		static NAN_METHOD(ReloadTexture);
		static NAN_METHOD(ResetAnchor);
		static NAN_METHOD(Resize);
		static NAN_METHOD(Rotate90);
		static NAN_METHOD(SaveImage);
		static NAN_METHOD(SetAnchorPercent);
		static NAN_METHOD(SetAnchorPoint);
		static NAN_METHOD(SetColor);
		static NAN_METHOD(SetCompression);
		static NAN_METHOD(SetFromPixels);
		static NAN_METHOD(SetImageType);
		static NAN_METHOD(SetUseTexture);
		static NAN_METHOD(Unbind);
		static NAN_METHOD(Update);
	};

	NAN_METHOD(ofxNode_ofLoadImage);
	NAN_METHOD(ofxNode_ofSaveImage);

} // !namespace ofxNode

#endif // !_ofxNode_wrapper_ofImage_H_
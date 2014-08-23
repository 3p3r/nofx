#ifndef _NOFX_OF_PIXELS_H_
#define _NOFX_OF_PIXELS_H_

#include "globals.h"
#include <memory>
#include "ofPixels.h"

using namespace v8;

namespace nofx
{
    namespace OfPixels
    {
        class OfPixelsWrap
            : public node::ObjectWrap
        {
        public:
            static void Initialize(v8::Handle<Object> target);
            ofPixels* GetWrapped() const { return internal_.get(); };
            void SetWrapped(ofPixels* n)  { internal_.reset(n); };
            void SetWrapped(ofPixels& n)  { if (!internal_) { internal_.reset(new ofPixels(n)); } };
            static const Persistent<Function>& Factory() { return constructor; }
        private:
            OfPixelsWrap();
            OfPixelsWrap(ofPixels*);
            ~OfPixelsWrap() {};

            static NAN_METHOD(Allocate);
            static NAN_METHOD(Clear);
            static NAN_METHOD(Crop);
            static NAN_METHOD(CropTo);
            static NAN_METHOD(GetBitsPerChannel);
            static NAN_METHOD(GetBitsPerPixel);
            static NAN_METHOD(GetBytesPerChannel);
            static NAN_METHOD(GetBytesPerPixel);
            static NAN_METHOD(GetChannel);
            static NAN_METHOD(GetColor);
            static NAN_METHOD(GetHeight);
            static NAN_METHOD(GetImageType);
            static NAN_METHOD(GetNumChannels);
            static NAN_METHOD(GetPixelIndex);
            static NAN_METHOD(GetPixels);
            static NAN_METHOD(GetWidth);
            static NAN_METHOD(IsAllocated);
            static NAN_METHOD(Mirror);
            static NAN_METHOD(MirrorTo);
            static NAN_METHOD(PasteInto);
            static NAN_METHOD(Resize);
            static NAN_METHOD(ResizeTo);
            static NAN_METHOD(Rotate90);
            static NAN_METHOD(Rotate90To);
            static NAN_METHOD(Set);
            static NAN_METHOD(SetChannel);
            static NAN_METHOD(SetColor);
            static NAN_METHOD(SetFromAlignedPixels);
            static NAN_METHOD(SetFromExternalPixels);
            static NAN_METHOD(SetFromPixels);
            static NAN_METHOD(SetImageType);
            static NAN_METHOD(SetNumChannels);
            static NAN_METHOD(Size);
            static NAN_METHOD(Swap);
            static NAN_METHOD(SwapRgb);
            
            //Js ctor, can be used inside the class itself to construct ofPixels
            static Persistent<Function> constructor;
            static NAN_METHOD(New);
            
            //Pointer to internal object
            std::shared_ptr<ofPixels> internal_;
        }; // !class OfPixelsWrap
    } //!namespace OfPixels
} // !namespace nofx

#endif // !_NOFX_OF_PIXELS_H_
    
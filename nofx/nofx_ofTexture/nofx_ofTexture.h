#ifndef _NOFX_OF_TEXTURE_H_
#define _NOFX_OF_TEXTURE_H_

#include "globals.h"
#include <memory>
#include "ofTexture.h"

using namespace v8;

namespace nofx
{
    namespace OfTexture
    {
        class OfTextureWrap
            : public node::ObjectWrap
        {
        public:
            static void Initialize(v8::Handle<Object> target);
            ofTexture* GetWrapped() const { return internal_.get(); };
            void SetWrapped(ofTexture* n)  { internal_.reset(n); };
            void SetWrapped(ofTexture& n)  { if (!internal_) { internal_.reset(new ofTexture(n)); } };
            static const Persistent<Function>& Factory() { return constructor; }
        private:
            OfTextureWrap();
            OfTextureWrap(ofTexture*);
            ~OfTextureWrap() {};

            static NAN_METHOD(Allocate);
            static NAN_METHOD(BAllocated);
            static NAN_METHOD(Clear);
            static NAN_METHOD(Draw);
            static NAN_METHOD(DrawSubsection);
            static NAN_METHOD(GetCoordFromPercent);
            static NAN_METHOD(GetCoordFromPoint);
            static NAN_METHOD(GetHeight);
            static NAN_METHOD(GetTextureData);
            static NAN_METHOD(GetWidth);
            static NAN_METHOD(IsAllocated);
            static NAN_METHOD(LoadData);
            static NAN_METHOD(LoadScreenData);
            static NAN_METHOD(ReadToPixels);
            static NAN_METHOD(SetAnchorPoint);
            static NAN_METHOD(SetCompression);
            static NAN_METHOD(SetRGToRGBASwizzles);
            static NAN_METHOD(SetTextureMinMagFilter);
            static NAN_METHOD(SetTextureWrap);
            static NAN_METHOD(SetUseExternalTextureID);
            
            //Js ctor, can be used inside the class itself to construct ofTexture
            static Persistent<Function> constructor;
            static NAN_METHOD(New);
            
            //Pointer to internal object
            std::shared_ptr<ofTexture> internal_;
        }; // !class OfTextureWrap
    } //!namespace OfTexture
} // !namespace nofx

#endif // !_NOFX_OF_TEXTURE_H_
    
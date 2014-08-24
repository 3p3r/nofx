#ifndef _NOFX_OF_TEXTURE_DATA_H_
#define _NOFX_OF_TEXTURE_DATA_H_

#include "globals.h"
#include <memory>
#include "ofTexture.h"

using namespace v8;

namespace nofx
{
    namespace OfTextureData
    {
        class OfTextureDataWrap
            : public node::ObjectWrap
        {
        public:
            static void Initialize(v8::Handle<Object> target);
            ofTextureData* GetWrapped() const { return internal_.get(); };
            void SetWrapped(ofTextureData* n)  { internal_.reset(n); };
            void SetWrapped(ofTextureData& n)  { if (!internal_) { internal_.reset(new ofTextureData(n)); } };
            static const Persistent<Function>& Factory() { return constructor; }
        private:
            OfTextureDataWrap();
            OfTextureDataWrap(ofTextureData*);
            ~OfTextureDataWrap() {};
            
            static NAN_GETTER(GetBAllocated);
            static NAN_GETTER(GetBFlipTexture);
            static NAN_GETTER(GetCompressionType);
            static NAN_GETTER(GetGlTypeInternal);
            static NAN_GETTER(GetHeight);
            static NAN_GETTER(GetTex_h);
            static NAN_GETTER(GetTex_t);
            static NAN_GETTER(GetTex_u);
            static NAN_GETTER(GetTex_w);
            static NAN_GETTER(GetTextureID);
            static NAN_GETTER(GetTextureTarget);
            static NAN_GETTER(GetWidth);
            
            static NAN_SETTER(SetBAllocated);
            static NAN_SETTER(SetBFlipTexture);
            static NAN_SETTER(SetBUseExternalTextureID);
            static NAN_SETTER(SetCompressionType);
            static NAN_SETTER(SetGlTypeInternal);
            static NAN_SETTER(SetHeight);
            static NAN_SETTER(SetTex_h);
            static NAN_SETTER(SetTex_t);
            static NAN_SETTER(SetTex_u);
            static NAN_SETTER(SetTex_w);
            static NAN_SETTER(SetTextureID);
            static NAN_SETTER(SetTextureTarget);
            static NAN_SETTER(SetWidth);

            
            //Js ctor, can be used inside the class itself to construct ofTextureData
            static Persistent<Function> constructor;
            static NAN_METHOD(New);
            
            //Pointer to internal object
            std::shared_ptr<ofTextureData> internal_;
        }; // !class OfTextureDataWrap
    } //!namespace OfTextureData
} // !namespace nofx

#endif // !_NOFX_OF_TEXTURE_DATA_H_
    
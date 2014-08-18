#ifndef _NOFX_OF_MATRIX3X3_H_
#define _NOFX_OF_MATRIX3X3_H_

#include "globals.h"
#include <memory>
#include "ofMatrix3x3.h"

using namespace v8;

namespace nofx
{
    namespace OfMatrix3x3
    {
        class OfMatrix3x3Wrap
            : public node::ObjectWrap
        {
        public:
            static void Initialize(v8::Handle<Object> target);
            ofMatrix3x3* GetWrapped() const { return internal_.get(); };
            void SetWrapped(ofMatrix3x3* n)  { internal_.reset(n); };
            void SetWrapped(ofMatrix3x3& n)  { if (!internal_) { internal_.reset(new ofMatrix3x3(n)); } };
            static const Persistent<Function>& Factory() { return constructor; }
        private:
            OfMatrix3x3Wrap();
            OfMatrix3x3Wrap(ofMatrix3x3*);
            ~OfMatrix3x3Wrap() {};

			static NAN_INDEX_GETTER(IndexGetter);
			static NAN_INDEX_SETTER(IndexSetter);
            
            static NAN_GETTER(GetA);
            static NAN_GETTER(GetB);
            static NAN_GETTER(GetC);
            static NAN_GETTER(GetD);
            static NAN_GETTER(GetE);
            static NAN_GETTER(GetF);
            static NAN_GETTER(GetG);
            static NAN_GETTER(GetH);
            static NAN_GETTER(GetI);
            
            static NAN_SETTER(SetA);
            static NAN_SETTER(SetB);
            static NAN_SETTER(SetC);
            static NAN_SETTER(SetD);
            static NAN_SETTER(SetE);
            static NAN_SETTER(SetF);
            static NAN_SETTER(SetG);
            static NAN_SETTER(SetH);
            static NAN_SETTER(SetI);

            static NAN_METHOD(Determinant);
            static NAN_METHOD(EntrywiseTimes);
            static NAN_METHOD(Inverse);
            static NAN_METHOD(Invert);
            static NAN_METHOD(Set);
            static NAN_METHOD(Transpose);
            
            //Js ctor, can be used inside the class itself to construct ofMatrix3x3
            static Persistent<Function> constructor;
            static NAN_METHOD(New);
            
            //Pointer to internal object
            std::shared_ptr<ofMatrix3x3> internal_;
        }; // !class OfMatrix3x3Wrap
    } //!namespace OfMatrix3x3
} // !namespace nofx

#endif // !_NOFX_OF_MATRIX3X3_H_
    
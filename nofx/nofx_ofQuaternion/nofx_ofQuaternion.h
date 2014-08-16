#ifndef _NOFX_OF_QUATERNION_H_
#define _NOFX_OF_QUATERNION_H_

#include "globals.h"
#include <memory>
#include "ofQuaternion.h"

using namespace v8;

namespace nofx
{
    namespace OfQuaternion
    {
        class OfQuaternionWrap
            : public node::ObjectWrap
        {
        public:
            static void Initialize(v8::Handle<Object> target);
            ofQuaternion* GetWrapped() const { return internal_.get(); };
            void SetWrapped(ofQuaternion* n)  { internal_.reset(n); };
			void SetWrapped(ofQuaternion& n)  { if (!internal_) { internal_.reset(new ofQuaternion()); } internal_.get()->set(n.w(), n.x(), n.y(), n.z()); };
			void SetWrapped(const ofQuaternion& n)  { if (!internal_) { internal_.reset(new ofQuaternion()); } internal_.get()->set(n.w(), n.x(), n.y(), n.z()); };
            static const Persistent<Function>& Factory() { return constructor; }
        private:
            OfQuaternionWrap();
            OfQuaternionWrap(ofQuaternion*);
            ~OfQuaternionWrap() {};

            
            static NAN_GETTER(Get_v);
            
            static NAN_SETTER(Set_v);

            static NAN_METHOD(AsVec3);
            static NAN_METHOD(AsVec4);
            static NAN_METHOD(Conj);
            static NAN_METHOD(Get);
            static NAN_METHOD(GetEuler);
            static NAN_METHOD(GetRotate);
            static NAN_METHOD(Inverse);
            static NAN_METHOD(Length);
            static NAN_METHOD(Length2);
            static NAN_METHOD(MakeRotate);
            static NAN_METHOD(Normalize);
            static NAN_METHOD(Set);
            static NAN_METHOD(Slerp);
            static NAN_METHOD(W);
            static NAN_METHOD(X);
            static NAN_METHOD(Y);
            static NAN_METHOD(Z);
            static NAN_METHOD(ZeroRotation);
            
            //Js ctor, can be used inside the class itself to construct ofQuaternion
            static Persistent<Function> constructor;
            static NAN_METHOD(New);
            
            //Pointer to internal object
            std::shared_ptr<ofQuaternion> internal_;
        }; // !class OfQuaternionWrap
    } //!namespace OfQuaternion
} // !namespace nofx

#endif // !_NOFX_OF_QUATERNION_H_
    
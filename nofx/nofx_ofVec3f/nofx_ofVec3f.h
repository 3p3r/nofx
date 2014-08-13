#ifndef _NOFX_OF_VEC3F_H_
#define _NOFX_OF_VEC3F_H_

#include "globals.h"
#include <memory>
#include "ofVec3f.h"

using namespace v8;

namespace nofx
{
    namespace OfVec3f
    {
        class OfVec3fWrap
            : public node::ObjectWrap
        {
        public:
            static void Initialize(v8::Handle<Object> target);
            ofVec3f* GetWrapped() const { return internal_.get(); };
            ofVec3f* GetWrapped() { return internal_.get(); };
            void SetWrapped(ofVec3f* n)  { internal_.reset(n); };
            static const Persistent<Function>& Factory() { return constructor; }
        private:
            OfVec3fWrap();
            OfVec3fWrap(ofVec3f*);
            ~OfVec3fWrap() {};

            
            static NAN_GETTER(GetDIM);
            static NAN_GETTER(GetX);
            static NAN_GETTER(GetY);
            static NAN_GETTER(GetZ);
            
            static NAN_SETTER(SetDIM);
            static NAN_SETTER(SetX);
            static NAN_SETTER(SetY);
            static NAN_SETTER(SetZ);

            static NAN_METHOD(Align);
            static NAN_METHOD(AlignRad);
            static NAN_METHOD(Angle);
            static NAN_METHOD(AngleRad);
            static NAN_METHOD(Average);
            static NAN_METHOD(Cross);
            static NAN_METHOD(Distance);
            static NAN_METHOD(Dot);
            static NAN_METHOD(GetCrossed);
            static NAN_METHOD(GetInterpolated);
            static NAN_METHOD(GetLimited);
            static NAN_METHOD(GetMapped);
            static NAN_METHOD(GetMiddle);
            static NAN_METHOD(GetNormalized);
            static NAN_METHOD(GetPerpendicular);
            static NAN_METHOD(GetPtr);
            static NAN_METHOD(GetRotated);
            static NAN_METHOD(GetRotatedRad);
            static NAN_METHOD(GetScaled);
            static NAN_METHOD(Interpolate);
            static NAN_METHOD(IsAligned);
            static NAN_METHOD(IsAlignedRad);
            static NAN_METHOD(Length);
            static NAN_METHOD(Limit);
            static NAN_METHOD(Map);
            static NAN_METHOD(Match);
            static NAN_METHOD(Middle);
            static NAN_METHOD(Normalize);
            static NAN_METHOD(One);
            static NAN_METHOD(Perpendicular);
            static NAN_METHOD(Rotate);
            static NAN_METHOD(RotateRad);
            static NAN_METHOD(Scale);
            static NAN_METHOD(Set);
            static NAN_METHOD(SquareDistance);
            static NAN_METHOD(Zero);
            static Persistent<Function> constructor;
            static NAN_METHOD(New);
            std::shared_ptr<ofVec3f> internal_;
        }; // !class OfVec3fWrap
    } //!namespace OfVec3f
} // !namespace nofx

#endif // !_NOFX_OF_VEC3F_H_
    
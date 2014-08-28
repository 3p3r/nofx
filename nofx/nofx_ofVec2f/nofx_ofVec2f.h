#ifndef _NOFX_OF_VEC2F_H_
#define _NOFX_OF_VEC2F_H_

#include "globals.h"
#include <memory>
#include "ofVec2f.h"
#include "..\nofx\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
	namespace ClassWrappers
	{
		class OfVec2fWrap
			: public nofx::ObjectWrap < ofVec2f >
		{
			
			DeclareObjectRoutines(Vec2f);

			// Mutators
			static NAN_GETTER(GetDIM);
			static NAN_GETTER(GetX);
			static NAN_GETTER(GetY);

			static NAN_SETTER(SetX);
			static NAN_SETTER(SetY);

			static NAN_INDEX_GETTER(IndexGetter);
			static NAN_INDEX_SETTER(IndexSetter);

			static NAN_METHOD(Align);
			static NAN_METHOD(AlignRad);
			static NAN_METHOD(Angle);
			static NAN_METHOD(AngleRad);
			static NAN_METHOD(Average);
			static NAN_METHOD(Distance);
			static NAN_METHOD(Dot);
			static NAN_METHOD(GetInterpolated);
			static NAN_METHOD(GetLimited);
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

		}; // !class OfVec2fWrap
	} //!namespace ClassWrappers
} // !namespace nofx

#endif // !_NOFX_OF_VEC2F_H_

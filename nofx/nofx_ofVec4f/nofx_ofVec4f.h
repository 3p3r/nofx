#ifndef _NOFX_OF_VEC4F_H_
#define _NOFX_OF_VEC4F_H_

#include "globals.h"
#include <memory>
#include "ofVec4f.h"
#include "..\nofx\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
	namespace OfVec4f
	{
		class OfVec4fWrap
			: public nofx::ObjectWrap<ofVec4f>
		{

			DeclareObjectRoutines(Vec4f);

			static NAN_GETTER(GetDIM);
			static NAN_GETTER(GetW);
			static NAN_GETTER(GetX);
			static NAN_GETTER(GetY);
			static NAN_GETTER(GetZ);

			static NAN_SETTER(SetW);
			static NAN_SETTER(SetX);
			static NAN_SETTER(SetY);
			static NAN_SETTER(SetZ);

			static NAN_INDEX_GETTER(IndexGetter);
			static NAN_INDEX_SETTER(IndexSetter);

			static NAN_METHOD(Average);
			static NAN_METHOD(Distance);
			static NAN_METHOD(DistanceSquared);
			static NAN_METHOD(Dot);
			static NAN_METHOD(GetInterpolated);
			static NAN_METHOD(GetLimited);
			static NAN_METHOD(GetMiddle);
			static NAN_METHOD(GetNormalized);
			static NAN_METHOD(GetPtr);
			static NAN_METHOD(GetScaled);
			static NAN_METHOD(Interpolate);
			static NAN_METHOD(Length);
			static NAN_METHOD(LengthSquared);
			static NAN_METHOD(Limit);
			static NAN_METHOD(Match);
			static NAN_METHOD(Middle);
			static NAN_METHOD(Normalize);
			static NAN_METHOD(One);
			static NAN_METHOD(Scale);
			static NAN_METHOD(Set);
			static NAN_METHOD(SquareDistance);
			static NAN_METHOD(Zero);

		}; // !class OfVec4fWrap
	} //!namespace OfVec4f
} // !namespace nofx

#endif // !_NOFX_OF_VEC4F_H_

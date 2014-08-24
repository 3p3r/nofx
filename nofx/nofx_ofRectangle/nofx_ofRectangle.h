#ifndef _NOFX_OF_RECTANGLE_H_
#define _NOFX_OF_RECTANGLE_H_

#include "globals.h"
#include <memory>
#include "ofRectangle.h"
#include "..\nofx\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
	namespace OfRectangle
	{
		class OfRectangleWrap
			: public nofx::ObjectWrap < ofRectangle >
		{

			DeclareObjectRoutines(Rectangle);

			static NAN_GETTER(GetHeight);
			static NAN_GETTER(GetPosition);
			static NAN_GETTER(GetWidth);
			static NAN_GETTER(GetX);
			static NAN_GETTER(GetY);

			static NAN_SETTER(SetHeight);
			static NAN_SETTER(SetPosition);
			static NAN_SETTER(SetWidth);
			static NAN_SETTER(SetX);
			static NAN_SETTER(SetY);

			static NAN_METHOD(AlignTo);
			static NAN_METHOD(AlignToHorz);
			static NAN_METHOD(AlignToVert);
			static NAN_METHOD(GetArea);
			static NAN_METHOD(GetAspectRatio);
			static NAN_METHOD(GetBottom);
			static NAN_METHOD(GetBottomLeft);
			static NAN_METHOD(GetBottomRight);
			static NAN_METHOD(GetCenter);
			static NAN_METHOD(GetHeight);
			static NAN_METHOD(GetHorzAnchor);
			static NAN_METHOD(GetIntersection);
			static NAN_METHOD(GetLeft);
			static NAN_METHOD(GetMax);
			static NAN_METHOD(GetMaxX);
			static NAN_METHOD(GetMaxY);
			static NAN_METHOD(GetMin);
			static NAN_METHOD(GetMinX);
			static NAN_METHOD(GetMinY);
			static NAN_METHOD(GetPerimeter);
			static NAN_METHOD(GetPosition);
			static NAN_METHOD(GetPositionRef);
			static NAN_METHOD(GetRight);
			static NAN_METHOD(GetStandardized);
			static NAN_METHOD(GetTop);
			static NAN_METHOD(GetTopLeft);
			static NAN_METHOD(GetTopRight);
			static NAN_METHOD(GetUnion);
			static NAN_METHOD(GetVertAnchor);
			static NAN_METHOD(GetWidth);
			static NAN_METHOD(GetX);
			static NAN_METHOD(GetY);
			static NAN_METHOD(GrowToInclude);
			static NAN_METHOD(Inside);
			static NAN_METHOD(Intersects);
			static NAN_METHOD(IsEmpty);
			static NAN_METHOD(IsStandardized);
			static NAN_METHOD(Scale);
			static NAN_METHOD(ScaleFromCenter);
			static NAN_METHOD(ScaleHeight);
			static NAN_METHOD(ScaleTo);
			static NAN_METHOD(ScaleWidth);
			static NAN_METHOD(Set);
			static NAN_METHOD(SetFromCenter);
			static NAN_METHOD(SetHeight);
			static NAN_METHOD(SetPosition);
			static NAN_METHOD(SetWidth);
			static NAN_METHOD(SetX);
			static NAN_METHOD(SetY);
			static NAN_METHOD(Standardize);
			static NAN_METHOD(Translate);
			static NAN_METHOD(TranslateX);
			static NAN_METHOD(TranslateY);

		}; // !class OfRectangleWrap
	} //!namespace OfRectangle
} // !namespace nofx

#endif // !_NOFX_OF_RECTANGLE_H_

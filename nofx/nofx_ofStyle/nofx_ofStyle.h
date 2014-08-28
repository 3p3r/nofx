#ifndef _NOFX_OF_STYLE_H_
#define _NOFX_OF_STYLE_H_

#include "globals.h"
#include <memory>
#include "ofTypes.h"
#include "..\nofx\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
	namespace ClassWrappers
	{
		class OfStyleWrap
			: public nofx::ObjectWrap < ofStyle >
		{

			DeclareObjectRoutines(Style);

			static NAN_GETTER(GetBFill);
			static NAN_GETTER(GetBgColor);
			static NAN_GETTER(GetBlendingMode);
			static NAN_GETTER(GetCircleResolution);
			static NAN_GETTER(GetColor);
			static NAN_GETTER(GetCurveResolution);
			static NAN_GETTER(GetDrawBitmapMode);
			static NAN_GETTER(GetLineWidth);
			static NAN_GETTER(GetPolyMode);
			static NAN_GETTER(GetRectMode);
			static NAN_GETTER(GetSmoothing);
			static NAN_GETTER(GetSphereResolution);

			static NAN_SETTER(SetBFill);
			static NAN_SETTER(SetBgColor);
			static NAN_SETTER(SetBlendingMode);
			static NAN_SETTER(SetCircleResolution);
			static NAN_SETTER(SetColor);
			static NAN_SETTER(SetCurveResolution);
			static NAN_SETTER(SetDrawBitmapMode);
			static NAN_SETTER(SetLineWidth);
			static NAN_SETTER(SetPolyMode);
			static NAN_SETTER(SetRectMode);
			static NAN_SETTER(SetSmoothing);
			static NAN_SETTER(SetSphereResolution);

		}; // !class OfStyleWrap
	} //!namespace ClassWrappers
} // !namespace nofx

#endif // !_NOFX_OF_STYLE_H_

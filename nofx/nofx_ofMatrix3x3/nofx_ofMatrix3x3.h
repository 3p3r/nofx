#ifndef _NOFX_OF_MATRIX3X3_H_
#define _NOFX_OF_MATRIX3X3_H_

#include "globals.h"
#include <memory>
#include "ofMatrix3x3.h"
#include "..\nofx\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
	namespace OfMatrix3x3
	{
		class OfMatrix3x3Wrap
			: public nofx::ObjectWrap < ofMatrix3x3 >
		{

			DeclareObjectRoutines(Matrix3x3);

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

		}; // !class OfMatrix3x3Wrap
	} //!namespace OfMatrix3x3
} // !namespace nofx

#endif // !_NOFX_OF_MATRIX3X3_H_

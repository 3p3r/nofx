#ifndef _NOFX_OF_QUATERNION_H_
#define _NOFX_OF_QUATERNION_H_

#include "globals.h"
#include <memory>
#include "ofQuaternion.h"
#include "..\nofx\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
	namespace OfQuaternion
	{
		class OfQuaternionWrap
			: public nofx::ObjectWrap < ofQuaternion >
		{

			DeclareObjectRoutines(Quaternion);

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

		}; // !class OfQuaternionWrap
	} //!namespace OfQuaternion
} // !namespace nofx

#endif // !_NOFX_OF_QUATERNION_H_

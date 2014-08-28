#ifndef _NOFX_OF_BUFFER_H_
#define _NOFX_OF_BUFFER_H_

#include "globals.h"
#include <memory>
#include "ofFileUtils.h"
#include "..\nofx\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
	namespace ClassWrappers
	{
		class OfBufferWrap
			: public nofx::ObjectWrap < ofBuffer >
		{

			DeclareObjectRoutines(Buffer);

			static NAN_METHOD(Allocate);
			static NAN_METHOD(Append);
			static NAN_METHOD(Clear);
			static NAN_METHOD(GetBinaryBuffer);
			static NAN_METHOD(GetFirstLine);
			static NAN_METHOD(GetNextLine);
			static NAN_METHOD(GetText);
			static NAN_METHOD(IsLastLine);
			static NAN_METHOD(ResetLineReader);
			static NAN_METHOD(Set);
			static NAN_METHOD(Size);
			static NAN_METHOD(WriteTo);

		}; // !class OfBufferWrap
	} //!namespace ClassWrappers
} // !namespace nofx

#endif // !_NOFX_OF_BUFFER_H_

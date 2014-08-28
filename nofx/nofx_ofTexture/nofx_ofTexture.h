#ifndef _NOFX_OF_TEXTURE_H_
#define _NOFX_OF_TEXTURE_H_

#include "globals.h"
#include <memory>
#include "ofTexture.h"
#include "..\nofx\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
	namespace ClassWrappers
	{
		class OfTextureWrap
			: public nofx::ObjectWrap < ofTexture >
		{

			DeclareObjectRoutines(Texture);

			static NAN_METHOD(Allocate);
			static NAN_METHOD(BAllocated);
			static NAN_METHOD(Clear);
			static NAN_METHOD(Draw);
			static NAN_METHOD(DrawSubsection);
			static NAN_METHOD(GetCoordFromPercent);
			static NAN_METHOD(GetCoordFromPoint);
			static NAN_METHOD(GetHeight);
			static NAN_METHOD(GetTextureData);
			static NAN_METHOD(GetWidth);
			static NAN_METHOD(IsAllocated);
			static NAN_METHOD(LoadData);
			static NAN_METHOD(LoadScreenData);
			static NAN_METHOD(ReadToPixels);
			static NAN_METHOD(SetAnchorPoint);
			static NAN_METHOD(SetCompression);
			static NAN_METHOD(SetRGToRGBASwizzles);
			static NAN_METHOD(SetTextureMinMagFilter);
			static NAN_METHOD(SetTextureWrap);
			static NAN_METHOD(SetUseExternalTextureID);

		}; // !class OfTextureWrap
	} //!namespace ClassWrappers
} // !namespace nofx

#endif // !_NOFX_OF_TEXTURE_H_

#ifndef _NOFX_OF_TEXTURE_DATA_H_
#define _NOFX_OF_TEXTURE_DATA_H_

#include "globals.h"
#include <memory>
#include "ofTexture.h"
#include "..\nofx\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
	namespace ClassWrappers
	{
		class OfTextureDataWrap
			: public nofx::ObjectWrap < ofTextureData >
		{

			DeclareObjectRoutines(TextureData);

			static NAN_GETTER(GetBAllocated);
			static NAN_GETTER(GetBFlipTexture);
			static NAN_GETTER(GetCompressionType);
			static NAN_GETTER(GetGlTypeInternal);
			static NAN_GETTER(GetHeight);
			static NAN_GETTER(GetTex_h);
			static NAN_GETTER(GetTex_t);
			static NAN_GETTER(GetTex_u);
			static NAN_GETTER(GetTex_w);
			static NAN_GETTER(GetTextureID);
			static NAN_GETTER(GetTextureTarget);
			static NAN_GETTER(GetWidth);

			static NAN_SETTER(SetBAllocated);
			static NAN_SETTER(SetBFlipTexture);
			static NAN_SETTER(SetBUseExternalTextureID);
			static NAN_SETTER(SetCompressionType);
			static NAN_SETTER(SetGlTypeInternal);
			static NAN_SETTER(SetHeight);
			static NAN_SETTER(SetTex_h);
			static NAN_SETTER(SetTex_t);
			static NAN_SETTER(SetTex_u);
			static NAN_SETTER(SetTex_w);
			static NAN_SETTER(SetTextureID);
			static NAN_SETTER(SetTextureTarget);
			static NAN_SETTER(SetWidth);

		}; // !class OfTextureDataWrap
	} //!namespace ClassWrappers
} // !namespace nofx

#endif // !_NOFX_OF_TEXTURE_DATA_H_

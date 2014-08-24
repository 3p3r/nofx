#include "nofx_ofSetTextureWrap.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofSetTextureWrap)
        {
        
			ofSetTextureWrap(
				args[0]->IsUndefined() ? GL_CLAMP_TO_EDGE : static_cast<GLfloat>(args[0]->NumberValue()),
				args[1]->IsUndefined() ? GL_CLAMP_TO_EDGE : static_cast<GLfloat>(args[1]->NumberValue()));
        
            NanReturnUndefined();
        } // !nofx_ofSetTextureWrap
    } // !namespace OfTexture
} // !namespace nofx
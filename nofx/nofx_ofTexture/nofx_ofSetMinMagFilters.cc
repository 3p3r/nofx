#include "nofx_ofSetMinMagFilters.h"
#include "ofTexture.h"

namespace nofx
{
    namespace OfTexture
    {
        NAN_METHOD(nofx_ofSetMinMagFilters)
        {
        
            ofSetMinMagFilters(
				args[0]->IsUndefined() ? GL_LINEAR : static_cast<GLfloat>(args[0]->NumberValue()),
				args[1]->IsUndefined() ? GL_LINEAR : static_cast<GLfloat>(args[1]->NumberValue()));
        
            NanReturnUndefined();
        } // !nofx_ofSetMinMagFilters
    } // !namespace OfTexture
} // !namespace nofx
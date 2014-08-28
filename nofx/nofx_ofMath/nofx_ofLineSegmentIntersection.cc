#include "nofx_ofLineSegmentIntersection.h"
#include "ofMath.h"
#include "..\nofx_ofVec3f\nofx_ofVec3f.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofLineSegmentIntersection)
        {

			NanReturnValue( ofLineSegmentIntersection(
				*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
				*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[1]->ToObject())->GetWrapped(),
				*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[2]->ToObject())->GetWrapped(),
				*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[3]->ToObject())->GetWrapped(),
				*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[4]->ToObject())->GetWrapped()) );

        } // !nofx_ofLineSegmentIntersection
    } // !namespace Math
} // !namespace nofx
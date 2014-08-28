#include "nofx_ofBezierTangent.h"
#include "ofMath.h"
#include "..\nofx_ofVec3f\nofx_ofVec3f.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofBezierTangent)
        {
			auto JsVec = DepNewInstance(DEP_ofVec3f);

			node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(JsVec->ToObject())->SetWrapped(ofBezierTangent(
				*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
				*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[1]->ToObject())->GetWrapped(),
				*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[2]->ToObject())->GetWrapped(),
				*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[3]->ToObject())->GetWrapped(),
				args[4]->NumberValue()));

			NanReturnValue(JsVec);
        } // !nofx_ofBezierTangent
    } // !namespace Math
} // !namespace nofx
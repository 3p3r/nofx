#include "nofx_ofInsidePoly.h"
#include "ofMath.h"
#include "..\nofx_ofVec3f\nofx_ofVec3f.h"

namespace nofx
{
    namespace Math
    {
        NAN_METHOD(nofx_ofInsidePoly)
        {
			bool result = false;

			auto& points = args[args.Length() - 1]->ToObject();
			auto& props = points->GetPropertyNames();

			if (props->Length() == 0)
			{
				NanReturnUndefined();
			}

			//extracting the array
			std::vector<ofVec3f> points_to_pass;
			points_to_pass.reserve(props->Length());

			for (auto it = 0; it < props->Length(); ++it)
			{
				points_to_pass.push_back(*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(points->Get(props->Get(it))->ToObject())->GetWrapped());
			}

			if (args.Length() == 2)
			{
				result = ofInsidePoly(
					*node::ObjectWrap::Unwrap<nofx::ClassWrappers::OfVec3fWrap>(args[0]->ToObject())->GetWrapped(),
					points_to_pass);
			}
			else
			{
				result = ofInsidePoly(
					args[0]->NumberValue(),
					args[1]->NumberValue(),
					points_to_pass);
			}

			NanReturnValue(result);
        } // !nofx_ofInsidePoly
    } // !namespace Math
} // !namespace nofx
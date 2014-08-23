#include "globals.h"
#include "nofx_ofAngleDifferenceDegrees.h"
#include "nofx_ofAngleDifferenceRadians.h"
#include "nofx_ofBezierPoint.h"
#include "nofx_ofBezierTangent.h"
#include "nofx_ofClamp.h"
#include "nofx_ofCurvePoint.h"
#include "nofx_ofCurveTangent.h"
#include "nofx_ofDegToRad.h"
#include "nofx_ofDist.h"
#include "nofx_ofDistSquared.h"
#include "nofx_ofInRange.h"
#include "nofx_ofInsidePoly.h"
#include "nofx_ofInterpolateCatmullRom.h"
#include "nofx_ofInterpolateCosine.h"
#include "nofx_ofInterpolateCubic.h"
#include "nofx_ofInterpolateHermite.h"
#include "nofx_ofLerp.h"
#include "nofx_ofLerpDegrees.h"
#include "nofx_ofLerpRadians.h"
#include "nofx_ofLineSegmentIntersection.h"
#include "nofx_ofMap.h"
#include "nofx_ofNextPow2.h"
#include "nofx_ofNoise.h"
#include "nofx_ofNormalize.h"
#include "nofx_ofRadToDeg.h"
#include "nofx_ofRandom.h"
#include "nofx_ofRandomHeight.h"
#include "nofx_ofRandomWidth.h"
#include "nofx_ofRandomf.h"
#include "nofx_ofRandomuf.h"
#include "nofx_ofSeedRandom.h"
#include "nofx_ofSign.h"
#include "nofx_ofSignedNoise.h"
#include "nofx_ofWrap.h"
#include "nofx_ofWrapDegrees.h"
#include "nofx_ofWrapRadians.h"

namespace nofx
{
	namespace Math
	{
		using namespace v8;

		void Initialize(v8::Handle<Object> target,
			v8::Handle<Value> unused,
			v8::Handle<Context> context)
		{

			target->Set(NanNew<v8::String>("ofAngleDifferenceDegrees"), NanNew<v8::FunctionTemplate>(nofx_ofAngleDifferenceDegrees)->GetFunction());
			target->Set(NanNew<v8::String>("ofAngleDifferenceRadians"), NanNew<v8::FunctionTemplate>(nofx_ofAngleDifferenceRadians)->GetFunction());
			target->Set(NanNew<v8::String>("ofBezierPoint"), NanNew<v8::FunctionTemplate>(nofx_ofBezierPoint)->GetFunction());
			target->Set(NanNew<v8::String>("ofBezierTangent"), NanNew<v8::FunctionTemplate>(nofx_ofBezierTangent)->GetFunction());
			target->Set(NanNew<v8::String>("ofClamp"), NanNew<v8::FunctionTemplate>(nofx_ofClamp)->GetFunction());
			target->Set(NanNew<v8::String>("ofCurvePoint"), NanNew<v8::FunctionTemplate>(nofx_ofCurvePoint)->GetFunction());
			target->Set(NanNew<v8::String>("ofCurveTangent"), NanNew<v8::FunctionTemplate>(nofx_ofCurveTangent)->GetFunction());
			target->Set(NanNew<v8::String>("ofDegToRad"), NanNew<v8::FunctionTemplate>(nofx_ofDegToRad)->GetFunction());
			target->Set(NanNew<v8::String>("ofDist"), NanNew<v8::FunctionTemplate>(nofx_ofDist)->GetFunction());
			target->Set(NanNew<v8::String>("ofDistSquared"), NanNew<v8::FunctionTemplate>(nofx_ofDistSquared)->GetFunction());
			target->Set(NanNew<v8::String>("ofInRange"), NanNew<v8::FunctionTemplate>(nofx_ofInRange)->GetFunction());
			target->Set(NanNew<v8::String>("ofInsidePoly"), NanNew<v8::FunctionTemplate>(nofx_ofInsidePoly)->GetFunction());
			target->Set(NanNew<v8::String>("ofInterpolateCatmullRom"), NanNew<v8::FunctionTemplate>(nofx_ofInterpolateCatmullRom)->GetFunction());
			target->Set(NanNew<v8::String>("ofInterpolateCosine"), NanNew<v8::FunctionTemplate>(nofx_ofInterpolateCosine)->GetFunction());
			target->Set(NanNew<v8::String>("ofInterpolateCubic"), NanNew<v8::FunctionTemplate>(nofx_ofInterpolateCubic)->GetFunction());
			target->Set(NanNew<v8::String>("ofInterpolateHermite"), NanNew<v8::FunctionTemplate>(nofx_ofInterpolateHermite)->GetFunction());
			target->Set(NanNew<v8::String>("ofLerp"), NanNew<v8::FunctionTemplate>(nofx_ofLerp)->GetFunction());
			target->Set(NanNew<v8::String>("ofLerpDegrees"), NanNew<v8::FunctionTemplate>(nofx_ofLerpDegrees)->GetFunction());
			target->Set(NanNew<v8::String>("ofLerpRadians"), NanNew<v8::FunctionTemplate>(nofx_ofLerpRadians)->GetFunction());
			target->Set(NanNew<v8::String>("ofLineSegmentIntersection"), NanNew<v8::FunctionTemplate>(nofx_ofLineSegmentIntersection)->GetFunction());
			target->Set(NanNew<v8::String>("ofMap"), NanNew<v8::FunctionTemplate>(nofx_ofMap)->GetFunction());
			target->Set(NanNew<v8::String>("ofNextPow2"), NanNew<v8::FunctionTemplate>(nofx_ofNextPow2)->GetFunction());
			target->Set(NanNew<v8::String>("ofNoise"), NanNew<v8::FunctionTemplate>(nofx_ofNoise)->GetFunction());
			target->Set(NanNew<v8::String>("ofNormalize"), NanNew<v8::FunctionTemplate>(nofx_ofNormalize)->GetFunction());
			target->Set(NanNew<v8::String>("ofRadToDeg"), NanNew<v8::FunctionTemplate>(nofx_ofRadToDeg)->GetFunction());
			target->Set(NanNew<v8::String>("ofRandom"), NanNew<v8::FunctionTemplate>(nofx_ofRandom)->GetFunction());
			target->Set(NanNew<v8::String>("ofRandomHeight"), NanNew<v8::FunctionTemplate>(nofx_ofRandomHeight)->GetFunction());
			target->Set(NanNew<v8::String>("ofRandomWidth"), NanNew<v8::FunctionTemplate>(nofx_ofRandomWidth)->GetFunction());
			target->Set(NanNew<v8::String>("ofRandomf"), NanNew<v8::FunctionTemplate>(nofx_ofRandomf)->GetFunction());
			target->Set(NanNew<v8::String>("ofRandomuf"), NanNew<v8::FunctionTemplate>(nofx_ofRandomuf)->GetFunction());
			target->Set(NanNew<v8::String>("ofSeedRandom"), NanNew<v8::FunctionTemplate>(nofx_ofSeedRandom)->GetFunction());
			target->Set(NanNew<v8::String>("ofSign"), NanNew<v8::FunctionTemplate>(nofx_ofSign)->GetFunction());
			target->Set(NanNew<v8::String>("ofSignedNoise"), NanNew<v8::FunctionTemplate>(nofx_ofSignedNoise)->GetFunction());
			target->Set(NanNew<v8::String>("ofWrap"), NanNew<v8::FunctionTemplate>(nofx_ofWrap)->GetFunction());
			target->Set(NanNew<v8::String>("ofWrapDegrees"), NanNew<v8::FunctionTemplate>(nofx_ofWrapDegrees)->GetFunction());
			target->Set(NanNew<v8::String>("ofWrapRadians"), NanNew<v8::FunctionTemplate>(nofx_ofWrapRadians)->GetFunction());

		} //!Initialize
	} //!namespace Math
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofMath, nofx::Math::Initialize)

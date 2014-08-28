#include "globals.h"
#include "nofx_ofTexture.h"
#include "nofx_ofDisableArbTex.h"
#include "nofx_ofDisableNormalizedTexCoords.h"
#include "nofx_ofDisableTextureEdgeHack.h"
#include "nofx_ofEnableArbTex.h"
#include "nofx_ofEnableNormalizedTexCoords.h"
#include "nofx_ofEnableTextureEdgeHack.h"
#include "nofx_ofGetUsingArbTex.h"
#include "nofx_ofGetUsingCustomMinMagFilters.h"
#include "nofx_ofGetUsingCustomTextureWrap.h"
#include "nofx_ofGetUsingNormalizedTexCoords.h"
#include "nofx_ofIsTextureEdgeHackEnabled.h"
#include "nofx_ofRestoreMinMagFilters.h"
#include "nofx_ofRestoreTextureWrap.h"
#include "nofx_ofSetMinMagFilters.h"
#include "nofx_ofSetTextureWrap.h"
#include "nofx_dependencies.h"

namespace nofx
{
    namespace ClassWrappers
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {
            target->Set(NanNew<v8::String>("dependencies"), NanNew<v8::FunctionTemplate>(nofx_dependencies)->GetFunction());
            OfTextureWrap::Initialize(target);

			target->Set(NanNew<v8::String>("ofDisableArbTex"), NanNew<v8::FunctionTemplate>(nofx_ofDisableArbTex)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisableNormalizedTexCoords"), NanNew<v8::FunctionTemplate>(nofx_ofDisableNormalizedTexCoords)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisableTextureEdgeHack"), NanNew<v8::FunctionTemplate>(nofx_ofDisableTextureEdgeHack)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableArbTex"), NanNew<v8::FunctionTemplate>(nofx_ofEnableArbTex)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableNormalizedTexCoords"), NanNew<v8::FunctionTemplate>(nofx_ofEnableNormalizedTexCoords)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableTextureEdgeHack"), NanNew<v8::FunctionTemplate>(nofx_ofEnableTextureEdgeHack)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetUsingArbTex"), NanNew<v8::FunctionTemplate>(nofx_ofGetUsingArbTex)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetUsingCustomMinMagFilters"), NanNew<v8::FunctionTemplate>(nofx_ofGetUsingCustomMinMagFilters)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetUsingCustomTextureWrap"), NanNew<v8::FunctionTemplate>(nofx_ofGetUsingCustomTextureWrap)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetUsingNormalizedTexCoords"), NanNew<v8::FunctionTemplate>(nofx_ofGetUsingNormalizedTexCoords)->GetFunction());
			target->Set(NanNew<v8::String>("ofIsTextureEdgeHackEnabled"), NanNew<v8::FunctionTemplate>(nofx_ofIsTextureEdgeHackEnabled)->GetFunction());
			target->Set(NanNew<v8::String>("ofRestoreMinMagFilters"), NanNew<v8::FunctionTemplate>(nofx_ofRestoreMinMagFilters)->GetFunction());
			target->Set(NanNew<v8::String>("ofRestoreTextureWrap"), NanNew<v8::FunctionTemplate>(nofx_ofRestoreTextureWrap)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetMinMagFilters"), NanNew<v8::FunctionTemplate>(nofx_ofSetMinMagFilters)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetTextureWrap"), NanNew<v8::FunctionTemplate>(nofx_ofSetTextureWrap)->GetFunction());

        } //!Initialize
    } //!namespace ClassWrappers
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofTexture, nofx::ClassWrappers::Initialize)
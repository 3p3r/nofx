#include "ofxNode_ofGetNativeViewport.h"
#include "ofGraphics.h"
#include "ofxNode_wrapper_ofRectangle.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofGetNativeViewport) {
        NanScope();

		const auto lCurrViewport = ofGetNativeViewport();
		v8::Local<v8::Value> lArgv[] = {
			NanNew(lCurrViewport.x),
			NanNew(lCurrViewport.y),
			NanNew(lCurrViewport.width),
			NanNew(lCurrViewport.height)
		};

		NanReturnValue(NanNew(ofxNode_ofRectangle::factory())->CallAsConstructor(4, lArgv));
    } // !{ofxNode_ofGetNativeViewport}
} // !namespace ofxNode
#include "ofxNode_ofBeginSaveScreenAsPDF.h"
#include "ofGraphics.h"
#include "ofTypes.h"
#include "ofxNode_wrapper_ofRectangle.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBeginSaveScreenAsPDF) {
		const auto filename = NanCString(args[0], nullptr);
		bool bMultipage = args[1]->IsUndefined() ? false : args[1]->BooleanValue();
		bool b3D = args[2]->IsUndefined() ? false : args[2]->BooleanValue();
		ofRectangle viewport = args[3]->IsUndefined() ? ofRectangle(0, 0, 0, 0) : node::ObjectWrap::Unwrap<ofxNode_ofRectangle>(args[3]->ToObject())->self();
		ofBeginSaveScreenAsPDF(filename, bMultipage, b3D, viewport);
		NanReturnValue(args.This());
	} // !ofxNode_ofBeginSaveScreenAsPDF
} // !namespace ofxNode
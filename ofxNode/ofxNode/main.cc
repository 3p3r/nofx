#include "globals.h"

// All API ports will go here
// Please keep this convention in mind:
// ALWAYS HAVE THE PRIORITY TO RETURN args.This() from your methods!
// If the original OF API returns a value, return that if it's a void
// always return args.This()
// This is really important because in Javascript
// domain one can do "this dot that dot this" kinda
// routines (aka chaining). Like jQuery.

//Internal methods
#include "ofxNode_draw.h"
#include "ofxNode_setup.h"
#include "ofxNode_update.h"
#include "ofxNode_exit.h"
#include "ofxNode_keyPressed.h"
#include "ofxNode_keyReleased.h"
#include "ofxNode_mouseMoved.h"
#include "ofxNode_mouseDragged.h"
#include "ofxNode_mousePressed.h"
#include "ofxNode_mouseReleased.h"
#include "ofxNode_windowResized.h"
#include "ofxNode_gotMessage.h"
#include "ofxNode_dragEvent.h"

//Classes and data type wrappers
#include "ofxNode_wrapper_ofVec2f.h"
#include "ofxNode_wrapper_ofVec3f.h"
#include "ofxNode_wrapper_ofVec4f.h"

//Global functions
#include "ofxNode_noop.h"
#include "ofxNode_ofRunApp.h"
#include "ofxNode_ofSetupOpenGL.h"
#include "ofxNode_ofCircle.h"
#include "ofxNode_ofFill.h"
#include "ofxNode_ofClear.h"
#include "ofxNode_ofGetElapsedTimeMillis.h"
#include "ofxNode_ofSetColor.h"
#include "ofxNode_ofBackground.h"
#include "ofxNode_ofBackgroundGradient.h"
#include "ofxNode_ofBackgroundHex.h"
#include "ofxNode_ofBeginSaveScreenAsPDF.h"
#include "ofxNode_ofBeginShape.h"
#include "ofxNode_ofEndShape.h"
#include "ofxNode_ofBezier.h"
#include "ofxNode_ofBezierVertex.h"
#include "ofxNode_ofBgColorPtr.h"
#include "ofxNode_ofClearAlpha.h"
#include "ofxNode_ofCurve.h"
#include "ofxNode_ofCurveVertex.h"
#include "ofxNode_ofCurveVertices.h"
#include "ofxNode_ofDisableAlphaBlending.h"
#include "ofxNode_ofDisableAntiAliasing.h"
#include "ofxNode_ofDisableBlendMode.h"
#include "ofxNode_ofDisableDepthTest.h"
#include "ofxNode_ofDisablePointSprites.h"
#include "ofxNode_ofDisableSmoothing.h"
#include "ofxNode_ofDrawBitmapString.h"
#include "ofxNode_ofDrawBitmapStringHighlight.h"
#include "ofxNode_ofEllipse.h"
#include "ofxNode_ofEnableAlphaBlending.h"
#include "ofxNode_ofEnableAntiAliasing.h"
#include "ofxNode_ofEnableBlendMode.h"
#include "ofxNode_ofEnableDepthTest.h"
#include "ofxNode_ofEnablePointSprites.h"
#include "ofxNode_ofEnableSmoothing.h"
#include "ofxNode_ofEndSaveScreenAsPDF.h"
#include "ofxNode_ofEndShape.h"
#include "ofxNode_ofFill.h"
#include "ofxNode_ofGetBackground.h"
#include "ofxNode_ofGetCoordHandedness.h"

// self_ is a reference to the loaded module across all ported API's
v8::Persistent<v8::Object> self_;

namespace ofxNode {
	void Initialize(v8::Handle<v8::Object> target,
		v8::Handle<v8::Value> unused,
		v8::Handle<v8::Context> context) {
			// First let's check if these two elements exist.
			// We absolutely require these two variables.
			ASSERT_TRUE(!target.IsEmpty());
			ASSERT_TRUE(!context.IsEmpty());
			// We also have to make sure self_ is empty by now
			ASSERT_TRUE(self_.IsEmpty());
			// Assigning target (what's being returned by Node's "require") to self_
			// for future reference.
			NanAssignPersistent(self_, target);
			// Checking if it happened successfully
			ASSERT_TRUE(!self_.IsEmpty());
			
			//setting hidden field values. These are implemented as hidden for future security implementations
			auto lNoop = NanNew<v8::FunctionTemplate>(ofxNode_noop)->GetFunction();
			target->SetHiddenValue(NanNew<v8::String>("setup_")			, lNoop);
			target->SetHiddenValue(NanNew<v8::String>("exit_")			, lNoop);
			target->SetHiddenValue(NanNew<v8::String>("update_")		, lNoop);
			target->SetHiddenValue(NanNew<v8::String>("draw_")			, lNoop);
			target->SetHiddenValue(NanNew<v8::String>("keyPressed_")	, lNoop);
			target->SetHiddenValue(NanNew<v8::String>("keyReleased_")	, lNoop);
			target->SetHiddenValue(NanNew<v8::String>("mouseMoved_")	, lNoop);
			target->SetHiddenValue(NanNew<v8::String>("mouseDragged_")	, lNoop);
			target->SetHiddenValue(NanNew<v8::String>("mousePressed_")	, lNoop);
			target->SetHiddenValue(NanNew<v8::String>("mouseReleased_")	, lNoop);
			target->SetHiddenValue(NanNew<v8::String>("windowResized_")	, lNoop);
			target->SetHiddenValue(NanNew<v8::String>("gotMessage_")	, lNoop);
			target->SetHiddenValue(NanNew<v8::String>("dragEvent_")		, lNoop);

			//initializing basic data types
			ofxNode_ofVec2f::Init(target);
			ofxNode_ofVec3f::Init(target);
			ofxNode_ofVec4f::Init(target);
			
			// Assertions are passed, let's initialize the module with assigning its methods
			target->Set(NanNew<v8::String>("draw")			, NanNew<v8::FunctionTemplate>(ofxNode_draw)->GetFunction());
			target->Set(NanNew<v8::String>("setup")			, NanNew<v8::FunctionTemplate>(ofxNode_setup)->GetFunction());
			target->Set(NanNew<v8::String>("exit")			, NanNew<v8::FunctionTemplate>(ofxNode_exit)->GetFunction());
			target->Set(NanNew<v8::String>("update")		, NanNew<v8::FunctionTemplate>(ofxNode_update)->GetFunction());
			target->Set(NanNew<v8::String>("keyPressed")	, NanNew<v8::FunctionTemplate>(ofxNode_keyPressed)->GetFunction());
			target->Set(NanNew<v8::String>("keyReleased")	, NanNew<v8::FunctionTemplate>(ofxNode_keyReleased)->GetFunction());
			target->Set(NanNew<v8::String>("mouseMoved")	, NanNew<v8::FunctionTemplate>(ofxNode_mouseMoved)->GetFunction());
			target->Set(NanNew<v8::String>("mouseDragged")	, NanNew<v8::FunctionTemplate>(ofxNode_mouseDragged)->GetFunction());
			target->Set(NanNew<v8::String>("mousePressed")	, NanNew<v8::FunctionTemplate>(ofxNode_mousePressed)->GetFunction());
			target->Set(NanNew<v8::String>("mouseReleased")	, NanNew<v8::FunctionTemplate>(ofxNode_mouseReleased)->GetFunction());
			target->Set(NanNew<v8::String>("windowResized")	, NanNew<v8::FunctionTemplate>(ofxNode_windowResized)->GetFunction());
			target->Set(NanNew<v8::String>("gotMessage")	, NanNew<v8::FunctionTemplate>(ofxNode_gotMessage)->GetFunction());
			target->Set(NanNew<v8::String>("dragEvent")		, NanNew<v8::FunctionTemplate>(ofxNode_dragEvent)->GetFunction());
			
			target->Set(NanNew<v8::String>("ofSetupOpenGL")					, NanNew<v8::FunctionTemplate>(ofxNode_ofSetupOpenGL)->GetFunction());
			target->Set(NanNew<v8::String>("ofRunApp")						, NanNew<v8::FunctionTemplate>(ofxNode_ofRunApp)->GetFunction());
			target->Set(NanNew<v8::String>("ofCircle")						, NanNew<v8::FunctionTemplate>(ofxNode_ofCircle)->GetFunction());
			target->Set(NanNew<v8::String>("ofFill")						, NanNew<v8::FunctionTemplate>(ofxNode_ofFill)->GetFunction());
			target->Set(NanNew<v8::String>("ofClear")						, NanNew<v8::FunctionTemplate>(ofxNode_ofClear)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetElapsedTimeMillis")		, NanNew<v8::FunctionTemplate>(ofxNode_ofGetElapsedTimeMillis)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetColor")					, NanNew<v8::FunctionTemplate>(ofxNode_ofSetColor)->GetFunction());
			target->Set(NanNew<v8::String>("ofBackground")					, NanNew<v8::FunctionTemplate>(ofxNode_ofBackground)->GetFunction());
			target->Set(NanNew<v8::String>("ofBackgroundGradient")			, NanNew<v8::FunctionTemplate>(ofxNode_ofBackgroundGradient)->GetFunction());
			target->Set(NanNew<v8::String>("ofBackgroundHex")				, NanNew<v8::FunctionTemplate>(ofxNode_ofBackgroundHex)->GetFunction());
			target->Set(NanNew<v8::String>("ofBeginShape")					, NanNew<v8::FunctionTemplate>(ofxNode_ofBeginShape)->GetFunction());
			target->Set(NanNew<v8::String>("ofEndShape")					, NanNew<v8::FunctionTemplate>(ofxNode_ofEndShape)->GetFunction());
			target->Set(NanNew<v8::String>("ofBezier")						, NanNew<v8::FunctionTemplate>(ofxNode_ofBezier)->GetFunction());
			target->Set(NanNew<v8::String>("ofBezierVertex")				, NanNew<v8::FunctionTemplate>(ofxNode_ofBezierVertex)->GetFunction());
			target->Set(NanNew<v8::String>("ofBgColorPtr")					, NanNew<v8::FunctionTemplate>(ofxNode_ofBgColorPtr)->GetFunction());
			target->Set(NanNew<v8::String>("ofBeginSaveScreenAsPDF")		, NanNew<v8::FunctionTemplate>(ofxNode_ofBeginSaveScreenAsPDF)->GetFunction());
			target->Set(NanNew<v8::String>("ofClearAlpha")					, NanNew<v8::FunctionTemplate>(ofxNode_ofClearAlpha)->GetFunction());
			target->Set(NanNew<v8::String>("ofCurve")						, NanNew<v8::FunctionTemplate>(ofxNode_ofCurve)->GetFunction());
			target->Set(NanNew<v8::String>("ofCurveVertex")					, NanNew<v8::FunctionTemplate>(ofxNode_ofCurveVertex)->GetFunction());
			target->Set(NanNew<v8::String>("ofCurveVertices")				, NanNew<v8::FunctionTemplate>(ofxNode_ofCurveVertices)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisableAlphaBlending")		, NanNew<v8::FunctionTemplate>(ofxNode_ofDisableAlphaBlending)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisableAntiAliasing")			, NanNew<v8::FunctionTemplate>(ofxNode_ofDisableAntiAliasing)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisableBlendMode")			, NanNew<v8::FunctionTemplate>(ofxNode_ofDisableBlendMode)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisableDepthTest")			, NanNew<v8::FunctionTemplate>(ofxNode_ofDisableDepthTest)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisablePointSprites")			, NanNew<v8::FunctionTemplate>(ofxNode_ofDisablePointSprites)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisableSmoothing")			, NanNew<v8::FunctionTemplate>(ofxNode_ofDisableSmoothing)->GetFunction());
			target->Set(NanNew<v8::String>("ofDrawBitmapString")			, NanNew<v8::FunctionTemplate>(ofxNode_ofDrawBitmapString)->GetFunction());
			target->Set(NanNew<v8::String>("ofDrawBitmapStringHighlight")	, NanNew<v8::FunctionTemplate>(ofxNode_ofDrawBitmapStringHighlight)->GetFunction());
			target->Set(NanNew<v8::String>("ofEllipse")						, NanNew<v8::FunctionTemplate>(ofxNode_ofEllipse)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableAlphaBlending")			, NanNew<v8::FunctionTemplate>(ofxNode_ofEnableAlphaBlending)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableAntiAliasing")			, NanNew<v8::FunctionTemplate>(ofxNode_ofEnableAntiAliasing)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableBlendMode")				, NanNew<v8::FunctionTemplate>(ofxNode_ofEnableBlendMode)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableDepthTest")				, NanNew<v8::FunctionTemplate>(ofxNode_ofEnableDepthTest)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnablePointSprites")			, NanNew<v8::FunctionTemplate>(ofxNode_ofEnablePointSprites)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableSmoothing")				, NanNew<v8::FunctionTemplate>(ofxNode_ofEnableSmoothing)->GetFunction());
			target->Set(NanNew<v8::String>("ofEndSaveScreenAsPDF")			, NanNew<v8::FunctionTemplate>(ofxNode_ofEndSaveScreenAsPDF)->GetFunction());
			target->Set(NanNew<v8::String>("ofEndShape")					, NanNew<v8::FunctionTemplate>(ofxNode_ofEndShape)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetBackground")				, NanNew<v8::FunctionTemplate>(ofxNode_ofGetBackground)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetCoordHandedness")			, NanNew<v8::FunctionTemplate>(ofxNode_ofGetCoordHandedness)->GetFunction());
	}

}

// We're using Context Aware initializer, for forward compatibility with Node 0.10+
// Although at the time it's not possible to have multiple instacnces of OF
// On the same Node instance due to OF's internals. Maybe this requires a patch to OF
// Will look at this later. TODO(sepehr)
// Consult http://strongloop.com/strongblog/whats-new-node-js-v0-12-multiple-context-execution/
NODE_MODULE_CONTEXT_AWARE(ofxNode, ofxNode::Initialize)
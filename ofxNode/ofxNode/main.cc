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
#include "ofxNode_wrapper_ofColor.h"
#include "ofxNode_wrapper_ofQuaternion.h"
#include "ofxNode_wrapper_ofMatrix4x4.h"
#include "ofxNode_wrapper_ofStyle.h"
#include "ofxNode_wrapper_ofRectangle.h"
#include "ofxNode_wrapper_ofTrueTypeFont.h"
#include "ofxNode_wrapper_ofImage.h"

//Global functions

/************************************************************************/
/* ofGraphics                                                           */
/************************************************************************/
#include "ofxNode_ofBackground.h"
#include "ofxNode_ofBackgroundGradient.h"
#include "ofxNode_ofBackgroundHex.h"
#include "ofxNode_ofBeginSaveScreenAsPDF.h"
#include "ofxNode_ofBeginShape.h"
#include "ofxNode_ofBezier.h"
#include "ofxNode_ofBezierVertex.h"
#include "ofxNode_ofBgColorPtr.h"
#include "ofxNode_ofCircle.h"
#include "ofxNode_ofClear.h"
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
#include "ofxNode_ofGetCurrentMatrix.h"
#include "ofxNode_ofGetCurrentRenderer.h"
#include "ofxNode_ofGetCurrentViewport.h"
#include "ofxNode_ofGetFill.h"
#include "ofxNode_ofGetNativeViewport.h"
#include "ofxNode_ofGetRectMode.h"
#include "ofxNode_ofGetStyle.h"
#include "ofxNode_ofGetViewportHeight.h"
#include "ofxNode_ofGetViewportWidth.h"
#include "ofxNode_ofIsVFlipped.h"
#include "ofxNode_ofLine.h"
#include "ofxNode_ofLoadIdentityMatrix.h"
#include "ofxNode_ofLoadMatrix.h"
#include "ofxNode_ofMultMatrix.h"
#include "ofxNode_ofNextContour.h"
#include "ofxNode_ofNoFill.h"
#include "ofxNode_ofOrientationToDegrees.h"
#include "ofxNode_ofPopMatrix.h"
#include "ofxNode_ofPopStyle.h"
#include "ofxNode_ofPopView.h"
#include "ofxNode_ofPushMatrix.h"
#include "ofxNode_ofPushStyle.h"
#include "ofxNode_ofPushView.h"
#include "ofxNode_ofRect.h"
#include "ofxNode_ofRectRounded.h"
#include "ofxNode_ofRotate.h"
#include "ofxNode_ofRotateX.h"
#include "ofxNode_ofRotateY.h"
#include "ofxNode_ofRotateZ.h"
#include "ofxNode_ofScale.h"
#include "ofxNode_ofSetBackgroundAuto.h"
#include "ofxNode_ofSetBackgroundColor.h"
#include "ofxNode_ofSetBackgroundColorHex.h"
#include "ofxNode_ofSetCircleResolution.h"
#include "ofxNode_ofSetColor.h"
#include "ofxNode_ofSetCoordHandedness.h"
#include "ofxNode_ofSetCurrentRenderer.h"
#include "ofxNode_ofSetCurveResolution.h"
#include "ofxNode_ofSetDepthTest.h"
#include "ofxNode_ofSetDrawBitmapMode.h"
#include "ofxNode_ofSetHexColor.h"
#include "ofxNode_ofSetLineWidth.h"
#include "ofxNode_ofSetMatrixMode.h"
#include "ofxNode_ofSetPolyMode.h"
#include "ofxNode_ofSetRectMode.h"
#include "ofxNode_ofSetStyle.h"
#include "ofxNode_ofSetupScreen.h"
#include "ofxNode_ofSetupScreenOrtho.h"
#include "ofxNode_ofSetupScreenPerspective.h"
#include "ofxNode_ofTranslate.h"
#include "ofxNode_ofTriangle.h"
#include "ofxNode_ofVertex.h"
#include "ofxNode_ofVertices.h"
#include "ofxNode_ofViewport.h"
#include "ofxNode_ofbClearBg.h"

/************************************************************************/
/* ofMath	                                                            */
/************************************************************************/
#include "ofxNode_ofAngleDifferenceDegrees.h"
#include "ofxNode_ofAngleDifferenceRadians.h"
#include "ofxNode_ofBezierPoint.h"
#include "ofxNode_ofBezierTangent.h"
#include "ofxNode_ofClamp.h"
#include "ofxNode_ofCurvePoint.h"
#include "ofxNode_ofCurveTangent.h"
#include "ofxNode_ofDegToRad.h"
#include "ofxNode_ofDist.h"
#include "ofxNode_ofDistSquared.h"
#include "ofxNode_ofInRange.h"
#include "ofxNode_ofInsidePoly.h"
#include "ofxNode_ofInterpolateCatmullRom.h"
#include "ofxNode_ofInterpolateCosine.h"
#include "ofxNode_ofInterpolateCubic.h"
#include "ofxNode_ofInterpolateHermite.h"
#include "ofxNode_ofLerp.h"
#include "ofxNode_ofLerpDegrees.h"
#include "ofxNode_ofLerpRadians.h"
#include "ofxNode_ofLineSegmentIntersection.h"
#include "ofxNode_ofMap.h"
#include "ofxNode_ofNextPow2.h"
#include "ofxNode_ofNoise.h"
#include "ofxNode_ofNormalize.h"
#include "ofxNode_ofRadToDeg.h"
#include "ofxNode_ofRandom.h"
#include "ofxNode_ofRandomHeight.h"
#include "ofxNode_ofRandomWidth.h"
#include "ofxNode_ofRandomf.h"
#include "ofxNode_ofRandomuf.h"
#include "ofxNode_ofSeedRandom.h"
#include "ofxNode_ofSign.h"
#include "ofxNode_ofSignedNoise.h"
#include "ofxNode_ofWrap.h"
#include "ofxNode_ofWrapDegrees.h"
#include "ofxNode_ofWrapRadians.h"

/************************************************************************/
/* MISC.                                                                */
/************************************************************************/
#include "ofxNode_noop.h"
#include "ofxNode_ofSetupOpenGL.h"
#include "ofxNode_ofRunApp.h"
#include "ofxNode_ofGetElapsedTimeMillis.h"
#include "ofxNode_ofSetFrameRate.h"
#include "ofxNode_ofSetWindowTitle.h"
#include "ofxNode_ofGetWidth.h"
#include "ofxNode_ofGetHeight.h"
#include "ofxNode_ofGetMouseY.h"
#include "ofxNode_ofGetMouseX.h"
#include "ofxNode_ofGetElapsedTimef.h"

// self_ is a reference to the loaded module across all ported API's
v8::Persistent<v8::Object> self_;

namespace ofxNode {
	void Initialize(v8::Handle<v8::Object> target,
		v8::Handle<v8::Value> unused,
		v8::Handle<v8::Context> context) {
			// Assigning target (what's being returned by Node's "require") to self_
			// for future reference.
			NanAssignPersistent(self_, target);
			
			/************************************************************************/
			/* initializing internal functions										*/
			/* These are implemented as hidden for future security implementations	*/
			/************************************************************************/
			const auto lNoop = NanNew<v8::FunctionTemplate>(ofxNode_noop)->GetFunction();
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

			/************************************************************************/
			/* initializing basic data types										*/
			/************************************************************************/
			ofxNode_ofVec2f::Init(target);
			ofxNode_ofVec3f::Init(target);
			ofxNode_ofVec4f::Init(target);
			ofxNode_ofColor::Init(target);
			ofxNode_ofQuaternion::Init(target);
			ofxNode_ofMatrix4x4::Init(target);
			ofxNode_ofStyle::Init(target);
			ofxNode_ofRectangle::Init(target);
			ofxNode_ofTrueTypeFont::Init(target);
			ofxNode_ofImage::Init(target);
			
			/************************************************************************/
			/* initializing internal function overrider API							*/
			/************************************************************************/
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
			
			/************************************************************************/
			/* ofGraphics initialization                                            */
			/************************************************************************/
			target->Set(NanNew<v8::String>("ofBackground"), NanNew<v8::FunctionTemplate>(ofxNode_ofBackground)->GetFunction());
			target->Set(NanNew<v8::String>("ofBackgroundGradient"), NanNew<v8::FunctionTemplate>(ofxNode_ofBackgroundGradient)->GetFunction());
			target->Set(NanNew<v8::String>("ofBackgroundHex"), NanNew<v8::FunctionTemplate>(ofxNode_ofBackgroundHex)->GetFunction());
			target->Set(NanNew<v8::String>("ofBeginSaveScreenAsPDF"), NanNew<v8::FunctionTemplate>(ofxNode_ofBeginSaveScreenAsPDF)->GetFunction());
			target->Set(NanNew<v8::String>("ofBeginShape"), NanNew<v8::FunctionTemplate>(ofxNode_ofBeginShape)->GetFunction());
			target->Set(NanNew<v8::String>("ofBezier"), NanNew<v8::FunctionTemplate>(ofxNode_ofBezier)->GetFunction());
			target->Set(NanNew<v8::String>("ofBezierVertex"), NanNew<v8::FunctionTemplate>(ofxNode_ofBezierVertex)->GetFunction());
			target->Set(NanNew<v8::String>("ofBgColorPtr"), NanNew<v8::FunctionTemplate>(ofxNode_ofBgColorPtr)->GetFunction());
			target->Set(NanNew<v8::String>("ofCircle"), NanNew<v8::FunctionTemplate>(ofxNode_ofCircle)->GetFunction());
			target->Set(NanNew<v8::String>("ofClear"), NanNew<v8::FunctionTemplate>(ofxNode_ofClear)->GetFunction());
			target->Set(NanNew<v8::String>("ofClearAlpha"), NanNew<v8::FunctionTemplate>(ofxNode_ofClearAlpha)->GetFunction());
			target->Set(NanNew<v8::String>("ofCurve"), NanNew<v8::FunctionTemplate>(ofxNode_ofCurve)->GetFunction());
			target->Set(NanNew<v8::String>("ofCurveVertex"), NanNew<v8::FunctionTemplate>(ofxNode_ofCurveVertex)->GetFunction());
			target->Set(NanNew<v8::String>("ofCurveVertices"), NanNew<v8::FunctionTemplate>(ofxNode_ofCurveVertices)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisableAlphaBlending"), NanNew<v8::FunctionTemplate>(ofxNode_ofDisableAlphaBlending)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisableAntiAliasing"), NanNew<v8::FunctionTemplate>(ofxNode_ofDisableAntiAliasing)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisableBlendMode"), NanNew<v8::FunctionTemplate>(ofxNode_ofDisableBlendMode)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisableDepthTest"), NanNew<v8::FunctionTemplate>(ofxNode_ofDisableDepthTest)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisablePointSprites"), NanNew<v8::FunctionTemplate>(ofxNode_ofDisablePointSprites)->GetFunction());
			target->Set(NanNew<v8::String>("ofDisableSmoothing"), NanNew<v8::FunctionTemplate>(ofxNode_ofDisableSmoothing)->GetFunction());
			target->Set(NanNew<v8::String>("ofDrawBitmapString"), NanNew<v8::FunctionTemplate>(ofxNode_ofDrawBitmapString)->GetFunction());
			target->Set(NanNew<v8::String>("ofDrawBitmapStringHighlight"), NanNew<v8::FunctionTemplate>(ofxNode_ofDrawBitmapStringHighlight)->GetFunction());
			target->Set(NanNew<v8::String>("ofEllipse"), NanNew<v8::FunctionTemplate>(ofxNode_ofEllipse)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableAlphaBlending"), NanNew<v8::FunctionTemplate>(ofxNode_ofEnableAlphaBlending)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableAntiAliasing"), NanNew<v8::FunctionTemplate>(ofxNode_ofEnableAntiAliasing)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableBlendMode"), NanNew<v8::FunctionTemplate>(ofxNode_ofEnableBlendMode)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableDepthTest"), NanNew<v8::FunctionTemplate>(ofxNode_ofEnableDepthTest)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnablePointSprites"), NanNew<v8::FunctionTemplate>(ofxNode_ofEnablePointSprites)->GetFunction());
			target->Set(NanNew<v8::String>("ofEnableSmoothing"), NanNew<v8::FunctionTemplate>(ofxNode_ofEnableSmoothing)->GetFunction());
			target->Set(NanNew<v8::String>("ofEndSaveScreenAsPDF"), NanNew<v8::FunctionTemplate>(ofxNode_ofEndSaveScreenAsPDF)->GetFunction());
			target->Set(NanNew<v8::String>("ofEndShape"), NanNew<v8::FunctionTemplate>(ofxNode_ofEndShape)->GetFunction());
			target->Set(NanNew<v8::String>("ofFill"), NanNew<v8::FunctionTemplate>(ofxNode_ofFill)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetBackground"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetBackground)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetCoordHandedness"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetCoordHandedness)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetCurrentMatrix"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetCurrentMatrix)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetCurrentRenderer"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetCurrentRenderer)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetCurrentViewport"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetCurrentViewport)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetFill"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetFill)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetNativeViewport"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetNativeViewport)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetRectMode"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetRectMode)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetStyle"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetStyle)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetViewportHeight"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetViewportHeight)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetViewportWidth"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetViewportWidth)->GetFunction());
			target->Set(NanNew<v8::String>("ofIsVFlipped"), NanNew<v8::FunctionTemplate>(ofxNode_ofIsVFlipped)->GetFunction());
			target->Set(NanNew<v8::String>("ofLine"), NanNew<v8::FunctionTemplate>(ofxNode_ofLine)->GetFunction());
			target->Set(NanNew<v8::String>("ofLoadIdentityMatrix"), NanNew<v8::FunctionTemplate>(ofxNode_ofLoadIdentityMatrix)->GetFunction());
			target->Set(NanNew<v8::String>("ofLoadMatrix"), NanNew<v8::FunctionTemplate>(ofxNode_ofLoadMatrix)->GetFunction());
			target->Set(NanNew<v8::String>("ofMultMatrix"), NanNew<v8::FunctionTemplate>(ofxNode_ofMultMatrix)->GetFunction());
			target->Set(NanNew<v8::String>("ofNextContour"), NanNew<v8::FunctionTemplate>(ofxNode_ofNextContour)->GetFunction());
			target->Set(NanNew<v8::String>("ofNoFill"), NanNew<v8::FunctionTemplate>(ofxNode_ofNoFill)->GetFunction());
			target->Set(NanNew<v8::String>("ofOrientationToDegrees"), NanNew<v8::FunctionTemplate>(ofxNode_ofOrientationToDegrees)->GetFunction());
			target->Set(NanNew<v8::String>("ofPopMatrix"), NanNew<v8::FunctionTemplate>(ofxNode_ofPopMatrix)->GetFunction());
			target->Set(NanNew<v8::String>("ofPopStyle"), NanNew<v8::FunctionTemplate>(ofxNode_ofPopStyle)->GetFunction());
			target->Set(NanNew<v8::String>("ofPopView"), NanNew<v8::FunctionTemplate>(ofxNode_ofPopView)->GetFunction());
			target->Set(NanNew<v8::String>("ofPushMatrix"), NanNew<v8::FunctionTemplate>(ofxNode_ofPushMatrix)->GetFunction());
			target->Set(NanNew<v8::String>("ofPushStyle"), NanNew<v8::FunctionTemplate>(ofxNode_ofPushStyle)->GetFunction());
			target->Set(NanNew<v8::String>("ofPushView"), NanNew<v8::FunctionTemplate>(ofxNode_ofPushView)->GetFunction());
			target->Set(NanNew<v8::String>("ofRect"), NanNew<v8::FunctionTemplate>(ofxNode_ofRect)->GetFunction());
			target->Set(NanNew<v8::String>("ofRectRounded"), NanNew<v8::FunctionTemplate>(ofxNode_ofRectRounded)->GetFunction());
			target->Set(NanNew<v8::String>("ofRotate"), NanNew<v8::FunctionTemplate>(ofxNode_ofRotate)->GetFunction());
			target->Set(NanNew<v8::String>("ofRotateX"), NanNew<v8::FunctionTemplate>(ofxNode_ofRotateX)->GetFunction());
			target->Set(NanNew<v8::String>("ofRotateY"), NanNew<v8::FunctionTemplate>(ofxNode_ofRotateY)->GetFunction());
			target->Set(NanNew<v8::String>("ofRotateZ"), NanNew<v8::FunctionTemplate>(ofxNode_ofRotateZ)->GetFunction());
			target->Set(NanNew<v8::String>("ofScale"), NanNew<v8::FunctionTemplate>(ofxNode_ofScale)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetBackgroundAuto"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetBackgroundAuto)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetBackgroundColor"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetBackgroundColor)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetBackgroundColorHex"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetBackgroundColorHex)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetCircleResolution"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetCircleResolution)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetColor"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetColor)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetCoordHandedness"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetCoordHandedness)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetCurrentRenderer"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetCurrentRenderer)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetCurveResolution"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetCurveResolution)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetDepthTest"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetDepthTest)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetDrawBitmapMode"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetDrawBitmapMode)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetHexColor"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetHexColor)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetLineWidth"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetLineWidth)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetMatrixMode"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetMatrixMode)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetPolyMode"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetPolyMode)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetRectMode"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetRectMode)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetStyle"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetStyle)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetupScreen"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetupScreen)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetupScreenOrtho"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetupScreenOrtho)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetupScreenPerspective"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetupScreenPerspective)->GetFunction());
			target->Set(NanNew<v8::String>("ofTranslate"), NanNew<v8::FunctionTemplate>(ofxNode_ofTranslate)->GetFunction());
			target->Set(NanNew<v8::String>("ofTriangle"), NanNew<v8::FunctionTemplate>(ofxNode_ofTriangle)->GetFunction());
			target->Set(NanNew<v8::String>("ofVertex"), NanNew<v8::FunctionTemplate>(ofxNode_ofVertex)->GetFunction());
			target->Set(NanNew<v8::String>("ofVertices"), NanNew<v8::FunctionTemplate>(ofxNode_ofVertices)->GetFunction());
			target->Set(NanNew<v8::String>("ofViewport"), NanNew<v8::FunctionTemplate>(ofxNode_ofViewport)->GetFunction());
			target->Set(NanNew<v8::String>("ofbClearBg"), NanNew<v8::FunctionTemplate>(ofxNode_ofbClearBg)->GetFunction());

			/************************************************************************/
			/* ofMath initialization												*/
			/************************************************************************/
			target->Set(NanNew<v8::String>("ofAngleDifferenceDegrees"), NanNew<v8::FunctionTemplate>(ofxNode_ofAngleDifferenceDegrees)->GetFunction());
			target->Set(NanNew<v8::String>("ofAngleDifferenceRadians"), NanNew<v8::FunctionTemplate>(ofxNode_ofAngleDifferenceRadians)->GetFunction());
			target->Set(NanNew<v8::String>("ofBezierPoint"), NanNew<v8::FunctionTemplate>(ofxNode_ofBezierPoint)->GetFunction());
			target->Set(NanNew<v8::String>("ofBezierTangent"), NanNew<v8::FunctionTemplate>(ofxNode_ofBezierTangent)->GetFunction());
			target->Set(NanNew<v8::String>("ofClamp"), NanNew<v8::FunctionTemplate>(ofxNode_ofClamp)->GetFunction());
			target->Set(NanNew<v8::String>("ofCurvePoint"), NanNew<v8::FunctionTemplate>(ofxNode_ofCurvePoint)->GetFunction());
			target->Set(NanNew<v8::String>("ofCurveTangent"), NanNew<v8::FunctionTemplate>(ofxNode_ofCurveTangent)->GetFunction());
			target->Set(NanNew<v8::String>("ofDegToRad"), NanNew<v8::FunctionTemplate>(ofxNode_ofDegToRad)->GetFunction());
			target->Set(NanNew<v8::String>("ofDist"), NanNew<v8::FunctionTemplate>(ofxNode_ofDist)->GetFunction());
			target->Set(NanNew<v8::String>("ofDistSquared"), NanNew<v8::FunctionTemplate>(ofxNode_ofDistSquared)->GetFunction());
			target->Set(NanNew<v8::String>("ofInRange"), NanNew<v8::FunctionTemplate>(ofxNode_ofInRange)->GetFunction());
			target->Set(NanNew<v8::String>("ofInsidePoly"), NanNew<v8::FunctionTemplate>(ofxNode_ofInsidePoly)->GetFunction());
			target->Set(NanNew<v8::String>("ofInterpolateCatmullRom"), NanNew<v8::FunctionTemplate>(ofxNode_ofInterpolateCatmullRom)->GetFunction());
			target->Set(NanNew<v8::String>("ofInterpolateCosine"), NanNew<v8::FunctionTemplate>(ofxNode_ofInterpolateCosine)->GetFunction());
			target->Set(NanNew<v8::String>("ofInterpolateCubic"), NanNew<v8::FunctionTemplate>(ofxNode_ofInterpolateCubic)->GetFunction());
			target->Set(NanNew<v8::String>("ofInterpolateHermite"), NanNew<v8::FunctionTemplate>(ofxNode_ofInterpolateHermite)->GetFunction());
			target->Set(NanNew<v8::String>("ofLerp"), NanNew<v8::FunctionTemplate>(ofxNode_ofLerp)->GetFunction());
			target->Set(NanNew<v8::String>("ofLerpDegrees"), NanNew<v8::FunctionTemplate>(ofxNode_ofLerpDegrees)->GetFunction());
			target->Set(NanNew<v8::String>("ofLerpRadians"), NanNew<v8::FunctionTemplate>(ofxNode_ofLerpRadians)->GetFunction());
			target->Set(NanNew<v8::String>("ofLineSegmentIntersection"), NanNew<v8::FunctionTemplate>(ofxNode_ofLineSegmentIntersection)->GetFunction());
			target->Set(NanNew<v8::String>("ofMap"), NanNew<v8::FunctionTemplate>(ofxNode_ofMap)->GetFunction());
			target->Set(NanNew<v8::String>("ofNextPow2"), NanNew<v8::FunctionTemplate>(ofxNode_ofNextPow2)->GetFunction());
			target->Set(NanNew<v8::String>("ofNoise"), NanNew<v8::FunctionTemplate>(ofxNode_ofNoise)->GetFunction());
			target->Set(NanNew<v8::String>("ofNormalize"), NanNew<v8::FunctionTemplate>(ofxNode_ofNormalize)->GetFunction());
			target->Set(NanNew<v8::String>("ofRadToDeg"), NanNew<v8::FunctionTemplate>(ofxNode_ofRadToDeg)->GetFunction());
			target->Set(NanNew<v8::String>("ofRandom"), NanNew<v8::FunctionTemplate>(ofxNode_ofRandom)->GetFunction());
			target->Set(NanNew<v8::String>("ofRandomHeight"), NanNew<v8::FunctionTemplate>(ofxNode_ofRandomHeight)->GetFunction());
			target->Set(NanNew<v8::String>("ofRandomWidth"), NanNew<v8::FunctionTemplate>(ofxNode_ofRandomWidth)->GetFunction());
			target->Set(NanNew<v8::String>("ofRandomf"), NanNew<v8::FunctionTemplate>(ofxNode_ofRandomf)->GetFunction());
			target->Set(NanNew<v8::String>("ofRandomuf"), NanNew<v8::FunctionTemplate>(ofxNode_ofRandomuf)->GetFunction());
			target->Set(NanNew<v8::String>("ofSeedRandom"), NanNew<v8::FunctionTemplate>(ofxNode_ofSeedRandom)->GetFunction());
			target->Set(NanNew<v8::String>("ofSign"), NanNew<v8::FunctionTemplate>(ofxNode_ofSign)->GetFunction());
			target->Set(NanNew<v8::String>("ofSignedNoise"), NanNew<v8::FunctionTemplate>(ofxNode_ofSignedNoise)->GetFunction());
			target->Set(NanNew<v8::String>("ofWrap"), NanNew<v8::FunctionTemplate>(ofxNode_ofWrap)->GetFunction());
			target->Set(NanNew<v8::String>("ofWrapDegrees"), NanNew<v8::FunctionTemplate>(ofxNode_ofWrapDegrees)->GetFunction());
			target->Set(NanNew<v8::String>("ofWrapRadians"), NanNew<v8::FunctionTemplate>(ofxNode_ofWrapRadians)->GetFunction());

			/************************************************************************/
			/* MISC.                                                                */
			/************************************************************************/
			target->Set(NanNew<v8::String>("noop"), NanNew<v8::FunctionTemplate>(ofxNode_noop)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetupOpenGL"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetupOpenGL)->GetFunction());
			target->Set(NanNew<v8::String>("ofRunApp"), NanNew<v8::FunctionTemplate>(ofxNode_ofRunApp)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetWindowTitle"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetWindowTitle)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetFrameRate"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetFrameRate)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetElapsedTimeMillis"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetElapsedTimeMillis)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetWidth"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetWidth)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetHeight"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetHeight)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetMouseY"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetMouseY)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetMouseX"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetMouseX)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetElapsedTimef"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetElapsedTimef)->GetFunction());
			target->Set(NanNew<v8::String>("ofLoadImage"), NanNew<v8::FunctionTemplate>(ofxNode_ofLoadImage)->GetFunction());
			target->Set(NanNew<v8::String>("ofSaveImage"), NanNew<v8::FunctionTemplate>(ofxNode_ofSaveImage)->GetFunction());
	}

}

// We're using Context Aware initializer, for forward compatibility with Node 0.10+
// Although at the time it's not possible to have multiple instances of OF
// On the same Node instance due to OF's internals. Maybe this requires a patch to OF
// Will look at this later. TODO(sepehr)
// Consult http://strongloop.com/strongblog/whats-new-node-js-v0-12-multiple-context-execution/
NODE_MODULE_CONTEXT_AWARE(ofxNode, ofxNode::Initialize)
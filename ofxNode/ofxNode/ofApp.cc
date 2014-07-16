#include "nan.h"
#include "v8.h"
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	mModuleObject = NanNew(moduleHandle_);
	if(mModuleObject->Has(NanNew<v8::String>("setup"))) {
		NanMakeCallback(mModuleObject, "setup", 0, nullptr);
	}
}

//--------------------------------------------------------------
void ofApp::exit(){
	if(mModuleObject->Has(NanNew<v8::String>("exit"))) {
		NanMakeCallback(mModuleObject, "exit", 0, nullptr);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	if(mModuleObject->Has(NanNew<v8::String>("update"))) {
		NanMakeCallback(mModuleObject, "update", 0, nullptr);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if(mModuleObject->Has(NanNew<v8::String>("draw"))) {
		NanMakeCallback(mModuleObject, "draw", 0, nullptr);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(mModuleObject->Has(NanNew<v8::String>("keyPressed"))) {
		v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(key)};
		NanMakeCallback(mModuleObject, "keyPressed", 1, argv);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(mModuleObject->Has(NanNew<v8::String>("keyReleased"))) {
		v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(key)};
		NanMakeCallback(mModuleObject, "keyReleased", 1, argv);
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if(mModuleObject->Has(NanNew<v8::String>("mouseMoved"))) {
		v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(x), NanNew<v8::Number>(y)};
		NanMakeCallback(mModuleObject, "mouseMoved", 2, argv);
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if(mModuleObject->Has(NanNew<v8::String>("mouseDragged"))) {
		v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(x), NanNew<v8::Number>(y), NanNew<v8::Number>(button)};
		NanMakeCallback(mModuleObject, "mouseDragged", 3, argv);
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if(mModuleObject->Has(NanNew<v8::String>("mousePressed"))) {
		v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(x), NanNew<v8::Number>(y), NanNew<v8::Number>(button)};
		NanMakeCallback(mModuleObject, "mousePressed", 3, argv);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if(mModuleObject->Has(NanNew<v8::String>("mouseReleased"))) {
		v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(x), NanNew<v8::Number>(y), NanNew<v8::Number>(button)};
		NanMakeCallback(mModuleObject, "mouseReleased", 3, argv);
	}
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if(mModuleObject->Has(NanNew<v8::String>("windowResized"))) {
		v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(w), NanNew<v8::Number>(h)};
		NanMakeCallback(mModuleObject, "windowResized", 2, argv);
	}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if(mModuleObject->Has(NanNew<v8::String>("gotMessage"))) {
		v8::Local<v8::Value> argv[] = {NanNew<v8::String>(msg.message.c_str())};
		NanMakeCallback(mModuleObject, "gotMessage", 1, argv);
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

#include "nan.h"
#include "v8.h"
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::exit(){
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	NanLocker();
	NanScope();
	v8::Handle<v8::Context> ctx = NanGetCurrentContext();
	ctx->Enter();
	v8::Handle<v8::Object> lo = NanNew(moduleHandle_);
	v8::Handle<v8::Value> lVal = lo->Get(NanNew<v8::String>("draw"));
	if (lVal->IsFunction())
	{
		v8::Handle<v8::Function> lFunc = v8::Handle<v8::Function>::Cast(lVal);
		lFunc->Call(lFunc, 0 , NULL);
	} 
	else
	{
		ofLogWarning() << "The draw method cannot be found!";
	}
	ctx->Exit();
	NanUnlocker();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

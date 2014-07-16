#include "nan.h"
#include "v8.h"
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::callHiddenJavascriptFunction_(std::string aName, int aArgc, v8::Local<v8::Value>* aArgv) {
	mModuleObject->GetHiddenValue(NanNew<v8::String>(aName.c_str()))->ToObject()->CallAsFunction(mModuleObject, aArgc, aArgv);
}
void ofApp::callHiddenJavascriptFunction_(std::string aName) {
	mModuleObject->GetHiddenValue(NanNew<v8::String>(aName.c_str()))->ToObject()->CallAsFunction(mModuleObject, 0, nullptr);
}

//--------------------------------------------------------------
void ofApp::setup() {
	mModuleObject = NanNew(moduleHandle_);
	callHiddenJavascriptFunction_("setup_");
}

//--------------------------------------------------------------
void ofApp::exit(){
	callHiddenJavascriptFunction_("exit_");
}

//--------------------------------------------------------------
void ofApp::update() {
	callHiddenJavascriptFunction_("update_");
}

//--------------------------------------------------------------
void ofApp::draw() {
	callHiddenJavascriptFunction_("draw_");
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(key)};
	callHiddenJavascriptFunction_("keyPressed_", 1, argv);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(key)};
	callHiddenJavascriptFunction_("keyReleased_", 1, argv);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(x), NanNew<v8::Number>(y)};
	callHiddenJavascriptFunction_("mouseMoved_", 2, argv);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(x), NanNew<v8::Number>(y), NanNew<v8::Number>(button)};
	callHiddenJavascriptFunction_("mouseDragged_", 3, argv);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(x), NanNew<v8::Number>(y), NanNew<v8::Number>(button)};
	callHiddenJavascriptFunction_("mousePressed_", 3, argv);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(x), NanNew<v8::Number>(y), NanNew<v8::Number>(button)};
	callHiddenJavascriptFunction_("mouseReleased_", 3, argv);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	v8::Local<v8::Value> argv[] = {NanNew<v8::Number>(w), NanNew<v8::Number>(h)};
	callHiddenJavascriptFunction_("windowResized_", 2, argv);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	v8::Local<v8::Value> argv[] = {NanNew<v8::String>(msg.message.c_str())};
	callHiddenJavascriptFunction_("gotMessage_", 1, argv);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	v8::Handle<v8::Array> lFiles = v8::Array::New(v8::Isolate::GetCurrent(), dragInfo.files.size());
	for (int i = 0; i < dragInfo.files.size(); ++i)
	{
		lFiles->Set(i, NanNew<v8::String>(dragInfo.files.at(i).c_str()));
	}

	//TODO(sepehr) we need a nice wrapper for ofPoint class
	v8::Local<v8::Object> lOfPoint = v8::Object::New(v8::Isolate::GetCurrent());
	lOfPoint->Set(NanNew<v8::String>("x"), NanNew<v8::Number>(dragInfo.position.x));
	lOfPoint->Set(NanNew<v8::String>("y"), NanNew<v8::Number>(dragInfo.position.y));
	lOfPoint->Set(NanNew<v8::String>("z"), NanNew<v8::Number>(dragInfo.position.z));

	v8::Local<v8::Object> lDragInfo = v8::Object::New(v8::Isolate::GetCurrent());
	lDragInfo->Set(NanNew<v8::String>("files"), lFiles);
	lDragInfo->Set(NanNew<v8::String>("position"), lOfPoint);

	v8::Local<v8::Value> argv[] = {lDragInfo};
	callHiddenJavascriptFunction_("dragEvent_", 1, argv);
}

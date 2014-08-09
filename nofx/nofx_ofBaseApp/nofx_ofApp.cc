#include "nofx_ofApp.h"
#include "nofx_noop.h"

namespace nofx
{
	OfAppImpl::OfAppImpl()
		: inherited()
		, setupCallback_			(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, updateCallback_			(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, drawCallback_				(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, exitCallback_				(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, keyPressedCallback_		(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, keyReleasedCallback_		(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, mouseMovedCallback_		(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, mouseDraggedCallback_		(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, mousePressedCallback_		(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, mouseReleasedCallback_	(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, windowEntryCallback_		(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, windowResizedCallback_	(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, dragEventCallback_		(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, gotMessageCallback_		(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, messageReceivedCallback_	(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, draggedCallback_			(new NanCallback(NanNew<v8::FunctionTemplate>(nofx_noop)->GetFunction()))
		, isolate(v8::Isolate::New())
	{}
	
	//--------------------------------------------------------------
	OfAppImpl::~OfAppImpl()
	{
		if( setupCallback_ )			{ delete setupCallback_; }
		if( updateCallback_ )			{ delete updateCallback_; }
		if( drawCallback_ )				{ delete drawCallback_; }
		if( exitCallback_ )				{ delete exitCallback_; }
		if( keyPressedCallback_ )		{ delete keyPressedCallback_; }
		if( keyReleasedCallback_ )		{ delete keyReleasedCallback_; }
		if( mouseMovedCallback_ )		{ delete mouseMovedCallback_; }
		if( mouseDraggedCallback_ )		{ delete mouseDraggedCallback_; }
		if( mousePressedCallback_ )		{ delete mousePressedCallback_; }
		if( mouseReleasedCallback_ )	{ delete mouseReleasedCallback_; }
		if( windowEntryCallback_ )		{ delete windowEntryCallback_; }
		if( windowResizedCallback_ )	{ delete windowResizedCallback_; }
		if( dragEventCallback_ )		{ delete dragEventCallback_; }
		if( gotMessageCallback_ )		{ delete gotMessageCallback_; }
		if( messageReceivedCallback_ )	{ delete messageReceivedCallback_; }
		if( draggedCallback_ )			{ delete draggedCallback_; }
	}

	//--------------------------------------------------------------
	void OfAppImpl::setup() {
		setupCallback_->Call(0, nullptr);
	}

	//--------------------------------------------------------------
	void OfAppImpl::exit() {
		isolate->Dispose();
		//exitCallback_->Call(0, nullptr); //? fix crash
	}

	//--------------------------------------------------------------
	void OfAppImpl::update() {
		updateCallback_->Call(0, nullptr);
	}

	//--------------------------------------------------------------
	void OfAppImpl::draw() {
		drawCallback_->Call(0, nullptr);
	}

	//--------------------------------------------------------------
	void OfAppImpl::keyPressed(int key){
		v8::Handle<Value> argv[1] = {NanNew(key)};
		keyPressedCallback_->Call(1, argv);
	}

	//--------------------------------------------------------------
	void OfAppImpl::keyReleased(int key){
		v8::Handle<Value> argv[1] = {NanNew(key)};
		keyReleasedCallback_->Call(1, argv);
	}

	//--------------------------------------------------------------
	void OfAppImpl::mouseMoved(int x, int y ){
		v8::Handle<Value> argv[2] = {NanNew(x), NanNew(y)};
		mouseMovedCallback_->Call(2, argv);
	}

	//--------------------------------------------------------------
	void OfAppImpl::mouseDragged(int x, int y, int button){
		v8::Handle<Value> argv[3] = {NanNew(x), NanNew(y), NanNew(button)};
		mouseDraggedCallback_->Call(3, argv);
	}

	//--------------------------------------------------------------
	void OfAppImpl::mousePressed(int x, int y, int button){
		v8::Handle<Value> argv[3] = {NanNew(x), NanNew(y), NanNew(button)};
		mousePressedCallback_->Call(3, argv);
	}

	//--------------------------------------------------------------
	void OfAppImpl::mouseReleased(int x, int y, int button){
		v8::Handle<Value> argv[3] = {NanNew(x), NanNew(y), NanNew(button)};
		mouseReleasedCallback_->Call(3, argv);
	}

	//--------------------------------------------------------------
	void OfAppImpl::windowResized(int w, int h){
		v8::Handle<Value> argv[2] = {NanNew(w), NanNew(h)};
		windowResizedCallback_->Call(2, argv);
	}

	//--------------------------------------------------------------
	void OfAppImpl::gotMessage(ofMessage msg){
		v8::Handle<Value> argv[1] = {NanNew(msg.message)};
		gotMessageCallback_->Call(1, argv);
	}

	//--------------------------------------------------------------
	void OfAppImpl::windowEntry(int state){
		v8::Handle<Value> argv[1] = {NanNew(state)};
		windowEntryCallback_->Call(1, argv);
	}

	//--------------------------------------------------------------
	void OfAppImpl::messageReceived(ofMessage& message){
		v8::Handle<Value> argv[1] = {NanNew(message.message)};
		messageReceivedCallback_->Call(1, argv);
	}

	//--------------------------------------------------------------
	void OfAppImpl::dragged(ofDragInfo & drag){
		//TODO, after Vec3f
	}

	//--------------------------------------------------------------
	void OfAppImpl::dragEvent(ofDragInfo dragInfo){
		//TODO, after Vec3f
	}

	/************************************************************************/
	/* End if OfAppImpl														*/
	/************************************************************************/

	Persistent<Function> OfAppWrap::constructor;

	OfAppWrap::OfAppWrap()
		: internal_(new OfAppImpl())
	{}
	
	//--------------------------------------------------------------
	OfAppWrap::OfAppWrap(OfAppImpl* aInternal)
		: internal_(aInternal)
	{}

	//--------------------------------------------------------------
	NAN_METHOD(OfAppWrap::New)
	{
		NanScope();
		OfAppWrap* obj;
		if (args.Length() == 0)
		{
			obj = new OfAppWrap();
		}
		else
		{
			//copy constructor
			obj = new OfAppWrap(ObjectWrap::Unwrap<OfAppWrap>(args[0]->ToObject())->GetWrapped());
		}
		obj->Wrap(args.This());
		NanReturnValue(args.This());
	}

	//--------------------------------------------------------------
	void OfAppWrap::Initialize(v8::Handle<Object> exports)
	{
		auto tpl = NanNew<v8::FunctionTemplate>(New);
		tpl->SetClassName(NanNew("ofApp"));
		
		auto inst = tpl->InstanceTemplate();
		inst->SetInternalFieldCount(1);

		inst->SetAccessor(NanNew("mouseX"), GetMouseX);
		inst->SetAccessor(NanNew("mouseY"), GetMouseY);
		inst->SetAccessor(NanNew("setup"), GetSetup, SetSetup);
		inst->SetAccessor(NanNew("update"), GetUpdate, SetUpdate);
		inst->SetAccessor(NanNew("draw"), GetDraw, SetDraw);
		inst->SetAccessor(NanNew("exit"), GetExit, SetExit);
		inst->SetAccessor(NanNew("keyPressed"), GetKeyPressed, SetKeyPressed);
		inst->SetAccessor(NanNew("keyReleased"), GetKeyReleased, SetKeyReleased);
		inst->SetAccessor(NanNew("mouseMoved"), GetMouseMoved, SetMouseMoved);
		inst->SetAccessor(NanNew("mouseDragged"), GetMouseDragged, SetMouseDragged);
		inst->SetAccessor(NanNew("mousePressed"), GetMousePressed, SetMousePressed);
		inst->SetAccessor(NanNew("mouseReleased"), GetMouseReleased, SetMouseReleased);
		inst->SetAccessor(NanNew("windowEntry"), GetWindowEntry, SetWindowEntry);
		inst->SetAccessor(NanNew("windowResized"), GetWindowResized, SetWindowResized);
		inst->SetAccessor(NanNew("dragEvent"), GetDragEvent, SetDragEvent);
		inst->SetAccessor(NanNew("gotMessage"), GetGotMessage, SetGotMessage);
		inst->SetAccessor(NanNew("messageReceived"), GetMessageReceived, SetMessageReceived);
		inst->SetAccessor(NanNew("dragged"), GetDragged, SetDragged);

		
		NanAssignPersistent(constructor, tpl->GetFunction());
		exports->Set(NanNew<String>("ofApp"), tpl->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetMouseX)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(NanNew(self->mouseX));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetMouseY)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(NanNew(self->mouseY));
	}


	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetSetup)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->setupCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetSetup)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->setupCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetUpdate)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->updateCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetUpdate)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->updateCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetDraw)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->drawCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetDraw)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->drawCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetExit)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->exitCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetExit)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->exitCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetKeyPressed)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->keyPressedCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetKeyPressed)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->keyPressedCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetKeyReleased)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->keyReleasedCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetKeyReleased)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->keyReleasedCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetMouseMoved)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->mouseMovedCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetMouseMoved)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->mouseMovedCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetMouseDragged)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->mouseDraggedCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetMouseDragged)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->mouseDraggedCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetMousePressed)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->mousePressedCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetMousePressed)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->mousePressedCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetMouseReleased)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->mouseReleasedCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetMouseReleased)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->mouseReleasedCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetWindowEntry)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->windowEntryCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetWindowEntry)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->windowEntryCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetWindowResized)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->windowResizedCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetWindowResized)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->windowResizedCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetDragEvent)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->dragEventCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetDragEvent)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->dragEventCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetGotMessage)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->gotMessageCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetGotMessage)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->gotMessageCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetMessageReceived)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->messageReceivedCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetMessageReceived)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->messageReceivedCallback_->SetFunction(Local<Function>::Cast(value));
	}

	//--------------------------------------------------------------
	NAN_GETTER(OfAppWrap::GetDragged)
	{
		const auto &self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		NanReturnValue(self->draggedCallback_->GetFunction());
	}

	//--------------------------------------------------------------
	NAN_SETTER(OfAppWrap::SetDragged)
	{
		auto self = node::ObjectWrap::Unwrap<OfAppWrap>(args.This())->GetWrapped();
		self->draggedCallback_->SetFunction(Local<Function>::Cast(value));
	}
} //!nofx
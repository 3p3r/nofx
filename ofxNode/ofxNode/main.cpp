#include "node.h"
#include "v8.h"
#include "nan.h"
#include "ofMain.h"
#include "ofApp.h"
#include "ofGraphics.h"

v8::Persistent<v8::Object> self_;

namespace node {
	namespace ofxNode {

		NAN_METHOD(Init) {
			NanScope();
			NanAssignPersistent(self_, args.This());
			ofSetupOpenGL(800, 550, OF_WINDOW);
			ofRunApp(new ofApp(self_));
			NanReturnUndefined();
		}
		
		NAN_METHOD(Draw) {
			NanScope();
			//to be overridden at user's will
			NanReturnUndefined();
		}

		NAN_METHOD(OfCircle) {
			NanScope();
			if (args.Length() > 2 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
			{
				ofCircle(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
			}
			NanReturnUndefined();
		}

		NAN_METHOD(OfFill) {
			NanScope();
			ofFill();
			NanReturnUndefined();
		}

		NAN_METHOD(OfClear) {
			NanScope();
			if (args.Length() > 2 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
			{
				ofClear(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
			}
			NanReturnUndefined();
		}

		NAN_METHOD(OfGetElapsedTimeMillis) {
			NanScope();
			NanReturnValue((int)ofGetElapsedTimeMillis());
		}

		NAN_METHOD(OfSetColor) {
			NanScope();
			if (args.Length() > 2 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
			{
				ofSetColor(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
			}
			NanReturnUndefined();
		}

		void Initialize(v8::Handle<v8::Object> target,
			v8::Handle<v8::Value> unused,
			v8::Handle<v8::Context> context) {
				//assigning methods
				target->Set(NanNew<v8::String>("init"), NanNew<v8::FunctionTemplate>(Init)->GetFunction());
				target->Set(NanNew<v8::String>("draw"), NanNew<v8::FunctionTemplate>(Draw)->GetFunction());
				target->Set(NanNew<v8::String>("ofCircle"), NanNew<v8::FunctionTemplate>(OfCircle)->GetFunction());
				target->Set(NanNew<v8::String>("ofFill"), NanNew<v8::FunctionTemplate>(OfFill)->GetFunction());
				target->Set(NanNew<v8::String>("ofClear"), NanNew<v8::FunctionTemplate>(OfClear)->GetFunction());
				target->Set(NanNew<v8::String>("ofGetElapsedTimeMillis"), NanNew<v8::FunctionTemplate>(OfGetElapsedTimeMillis)->GetFunction());
				target->Set(NanNew<v8::String>("ofSetColor"), NanNew<v8::FunctionTemplate>(OfSetColor)->GetFunction());
		}

	}
}

NODE_MODULE_CONTEXT_AWARE(ofxNode, node::ofxNode::Initialize)
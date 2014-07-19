#include "ofxNode_ofBackgroundGradient.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBackgroundGradient) {
		NanScope();
		
		if (args.Length() == 2 &&
			args[0]->IsObject() &&
			args[1]->IsObject())
		{
			//void ofBackgroundGradient(const ofColor &start, const ofColor &end)
			v8::Local<v8::Object> lStart = v8::Local<v8::Object>::Cast(args[0]);
			v8::Local<v8::Object> lEnd = v8::Local<v8::Object>::Cast(args[1]);
			if (lStart->Has(NanNew<v8::String>("r")) &&
				lStart->Has(NanNew<v8::String>("g")) &&
				lStart->Has(NanNew<v8::String>("b")) &&
				lEnd->Has(NanNew<v8::String>("r")) &&
				lEnd->Has(NanNew<v8::String>("g")) &&
				lEnd->Has(NanNew<v8::String>("b")))
			{
				float lStartAlpha = lStart->Has(NanNew<v8::String>("a")) ? lStart->Get(NanNew<v8::String>("a"))->NumberValue() : 255;
				float lEndAlpha = lEnd->Has(NanNew<v8::String>("a")) ? lEnd->Get(NanNew<v8::String>("a"))->NumberValue() : 255;
				ofBackgroundGradient(
					ofColor(lStart->Get(NanNew<v8::String>("r"))->NumberValue(), lStart->Get(NanNew<v8::String>("g"))->NumberValue(), lStart->Get(NanNew<v8::String>("b"))->NumberValue(), lStartAlpha) ,
					ofColor(lEnd->Get(NanNew<v8::String>("r"))->NumberValue(), lEnd->Get(NanNew<v8::String>("g"))->NumberValue(), lEnd->Get(NanNew<v8::String>("b"))->NumberValue(), lEndAlpha));
			}
			else
			{
				NanThrowError("bad arguments passed to ofBackgroundGradient.");
			}
		}
		else if (args.Length() == 3 &&
			args[0]->IsObject() &&
			args[1]->IsObject() &&
			args[2]->IsNumber())
		{
			//void ofBackgroundGradient(const ofColor &start, const ofColor &end, ofGradientMode mode=OF_GRADIENT_CIRCULAR)
			v8::Local<v8::Object> lStart = v8::Local<v8::Object>::Cast(args[0]);
			v8::Local<v8::Object> lEnd = v8::Local<v8::Object>::Cast(args[1]);
			ofGradientMode lGradientMode = (ofGradientMode)args[2]->Uint32Value();
			if (lStart->Has(NanNew<v8::String>("r")) &&
				lStart->Has(NanNew<v8::String>("g")) &&
				lStart->Has(NanNew<v8::String>("b")) &&
				lEnd->Has(NanNew<v8::String>("r")) &&
				lEnd->Has(NanNew<v8::String>("g")) &&
				lEnd->Has(NanNew<v8::String>("b")))
			{
				float lStartAlpha = lStart->Has(NanNew<v8::String>("a")) ? lStart->Get(NanNew<v8::String>("a"))->NumberValue() : 255;
				float lEndAlpha = lEnd->Has(NanNew<v8::String>("a")) ? lEnd->Get(NanNew<v8::String>("a"))->NumberValue() : 255;
				ofBackgroundGradient(
					ofColor(lStart->Get(NanNew<v8::String>("r"))->NumberValue(), lStart->Get(NanNew<v8::String>("g"))->NumberValue(), lStart->Get(NanNew<v8::String>("b"))->NumberValue(), lStartAlpha) ,
					ofColor(lEnd->Get(NanNew<v8::String>("r"))->NumberValue(), lEnd->Get(NanNew<v8::String>("g"))->NumberValue(), lEnd->Get(NanNew<v8::String>("b"))->NumberValue(), lEndAlpha) ,
					lGradientMode);
			}
			else
			{
				NanThrowError("bad arguments passed to ofBackgroundGradient.");
			}
		}
		else
		{
			NanThrowError("bad arguments passed to ofBackgroundGradient.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofBackgroundGradient
} // !namespace ofxNode
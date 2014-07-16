#pragma once

#include "ofMain.h"
#include "ofThread.h"
#include "v8.h"

class ofApp
	: public ofBaseApp
{
public:
	ofApp(v8::Persistent<v8::Object> &aModuleHandle) : moduleHandle_(aModuleHandle) {};
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
private:
	typedef ofBaseApp inherited;
	v8::Persistent<v8::Object> &moduleHandle_;
	v8::Handle<v8::Object> mModuleObject;
};

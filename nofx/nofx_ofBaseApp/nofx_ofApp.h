#ifndef _NOFX_BASE_APP_H_
#define _NOFX_BASE_APP_H_

#include "globals.h"
#include "ofBaseApp.h"

using namespace v8;

namespace nofx
{
	class OfAppImpl
		: public ofBaseApp
	{
	public:
		friend class OfAppWrap;
		OfAppImpl();
		~OfAppImpl();
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
		void windowEntry(int state);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void messageReceived(ofMessage & message);
		void dragged(ofDragInfo & drag);
	protected:
		typedef ofBaseApp inherited;
		NanCallback *setupCallback_;
		NanCallback *updateCallback_;
		NanCallback *drawCallback_;
		NanCallback *exitCallback_;
		NanCallback *keyPressedCallback_;
		NanCallback *keyReleasedCallback_;
		NanCallback *mouseMovedCallback_;
		NanCallback *mouseDraggedCallback_;
		NanCallback *mousePressedCallback_;
		NanCallback *mouseReleasedCallback_;
		NanCallback *windowEntryCallback_;
		NanCallback *windowResizedCallback_;
		NanCallback *dragEventCallback_;
		NanCallback *gotMessageCallback_;
		NanCallback *messageReceivedCallback_;
		NanCallback *draggedCallback_;
		Isolate* isolate;
	}; // !class OfAppImpl

	class OfAppWrap
		: public node::ObjectWrap
	{
	public:
		static void Initialize(v8::Handle<Object> target);
		OfAppImpl* GetWrapped() const { return internal_; };
		static const Persistent<Function>& Factory() {return constructor;}
	private:
		OfAppWrap();
		OfAppWrap(OfAppImpl*);
		~OfAppWrap() { if( internal_ ) delete internal_; };

		// Mutators
		static NAN_GETTER( GetMouseX );
		static NAN_GETTER( GetMouseY );

		static NAN_GETTER( GetSetup );
		static NAN_GETTER( GetUpdate );
		static NAN_GETTER( GetDraw );
		static NAN_GETTER( GetExit );
		static NAN_GETTER( GetKeyPressed );
		static NAN_GETTER( GetKeyReleased );
		static NAN_GETTER( GetMouseMoved );
		static NAN_GETTER( GetMouseDragged );
		static NAN_GETTER( GetMousePressed );
		static NAN_GETTER( GetMouseReleased );
		static NAN_GETTER( GetWindowEntry );
		static NAN_GETTER( GetWindowResized );
		static NAN_GETTER( GetDragEvent );
		static NAN_GETTER( GetGotMessage );
		static NAN_GETTER( GetMessageReceived );
		static NAN_GETTER( GetDragged );

		static NAN_SETTER( SetSetup );
		static NAN_SETTER( SetUpdate );
		static NAN_SETTER( SetDraw );
		static NAN_SETTER( SetExit );
		static NAN_SETTER( SetKeyPressed );
		static NAN_SETTER( SetKeyReleased );
		static NAN_SETTER( SetMouseMoved );
		static NAN_SETTER( SetMouseDragged );
		static NAN_SETTER( SetMousePressed );
		static NAN_SETTER( SetMouseReleased );
		static NAN_SETTER( SetWindowEntry );
		static NAN_SETTER( SetWindowResized );
		static NAN_SETTER( SetDragEvent );
		static NAN_SETTER( SetGotMessage );
		static NAN_SETTER( SetMessageReceived );
		static NAN_SETTER( SetDragged );

		static Persistent<Function> constructor;
		static NAN_METHOD(New);
		OfAppImpl* internal_;
	}; // !class OfAppWrap
} // !namespace nofx

#endif // !_NOFX_BASE_APP_H_
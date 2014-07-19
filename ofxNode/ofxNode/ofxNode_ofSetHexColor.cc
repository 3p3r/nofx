#include "ofxNode_ofSetHexColor.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofSetHexColor) {
		NanScope();

		if (args[0]->IsNumber())
		{
			ofSetHexColor(args[0]->Uint32Value());
		}
		else if (args[0]->IsString())
		{
			size_t lStrLen = 0;
			std::string lColorStr = NanCString(args[0], &lStrLen);
			if (lStrLen == 4 || lStrLen == 7 || lColorStr.at(0) != '#')
			{
				unsigned int r = 0, g = 0, b = 0;
				if (lStrLen == 4)
				{
					r = atoi(lColorStr.substr(1, 1).c_str());
					g = atoi(lColorStr.substr(2, 1).c_str());
					b = atoi(lColorStr.substr(3, 1).c_str());
				}
				else if (lStrLen == 7)
				{
					r = atoi(lColorStr.substr(1, 2).c_str());
					g = atoi(lColorStr.substr(3, 2).c_str());
					b = atoi(lColorStr.substr(5, 2).c_str());
				}
				ofSetHexColor(ofColor(r, g, b).getHex());
			}
			else
			{
				NanThrowTypeError("bad arguments passed to ofBackgroundHex.");
			}
		}
		else
		{
			NanThrowTypeError("bad arguments passed to ofBackgroundHex.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofSetHexColor
} // !namespace ofxNode

#include "ofxNode_ofBackgroundHex.h"
#include "ofGraphics.h"

namespace ofxNode
{
	NAN_METHOD(ofxNode_ofBackgroundHex) {
		ASSERT_FALSE(self_.IsEmpty());

		NanScope();
		
		if(args.Length() == 1)
		{
			if (args[0]->IsNumber())
			{
				ofBackgroundHex(args[0]->Uint32Value());
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
					ofBackground(r, g, b);
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
		}
		else if(args.Length() == 2)
		{
			if (args[0]->IsNumber() && args[1]->IsNumber())
			{
				ofBackgroundHex(args[0]->Uint32Value(), args[1]->NumberValue());
			}
			else if (args[0]->IsString() && args[1]->IsNumber())
			{
				size_t lStrLen = 0;
				std::string lColorStr = NanCString(args[0], &lStrLen);
				if (lStrLen == 5 || lStrLen == 9 || lColorStr.at(0) != '#')
				{
					unsigned int r = 0, g = 0, b = 0;
					if (lStrLen == 5)
					{
						r = atoi(lColorStr.substr(1, 1).c_str());
						g = atoi(lColorStr.substr(2, 1).c_str());
						b = atoi(lColorStr.substr(3, 1).c_str());
					}
					else if (lStrLen == 9)
					{
						r = atoi(lColorStr.substr(1, 2).c_str());
						g = atoi(lColorStr.substr(3, 2).c_str());
						b = atoi(lColorStr.substr(5, 2).c_str());
					}
					ofBackground(r, g, b, args[1]->NumberValue());
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
		}
		else
		{
			NanThrowTypeError("bad arguments passed to ofBackgroundHex.");
		}

		NanReturnValue(args.This());
	} // !ofxNode_ofBackgroundHex
} // !namespace ofxNode
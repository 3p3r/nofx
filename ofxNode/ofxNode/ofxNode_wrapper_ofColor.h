#ifndef _ofxNode_wrapper_ofColor_H_
#define _ofxNode_wrapper_ofColor_H_

#include "globals.h"
#include "ofColor.h"

namespace ofxNode
{
	class ofxNode_ofColor
		: public node::ObjectWrap
	{
	public:
		static void Init(v8::Handle<v8::Object> exports);
	private:
		// will be used to initialize native OF datatype
		ofColor internal_;

		// C++ constructors
		explicit ofxNode_ofColor(ofColor);
		~ofxNode_ofColor();

		// JS constructors
		static v8::Persistent<v8::Function> constructor;
		static NAN_METHOD(New);

		// setters
		static NAN_SETTER(SetR);
		static NAN_SETTER(SetG);
		static NAN_SETTER(SetB);
		static NAN_SETTER(SetA);

		// getters
		static NAN_GETTER(GetR);
		static NAN_GETTER(GetG);
		static NAN_GETTER(GetB);
		static NAN_GETTER(GetA);

		static NAN_PROPERTY_GETTER(GetAliceBlue);
		static NAN_PROPERTY_GETTER(GetAntiqueWhite);
		static NAN_PROPERTY_GETTER(GetAqua);
		static NAN_PROPERTY_GETTER(GetAquamarine);
		static NAN_PROPERTY_GETTER(GetAzure);
		static NAN_PROPERTY_GETTER(GetBeige);
		static NAN_PROPERTY_GETTER(GetBisque);
		static NAN_PROPERTY_GETTER(GetBlack);
		static NAN_PROPERTY_GETTER(GetBlanchedAlmond);
		static NAN_PROPERTY_GETTER(GetBlue);
		static NAN_PROPERTY_GETTER(GetBlueSteel);
		static NAN_PROPERTY_GETTER(GetBlueViolet);
		static NAN_PROPERTY_GETTER(GetBrown);
		static NAN_PROPERTY_GETTER(GetBurlyWood);
		static NAN_PROPERTY_GETTER(GetCadetBlue);
		static NAN_PROPERTY_GETTER(GetChartreuse);
		static NAN_PROPERTY_GETTER(GetChocolate);
		static NAN_PROPERTY_GETTER(GetCoral);
		static NAN_PROPERTY_GETTER(GetCornflowerBlue);
		static NAN_PROPERTY_GETTER(GetCornsilk);
		static NAN_PROPERTY_GETTER(GetCrimson);
		static NAN_PROPERTY_GETTER(GetCyan);
		static NAN_PROPERTY_GETTER(GetDarkBlue);
		static NAN_PROPERTY_GETTER(GetDarkCyan);
		static NAN_PROPERTY_GETTER(GetDarkGoldenRod);
		static NAN_PROPERTY_GETTER(GetDarkGray);
		static NAN_PROPERTY_GETTER(GetDarkGreen);
		static NAN_PROPERTY_GETTER(GetDarkGrey);
		static NAN_PROPERTY_GETTER(GetDarkKhaki);
		static NAN_PROPERTY_GETTER(GetDarkMagenta);
		static NAN_PROPERTY_GETTER(GetDarkOliveGreen);
		static NAN_PROPERTY_GETTER(GetDarkOrchid);
		static NAN_PROPERTY_GETTER(GetDarkRed);
		static NAN_PROPERTY_GETTER(GetDarkSalmon);
		static NAN_PROPERTY_GETTER(GetDarkSeaGreen);
		static NAN_PROPERTY_GETTER(GetDarkSlateBlue);
		static NAN_PROPERTY_GETTER(GetDarkSlateGray);
		static NAN_PROPERTY_GETTER(GetDarkSlateGrey);
		static NAN_PROPERTY_GETTER(GetDarkTurquoise);
		static NAN_PROPERTY_GETTER(GetDarkViolet);
		static NAN_PROPERTY_GETTER(GetDarkorange);
		static NAN_PROPERTY_GETTER(GetDeepPink);
		static NAN_PROPERTY_GETTER(GetDeepSkyBlue);
		static NAN_PROPERTY_GETTER(GetDimGray);
		static NAN_PROPERTY_GETTER(GetDimGrey);
		static NAN_PROPERTY_GETTER(GetDodgerBlue);
		static NAN_PROPERTY_GETTER(GetFireBrick);
		static NAN_PROPERTY_GETTER(GetFloralWhite);
		static NAN_PROPERTY_GETTER(GetForestGreen);
		static NAN_PROPERTY_GETTER(GetFuchsia);
		static NAN_PROPERTY_GETTER(GetGainsboro);
		static NAN_PROPERTY_GETTER(GetGhostWhite);
		static NAN_PROPERTY_GETTER(GetGold);
		static NAN_PROPERTY_GETTER(GetGoldenRod);
		static NAN_PROPERTY_GETTER(GetGray);
		static NAN_PROPERTY_GETTER(GetGreen);
		static NAN_PROPERTY_GETTER(GetGreenYellow);
		static NAN_PROPERTY_GETTER(GetGrey);
		static NAN_PROPERTY_GETTER(GetHoneyDew);
		static NAN_PROPERTY_GETTER(GetHotPink);
		static NAN_PROPERTY_GETTER(GetIndianRed);
		static NAN_PROPERTY_GETTER(GetIndigo);
		static NAN_PROPERTY_GETTER(GetIvory);
		static NAN_PROPERTY_GETTER(GetKhaki);
		static NAN_PROPERTY_GETTER(GetLavender);
		static NAN_PROPERTY_GETTER(GetLavenderBlush);
		static NAN_PROPERTY_GETTER(GetLawnGreen);
		static NAN_PROPERTY_GETTER(GetLemonChiffon);
		static NAN_PROPERTY_GETTER(GetLightBlue);
		static NAN_PROPERTY_GETTER(GetLightCoral);
		static NAN_PROPERTY_GETTER(GetLightCyan);
		static NAN_PROPERTY_GETTER(GetLightGoldenRodYellow);
		static NAN_PROPERTY_GETTER(GetLightGray);
		static NAN_PROPERTY_GETTER(GetLightGreen);
		static NAN_PROPERTY_GETTER(GetLightGrey);
		static NAN_PROPERTY_GETTER(GetLightPink);
		static NAN_PROPERTY_GETTER(GetLightSalmon);
		static NAN_PROPERTY_GETTER(GetLightSeaGreen);
		static NAN_PROPERTY_GETTER(GetLightSkyBlue);
		static NAN_PROPERTY_GETTER(GetLightSlateGray);
		static NAN_PROPERTY_GETTER(GetLightSlateGrey);
		static NAN_PROPERTY_GETTER(GetLightSteelBlue);
		static NAN_PROPERTY_GETTER(GetLightYellow);
		static NAN_PROPERTY_GETTER(GetLime);
		static NAN_PROPERTY_GETTER(GetLimeGreen);
		static NAN_PROPERTY_GETTER(GetLinen);
		static NAN_PROPERTY_GETTER(GetMagenta);
		static NAN_PROPERTY_GETTER(GetMaroon);
		static NAN_PROPERTY_GETTER(GetMediumAquaMarine);
		static NAN_PROPERTY_GETTER(GetMediumBlue);
		static NAN_PROPERTY_GETTER(GetMediumOrchid);
		static NAN_PROPERTY_GETTER(GetMediumPurple);
		static NAN_PROPERTY_GETTER(GetMediumSeaGreen);
		static NAN_PROPERTY_GETTER(GetMediumSlateBlue);
		static NAN_PROPERTY_GETTER(GetMediumSpringGreen);
		static NAN_PROPERTY_GETTER(GetMediumTurquoise);
		static NAN_PROPERTY_GETTER(GetMediumVioletRed);
		static NAN_PROPERTY_GETTER(GetMidnightBlue);
		static NAN_PROPERTY_GETTER(GetMintCream);
		static NAN_PROPERTY_GETTER(GetMistyRose);
		static NAN_PROPERTY_GETTER(GetMoccasin);
		static NAN_PROPERTY_GETTER(GetNavajoWhite);
		static NAN_PROPERTY_GETTER(GetNavy);
		static NAN_PROPERTY_GETTER(GetOldLace);
		static NAN_PROPERTY_GETTER(GetOlive);
		static NAN_PROPERTY_GETTER(GetOliveDrab);
		static NAN_PROPERTY_GETTER(GetOrange);
		static NAN_PROPERTY_GETTER(GetOrangeRed);
		static NAN_PROPERTY_GETTER(GetOrchid);
		static NAN_PROPERTY_GETTER(GetPaleGoldenRod);
		static NAN_PROPERTY_GETTER(GetPaleGreen);
		static NAN_PROPERTY_GETTER(GetPaleTurquoise);
		static NAN_PROPERTY_GETTER(GetPaleVioletRed);
		static NAN_PROPERTY_GETTER(GetPapayaWhip);
		static NAN_PROPERTY_GETTER(GetPeachPuff);
		static NAN_PROPERTY_GETTER(GetPeru);
		static NAN_PROPERTY_GETTER(GetPink);
		static NAN_PROPERTY_GETTER(GetPlum);
		static NAN_PROPERTY_GETTER(GetPowderBlue);
		static NAN_PROPERTY_GETTER(GetPurple);
		static NAN_PROPERTY_GETTER(GetRed);
		static NAN_PROPERTY_GETTER(GetRosyBrown);
		static NAN_PROPERTY_GETTER(GetRoyalBlue);
		static NAN_PROPERTY_GETTER(GetSaddleBrown);
		static NAN_PROPERTY_GETTER(GetSalmon);
		static NAN_PROPERTY_GETTER(GetSandyBrown);
		static NAN_PROPERTY_GETTER(GetSeaGreen);
		static NAN_PROPERTY_GETTER(GetSeaShell);
		static NAN_PROPERTY_GETTER(GetSienna);
		static NAN_PROPERTY_GETTER(GetSilver);
		static NAN_PROPERTY_GETTER(GetSkyBlue);
		static NAN_PROPERTY_GETTER(GetSlateBlue);
		static NAN_PROPERTY_GETTER(GetSlateGray);
		static NAN_PROPERTY_GETTER(GetSlateGrey);
		static NAN_PROPERTY_GETTER(GetSnow);
		static NAN_PROPERTY_GETTER(GetSpringGreen);
		static NAN_PROPERTY_GETTER(GetSteelBlue);
		static NAN_PROPERTY_GETTER(GetTan);
		static NAN_PROPERTY_GETTER(GetTeal);
		static NAN_PROPERTY_GETTER(GetThistle);
		static NAN_PROPERTY_GETTER(GetTomato);
		static NAN_PROPERTY_GETTER(GetTurquoise);
		static NAN_PROPERTY_GETTER(GetViolet);
		static NAN_PROPERTY_GETTER(GetWheat);
		static NAN_PROPERTY_GETTER(GetWhite);
		static NAN_PROPERTY_GETTER(GetWhiteSmoke);
		static NAN_PROPERTY_GETTER(GetYellow);
		static NAN_PROPERTY_GETTER(GetYellowGreen);

		//public methods
		static NAN_METHOD(SetSaturation);
		static NAN_METHOD(SetHue);
		static NAN_METHOD(SetHueAngle);
		static NAN_METHOD(SetBrightness);
		static NAN_METHOD(SetHsb);
		static NAN_METHOD(SetHex);
		static NAN_METHOD(Set);
		static NAN_METHOD(Limit);
		static NAN_METHOD(Lerp);
		static NAN_METHOD(Invert);
		static NAN_METHOD(GetSaturation);
		static NAN_METHOD(GetLightness);
		static NAN_METHOD(GetHueAngle);
		static NAN_METHOD(GetHue);
		static NAN_METHOD(GetHex);
		static NAN_METHOD(GetBrightness);
		static NAN_METHOD(GetLerped);
		static NAN_METHOD(GetInverted);
		static NAN_METHOD(GetHsb);
		static NAN_METHOD(GetClamped);
		static NAN_METHOD(Clamp);
		static NAN_METHOD(FromHsb);
		static NAN_METHOD(FromHex);

		// Primitives
		static NAN_METHOD(ToString);
		static NAN_METHOD(Plus);
		static NAN_METHOD(Minus);
		static NAN_METHOD(Times);
		static NAN_METHOD(Over);
		static NAN_METHOD(Equals);
	};
	
} // !namespace ofxNode

#endif // !_ofxNode_wrapper_ofColor_H_
#include "ofxNode_wrapper_ofColor.h"

namespace ofxNode
{
	v8::Persistent<v8::Function> ofxNode_ofColor::constructor;

	ofxNode_ofColor::ofxNode_ofColor(ofColor aOfColor)
		: internal_(aOfColor)
	{}

	ofxNode_ofColor::~ofxNode_ofColor()
	{}

	void ofxNode_ofColor::Init(v8::Handle<v8::Object> exports)
	{
		// Prepare constructor template
		auto tpl = NanNew<v8::FunctionTemplate>(New);
		tpl->SetClassName(NanNew("ofColor"));
		auto inst = tpl->InstanceTemplate();
		inst->SetInternalFieldCount(1); //One + number of ofVec4f public methods assigned by NanSetPrototypeTemplate
		
		// Instance Props
		inst->SetAccessor(NanNew("r")	, ofxNode_ofColor::GetR , ofxNode_ofColor::SetR);
		inst->SetAccessor(NanNew("g")	, ofxNode_ofColor::GetG , ofxNode_ofColor::SetG);
		inst->SetAccessor(NanNew("b")	, ofxNode_ofColor::GetB , ofxNode_ofColor::SetB);
		inst->SetAccessor(NanNew("a")	, ofxNode_ofColor::GetA , ofxNode_ofColor::SetA);

		// Prototype
		auto proto = tpl->PrototypeTemplate();

		proto->SetAccessor(NanNew<v8::String>("aliceBlue"), ofxNode_ofColor::GetAliceBlue);
		proto->SetAccessor(NanNew<v8::String>("antiqueWhite"), ofxNode_ofColor::GetAntiqueWhite);
		proto->SetAccessor(NanNew<v8::String>("aqua"), ofxNode_ofColor::GetAqua);
		proto->SetAccessor(NanNew<v8::String>("aquamarine"), ofxNode_ofColor::GetAquamarine);
		proto->SetAccessor(NanNew<v8::String>("azure"), ofxNode_ofColor::GetAzure);
		proto->SetAccessor(NanNew<v8::String>("beige"), ofxNode_ofColor::GetBeige);
		proto->SetAccessor(NanNew<v8::String>("bisque"), ofxNode_ofColor::GetBisque);
		proto->SetAccessor(NanNew<v8::String>("black"), ofxNode_ofColor::GetBlack);
		proto->SetAccessor(NanNew<v8::String>("blanchedAlmond"), ofxNode_ofColor::GetBlanchedAlmond);
		proto->SetAccessor(NanNew<v8::String>("blue"), ofxNode_ofColor::GetBlue);
		proto->SetAccessor(NanNew<v8::String>("blueSteel"), ofxNode_ofColor::GetBlueSteel);
		proto->SetAccessor(NanNew<v8::String>("blueViolet"), ofxNode_ofColor::GetBlueViolet);
		proto->SetAccessor(NanNew<v8::String>("brown"), ofxNode_ofColor::GetBrown);
		proto->SetAccessor(NanNew<v8::String>("burlyWood"), ofxNode_ofColor::GetBurlyWood);
		proto->SetAccessor(NanNew<v8::String>("cadetBlue"), ofxNode_ofColor::GetCadetBlue);
		proto->SetAccessor(NanNew<v8::String>("chartreuse"), ofxNode_ofColor::GetChartreuse);
		proto->SetAccessor(NanNew<v8::String>("chocolate"), ofxNode_ofColor::GetChocolate);
		proto->SetAccessor(NanNew<v8::String>("coral"), ofxNode_ofColor::GetCoral);
		proto->SetAccessor(NanNew<v8::String>("cornflowerBlue"), ofxNode_ofColor::GetCornflowerBlue);
		proto->SetAccessor(NanNew<v8::String>("cornsilk"), ofxNode_ofColor::GetCornsilk);
		proto->SetAccessor(NanNew<v8::String>("crimson"), ofxNode_ofColor::GetCrimson);
		proto->SetAccessor(NanNew<v8::String>("cyan"), ofxNode_ofColor::GetCyan);
		proto->SetAccessor(NanNew<v8::String>("darkBlue"), ofxNode_ofColor::GetDarkBlue);
		proto->SetAccessor(NanNew<v8::String>("darkCyan"), ofxNode_ofColor::GetDarkCyan);
		proto->SetAccessor(NanNew<v8::String>("darkGoldenRod"), ofxNode_ofColor::GetDarkGoldenRod);
		proto->SetAccessor(NanNew<v8::String>("darkGray"), ofxNode_ofColor::GetDarkGray);
		proto->SetAccessor(NanNew<v8::String>("darkGreen"), ofxNode_ofColor::GetDarkGreen);
		proto->SetAccessor(NanNew<v8::String>("darkGrey"), ofxNode_ofColor::GetDarkGrey);
		proto->SetAccessor(NanNew<v8::String>("darkKhaki"), ofxNode_ofColor::GetDarkKhaki);
		proto->SetAccessor(NanNew<v8::String>("darkMagenta"), ofxNode_ofColor::GetDarkMagenta);
		proto->SetAccessor(NanNew<v8::String>("darkOliveGreen"), ofxNode_ofColor::GetDarkOliveGreen);
		proto->SetAccessor(NanNew<v8::String>("darkOrchid"), ofxNode_ofColor::GetDarkOrchid);
		proto->SetAccessor(NanNew<v8::String>("darkRed"), ofxNode_ofColor::GetDarkRed);
		proto->SetAccessor(NanNew<v8::String>("darkSalmon"), ofxNode_ofColor::GetDarkSalmon);
		proto->SetAccessor(NanNew<v8::String>("darkSeaGreen"), ofxNode_ofColor::GetDarkSeaGreen);
		proto->SetAccessor(NanNew<v8::String>("darkSlateBlue"), ofxNode_ofColor::GetDarkSlateBlue);
		proto->SetAccessor(NanNew<v8::String>("darkSlateGray"), ofxNode_ofColor::GetDarkSlateGray);
		proto->SetAccessor(NanNew<v8::String>("darkSlateGrey"), ofxNode_ofColor::GetDarkSlateGrey);
		proto->SetAccessor(NanNew<v8::String>("darkTurquoise"), ofxNode_ofColor::GetDarkTurquoise);
		proto->SetAccessor(NanNew<v8::String>("darkViolet"), ofxNode_ofColor::GetDarkViolet);
		proto->SetAccessor(NanNew<v8::String>("darkorange"), ofxNode_ofColor::GetDarkorange);
		proto->SetAccessor(NanNew<v8::String>("deepPink"), ofxNode_ofColor::GetDeepPink);
		proto->SetAccessor(NanNew<v8::String>("deepSkyBlue"), ofxNode_ofColor::GetDeepSkyBlue);
		proto->SetAccessor(NanNew<v8::String>("dimGray"), ofxNode_ofColor::GetDimGray);
		proto->SetAccessor(NanNew<v8::String>("dimGrey"), ofxNode_ofColor::GetDimGrey);
		proto->SetAccessor(NanNew<v8::String>("dodgerBlue"), ofxNode_ofColor::GetDodgerBlue);
		proto->SetAccessor(NanNew<v8::String>("fireBrick"), ofxNode_ofColor::GetFireBrick);
		proto->SetAccessor(NanNew<v8::String>("floralWhite"), ofxNode_ofColor::GetFloralWhite);
		proto->SetAccessor(NanNew<v8::String>("forestGreen"), ofxNode_ofColor::GetForestGreen);
		proto->SetAccessor(NanNew<v8::String>("fuchsia"), ofxNode_ofColor::GetFuchsia);
		proto->SetAccessor(NanNew<v8::String>("gainsboro"), ofxNode_ofColor::GetGainsboro);
		proto->SetAccessor(NanNew<v8::String>("ghostWhite"), ofxNode_ofColor::GetGhostWhite);
		proto->SetAccessor(NanNew<v8::String>("gold"), ofxNode_ofColor::GetGold);
		proto->SetAccessor(NanNew<v8::String>("goldenRod"), ofxNode_ofColor::GetGoldenRod);
		proto->SetAccessor(NanNew<v8::String>("gray"), ofxNode_ofColor::GetGray);
		proto->SetAccessor(NanNew<v8::String>("green"), ofxNode_ofColor::GetGreen);
		proto->SetAccessor(NanNew<v8::String>("greenYellow"), ofxNode_ofColor::GetGreenYellow);
		proto->SetAccessor(NanNew<v8::String>("grey"), ofxNode_ofColor::GetGrey);
		proto->SetAccessor(NanNew<v8::String>("honeyDew"), ofxNode_ofColor::GetHoneyDew);
		proto->SetAccessor(NanNew<v8::String>("hotPink"), ofxNode_ofColor::GetHotPink);
		proto->SetAccessor(NanNew<v8::String>("indianRed"), ofxNode_ofColor::GetIndianRed);
		proto->SetAccessor(NanNew<v8::String>("indigo"), ofxNode_ofColor::GetIndigo);
		proto->SetAccessor(NanNew<v8::String>("ivory"), ofxNode_ofColor::GetIvory);
		proto->SetAccessor(NanNew<v8::String>("khaki"), ofxNode_ofColor::GetKhaki);
		proto->SetAccessor(NanNew<v8::String>("lavender"), ofxNode_ofColor::GetLavender);
		proto->SetAccessor(NanNew<v8::String>("lavenderBlush"), ofxNode_ofColor::GetLavenderBlush);
		proto->SetAccessor(NanNew<v8::String>("lawnGreen"), ofxNode_ofColor::GetLawnGreen);
		proto->SetAccessor(NanNew<v8::String>("lemonChiffon"), ofxNode_ofColor::GetLemonChiffon);
		proto->SetAccessor(NanNew<v8::String>("lightBlue"), ofxNode_ofColor::GetLightBlue);
		proto->SetAccessor(NanNew<v8::String>("lightCoral"), ofxNode_ofColor::GetLightCoral);
		proto->SetAccessor(NanNew<v8::String>("lightCyan"), ofxNode_ofColor::GetLightCyan);
		proto->SetAccessor(NanNew<v8::String>("lightGoldenRodYellow"), ofxNode_ofColor::GetLightGoldenRodYellow);
		proto->SetAccessor(NanNew<v8::String>("lightGray"), ofxNode_ofColor::GetLightGray);
		proto->SetAccessor(NanNew<v8::String>("lightGreen"), ofxNode_ofColor::GetLightGreen);
		proto->SetAccessor(NanNew<v8::String>("lightGrey"), ofxNode_ofColor::GetLightGrey);
		proto->SetAccessor(NanNew<v8::String>("lightPink"), ofxNode_ofColor::GetLightPink);
		proto->SetAccessor(NanNew<v8::String>("lightSalmon"), ofxNode_ofColor::GetLightSalmon);
		proto->SetAccessor(NanNew<v8::String>("lightSeaGreen"), ofxNode_ofColor::GetLightSeaGreen);
		proto->SetAccessor(NanNew<v8::String>("lightSkyBlue"), ofxNode_ofColor::GetLightSkyBlue);
		proto->SetAccessor(NanNew<v8::String>("lightSlateGray"), ofxNode_ofColor::GetLightSlateGray);
		proto->SetAccessor(NanNew<v8::String>("lightSlateGrey"), ofxNode_ofColor::GetLightSlateGrey);
		proto->SetAccessor(NanNew<v8::String>("lightSteelBlue"), ofxNode_ofColor::GetLightSteelBlue);
		proto->SetAccessor(NanNew<v8::String>("lightYellow"), ofxNode_ofColor::GetLightYellow);
		proto->SetAccessor(NanNew<v8::String>("lime"), ofxNode_ofColor::GetLime);
		proto->SetAccessor(NanNew<v8::String>("limeGreen"), ofxNode_ofColor::GetLimeGreen);
		proto->SetAccessor(NanNew<v8::String>("linen"), ofxNode_ofColor::GetLinen);
		proto->SetAccessor(NanNew<v8::String>("magenta"), ofxNode_ofColor::GetMagenta);
		proto->SetAccessor(NanNew<v8::String>("maroon"), ofxNode_ofColor::GetMaroon);
		proto->SetAccessor(NanNew<v8::String>("mediumAquaMarine"), ofxNode_ofColor::GetMediumAquaMarine);
		proto->SetAccessor(NanNew<v8::String>("mediumBlue"), ofxNode_ofColor::GetMediumBlue);
		proto->SetAccessor(NanNew<v8::String>("mediumOrchid"), ofxNode_ofColor::GetMediumOrchid);
		proto->SetAccessor(NanNew<v8::String>("mediumPurple"), ofxNode_ofColor::GetMediumPurple);
		proto->SetAccessor(NanNew<v8::String>("mediumSeaGreen"), ofxNode_ofColor::GetMediumSeaGreen);
		proto->SetAccessor(NanNew<v8::String>("mediumSlateBlue"), ofxNode_ofColor::GetMediumSlateBlue);
		proto->SetAccessor(NanNew<v8::String>("mediumSpringGreen"), ofxNode_ofColor::GetMediumSpringGreen);
		proto->SetAccessor(NanNew<v8::String>("mediumTurquoise"), ofxNode_ofColor::GetMediumTurquoise);
		proto->SetAccessor(NanNew<v8::String>("mediumVioletRed"), ofxNode_ofColor::GetMediumVioletRed);
		proto->SetAccessor(NanNew<v8::String>("midnightBlue"), ofxNode_ofColor::GetMidnightBlue);
		proto->SetAccessor(NanNew<v8::String>("mintCream"), ofxNode_ofColor::GetMintCream);
		proto->SetAccessor(NanNew<v8::String>("mistyRose"), ofxNode_ofColor::GetMistyRose);
		proto->SetAccessor(NanNew<v8::String>("moccasin"), ofxNode_ofColor::GetMoccasin);
		proto->SetAccessor(NanNew<v8::String>("navajoWhite"), ofxNode_ofColor::GetNavajoWhite);
		proto->SetAccessor(NanNew<v8::String>("navy"), ofxNode_ofColor::GetNavy);
		proto->SetAccessor(NanNew<v8::String>("oldLace"), ofxNode_ofColor::GetOldLace);
		proto->SetAccessor(NanNew<v8::String>("olive"), ofxNode_ofColor::GetOlive);
		proto->SetAccessor(NanNew<v8::String>("oliveDrab"), ofxNode_ofColor::GetOliveDrab);
		proto->SetAccessor(NanNew<v8::String>("orange"), ofxNode_ofColor::GetOrange);
		proto->SetAccessor(NanNew<v8::String>("orangeRed"), ofxNode_ofColor::GetOrangeRed);
		proto->SetAccessor(NanNew<v8::String>("orchid"), ofxNode_ofColor::GetOrchid);
		proto->SetAccessor(NanNew<v8::String>("paleGoldenRod"), ofxNode_ofColor::GetPaleGoldenRod);
		proto->SetAccessor(NanNew<v8::String>("paleGreen"), ofxNode_ofColor::GetPaleGreen);
		proto->SetAccessor(NanNew<v8::String>("paleTurquoise"), ofxNode_ofColor::GetPaleTurquoise);
		proto->SetAccessor(NanNew<v8::String>("paleVioletRed"), ofxNode_ofColor::GetPaleVioletRed);
		proto->SetAccessor(NanNew<v8::String>("papayaWhip"), ofxNode_ofColor::GetPapayaWhip);
		proto->SetAccessor(NanNew<v8::String>("peachPuff"), ofxNode_ofColor::GetPeachPuff);
		proto->SetAccessor(NanNew<v8::String>("peru"), ofxNode_ofColor::GetPeru);
		proto->SetAccessor(NanNew<v8::String>("pink"), ofxNode_ofColor::GetPink);
		proto->SetAccessor(NanNew<v8::String>("plum"), ofxNode_ofColor::GetPlum);
		proto->SetAccessor(NanNew<v8::String>("powderBlue"), ofxNode_ofColor::GetPowderBlue);
		proto->SetAccessor(NanNew<v8::String>("purple"), ofxNode_ofColor::GetPurple);
		proto->SetAccessor(NanNew<v8::String>("red"), ofxNode_ofColor::GetRed);
		proto->SetAccessor(NanNew<v8::String>("rosyBrown"), ofxNode_ofColor::GetRosyBrown);
		proto->SetAccessor(NanNew<v8::String>("royalBlue"), ofxNode_ofColor::GetRoyalBlue);
		proto->SetAccessor(NanNew<v8::String>("saddleBrown"), ofxNode_ofColor::GetSaddleBrown);
		proto->SetAccessor(NanNew<v8::String>("salmon"), ofxNode_ofColor::GetSalmon);
		proto->SetAccessor(NanNew<v8::String>("sandyBrown"), ofxNode_ofColor::GetSandyBrown);
		proto->SetAccessor(NanNew<v8::String>("seaGreen"), ofxNode_ofColor::GetSeaGreen);
		proto->SetAccessor(NanNew<v8::String>("seaShell"), ofxNode_ofColor::GetSeaShell);
		proto->SetAccessor(NanNew<v8::String>("sienna"), ofxNode_ofColor::GetSienna);
		proto->SetAccessor(NanNew<v8::String>("silver"), ofxNode_ofColor::GetSilver);
		proto->SetAccessor(NanNew<v8::String>("skyBlue"), ofxNode_ofColor::GetSkyBlue);
		proto->SetAccessor(NanNew<v8::String>("slateBlue"), ofxNode_ofColor::GetSlateBlue);
		proto->SetAccessor(NanNew<v8::String>("slateGray"), ofxNode_ofColor::GetSlateGray);
		proto->SetAccessor(NanNew<v8::String>("slateGrey"), ofxNode_ofColor::GetSlateGrey);
		proto->SetAccessor(NanNew<v8::String>("snow"), ofxNode_ofColor::GetSnow);
		proto->SetAccessor(NanNew<v8::String>("springGreen"), ofxNode_ofColor::GetSpringGreen);
		proto->SetAccessor(NanNew<v8::String>("steelBlue"), ofxNode_ofColor::GetSteelBlue);
		proto->SetAccessor(NanNew<v8::String>("tan"), ofxNode_ofColor::GetTan);
		proto->SetAccessor(NanNew<v8::String>("teal"), ofxNode_ofColor::GetTeal);
		proto->SetAccessor(NanNew<v8::String>("thistle"), ofxNode_ofColor::GetThistle);
		proto->SetAccessor(NanNew<v8::String>("tomato"), ofxNode_ofColor::GetTomato);
		proto->SetAccessor(NanNew<v8::String>("turquoise"), ofxNode_ofColor::GetTurquoise);
		proto->SetAccessor(NanNew<v8::String>("violet"), ofxNode_ofColor::GetViolet);
		proto->SetAccessor(NanNew<v8::String>("wheat"), ofxNode_ofColor::GetWheat);
		proto->SetAccessor(NanNew<v8::String>("white"), ofxNode_ofColor::GetWhite);
		proto->SetAccessor(NanNew<v8::String>("whiteSmoke"), ofxNode_ofColor::GetWhiteSmoke);
		proto->SetAccessor(NanNew<v8::String>("yellow"), ofxNode_ofColor::GetYellow);
		proto->SetAccessor(NanNew<v8::String>("yellowGreen"), ofxNode_ofColor::GetYellowGreen);

		NanSetPrototypeTemplate(tpl, NanNew("setSaturation"), NanNew<v8::FunctionTemplate>(SetSaturation), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setHue"), NanNew<v8::FunctionTemplate>(SetHue), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setHueAngle"), NanNew<v8::FunctionTemplate>(SetHueAngle), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setBrightness"), NanNew<v8::FunctionTemplate>(SetBrightness), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setHsb"), NanNew<v8::FunctionTemplate>(SetHsb), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("setHex"), NanNew<v8::FunctionTemplate>(SetHex), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("set"), NanNew<v8::FunctionTemplate>(Set), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("limit"), NanNew<v8::FunctionTemplate>(Limit), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("lerp"), NanNew<v8::FunctionTemplate>(Lerp), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("invert"), NanNew<v8::FunctionTemplate>(Invert), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getSaturation"), NanNew<v8::FunctionTemplate>(GetSaturation), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getLightness"), NanNew<v8::FunctionTemplate>(GetLightness), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getHueAngle"), NanNew<v8::FunctionTemplate>(GetHueAngle), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getHue"), NanNew<v8::FunctionTemplate>(GetHue), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getHex"), NanNew<v8::FunctionTemplate>(GetHex), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getBrightness"), NanNew<v8::FunctionTemplate>(GetBrightness), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getLerped"), NanNew<v8::FunctionTemplate>(GetLerped), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getInverted"), NanNew<v8::FunctionTemplate>(GetInverted), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getHsb"), NanNew<v8::FunctionTemplate>(GetInverted), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("getClamped"), NanNew<v8::FunctionTemplate>(GetClamped), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("clamp"), NanNew<v8::FunctionTemplate>(Clamp), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("fromHsb"), NanNew<v8::FunctionTemplate>(FromHsb), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("fromHex"), NanNew<v8::FunctionTemplate>(FromHex), v8::ReadOnly);

		// Javascript Primitives
		NanSetPrototypeTemplate(tpl, NanNew("toString"), NanNew<v8::FunctionTemplate>(ToString), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("plus"), NanNew<v8::FunctionTemplate>(Plus), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("times"), NanNew<v8::FunctionTemplate>(Times), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("over"), NanNew<v8::FunctionTemplate>(Over), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("minus"), NanNew<v8::FunctionTemplate>(Minus), v8::ReadOnly);
		NanSetPrototypeTemplate(tpl, NanNew("equals"), NanNew<v8::FunctionTemplate>(Equals), v8::ReadOnly);

		NanSetPrototypeTemplate(tpl, NanNew("OFXNODE_TYPE"), NanNew(OFXNODE_TYPES::OFCOLOR), v8::DontEnum);
		NanAssignPersistent(constructor, tpl->GetFunction());
		exports->Set(NanNew<v8::String>("ofColor"), tpl->GetFunction());
	}

	NAN_GETTER(ofxNode_ofColor::GetR) {NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.r));}
	NAN_SETTER(ofxNode_ofColor::SetR) {node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.r = value->NumberValue();}
	NAN_GETTER(ofxNode_ofColor::GetG) {NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.g));}
	NAN_SETTER(ofxNode_ofColor::SetG) {node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.g = value->NumberValue();}
	NAN_GETTER(ofxNode_ofColor::GetB) {NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.b));}
	NAN_SETTER(ofxNode_ofColor::SetB) {node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.b = value->NumberValue();}
	NAN_GETTER(ofxNode_ofColor::GetA) {NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.a));}
	NAN_SETTER(ofxNode_ofColor::SetA) {node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.a = value->NumberValue();}

	NAN_METHOD(ofxNode_ofColor::FromHex)
	{
		NanScope();
		
		if(args.Length() == 1)
		{
			if (args[0]->IsNumber())
			{
				const auto toRet = node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.fromHex(args[0]->Uint32Value());
				v8::Handle<v8::Value> lArgv[] = {
					NanNew(toRet.r),
					NanNew(toRet.g),
					NanNew(toRet.b),
					NanNew(toRet.a)
				};
				NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
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
					const auto toRet = ofColor(r, g, b);
					v8::Handle<v8::Value> lArgv[] = {
						NanNew(toRet.r),
						NanNew(toRet.g),
						NanNew(toRet.b),
						NanNew(toRet.a)
					};
					NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
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
				const auto toRet = node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.fromHex(args[0]->Uint32Value(), args[1]->Uint32Value());
				v8::Handle<v8::Value> lArgv[] = {
					NanNew(toRet.r),
					NanNew(toRet.g),
					NanNew(toRet.b),
					NanNew(toRet.a)
				};
				NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
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
					
					const auto toRet = ofColor(r, g, b, args[1]->NumberValue());
					v8::Handle<v8::Value> lArgv[] = {
						NanNew(toRet.r),
						NanNew(toRet.g),
						NanNew(toRet.b),
						NanNew(toRet.a)
					};
					NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
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
	}

	NAN_METHOD(ofxNode_ofColor::FromHsb)
	{
		const auto toRet = node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.fromHsb(
			args[0]->NumberValue(),
			args[1]->NumberValue(),
			args[2]->NumberValue()
			);
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(toRet.r),
			NanNew(toRet.g),
			NanNew(toRet.b),
			NanNew(toRet.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_METHOD(ofxNode_ofColor::GetHsb)
	{
		float hue = 0, saturation = 0, brightness = 0;
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.getHsb(hue, saturation, brightness);
		auto toRet = NanNew<v8::Object>();
		toRet->Set(NanNew("hue"), NanNew(hue));
		toRet->Set(NanNew("saturation"), NanNew(saturation));
		toRet->Set(NanNew("brightness"), NanNew(brightness));
		NanReturnValue(toRet);
	}

	NAN_METHOD(ofxNode_ofColor::GetClamped)
	{
		const auto lClamped = node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.getClamped();
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lClamped.r),
			NanNew(lClamped.g),
			NanNew(lClamped.b),
			NanNew(lClamped.a)};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4,lArgv));
	}

	NAN_METHOD(ofxNode_ofColor::Clamp)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.clamp();
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::GetSaturation)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.getSaturation()));
	}

	NAN_METHOD(ofxNode_ofColor::GetLightness)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.getLightness()));
	}

	NAN_METHOD(ofxNode_ofColor::GetHueAngle)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.getHueAngle()));
	}

	NAN_METHOD(ofxNode_ofColor::GetHue)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.getHue()));
	}

	NAN_METHOD(ofxNode_ofColor::GetHex)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.getHex()));
	}

	NAN_METHOD(ofxNode_ofColor::GetBrightness)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.getBrightness()));
	}

	NAN_METHOD(ofxNode_ofColor::GetInverted)
	{
		const auto lInverted = node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.getInverted();
		v8::Handle<v8::Value> lArgv[] = {NanNew(lInverted.r), NanNew(lInverted.g), NanNew(lInverted.b), NanNew(lInverted.a)};
		NanReturnValue(NanNew<v8::Function>(constructor)->CallAsConstructor(4, lArgv));
	}
	
	NAN_METHOD(ofxNode_ofColor::Invert)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.invert();
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::GetLerped)
	{
		const auto lLerped = node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.getLerped(
			node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->internal_,
			args[1]->NumberValue()
			);
		v8::Handle<v8::Value> lArgv[] = {NanNew(lLerped.r), NanNew(lLerped.g), NanNew(lLerped.b), NanNew(lLerped.a)};
		NanReturnValue(NanNew<v8::Function>(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_METHOD(ofxNode_ofColor::Lerp)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.lerp(
			node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->internal_,
			args[1]->NumberValue()
			);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::Limit)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.limit()));
	}

	NAN_METHOD(ofxNode_ofColor::Equals)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_;
		if (args[0]->IsArray())
		{
			bool result = true;
			bool ranAtLeastOnce = false;
			const auto lProps = args[0]->ToObject()->GetPropertyNames();
			for (int i = 0; i < lProps->Length(); ++i)
			{
				const auto lKey = lProps->Get(i);
				const auto lVal = args[0]->ToObject()->Get(i);

				if(lVal->ToObject()->Has(NanNew("OFXNODE_TYPE")) &&
					lVal->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() == OFXNODE_TYPES::OFCOLOR)
				{
					ranAtLeastOnce = true;
					result = result && ((ofColor)self == (ofColor)ObjectWrap::Unwrap<ofxNode_ofColor>(lVal->ToObject())->internal_);
				}
			}

			NanReturnValue( (NanNew(result && ranAtLeastOnce)) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->internal_;
			NanReturnValue( (NanNew((ofColor)self == (ofColor)lArgVec)) );
		}
	}

	NAN_METHOD(ofxNode_ofColor::Over)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_;
		const int lArgc = 4;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self / lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.r), NanNew(result.g), NanNew(result.b), NanNew(result.a)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->internal_;
			const auto result = self / lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.r), NanNew(result.g), NanNew(result.b), NanNew(result.a)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofColor::Times)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_;
		const int lArgc = 4;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self * lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.r), NanNew(result.g), NanNew(result.b), NanNew(result.a)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->internal_;
			const auto result = self * lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.r), NanNew(result.g), NanNew(result.b), NanNew(result.a)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofColor::Minus)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_;
		const int lArgc = 4;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self - lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.r), NanNew(result.g), NanNew(result.b), NanNew(result.a)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->internal_;
			const auto result = self - lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.r), NanNew(result.g), NanNew(result.b), NanNew(result.a)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofColor::Plus)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_;
		const int lArgc = 4;
		if(args[0]->IsNumber())
		{
			const auto lArgVec = args[0]->NumberValue();
			const auto result = self + lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.r), NanNew(result.g), NanNew(result.b), NanNew(result.a)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->internal_;
			const auto result = self + lArgVec;
			v8::Handle<v8::Value> lArgv[] = {NanNew(result.r), NanNew(result.g), NanNew(result.b), NanNew(result.a)};
			NanReturnValue( (NanNew(constructor))->CallAsConstructor(lArgc, lArgv) );
		}
	}

	NAN_METHOD(ofxNode_ofColor::ToString)
	{
		const auto self = ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_;
		std::ostringstream out;
		out << self;
		NanReturnValue( NanNew(out.str().c_str()) );
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetAliceBlue)
	{
		const auto lReturnColor = ofColor::aliceBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetAntiqueWhite)
	{
		const auto lReturnColor = ofColor::antiqueWhite;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetAqua)
	{
		const auto lReturnColor = ofColor::aqua;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetAquamarine)
	{
		const auto lReturnColor = ofColor::aquamarine;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetAzure)
	{
		const auto lReturnColor = ofColor::azure;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBeige)
	{
		const auto lReturnColor = ofColor::beige;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBisque)
	{
		const auto lReturnColor = ofColor::bisque;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBlack)
	{
		const auto lReturnColor = ofColor::black;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBlanchedAlmond)
	{
		const auto lReturnColor = ofColor::blanchedAlmond;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBlue)
	{
		const auto lReturnColor = ofColor::blue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBlueSteel)
	{
		const auto lReturnColor = ofColor::blueSteel;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBlueViolet)
	{
		const auto lReturnColor = ofColor::blueViolet;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBrown)
	{
		const auto lReturnColor = ofColor::brown;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBurlyWood)
	{
		const auto lReturnColor = ofColor::burlyWood;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetCadetBlue)
	{
		const auto lReturnColor = ofColor::cadetBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetChartreuse)
	{
		const auto lReturnColor = ofColor::chartreuse;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetChocolate)
	{
		const auto lReturnColor = ofColor::chocolate;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetCoral)
	{
		const auto lReturnColor = ofColor::coral;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetCornflowerBlue)
	{
		const auto lReturnColor = ofColor::cornflowerBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetCornsilk)
	{
		const auto lReturnColor = ofColor::cornsilk;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetCrimson)
	{
		const auto lReturnColor = ofColor::crimson;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetCyan)
	{
		const auto lReturnColor = ofColor::cyan;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkBlue)
	{
		const auto lReturnColor = ofColor::darkBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkCyan)
	{
		const auto lReturnColor = ofColor::darkCyan;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkGoldenRod)
	{
		const auto lReturnColor = ofColor::darkGoldenRod;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkGray)
	{
		const auto lReturnColor = ofColor::darkGray;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkGreen)
	{
		const auto lReturnColor = ofColor::darkGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkGrey)
	{
		const auto lReturnColor = ofColor::darkGrey;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkKhaki)
	{
		const auto lReturnColor = ofColor::darkKhaki;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkMagenta)
	{
		const auto lReturnColor = ofColor::darkMagenta;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkOliveGreen)
	{
		const auto lReturnColor = ofColor::darkOliveGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkOrchid)
	{
		const auto lReturnColor = ofColor::darkOrchid;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkRed)
	{
		const auto lReturnColor = ofColor::darkRed;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkSalmon)
	{
		const auto lReturnColor = ofColor::darkSalmon;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkSeaGreen)
	{
		const auto lReturnColor = ofColor::darkSeaGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkSlateBlue)
	{
		const auto lReturnColor = ofColor::darkSlateBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkSlateGray)
	{
		const auto lReturnColor = ofColor::darkSlateGray;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkSlateGrey)
	{
		const auto lReturnColor = ofColor::darkSlateGrey;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkTurquoise)
	{
		const auto lReturnColor = ofColor::darkTurquoise;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkViolet)
	{
		const auto lReturnColor = ofColor::darkViolet;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkorange)
	{
		const auto lReturnColor = ofColor::darkorange;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDeepPink)
	{
		const auto lReturnColor = ofColor::deepPink;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDeepSkyBlue)
	{
		const auto lReturnColor = ofColor::deepSkyBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDimGray)
	{
		const auto lReturnColor = ofColor::dimGray;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDimGrey)
	{
		const auto lReturnColor = ofColor::dimGrey;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDodgerBlue)
	{
		const auto lReturnColor = ofColor::dodgerBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetFireBrick)
	{
		const auto lReturnColor = ofColor::fireBrick;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetFloralWhite)
	{
		const auto lReturnColor = ofColor::floralWhite;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetForestGreen)
	{
		const auto lReturnColor = ofColor::forestGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetFuchsia)
	{
		const auto lReturnColor = ofColor::fuchsia;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGainsboro)
	{
		const auto lReturnColor = ofColor::gainsboro;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGhostWhite)
	{
		const auto lReturnColor = ofColor::ghostWhite;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGold)
	{
		const auto lReturnColor = ofColor::gold;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGoldenRod)
	{
		const auto lReturnColor = ofColor::goldenRod;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGray)
	{
		const auto lReturnColor = ofColor::gray;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGreen)
	{
		const auto lReturnColor = ofColor::green;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGreenYellow)
	{
		const auto lReturnColor = ofColor::greenYellow;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGrey)
	{
		const auto lReturnColor = ofColor::grey;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetHoneyDew)
	{
		const auto lReturnColor = ofColor::honeyDew;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetHotPink)
	{
		const auto lReturnColor = ofColor::hotPink;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetIndianRed)
	{
		const auto lReturnColor = ofColor::indianRed;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetIndigo)
	{
		const auto lReturnColor = ofColor::indigo;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetIvory)
	{
		const auto lReturnColor = ofColor::ivory;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetKhaki)
	{
		const auto lReturnColor = ofColor::khaki;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLavender)
	{
		const auto lReturnColor = ofColor::lavender;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLavenderBlush)
	{
		const auto lReturnColor = ofColor::lavenderBlush;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLawnGreen)
	{
		const auto lReturnColor = ofColor::lawnGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLemonChiffon)
	{
		const auto lReturnColor = ofColor::lemonChiffon;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightBlue)
	{
		const auto lReturnColor = ofColor::lightBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightCoral)
	{
		const auto lReturnColor = ofColor::lightCoral;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightCyan)
	{
		const auto lReturnColor = ofColor::lightCyan;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightGoldenRodYellow)
	{
		const auto lReturnColor = ofColor::lightGoldenRodYellow;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightGray)
	{
		const auto lReturnColor = ofColor::lightGray;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightGreen)
	{
		const auto lReturnColor = ofColor::lightGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightGrey)
	{
		const auto lReturnColor = ofColor::lightGrey;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightPink)
	{
		const auto lReturnColor = ofColor::lightPink;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightSalmon)
	{
		const auto lReturnColor = ofColor::lightSalmon;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightSeaGreen)
	{
		const auto lReturnColor = ofColor::lightSeaGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightSkyBlue)
	{
		const auto lReturnColor = ofColor::lightSkyBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightSlateGray)
	{
		const auto lReturnColor = ofColor::lightSlateGray;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightSlateGrey)
	{
		const auto lReturnColor = ofColor::lightSlateGrey;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightSteelBlue)
	{
		const auto lReturnColor = ofColor::lightSteelBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightYellow)
	{
		const auto lReturnColor = ofColor::lightYellow;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLime)
	{
		const auto lReturnColor = ofColor::lime;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLimeGreen)
	{
		const auto lReturnColor = ofColor::limeGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLinen)
	{
		const auto lReturnColor = ofColor::linen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMagenta)
	{
		const auto lReturnColor = ofColor::magenta;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMaroon)
	{
		const auto lReturnColor = ofColor::maroon;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumAquaMarine)
	{
		const auto lReturnColor = ofColor::mediumAquaMarine;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumBlue)
	{
		const auto lReturnColor = ofColor::mediumBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumOrchid)
	{
		const auto lReturnColor = ofColor::mediumOrchid;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumPurple)
	{
		const auto lReturnColor = ofColor::mediumPurple;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumSeaGreen)
	{
		const auto lReturnColor = ofColor::mediumSeaGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumSlateBlue)
	{
		const auto lReturnColor = ofColor::mediumSlateBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumSpringGreen)
	{
		const auto lReturnColor = ofColor::mediumSpringGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumTurquoise)
	{
		const auto lReturnColor = ofColor::mediumTurquoise;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumVioletRed)
	{
		const auto lReturnColor = ofColor::mediumVioletRed;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMidnightBlue)
	{
		const auto lReturnColor = ofColor::midnightBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMintCream)
	{
		const auto lReturnColor = ofColor::mintCream;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMistyRose)
	{
		const auto lReturnColor = ofColor::mistyRose;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMoccasin)
	{
		const auto lReturnColor = ofColor::moccasin;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetNavajoWhite)
	{
		const auto lReturnColor = ofColor::navajoWhite;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetNavy)
	{
		const auto lReturnColor = ofColor::navy;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetOldLace)
	{
		const auto lReturnColor = ofColor::oldLace;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetOlive)
	{
		const auto lReturnColor = ofColor::olive;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetOliveDrab)
	{
		const auto lReturnColor = ofColor::oliveDrab;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetOrange)
	{
		const auto lReturnColor = ofColor::orange;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetOrangeRed)
	{
		const auto lReturnColor = ofColor::orangeRed;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetOrchid)
	{
		const auto lReturnColor = ofColor::orchid;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPaleGoldenRod)
	{
		const auto lReturnColor = ofColor::paleGoldenRod;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPaleGreen)
	{
		const auto lReturnColor = ofColor::paleGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPaleTurquoise)
	{
		const auto lReturnColor = ofColor::paleTurquoise;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPaleVioletRed)
	{
		const auto lReturnColor = ofColor::paleVioletRed;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPapayaWhip)
	{
		const auto lReturnColor = ofColor::papayaWhip;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPeachPuff)
	{
		const auto lReturnColor = ofColor::peachPuff;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPeru)
	{
		const auto lReturnColor = ofColor::peru;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPink)
	{
		const auto lReturnColor = ofColor::pink;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPlum)
	{
		const auto lReturnColor = ofColor::plum;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPowderBlue)
	{
		const auto lReturnColor = ofColor::powderBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPurple)
	{
		const auto lReturnColor = ofColor::purple;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetRed)
	{
		const auto lReturnColor = ofColor::red;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetRosyBrown)
	{
		const auto lReturnColor = ofColor::rosyBrown;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetRoyalBlue)
	{
		const auto lReturnColor = ofColor::royalBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSaddleBrown)
	{
		const auto lReturnColor = ofColor::saddleBrown;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSalmon)
	{
		const auto lReturnColor = ofColor::salmon;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSandyBrown)
	{
		const auto lReturnColor = ofColor::sandyBrown;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSeaGreen)
	{
		const auto lReturnColor = ofColor::seaGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSeaShell)
	{
		const auto lReturnColor = ofColor::seaShell;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSienna)
	{
		const auto lReturnColor = ofColor::sienna;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSilver)
	{
		const auto lReturnColor = ofColor::silver;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSkyBlue)
	{
		const auto lReturnColor = ofColor::skyBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSlateBlue)
	{
		const auto lReturnColor = ofColor::slateBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSlateGray)
	{
		const auto lReturnColor = ofColor::slateGray;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSlateGrey)
	{
		const auto lReturnColor = ofColor::slateGrey;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSnow)
	{
		const auto lReturnColor = ofColor::snow;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSpringGreen)
	{
		const auto lReturnColor = ofColor::springGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSteelBlue)
	{
		const auto lReturnColor = ofColor::steelBlue;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetTan)
	{
		const auto lReturnColor = ofColor::tan;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetTeal)
	{
		const auto lReturnColor = ofColor::teal;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetThistle)
	{
		const auto lReturnColor = ofColor::thistle;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetTomato)
	{
		const auto lReturnColor = ofColor::tomato;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetTurquoise)
	{
		const auto lReturnColor = ofColor::turquoise;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetViolet)
	{
		const auto lReturnColor = ofColor::violet;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetWheat)
	{
		const auto lReturnColor = ofColor::wheat;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetWhite)
	{
		const auto lReturnColor = ofColor::white;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetWhiteSmoke)
	{
		const auto lReturnColor = ofColor::whiteSmoke;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetYellow)
	{
		const auto lReturnColor = ofColor::yellow;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetYellowGreen)
	{
		const auto lReturnColor = ofColor::yellowGreen;
		v8::Handle<v8::Value> lArgv[] = {
			NanNew(lReturnColor.r) ,
			NanNew(lReturnColor.g) ,
			NanNew(lReturnColor.b) ,
			NanNew(lReturnColor.a)
		};
		NanReturnValue(NanNew(constructor)->CallAsConstructor(4, lArgv));
	}

	NAN_METHOD(ofxNode_ofColor::SetSaturation)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.setSaturation(args[0]->NumberValue());
		NanReturnValue(args.This());
	}


	NAN_METHOD(ofxNode_ofColor::SetHue)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.setHue(args[0]->NumberValue());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::SetHueAngle)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.setHueAngle(args[0]->NumberValue());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::SetBrightness)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.setBrightness(args[0]->NumberValue());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::SetHex)
	{
		float alpha = ofColor::limit();
		if (!args[1]->IsUndefined())
		{
			alpha = args[1]->NumberValue();
		}
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.setHex(
			args[0]->NumberValue(),
			alpha);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::SetHsb)
	{
		float alpha = ofColor::limit();
		if (!args[3]->IsUndefined())
		{
			alpha = args[3]->NumberValue();
		}
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_.setHsb(
			args[0]->NumberValue(),
			args[1]->NumberValue(), 
			args[2]->NumberValue(),
			alpha);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::Set)
	{
		NanScope();
		auto self = node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->internal_;
		if (args.IsConstructCall()) {
			// Invoked as constructor: `new ofColor(...)`
			ofxNode_ofColor* obj;
			if (args.Length() >= 3)
			{
				float alpha = self.a;
				if(!args[3]->IsUndefined())
				{
					alpha = args[3]->NumberValue();
				}
				self.set(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]), alpha);
			}
			else if (args.Length() < 3 && args.Length() >= 1)
			{
				//void ofColor_::set(float gray, float alpha=limit())
				float alpha = self.a;
				if(!args[1]->IsUndefined())
				{
					alpha = args[1]->NumberValue();
				}
				self.set(V8_ARG_NUMBER(args[0]), alpha);
			}
			else
			{
				//copy constructor like a BOSS! This will also throw an exception if user is entering an "i dunno" color.
				self.set(ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->internal_);
			}
		}
		NanReturnValue(args.This());
	}
	
	NAN_METHOD(ofxNode_ofColor::New)
	{
		NanScope();
		if (args.IsConstructCall()) {
			// Invoked as constructor: `new ofColor(...)`
			ofxNode_ofColor* obj;
			if (args.Length() >= 3)
			{
				float alpha = ofColor::limit();
				if(!args[3]->IsUndefined())
				{
					alpha = args[3]->NumberValue();
				}
				ofColor lColor(V8_ARG_NUMBER(args[0]), V8_ARG_NUMBER(args[1]), V8_ARG_NUMBER(args[2]), alpha);
				obj = new ofxNode_ofColor(lColor);
			}
			else if (args.Length() < 3 && args.Length() >= 1)
			{
				//void ofColor_::set(float gray, float alpha=limit())
				float alpha = ofColor::limit();
				if(!args[1]->IsUndefined())
				{
					alpha = args[1]->NumberValue();
				}
				ofColor lColor(V8_ARG_NUMBER(args[0]), alpha);
				obj = new ofxNode_ofColor(lColor);
			}
			else
			{
				//copy constructor like a BOSS! This will also throw an exception if user is entering an "i dunno" color.
				obj = new ofxNode_ofColor(ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->internal_);
			}
			obj->Wrap(args.This());
			NanReturnValue(args.This());
		} else {
			// Invoked as plain function, forwarding to construct call.
			std::vector<v8::Handle<v8::Value>> lArgvVec;
			for (int i = 0; i < args.Length(); ++i) {lArgvVec.push_back(args[i]);}
			NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(lArgvVec.size(), &lArgvVec[0]));
		}
	}

} // !namespace ofxNode
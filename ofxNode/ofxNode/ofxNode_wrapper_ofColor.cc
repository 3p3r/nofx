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
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::fromHex(args[0]->Uint32Value(), args[1]->IsUndefined() ? ofColor::limit() : args[1]->NumberValue());
		NanReturnValue(lToRet);
	}

	NAN_METHOD(ofxNode_ofColor::FromHsb)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::fromHsb(
			V8_ARG_NUMBER(args[0]),
			V8_ARG_NUMBER(args[1]),
			V8_ARG_NUMBER(args[2]),
			args[3]->IsUndefined() ? ofColor::limit() : args[1]->NumberValue());
		NanReturnValue(lToRet);
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
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().getClamped();
		NanReturnValue(lToRet);
	}

	NAN_METHOD(ofxNode_ofColor::Clamp)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().clamp();
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::GetSaturation)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().getSaturation()));
	}

	NAN_METHOD(ofxNode_ofColor::GetLightness)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().getLightness()));
	}

	NAN_METHOD(ofxNode_ofColor::GetHueAngle)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().getHueAngle()));
	}

	NAN_METHOD(ofxNode_ofColor::GetHue)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().getHue()));
	}

	NAN_METHOD(ofxNode_ofColor::GetHex)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().getHex()));
	}

	NAN_METHOD(ofxNode_ofColor::GetBrightness)
	{
		NanReturnValue(NanNew(node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().getBrightness()));
	}

	NAN_METHOD(ofxNode_ofColor::GetInverted)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().getInverted();
		NanReturnValue(lToRet);
	}
	
	NAN_METHOD(ofxNode_ofColor::Invert)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().invert();
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::GetLerped)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().getLerped(
			node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self(),
			args[1]->NumberValue()
			);
		NanReturnValue(lToRet);
	}

	NAN_METHOD(ofxNode_ofColor::Lerp)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().lerp(
			node::ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self(),
			args[1]->NumberValue()
			);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::Limit)
	{
		NanReturnValue(NanNew(ofColor::limit()));
	}

	NAN_METHOD(ofxNode_ofColor::Equals)
	{
		const auto& self = ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self();
		if (args[0]->IsArray())
		{
			bool result = true;
			bool ranAtLeastOnce = false;
			const auto lProps = args[0]->ToObject()->GetPropertyNames();
			for (int i = 0; i < lProps->Length(); ++i)
			{
				const auto lVal = args[0]->ToObject()->Get(i);

				if(lVal->ToObject()->Has(NanNew("OFXNODE_TYPE")) &&
					lVal->ToObject()->Get(NanNew("OFXNODE_TYPE"))->Uint32Value() == OFXNODE_TYPES::OFCOLOR)
				{
					ranAtLeastOnce = true;
					result = result && ((ofColor)self == (ofColor)ObjectWrap::Unwrap<ofxNode_ofColor>(lVal->ToObject())->self());
				}
			}

			NanReturnValue( (NanNew(result && ranAtLeastOnce)) );
		}
		else
		{
			const auto lArgVec = ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self();
			NanReturnValue( (NanNew((ofColor)self == (ofColor)lArgVec)) );
		}
	}

	NAN_METHOD(ofxNode_ofColor::Over)
	{
		const auto &self = ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self();
		const auto denom = ((args[0]->IsNumber()) ? args[0]->NumberValue() : ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self());
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = self / denom;
		NanReturnValue(lToRet);
	}

	NAN_METHOD(ofxNode_ofColor::Times)
	{
		const auto &self = ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self();
		const auto coeff = ((args[0]->IsNumber()) ? args[0]->NumberValue() : ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self());
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = self * coeff;
		NanReturnValue(lToRet);
	}

	NAN_METHOD(ofxNode_ofColor::Minus)
	{
		const auto &self = ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self();
		const auto rhs = ((args[0]->IsNumber()) ? args[0]->NumberValue() : ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self());
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = self - rhs;
		NanReturnValue(lToRet);
	}

	NAN_METHOD(ofxNode_ofColor::Plus)
	{
		const auto &self = ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self();
		const auto rhs = ((args[0]->IsNumber()) ? args[0]->NumberValue() : ObjectWrap::Unwrap<ofxNode_ofColor>(args[0]->ToObject())->self());
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = self + rhs;
		NanReturnValue(lToRet);
	}

	NAN_METHOD(ofxNode_ofColor::ToString)
	{
		const auto &self = ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self();
		std::ostringstream out;
		out << self;
		NanReturnValue( NanNew(out.str().c_str()) );
	}


	//------------------------------------------------------- Auto generated const color getters

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetAliceBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::aliceBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetAntiqueWhite)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::antiqueWhite;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetAqua)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::aqua;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetAquamarine)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::aquamarine;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetAzure)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::azure;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBeige)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::beige;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBisque)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::bisque;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBlack)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::black;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBlanchedAlmond)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::blanchedAlmond;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::blue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBlueSteel)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::blueSteel;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBlueViolet)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::blueViolet;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBrown)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::brown;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetBurlyWood)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::burlyWood;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetCadetBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::cadetBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetChartreuse)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::chartreuse;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetChocolate)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::chocolate;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetCoral)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::coral;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetCornflowerBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::cornflowerBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetCornsilk)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::cornsilk;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetCrimson)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::crimson;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetCyan)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::cyan;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkCyan)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkCyan;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkGoldenRod)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkGoldenRod;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkGray)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkGray;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkGrey)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkGrey;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkKhaki)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkKhaki;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkMagenta)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkMagenta;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkOliveGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkOliveGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkOrchid)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkOrchid;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkRed)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkRed;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkSalmon)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkSalmon;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkSeaGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkSeaGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkSlateBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkSlateBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkSlateGray)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkSlateGray;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkSlateGrey)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkSlateGrey;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkTurquoise)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkTurquoise;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkViolet)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkViolet;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDarkorange)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::darkorange;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDeepPink)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::deepPink;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDeepSkyBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::deepSkyBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDimGray)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::dimGray;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDimGrey)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::dimGrey;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetDodgerBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::dodgerBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetFireBrick)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::fireBrick;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetFloralWhite)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::floralWhite;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetForestGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::forestGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetFuchsia)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::fuchsia;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGainsboro)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::gainsboro;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGhostWhite)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::ghostWhite;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGold)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::gold;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGoldenRod)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::goldenRod;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGray)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::gray;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::green;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGreenYellow)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::greenYellow;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetGrey)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::grey;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetHoneyDew)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::honeyDew;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetHotPink)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::hotPink;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetIndianRed)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::indianRed;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetIndigo)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::indigo;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetIvory)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::ivory;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetKhaki)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::khaki;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLavender)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lavender;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLavenderBlush)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lavenderBlush;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLawnGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lawnGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLemonChiffon)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lemonChiffon;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightCoral)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightCoral;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightCyan)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightCyan;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightGoldenRodYellow)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightGoldenRodYellow;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightGray)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightGray;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightGrey)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightGrey;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightPink)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightPink;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightSalmon)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightSalmon;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightSeaGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightSeaGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightSkyBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightSkyBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightSlateGray)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightSlateGray;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightSlateGrey)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightSlateGrey;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightSteelBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightSteelBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLightYellow)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lightYellow;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLime)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::lime;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLimeGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::limeGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetLinen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::linen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMagenta)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::magenta;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMaroon)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::maroon;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumAquaMarine)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::mediumAquaMarine;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::mediumBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumOrchid)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::mediumOrchid;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumPurple)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::mediumPurple;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumSeaGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::mediumSeaGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumSlateBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::mediumSlateBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumSpringGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::mediumSpringGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumTurquoise)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::mediumTurquoise;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMediumVioletRed)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::mediumVioletRed;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMidnightBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::midnightBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMintCream)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::mintCream;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMistyRose)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::mistyRose;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetMoccasin)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::moccasin;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetNavajoWhite)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::navajoWhite;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetNavy)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::navy;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetOldLace)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::oldLace;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetOlive)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::olive;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetOliveDrab)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::oliveDrab;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetOrange)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::orange;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetOrangeRed)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::orangeRed;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetOrchid)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::orchid;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPaleGoldenRod)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::paleGoldenRod;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPaleGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::paleGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPaleTurquoise)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::paleTurquoise;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPaleVioletRed)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::paleVioletRed;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPapayaWhip)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::papayaWhip;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPeachPuff)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::peachPuff;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPeru)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::peru;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPink)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::pink;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPlum)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::plum;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPowderBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::powderBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetPurple)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::purple;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetRed)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::red;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetRosyBrown)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::rosyBrown;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetRoyalBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::royalBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSaddleBrown)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::saddleBrown;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSalmon)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::salmon;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSandyBrown)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::sandyBrown;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSeaGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::seaGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSeaShell)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::seaShell;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSienna)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::sienna;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSilver)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::silver;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSkyBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::skyBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSlateBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::slateBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSlateGray)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::slateGray;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSlateGrey)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::slateGrey;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSnow)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::snow;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSpringGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::springGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetSteelBlue)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::steelBlue;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetTan)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::tan;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetTeal)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::teal;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetThistle)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::thistle;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetTomato)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::tomato;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetTurquoise)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::turquoise;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetViolet)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::violet;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetWheat)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::wheat;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetWhite)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::white;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetWhiteSmoke)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::whiteSmoke;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetYellow)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::yellow;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_PROPERTY_GETTER(ofxNode_ofColor::GetYellowGreen)
	{
		auto lToRet = NanNew(constructor)->NewInstance();
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(lToRet)->self() = ofColor::yellowGreen;
		NanReturnValue(lToRet);
	}
	//-------------------------------------------------------

	NAN_METHOD(ofxNode_ofColor::SetSaturation)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().setSaturation(args[0]->NumberValue());
		NanReturnValue(args.This());
	}


	NAN_METHOD(ofxNode_ofColor::SetHue)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().setHue(args[0]->NumberValue());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::SetHueAngle)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().setHueAngle(args[0]->NumberValue());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::SetBrightness)
	{
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().setBrightness(args[0]->NumberValue());
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::SetHex)
	{
		float alpha = ofColor::limit();
		if (!args[1]->IsUndefined())
		{
			alpha = args[1]->NumberValue();
		}
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().setHex(
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
		node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self().setHsb(
			args[0]->NumberValue(),
			args[1]->NumberValue(), 
			args[2]->NumberValue(),
			alpha);
		NanReturnValue(args.This());
	}

	NAN_METHOD(ofxNode_ofColor::Set)
	{
		auto &self = node::ObjectWrap::Unwrap<ofxNode_ofColor>(args.This())->self();
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
		NanReturnValue(args.This());
	}
	
	NAN_METHOD(ofxNode_ofColor::New)
	{
		if (args.IsConstructCall()) {
			// Invoked as constructor: `new ofColor(...)`
			ofxNode_ofColor* obj;
			if (args.Length() == 0)
			{
				//This is called by NewInstance method on constructors. We'll return a mock color to play with
				obj = new ofxNode_ofColor(ofColor());
			}
			else if (args.Length() >= 3)
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
			NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(lArgvVec.size(), (lArgvVec.size()==0)? nullptr: &lArgvVec[0]));
		}
	}

} // !namespace ofxNode
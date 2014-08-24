#include "nofx_ofColor.h"
#include "..\nofx\nofx_types.h"

namespace nofx
{
	namespace OfColor
	{
		using node::ObjectWrap;

		Persistent<Function> OfColorWrap::constructor;

		//--------------------------------------------------------------
		NAN_METHOD(OfColorWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfColorWrap* obj;
				if (args[0]->IsNull())
				{
					obj = new OfColorWrap(nullptr);
				}
				else if (args.Length() == 0)
				{
					//This is called by NewInstance method on constructors. We'll return a mock color to play with
					obj = new OfColorWrap(new ofColor());
				}
				else if (args.Length() >= 3)
				{
					float alpha = ofColor::limit();
					if (!args[3]->IsUndefined())
					{
						alpha = args[3]->NumberValue();
					}
					obj = new OfColorWrap(new ofColor(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), alpha));
				}
				else if (args.Length() < 3 && args.Length() >= 1)
				{
					float alpha = ofColor::limit();
					if (!args[1]->IsUndefined())
					{
						alpha = args[1]->NumberValue();
					}
					obj = new OfColorWrap(new ofColor(args[0]->NumberValue(), alpha));
				}
				else
				{
					//copy constructor
					obj = new OfColorWrap(ObjectWrap::Unwrap<OfColorWrap>(args[0]->ToObject())->GetWrapped());
				}
				obj->Wrap(args.This());
				NanReturnValue(args.This());
			}
			else
			{
				// Invoked as plain function `MyObject(...)`, turn into construct call.
				std::vector<v8::Handle<v8::Value>> lArgvVec;
				for (int i = 0; i < args.Length(); ++i) { lArgvVec.push_back(args[i]); }
				NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(lArgvVec.size(), (lArgvVec.size() == 0) ? nullptr : &lArgvVec[0]));
			}
		}

		//--------------------------------------------------------------
		void OfColorWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofColor"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);

			inst->SetAccessor(NanNew("a"), OfColorWrap::GetA, OfColorWrap::SetA);
			inst->SetAccessor(NanNew("b"), OfColorWrap::GetB, OfColorWrap::SetB);
			inst->SetAccessor(NanNew("g"), OfColorWrap::GetG, OfColorWrap::SetG);
			inst->SetAccessor(NanNew("r"), OfColorWrap::GetR, OfColorWrap::SetR);

			// Prototype
			auto proto = tpl->PrototypeTemplate();

			proto->SetAccessor(NanNew<v8::String>("aliceBlue"), OfColorWrap::GetAliceBlue);
			proto->SetAccessor(NanNew<v8::String>("antiqueWhite"), OfColorWrap::GetAntiqueWhite);
			proto->SetAccessor(NanNew<v8::String>("aqua"), OfColorWrap::GetAqua);
			proto->SetAccessor(NanNew<v8::String>("aquamarine"), OfColorWrap::GetAquamarine);
			proto->SetAccessor(NanNew<v8::String>("azure"), OfColorWrap::GetAzure);
			proto->SetAccessor(NanNew<v8::String>("beige"), OfColorWrap::GetBeige);
			proto->SetAccessor(NanNew<v8::String>("bisque"), OfColorWrap::GetBisque);
			proto->SetAccessor(NanNew<v8::String>("black"), OfColorWrap::GetBlack);
			proto->SetAccessor(NanNew<v8::String>("blanchedAlmond"), OfColorWrap::GetBlanchedAlmond);
			proto->SetAccessor(NanNew<v8::String>("blue"), OfColorWrap::GetBlue);
			proto->SetAccessor(NanNew<v8::String>("blueSteel"), OfColorWrap::GetBlueSteel);
			proto->SetAccessor(NanNew<v8::String>("blueViolet"), OfColorWrap::GetBlueViolet);
			proto->SetAccessor(NanNew<v8::String>("brown"), OfColorWrap::GetBrown);
			proto->SetAccessor(NanNew<v8::String>("burlyWood"), OfColorWrap::GetBurlyWood);
			proto->SetAccessor(NanNew<v8::String>("cadetBlue"), OfColorWrap::GetCadetBlue);
			proto->SetAccessor(NanNew<v8::String>("chartreuse"), OfColorWrap::GetChartreuse);
			proto->SetAccessor(NanNew<v8::String>("chocolate"), OfColorWrap::GetChocolate);
			proto->SetAccessor(NanNew<v8::String>("coral"), OfColorWrap::GetCoral);
			proto->SetAccessor(NanNew<v8::String>("cornflowerBlue"), OfColorWrap::GetCornflowerBlue);
			proto->SetAccessor(NanNew<v8::String>("cornsilk"), OfColorWrap::GetCornsilk);
			proto->SetAccessor(NanNew<v8::String>("crimson"), OfColorWrap::GetCrimson);
			proto->SetAccessor(NanNew<v8::String>("cyan"), OfColorWrap::GetCyan);
			proto->SetAccessor(NanNew<v8::String>("darkBlue"), OfColorWrap::GetDarkBlue);
			proto->SetAccessor(NanNew<v8::String>("darkCyan"), OfColorWrap::GetDarkCyan);
			proto->SetAccessor(NanNew<v8::String>("darkGoldenRod"), OfColorWrap::GetDarkGoldenRod);
			proto->SetAccessor(NanNew<v8::String>("darkGray"), OfColorWrap::GetDarkGray);
			proto->SetAccessor(NanNew<v8::String>("darkGreen"), OfColorWrap::GetDarkGreen);
			proto->SetAccessor(NanNew<v8::String>("darkGrey"), OfColorWrap::GetDarkGrey);
			proto->SetAccessor(NanNew<v8::String>("darkKhaki"), OfColorWrap::GetDarkKhaki);
			proto->SetAccessor(NanNew<v8::String>("darkMagenta"), OfColorWrap::GetDarkMagenta);
			proto->SetAccessor(NanNew<v8::String>("darkOliveGreen"), OfColorWrap::GetDarkOliveGreen);
			proto->SetAccessor(NanNew<v8::String>("darkOrchid"), OfColorWrap::GetDarkOrchid);
			proto->SetAccessor(NanNew<v8::String>("darkRed"), OfColorWrap::GetDarkRed);
			proto->SetAccessor(NanNew<v8::String>("darkSalmon"), OfColorWrap::GetDarkSalmon);
			proto->SetAccessor(NanNew<v8::String>("darkSeaGreen"), OfColorWrap::GetDarkSeaGreen);
			proto->SetAccessor(NanNew<v8::String>("darkSlateBlue"), OfColorWrap::GetDarkSlateBlue);
			proto->SetAccessor(NanNew<v8::String>("darkSlateGray"), OfColorWrap::GetDarkSlateGray);
			proto->SetAccessor(NanNew<v8::String>("darkSlateGrey"), OfColorWrap::GetDarkSlateGrey);
			proto->SetAccessor(NanNew<v8::String>("darkTurquoise"), OfColorWrap::GetDarkTurquoise);
			proto->SetAccessor(NanNew<v8::String>("darkViolet"), OfColorWrap::GetDarkViolet);
			proto->SetAccessor(NanNew<v8::String>("darkorange"), OfColorWrap::GetDarkorange);
			proto->SetAccessor(NanNew<v8::String>("deepPink"), OfColorWrap::GetDeepPink);
			proto->SetAccessor(NanNew<v8::String>("deepSkyBlue"), OfColorWrap::GetDeepSkyBlue);
			proto->SetAccessor(NanNew<v8::String>("dimGray"), OfColorWrap::GetDimGray);
			proto->SetAccessor(NanNew<v8::String>("dimGrey"), OfColorWrap::GetDimGrey);
			proto->SetAccessor(NanNew<v8::String>("dodgerBlue"), OfColorWrap::GetDodgerBlue);
			proto->SetAccessor(NanNew<v8::String>("fireBrick"), OfColorWrap::GetFireBrick);
			proto->SetAccessor(NanNew<v8::String>("floralWhite"), OfColorWrap::GetFloralWhite);
			proto->SetAccessor(NanNew<v8::String>("forestGreen"), OfColorWrap::GetForestGreen);
			proto->SetAccessor(NanNew<v8::String>("fuchsia"), OfColorWrap::GetFuchsia);
			proto->SetAccessor(NanNew<v8::String>("gainsboro"), OfColorWrap::GetGainsboro);
			proto->SetAccessor(NanNew<v8::String>("ghostWhite"), OfColorWrap::GetGhostWhite);
			proto->SetAccessor(NanNew<v8::String>("gold"), OfColorWrap::GetGold);
			proto->SetAccessor(NanNew<v8::String>("goldenRod"), OfColorWrap::GetGoldenRod);
			proto->SetAccessor(NanNew<v8::String>("gray"), OfColorWrap::GetGray);
			proto->SetAccessor(NanNew<v8::String>("green"), OfColorWrap::GetGreen);
			proto->SetAccessor(NanNew<v8::String>("greenYellow"), OfColorWrap::GetGreenYellow);
			proto->SetAccessor(NanNew<v8::String>("grey"), OfColorWrap::GetGrey);
			proto->SetAccessor(NanNew<v8::String>("honeyDew"), OfColorWrap::GetHoneyDew);
			proto->SetAccessor(NanNew<v8::String>("hotPink"), OfColorWrap::GetHotPink);
			proto->SetAccessor(NanNew<v8::String>("indianRed"), OfColorWrap::GetIndianRed);
			proto->SetAccessor(NanNew<v8::String>("indigo"), OfColorWrap::GetIndigo);
			proto->SetAccessor(NanNew<v8::String>("ivory"), OfColorWrap::GetIvory);
			proto->SetAccessor(NanNew<v8::String>("khaki"), OfColorWrap::GetKhaki);
			proto->SetAccessor(NanNew<v8::String>("lavender"), OfColorWrap::GetLavender);
			proto->SetAccessor(NanNew<v8::String>("lavenderBlush"), OfColorWrap::GetLavenderBlush);
			proto->SetAccessor(NanNew<v8::String>("lawnGreen"), OfColorWrap::GetLawnGreen);
			proto->SetAccessor(NanNew<v8::String>("lemonChiffon"), OfColorWrap::GetLemonChiffon);
			proto->SetAccessor(NanNew<v8::String>("lightBlue"), OfColorWrap::GetLightBlue);
			proto->SetAccessor(NanNew<v8::String>("lightCoral"), OfColorWrap::GetLightCoral);
			proto->SetAccessor(NanNew<v8::String>("lightCyan"), OfColorWrap::GetLightCyan);
			proto->SetAccessor(NanNew<v8::String>("lightGoldenRodYellow"), OfColorWrap::GetLightGoldenRodYellow);
			proto->SetAccessor(NanNew<v8::String>("lightGray"), OfColorWrap::GetLightGray);
			proto->SetAccessor(NanNew<v8::String>("lightGreen"), OfColorWrap::GetLightGreen);
			proto->SetAccessor(NanNew<v8::String>("lightGrey"), OfColorWrap::GetLightGrey);
			proto->SetAccessor(NanNew<v8::String>("lightPink"), OfColorWrap::GetLightPink);
			proto->SetAccessor(NanNew<v8::String>("lightSalmon"), OfColorWrap::GetLightSalmon);
			proto->SetAccessor(NanNew<v8::String>("lightSeaGreen"), OfColorWrap::GetLightSeaGreen);
			proto->SetAccessor(NanNew<v8::String>("lightSkyBlue"), OfColorWrap::GetLightSkyBlue);
			proto->SetAccessor(NanNew<v8::String>("lightSlateGray"), OfColorWrap::GetLightSlateGray);
			proto->SetAccessor(NanNew<v8::String>("lightSlateGrey"), OfColorWrap::GetLightSlateGrey);
			proto->SetAccessor(NanNew<v8::String>("lightSteelBlue"), OfColorWrap::GetLightSteelBlue);
			proto->SetAccessor(NanNew<v8::String>("lightYellow"), OfColorWrap::GetLightYellow);
			proto->SetAccessor(NanNew<v8::String>("lime"), OfColorWrap::GetLime);
			proto->SetAccessor(NanNew<v8::String>("limeGreen"), OfColorWrap::GetLimeGreen);
			proto->SetAccessor(NanNew<v8::String>("linen"), OfColorWrap::GetLinen);
			proto->SetAccessor(NanNew<v8::String>("magenta"), OfColorWrap::GetMagenta);
			proto->SetAccessor(NanNew<v8::String>("maroon"), OfColorWrap::GetMaroon);
			proto->SetAccessor(NanNew<v8::String>("mediumAquaMarine"), OfColorWrap::GetMediumAquaMarine);
			proto->SetAccessor(NanNew<v8::String>("mediumBlue"), OfColorWrap::GetMediumBlue);
			proto->SetAccessor(NanNew<v8::String>("mediumOrchid"), OfColorWrap::GetMediumOrchid);
			proto->SetAccessor(NanNew<v8::String>("mediumPurple"), OfColorWrap::GetMediumPurple);
			proto->SetAccessor(NanNew<v8::String>("mediumSeaGreen"), OfColorWrap::GetMediumSeaGreen);
			proto->SetAccessor(NanNew<v8::String>("mediumSlateBlue"), OfColorWrap::GetMediumSlateBlue);
			proto->SetAccessor(NanNew<v8::String>("mediumSpringGreen"), OfColorWrap::GetMediumSpringGreen);
			proto->SetAccessor(NanNew<v8::String>("mediumTurquoise"), OfColorWrap::GetMediumTurquoise);
			proto->SetAccessor(NanNew<v8::String>("mediumVioletRed"), OfColorWrap::GetMediumVioletRed);
			proto->SetAccessor(NanNew<v8::String>("midnightBlue"), OfColorWrap::GetMidnightBlue);
			proto->SetAccessor(NanNew<v8::String>("mintCream"), OfColorWrap::GetMintCream);
			proto->SetAccessor(NanNew<v8::String>("mistyRose"), OfColorWrap::GetMistyRose);
			proto->SetAccessor(NanNew<v8::String>("moccasin"), OfColorWrap::GetMoccasin);
			proto->SetAccessor(NanNew<v8::String>("navajoWhite"), OfColorWrap::GetNavajoWhite);
			proto->SetAccessor(NanNew<v8::String>("navy"), OfColorWrap::GetNavy);
			proto->SetAccessor(NanNew<v8::String>("oldLace"), OfColorWrap::GetOldLace);
			proto->SetAccessor(NanNew<v8::String>("olive"), OfColorWrap::GetOlive);
			proto->SetAccessor(NanNew<v8::String>("oliveDrab"), OfColorWrap::GetOliveDrab);
			proto->SetAccessor(NanNew<v8::String>("orange"), OfColorWrap::GetOrange);
			proto->SetAccessor(NanNew<v8::String>("orangeRed"), OfColorWrap::GetOrangeRed);
			proto->SetAccessor(NanNew<v8::String>("orchid"), OfColorWrap::GetOrchid);
			proto->SetAccessor(NanNew<v8::String>("paleGoldenRod"), OfColorWrap::GetPaleGoldenRod);
			proto->SetAccessor(NanNew<v8::String>("paleGreen"), OfColorWrap::GetPaleGreen);
			proto->SetAccessor(NanNew<v8::String>("paleTurquoise"), OfColorWrap::GetPaleTurquoise);
			proto->SetAccessor(NanNew<v8::String>("paleVioletRed"), OfColorWrap::GetPaleVioletRed);
			proto->SetAccessor(NanNew<v8::String>("papayaWhip"), OfColorWrap::GetPapayaWhip);
			proto->SetAccessor(NanNew<v8::String>("peachPuff"), OfColorWrap::GetPeachPuff);
			proto->SetAccessor(NanNew<v8::String>("peru"), OfColorWrap::GetPeru);
			proto->SetAccessor(NanNew<v8::String>("pink"), OfColorWrap::GetPink);
			proto->SetAccessor(NanNew<v8::String>("plum"), OfColorWrap::GetPlum);
			proto->SetAccessor(NanNew<v8::String>("powderBlue"), OfColorWrap::GetPowderBlue);
			proto->SetAccessor(NanNew<v8::String>("purple"), OfColorWrap::GetPurple);
			proto->SetAccessor(NanNew<v8::String>("red"), OfColorWrap::GetRed);
			proto->SetAccessor(NanNew<v8::String>("rosyBrown"), OfColorWrap::GetRosyBrown);
			proto->SetAccessor(NanNew<v8::String>("royalBlue"), OfColorWrap::GetRoyalBlue);
			proto->SetAccessor(NanNew<v8::String>("saddleBrown"), OfColorWrap::GetSaddleBrown);
			proto->SetAccessor(NanNew<v8::String>("salmon"), OfColorWrap::GetSalmon);
			proto->SetAccessor(NanNew<v8::String>("sandyBrown"), OfColorWrap::GetSandyBrown);
			proto->SetAccessor(NanNew<v8::String>("seaGreen"), OfColorWrap::GetSeaGreen);
			proto->SetAccessor(NanNew<v8::String>("seaShell"), OfColorWrap::GetSeaShell);
			proto->SetAccessor(NanNew<v8::String>("sienna"), OfColorWrap::GetSienna);
			proto->SetAccessor(NanNew<v8::String>("silver"), OfColorWrap::GetSilver);
			proto->SetAccessor(NanNew<v8::String>("skyBlue"), OfColorWrap::GetSkyBlue);
			proto->SetAccessor(NanNew<v8::String>("slateBlue"), OfColorWrap::GetSlateBlue);
			proto->SetAccessor(NanNew<v8::String>("slateGray"), OfColorWrap::GetSlateGray);
			proto->SetAccessor(NanNew<v8::String>("slateGrey"), OfColorWrap::GetSlateGrey);
			proto->SetAccessor(NanNew<v8::String>("snow"), OfColorWrap::GetSnow);
			proto->SetAccessor(NanNew<v8::String>("springGreen"), OfColorWrap::GetSpringGreen);
			proto->SetAccessor(NanNew<v8::String>("steelBlue"), OfColorWrap::GetSteelBlue);
			proto->SetAccessor(NanNew<v8::String>("tan"), OfColorWrap::GetTan);
			proto->SetAccessor(NanNew<v8::String>("teal"), OfColorWrap::GetTeal);
			proto->SetAccessor(NanNew<v8::String>("thistle"), OfColorWrap::GetThistle);
			proto->SetAccessor(NanNew<v8::String>("tomato"), OfColorWrap::GetTomato);
			proto->SetAccessor(NanNew<v8::String>("turquoise"), OfColorWrap::GetTurquoise);
			proto->SetAccessor(NanNew<v8::String>("violet"), OfColorWrap::GetViolet);
			proto->SetAccessor(NanNew<v8::String>("wheat"), OfColorWrap::GetWheat);
			proto->SetAccessor(NanNew<v8::String>("white"), OfColorWrap::GetWhite);
			proto->SetAccessor(NanNew<v8::String>("whiteSmoke"), OfColorWrap::GetWhiteSmoke);
			proto->SetAccessor(NanNew<v8::String>("yellow"), OfColorWrap::GetYellow);
			proto->SetAccessor(NanNew<v8::String>("yellowGreen"), OfColorWrap::GetYellowGreen);

			NanSetPrototypeTemplate(tpl, NanNew("clamp"), NanNew<v8::FunctionTemplate>(Clamp), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("fromHex"), NanNew<v8::FunctionTemplate>(FromHex), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("fromHsb"), NanNew<v8::FunctionTemplate>(FromHsb), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getBrightness"), NanNew<v8::FunctionTemplate>(GetBrightness), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getClamped"), NanNew<v8::FunctionTemplate>(GetClamped), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getHex"), NanNew<v8::FunctionTemplate>(GetHex), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getHsb"), NanNew<v8::FunctionTemplate>(GetHsb), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getHue"), NanNew<v8::FunctionTemplate>(GetHue), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getHueAngle"), NanNew<v8::FunctionTemplate>(GetHueAngle), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getInverted"), NanNew<v8::FunctionTemplate>(GetInverted), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getLerped"), NanNew<v8::FunctionTemplate>(GetLerped), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getLightness"), NanNew<v8::FunctionTemplate>(GetLightness), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getSaturation"), NanNew<v8::FunctionTemplate>(GetSaturation), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("invert"), NanNew<v8::FunctionTemplate>(Invert), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("lerp"), NanNew<v8::FunctionTemplate>(Lerp), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("limit"), NanNew<v8::FunctionTemplate>(Limit), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("set"), NanNew<v8::FunctionTemplate>(Set), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setBrightness"), NanNew<v8::FunctionTemplate>(SetBrightness), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setHex"), NanNew<v8::FunctionTemplate>(SetHex), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setHsb"), NanNew<v8::FunctionTemplate>(SetHsb), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setHue"), NanNew<v8::FunctionTemplate>(SetHue), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setHueAngle"), NanNew<v8::FunctionTemplate>(SetHueAngle), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("setSaturation"), NanNew<v8::FunctionTemplate>(SetSaturation), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFCOLOR), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofColor"), tpl->GetFunction());
		}


		NAN_GETTER(OfColorWrap::GetA)
		{
			const auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			NanReturnValue(self->a);
		}
		//----------------------------------------------------

		NAN_GETTER(OfColorWrap::GetB)
		{
			const auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			NanReturnValue(self->b);
		}
		//----------------------------------------------------

		NAN_GETTER(OfColorWrap::GetG)
		{
			const auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			NanReturnValue(self->g);
		}
		//----------------------------------------------------

		NAN_GETTER(OfColorWrap::GetR)
		{
			const auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			NanReturnValue(self->r);
		}
		//----------------------------------------------------


		NAN_SETTER(OfColorWrap::SetA)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			self->a = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfColorWrap::SetB)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			self->b = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfColorWrap::SetG)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			self->g = value->NumberValue();
		}
		//----------------------------------------------------

		NAN_SETTER(OfColorWrap::SetR)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			self->r = value->NumberValue();
		}
		//----------------------------------------------------


		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::Clamp)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			self->clamp();
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::FromHex)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(ofColor::fromHex(args[0]->Uint32Value(), args[1]->IsUndefined() ? ofColor::limit() : args[1]->NumberValue()));
			NanReturnValue(lToRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::FromHsb)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(ofColor::fromHsb(
				args[0]->NumberValue(),
				args[1]->NumberValue(),
				args[2]->NumberValue(),
				args[3]->IsUndefined() ? ofColor::limit() : args[1]->NumberValue()));
			NanReturnValue(lToRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::GetBrightness)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getBrightness());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::GetClamped)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			auto lToRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(self->getClamped());
			NanReturnValue(lToRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::GetHex)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getHex());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::GetHsb)
		{
			float hue = 0, saturation = 0, brightness = 0;
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			self->getHsb(hue, saturation, brightness);
			auto toRet = NanNew<Object>();
			toRet->Set(NanNew("hue"), NanNew(hue));
			toRet->Set(NanNew("saturation"), NanNew(saturation));
			toRet->Set(NanNew("brightness"), NanNew(brightness));
			NanReturnValue(toRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::GetHue)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getHue());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::GetHueAngle)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getHueAngle());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::GetInverted)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			auto lToRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(self->getInverted());
			NanReturnValue(lToRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::GetLerped)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			auto lToRet = NanNew(Factory())->NewInstance();
			ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(self->getLerped(
				*ObjectWrap::Unwrap<OfColorWrap>(args[0]->ToObject())->GetWrapped(),
				args[1]->NumberValue()
				));
			NanReturnValue(lToRet);
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::GetLightness)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getLightness());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::GetSaturation)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			NanReturnValue(self->getSaturation());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::Invert)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			self->invert();
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::Lerp)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			self->lerp(*ObjectWrap::Unwrap<OfColorWrap>(args[0]->ToObject())->GetWrapped(),
				args[1]->NumberValue());
			NanReturnValue(args.This());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::Limit)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			NanReturnValue(ofColor::limit());
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::Set)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			if (args.Length() >= 3)
			{
				float alpha = self->a;
				if (!args[3]->IsUndefined())
				{
					alpha = args[3]->NumberValue();
				}
				self->set(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), alpha);
			}
			else if (args.Length() < 3 && args.Length() >= 1)
			{
				float alpha = self->a;
				if (!args[1]->IsUndefined())
				{
					alpha = args[1]->NumberValue();
				}
				self->set(args[0]->NumberValue(), alpha);
			}
			else
			{
				//copy constructor like a BOSS! This will also throw an exception if user is entering an "i dunno" color.
				self->set(*ObjectWrap::Unwrap<OfColorWrap>(args[0]->ToObject())->GetWrapped());
			}
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::SetBrightness)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			self->setBrightness(args[0]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::SetHex)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			float alpha = ofColor::limit();
			if (!args[1]->IsUndefined())
			{
				alpha = args[1]->NumberValue();
			}
			self->setHex(
				args[0]->Int32Value(),
				alpha);
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::SetHsb)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			float alpha = ofColor::limit();
			if (!args[3]->IsUndefined())
			{
				alpha = args[3]->NumberValue();
			}
			self->setHsb(
				args[0]->NumberValue(),
				args[1]->NumberValue(),
				args[2]->NumberValue(),
				alpha);
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::SetHue)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			self->setHue(args[0]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::SetHueAngle)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			self->setHueAngle(args[0]->NumberValue());
			NanReturnUndefined();
		}

		//---------------------------------------------------------
		NAN_METHOD(OfColorWrap::SetSaturation)
		{
			auto self = ObjectWrap::Unwrap<OfColorWrap>(args.This())->GetWrapped();
			self->setSaturation(args[0]->NumberValue());
			NanReturnUndefined();
		}

		//------------------------------------------------------- Auto generated const color getters

		NAN_PROPERTY_GETTER(OfColorWrap::GetAliceBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::aliceBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetAntiqueWhite)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::antiqueWhite));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetAqua)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::aqua));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetAquamarine)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::aquamarine));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetAzure)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::azure));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetBeige)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::beige));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetBisque)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::bisque));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetBlack)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::black));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetBlanchedAlmond)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::blanchedAlmond));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::blue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetBlueSteel)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::blueSteel));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetBlueViolet)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::blueViolet));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetBrown)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::brown));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetBurlyWood)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::burlyWood));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetCadetBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::cadetBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetChartreuse)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::chartreuse));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetChocolate)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::chocolate));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetCoral)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::coral));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetCornflowerBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::cornflowerBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetCornsilk)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::cornsilk));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetCrimson)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::crimson));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetCyan)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::cyan));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkCyan)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkCyan));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkGoldenRod)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkGoldenRod));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkGray)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkGray));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkGrey)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkGrey));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkKhaki)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkKhaki));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkMagenta)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkMagenta));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkOliveGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkOliveGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkOrchid)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkOrchid));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkRed)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkRed));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkSalmon)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkSalmon));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkSeaGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkSeaGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkSlateBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkSlateBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkSlateGray)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkSlateGray));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkSlateGrey)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkSlateGrey));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkTurquoise)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkTurquoise));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkViolet)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkViolet));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDarkorange)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::darkorange));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDeepPink)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::deepPink));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDeepSkyBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::deepSkyBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDimGray)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::dimGray));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDimGrey)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::dimGrey));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetDodgerBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::dodgerBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetFireBrick)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::fireBrick));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetFloralWhite)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::floralWhite));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetForestGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::forestGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetFuchsia)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::fuchsia));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetGainsboro)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::gainsboro));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetGhostWhite)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::ghostWhite));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetGold)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::gold));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetGoldenRod)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::goldenRod));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetGray)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::gray));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::green));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetGreenYellow)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::greenYellow));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetGrey)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::grey));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetHoneyDew)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::honeyDew));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetHotPink)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::hotPink));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetIndianRed)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::indianRed));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetIndigo)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::indigo));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetIvory)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::ivory));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetKhaki)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::khaki));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLavender)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lavender));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLavenderBlush)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lavenderBlush));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLawnGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lawnGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLemonChiffon)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lemonChiffon));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightCoral)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightCoral));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightCyan)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightCyan));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightGoldenRodYellow)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightGoldenRodYellow));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightGray)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightGray));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightGrey)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightGrey));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightPink)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightPink));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightSalmon)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightSalmon));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightSeaGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightSeaGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightSkyBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightSkyBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightSlateGray)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightSlateGray));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightSlateGrey)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightSlateGrey));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightSteelBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightSteelBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLightYellow)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lightYellow));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLime)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::lime));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLimeGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::limeGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetLinen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::linen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMagenta)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::magenta));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMaroon)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::maroon));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMediumAquaMarine)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::mediumAquaMarine));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMediumBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::mediumBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMediumOrchid)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::mediumOrchid));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMediumPurple)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::mediumPurple));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMediumSeaGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::mediumSeaGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMediumSlateBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::mediumSlateBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMediumSpringGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::mediumSpringGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMediumTurquoise)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::mediumTurquoise));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMediumVioletRed)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::mediumVioletRed));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMidnightBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::midnightBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMintCream)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::mintCream));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMistyRose)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::mistyRose));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetMoccasin)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::moccasin));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetNavajoWhite)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::navajoWhite));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetNavy)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::navy));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetOldLace)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::oldLace));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetOlive)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::olive));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetOliveDrab)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::oliveDrab));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetOrange)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::orange));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetOrangeRed)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::orangeRed));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetOrchid)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::orchid));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetPaleGoldenRod)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::paleGoldenRod));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetPaleGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::paleGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetPaleTurquoise)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::paleTurquoise));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetPaleVioletRed)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::paleVioletRed));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetPapayaWhip)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::papayaWhip));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetPeachPuff)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::peachPuff));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetPeru)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::peru));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetPink)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::pink));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetPlum)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::plum));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetPowderBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::powderBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetPurple)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::purple));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetRed)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::red));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetRosyBrown)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::rosyBrown));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetRoyalBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::royalBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSaddleBrown)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::saddleBrown));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSalmon)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::salmon));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSandyBrown)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::sandyBrown));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSeaGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::seaGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSeaShell)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::seaShell));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSienna)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::sienna));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSilver)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::silver));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSkyBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::skyBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSlateBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::slateBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSlateGray)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::slateGray));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSlateGrey)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::slateGrey));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSnow)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::snow));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSpringGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::springGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetSteelBlue)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::steelBlue));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetTan)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::tan));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetTeal)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::teal));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetThistle)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::thistle));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetTomato)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::tomato));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetTurquoise)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::turquoise));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetViolet)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::violet));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetWheat)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::wheat));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetWhite)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::white));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetWhiteSmoke)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::whiteSmoke));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetYellow)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::yellow));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

		NAN_PROPERTY_GETTER(OfColorWrap::GetYellowGreen)
		{
			auto lToRet = NanNew(Factory())->NewInstance();
			node::ObjectWrap::Unwrap<OfColorWrap>(lToRet)->SetWrapped(static_cast<ofColor>(ofColor::yellowGreen));
			NanReturnValue(lToRet);
		}
		//-------------------------------------------------------

	} //!namespace OfColor
} //!namespace nofx
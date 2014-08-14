#include "nofx_pointer.h"

namespace nofx
{
	namespace Pointer
	{
		using namespace v8;
		//--------------------------------------------------------------
		template<typename T>
		NAN_METHOD(PointerWrap<T>::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				PointerWrap<T>* obj;
				if (args.Length() == 0)
				{
					obj = new PointerWrap<T>();
				}
				else if (args[0]->IsNull())
				{
					obj = new PointerWrap<T>(nullptr);
				}
				else
				{
					//copy constructor
					obj = new PointerWrap<T>(ObjectWrap::Unwrap<PointerWrap<T>>(args[0]->ToObject())->GetWrapped());
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

			//--------------------------------------------------------------
			template<typename T>
			void PointerWrap<T>::Initialize(v8::Handle<Object> exports, std::string name)
			{
				auto tpl = NanNew<v8::FunctionTemplate>(New);
				tpl->SetClassName(NanNew(name));

				auto inst = tpl->InstanceTemplate();
				inst->SetInternalFieldCount(1);

				inst->SetAccessor(NanNew("pointsTo"), PointerWrap<T>::PointsTo, 0, v8::Handle<v8::Value>(), v8::PROHIBITS_OVERWRITING);
				
				NanAssignPersistent(constructor, tpl->GetFunction());
				exports->Set(NanNew(name), tpl->GetFunction());
			}

			template<typename T>
			NAN_GETTER(PointerWrap::PointsTo)
			{
				const auto self = ObjectWrap::Unwrap<PointerWrap<T>>(args.This())->GetWrapped();
				if (self != nullptr)
				{
					auto JsArr = NanNew<Array>();
					for (auto i = 0; i < sizeof(self) / sizeof(self[0]); ++i)
					{
						JsArr->Set(i, NanNew(self[i]));
					}
					NanReturnValue(JsArr);
				}
				else
				{
					NanReturnNull();
				}
			}
		}
	}
}
#ifndef _NOFX_POINTER_H_
#define _NOFX_POINTER_H_

#include "globals.h"
#include <memory>
#include <vector>
#include "ofTypes.h"

namespace nofx
{
	namespace Pointer
	{
		using namespace v8;

		template<typename T>
		class RawPointerWrap
			: public node::ObjectWrap
		{
		public:
			static void Initialize(v8::Handle<Object> exports, std::string name, NOFX_TYPES type) {
				auto tpl = NanNew<v8::FunctionTemplate>(New);
				tpl->SetClassName(NanNew(name));

				auto inst = tpl->InstanceTemplate();
				inst->SetInternalFieldCount(1);

				NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(type), v8::ReadOnly);
				NanAssignPersistent(constructor, tpl->GetFunction());
				exports->Set(NanNew(name), tpl->GetFunction());
			}
			T* GetWrapped() const { return internal_; };
			void SetWrapped(T* n)  { if (internal_) delete internal_; internal_ = n; };

		private:
			RawPointerWrap() : internal_(nullptr) {};
			RawPointerWrap(T* aInternal) : internal_(aInternal) {};
			~RawPointerWrap() { if (internal_) delete internal_; };

			static Persistent<Function> constructor;

			static NAN_METHOD(New) {
				NanScope();
				if (args.IsConstructCall()) {
					RawPointerWrap* obj;
					if (args.Length() == 0)
					{
						obj = new RawPointerWrap();
					}
					else if (args[0]->IsNull())
					{
						obj = new RawPointerWrap(nullptr);
					}
					else
					{
						//copy constructor
						obj = new RawPointerWrap(ObjectWrap::Unwrap<RawPointerWrap>(args[0]->ToObject())->GetWrapped());
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
			T* internal_;
		};
	}
}

#endif
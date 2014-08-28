#include "nofx_dependencies.h"

v8::Persistent<v8::Function> DEP_charPtr;

namespace nofx
{
    namespace ClassWrappers
    {
        NAN_METHOD(nofx_dependencies)
        {

            if (args.Length() != 1)
            {
                NanThrowTypeError("ofBuffer module has dependencies. Please pass the right dependencies first.");
            }
            
            NanAssignPersistent(DEP_charPtr, v8::Handle<v8::Function>::Cast(
                args[0]->ToObject()->Get(NanNew("charPtr"))));
        
            NanReturnValue(args.This());
        } // !nofx_dependencies
    } // !namespace ClassWrappers
} // !namespace nofx
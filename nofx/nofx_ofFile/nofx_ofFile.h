#ifndef _NOFX_OF_FILE_H_
#define _NOFX_OF_FILE_H_

#include "globals.h"
#include <memory>
#include "ofFileUtils.h"
#include "..\nofx\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
    namespace ClassWrappers
    {
        class OfFileWrap
            : public nofx::ObjectWrap< ofFile >
        {

            DeclareObjectRoutines(File);
            
            static NAN_METHOD(CanExecute);
            static NAN_METHOD(CanRead);
            static NAN_METHOD(CanWrite);
            static NAN_METHOD(ChangeMode);
            static NAN_METHOD(Close);
            static NAN_METHOD(CopyFromTo);
            static NAN_METHOD(CopyTo);
            static NAN_METHOD(Create);
            static NAN_METHOD(DoesFileExist);
            static NAN_METHOD(Exists);
            static NAN_METHOD(GetAbsolutePath);
            static NAN_METHOD(GetBaseName);
            static NAN_METHOD(GetEnclosingDirectory);
            static NAN_METHOD(GetExtension);
            static NAN_METHOD(GetFileBuffer);
            static NAN_METHOD(GetFileName);
            static NAN_METHOD(GetPocoFile);
            static NAN_METHOD(GetSize);
            static NAN_METHOD(IsDevice);
            static NAN_METHOD(IsDirectory);
            static NAN_METHOD(IsFile);
            static NAN_METHOD(IsHidden);
            static NAN_METHOD(IsLink);
            static NAN_METHOD(MoveFromTo);
            static NAN_METHOD(MoveTo);
            static NAN_METHOD(Open);
            static NAN_METHOD(Path);
            static NAN_METHOD(ReadToBuffer);
            static NAN_METHOD(Remove);
            static NAN_METHOD(RemoveFile);
            static NAN_METHOD(RenameTo);
            static NAN_METHOD(SetExecutable);
            static NAN_METHOD(SetReadOnly);
            static NAN_METHOD(SetWriteable);
            static NAN_METHOD(WriteFromBuffer);

        }; // !class OfFileWrap
    } //!namespace ClassWrappers
} // !namespace nofx

#endif // !_NOFX_OF_FILE_H_
    
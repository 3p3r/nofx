<?php

require_once('compiler.php');

$OF_header = OFROOT
.DIRECTORY_SEPARATOR .'openFrameworks'
.DIRECTORY_SEPARATOR .'libs'
.DIRECTORY_SEPARATOR .'openFrameworks'
.DIRECTORY_SEPARATOR .'math'
.DIRECTORY_SEPARATOR .'ofQuaternion.h';

class OfQuaternionUnit extends CompilerUnit {

    public function __construct() {
        global $OF_header;
        parent::__construct($OF_header);
    }

    public function main() {
        $template = <<<TMP
#include "nofx_{$this->getLClassName()}_globals.h"
{$this->getNofxDependencyHeaderInclude()}
#include "nofx_{$this->getLClassName()}.h"

namespace nofx
{
    using namespace v8;

    void Initialize{$this->getUClassName()}(
        v8::Handle<v8::Object> target,
        v8::Handle<v8::Value> unused,
        v8::Handle<v8::Context> context)
    {
        {$this->getDependencySetterBlock()}
        ClassWrappers::{$this->getUClassName()}Wrap::Initialize(target);

    } //!Initialize{$this->getUClassName()}
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_{$this->getLClassName()}, nofx::Initialize{$this->getUClassName()})
TMP;
        $this->writeSource("nofx_{$this->getLClassName()}_main.cc", $template);
    }
    public function H() {
        $guard = self::camelCasedToUnderScored($this->getClassName());
        $trimmedName = self::trimOfPrefix($this->getClassName());
        $template = <<<TMP
#ifndef _NOFX_{$guard}_H_
#define _NOFX_{$guard}_H_

#include <memory>
#include "nofx_{$this->getLClassName()}_globals.h"
#include "{$this->getHeaderName()}"
#include "..\\nofx\\nofx_objectWrap.h"

using namespace v8;

namespace nofx
{
    namespace ClassWrappers
    {
        class {$this->getUClassName()}Wrap
            : public nofx::ObjectWrap< {$this->getLClassName()} >
        {

            DeclareObjectRoutines({$trimmedName});

{$this->getClassGettersForWrapperHeader()}
{$this->getClassSettersForWrapperHeader()}
{$this->getClassMethodsForWrapperHeader()}

        }; //!class {$this->getUClassName()}Wrap
    } //!namespace ClassWrappers
} //!namespace nofx

#endif // !_NOFX_{$guard}_H_
    
TMP;
        $this->writeSource("nofx_{$this->getLClassName()}.h", $template);
    }
    public function CC() {
        $template = <<<TMP
#include "nofx_{$this->getLClassName()}.h"
#include "..\\nofx\\nofx_types.h"
{$this->getNofxDependencyHeaderFiles()}
namespace nofx
{
    namespace ClassWrappers
    {
        using nofx::ObjectWrap;
    
        Persistent<Function> {$this->getUClassName()}Wrap::constructor;
        {$this->getConstructorImplementation()}
        {$this->getClassInitializer()}
        {$this->getClassGettersForWrapperSource()}
        {$this->getClassSettersForWrapperSource()}
        {$this->getClassMethodsForWrapperSource()}
    } //!namespace ClassWrappers
} //!namespace nofx
TMP;
        $this->writeSource("nofx_{$this->getLClassName()}.cc", $template);
    }
    public function depCC() {
        $tmpl = <<<TPL
#include "nofx_{$this->getLClassName()}_dependencies.h"
{$this->getDependencyListForSource()}
namespace nofx
{
    NAN_METHOD(nofx_{$this->getLClassName()}_dependencies)
    {

#if NOFX_STRICT
        if (args.Length() < 1 || !args[0]->IsObject())
        {
            NanThrowTypeError("You do not meet the requirements of {$this->getLClassName()}'s dependencies.");
        }
#endif
{$this->getDependencyBlockForSource()}
        NanReturnValue(args.This());
    } // !nofx_{$this->getLClassName()}_dependencies
} // !namespace nofx

TPL;
        $this->writeSource("nofx_{$this->getLClassName()}_dependencies.cc", $tmpl);
    }
    public function depH() {
        $tmpl = <<<TPL
#ifndef _NOFX_{$this->getAllCapsClassName()}_DEPENENCIES_H_
#define _NOFX_{$this->getAllCapsClassName()}_DEPENENCIES_H_

#include "nofx_{$this->getLClassName()}_globals.h"

namespace nofx
{
    
    NAN_METHOD(nofx_{$this->getLClassName()}_dependencies);
    
} //!namespace nofx

#endif // !_NOFX_{$this->getAllCapsClassName()}_DEPENENCIES_H_

TPL;
        $this->writeSource("nofx_{$this->getLClassName()}_dependencies.h", $tmpl);
    }
    public function globals() {
        $tmpl = <<<TPL
#ifndef _NOFX_{$this->getAllCapsClassName()}_GLOBALS_H_
#define _NOFX_{$this->getAllCapsClassName()}_GLOBALS_H_

// Always including node.h first. Otherwise we'll
// get random weird errors about mixing C/C++ routines.

#include "node.h"
#include "v8.h"
#include "nan.h"
#include "..\\nofx\\nofx_types.h"
{$this->getDependencyListForGlobals()}
#endif // !_NOFX_{$this->getAllCapsClassName()}_GLOBALS_H_

TPL;
        $this->writeSource("nofx_{$this->getLClassName()}_globals.h", $tmpl);
    }
}

$generator = new OfQuaternionUnit();
$generator->compile();
?>
#ifndef _NOFX_GLOBALS_H_
#define _NOFX_GLOBALS_H_

// Make sure you always include node.h first. Otherwise you'll
// get random weird errors about mixing C/C++ routines.

#include "node.h"
#include "v8.h"
#include "nan.h"

extern v8::Persistent<v8::Function> DEP_ofColor;
extern v8::Persistent<v8::Function> DEP_ofPixels;
extern v8::Persistent<v8::Function> DEP_ofTexture;

#endif // !_NOFX_GLOBALS_H_    
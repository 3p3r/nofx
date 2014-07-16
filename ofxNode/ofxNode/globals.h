#ifndef _OFXNODE_GLOBALS_H_
#define _OFXNODE_GLOBALS_H_

// Make sure you always include node.h first. Otherwise you'll
// get random weird errors about mixing C/C++ routines.

#include "node.h"
#include "v8.h"
#include "nan.h"
#include "gtest\gtest.h"

// Global externs
extern v8::Persistent<v8::Object> self_;

#endif // !_OFXNODE_GLOBALS_H_
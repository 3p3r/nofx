#ifndef _OFXNODE_GLOBALS_H_
#define _OFXNODE_GLOBALS_H_

// Make sure you always include node.h first. Otherwise you'll
// get random weird errors about mixing C/C++ routines.

#include "node.h"
#include "v8.h"
#include "nan.h"

// Global externs
extern v8::Persistent<v8::Object> self_;

// Internal ofxNode types
enum OFXNODE_TYPES
{
	OFVEC2F = 1,
	OFVEC3F = 1 << 1,
	OFVEC4F = 1 << 2,
	OFCOLOR = 1 << 3,
	OFPOINT = 1 << 4
};

// v8 <-> OF <-> Node Goodies

// Checks to see if a v8 argument is string
#define IS_V8_ARG_STRING(arg) \
	(arg->IsString())

// Extracts string from v8 arg
#define V8_ARG_STRING(arg) \
	(NanCString(arg, nullptr))

// Checks to see if a v8 argument is string
#define IS_V8_ARG_NUMBER(arg) \
	(arg->IsNumber())

// Extracts number value from v8 arg
#define V8_ARG_NUMBER(arg) \
	(arg->NumberValue())

// Checks to see if a v8 argument can be casted as an ofColor
#define IS_V8_ARG_OF_COLOR(arg) \
	((arg->IsObject()) && \
	(arg->ToObject()->Has(NanNew("r"))) && \
	(arg->ToObject()->Has(NanNew("g"))) && \
	(arg->ToObject()->Has(NanNew("b"))) && \
	(arg->ToObject()->Get(NanNew("r"))->IsNumber()) && \
	(arg->ToObject()->Get(NanNew("g"))->IsNumber()) && \
	(arg->ToObject()->Get(NanNew("b"))->IsNumber()))

// Checks to see if a v8 argument can be casted as an ofColor with Alpha
#define DOES_V8_COLOR_ARG_HAVE_ALPHA(arg) \
	((IS_V8_ARG_OF_COLOR(arg)) && \
	(arg->ToObject()->Has(NanNew("a"))) && \
	(arg->ToObject()->Get(NanNew("a"))->IsNumber()))

// Gets Red property of a v8 color argument
#define V8_COLOR_R(arg) \
	(arg->ToObject()->Get(NanNew("r"))->NumberValue())

// Gets Alpha property of a v8 color argument
#define V8_COLOR_A(arg) \
	DOES_V8_COLOR_ARG_HAVE_ALPHA(arg) ? \
	(arg->ToObject()->Get(NanNew("a"))->NumberValue()) : 255

// Gets Blue property of a v8 color argument
#define V8_COLOR_B(arg) \
	(arg->ToObject()->Get(NanNew("b"))->NumberValue())

// Gets Green property of a v8 color argument
#define V8_COLOR_G(arg) \
	(arg->ToObject()->Get(NanNew("g"))->NumberValue())

// Checks to see if a v8 argument can be casted as a 2D ofPoint
#define IS_V8_ARG_2D_OF_POS(arg) \
	((arg->IsObject()) && \
	(arg->ToObject()->Has(NanNew("x"))) && \
	(arg->ToObject()->Has(NanNew("y"))) && \
	(arg->ToObject()->Get(NanNew("x"))->IsNumber()) && \
	(arg->ToObject()->Get(NanNew("y"))->IsNumber()))

// Checks if a v8 argument has a potential z property
#define DOES_V8_POS_ARG_HAVE_DEPTH(arg) \
	((IS_V8_ARG_2D_OF_POS(arg)) && \
	(arg->ToObject()->Has(NanNew("z"))) && \
	(arg->ToObject()->Get(NanNew("z"))->IsNumber()))

// Gets X property of a v8 pos argument
#define V8_POS_X(arg) \
	(arg->ToObject()->Get(NanNew("x"))->NumberValue())

// Gets Y property of a v8 pos argument
#define V8_POS_Z(arg) \
	DOES_V8_POS_ARG_HAVE_DEPTH(arg) ? \
	(arg->ToObject()->Get(NanNew("z"))->NumberValue()) : 0

// Gets Z property of a v8 pos argument
#define V8_POS_Y(arg) \
	(arg->ToObject()->Get(NanNew("y"))->NumberValue())

// Checks to see if a v8 argument can be casted as a 3D ofPoint
#define IS_V8_ARG_3D_OF_POS(arg) \
	((IS_V8_ARG_2D_OF_POS(arg)) && \
	(arg->ToObject()->Has(NanNew("z"))) && \
	(arg->ToObject()->Get(NanNew("z"))->IsNumber()))

#endif // !_OFXNODE_GLOBALS_H_
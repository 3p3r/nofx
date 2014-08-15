#ifndef _NOFX_TYPES_H_
#define _NOFX_TYPES_H_

enum NOFX_TYPES
{
	OFVEC3F = 0,
	OFVEC2F,
	OFVEC4F,
	OFBASEAPP,
	OFAPPBASEWINDOW
};

#define DepNewInstance(name) (NanNew(name)->Call(args.This(), 0, nullptr))

#endif // !_NOFX_TYPES_H_
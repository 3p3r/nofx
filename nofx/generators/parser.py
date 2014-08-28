#!/usr/bin/python
import sys
import os

sys.path = ["../"] + sys.path
if (len(sys.argv) < 2):
    print("usage:\n\t%s someCppHeader.h\nOR\n\tgetOF"%os.path.basename(__file__))
    sys.exit(1)
    
if (sys.argv[1] == "getOF"):
    print os.getenv('NOFX_OF', "not found.")
    sys.exit(0)

import jsonpickle
import CppHeaderParser
try:
    cppHeader = CppHeaderParser.CppHeader(sys.argv[1])
except CppHeaderParser.CppParseError as e:
    print(e)
    sys.exit(1)

print("%s"%jsonpickle.encode(cppHeader))
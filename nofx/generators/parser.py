#!/usr/bin/python
import sys
import os

sys.path = ["../"] + sys.path
if (len(sys.argv) < 2):
    print("usage:\n\t %s someCppHeader.h"%os.path.basename(__file__))
    sys.exit(1)

import jsonpickle
import CppHeaderParser
try:
    cppHeader = CppHeaderParser.CppHeader(sys.argv[1])
except CppHeaderParser.CppParseError as e:
    print(e)
    sys.exit(1)

print("%s"%jsonpickle.encode(cppHeader))
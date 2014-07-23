#include "ofxNode_ofClamp.h"
#include "ofMath.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofClamp) {
        NanReturnValue(NanNew<v8::Number>(ofClamp(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue())));
    } // !ofxNode_ofClamp
} // !namespace ofxNode
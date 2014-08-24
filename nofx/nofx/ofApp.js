var floatPtr = require("../bin/nofx_pointer").floatPtr;

var ofVec3f = require("../bin/nofx_ofVec3f").dependencies({
    "floatPtr": function () { return new floatPtr(null); }
}).ofVec3f;

var ofVec4f = require("../bin/nofx_ofVec4f").dependencies({
    "floatPtr": function () { return new floatPtr(null); }
}).ofVec4f;

var ofApp = require("../bin/nofx_ofBaseApp").ofApp;

var ofAppBaseWindow = require("../bin/nofx_ofAppBaseWindow").dependencies({
    "ofVec3f": function () { return new ofVec3f(null); }
}).ofAppBaseWindow;

var ofAppRunner = require("../bin/nofx_ofAppRunner").dependencies({
    "ofApp" : function () { return new ofApp(null); },
    "ofAppBaseWindow": function () { return new ofAppBaseWindow(null); },
    "ofVec3f": function () { return new ofVec3f(null); }
});

var ofColor = require("../bin/nofx_ofColor").ofColor;

var ofQuaternion = require("../bin/nofx_ofQuaternion").dependencies({
    "ofVec3f": function () { return new ofVec3f(null); },
    "ofVec4f": function () { return new ofVec4f(null); }
}).ofQuaternion;

var ofMatrix4x4 = require("../bin/nofx_ofMatrix4x4").dependencies({
    "ofQuaternion": function () { return new ofQuaternion(null); },
    "ofVec4f": function () { return new ofVec4f(null); },
    "ofVec3f": function () { return new ofVec3f(null); },
    "floatPtr": function () { return new floatPtr(null); }
}).ofMatrix4x4;

// We do this to avoid calling "this" on every API call
// Source code will get cleaner and more readable.
var extend = require("./extend.js");
extend(true, GLOBAL, ofAppRunner);

var app = new ofApp();

app.update = function () {
    
}

app.mousePressed = function () {
    var mat = new ofMatrix4x4(1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4);
    console.log(mat.getPtr());

    var vec = new ofVec3f(4, 5, 666666666);
    console.log(vec);
}

ofSetupOpenGL(150, 150);
ofRunApp(app);
var floatPtr = require("../bin/nofx_pointer").floatPtr;

var ofVec3f = require("../bin/nofx_ofVec3f").dependencies({
    "floatPtr": function () { return new floatPtr(null); }
}).ofVec3f;

var ofApp = require("../bin/nofx_ofBaseApp").ofApp;

var ofAppBaseWindow = require("../bin/nofx_ofAppBaseWindow").dependencies({
    "ofVec3f": function () { return new ofVec3f(null); }
}).ofAppBaseWindow;

var ofAppRunner = require("../bin/nofx_ofAppRunner").dependencies({
    "ofApp" : function () { return new ofApp(null); },
    "ofAppBaseWindow": function () { return new ofAppBaseWindow(null); }
});

// We do this to avoid calling "this" on every API call
// Source code will get cleaner and more readable.
var extend = require("./extend.js");
extend(true, GLOBAL, ofAppRunner);

var app = new ofApp();

app.update = function () {
    
}

app.mousePressed = function () {
    console.log(ofGetWindowPtr().getWindowSize());
    console.log(ofGetWindowPtr().getWindowPosition());
}

ofSetupOpenGL(150, 150);
ofRunApp(app);
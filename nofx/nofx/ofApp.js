var ofApp = require("../bin/nofx_ofBaseApp").ofApp;
var ofAppBaseWindow = require("../bin/nofx_ofAppBaseWindow").ofAppBaseWindow;
var ofAppRunner = require("../bin/nofx_ofAppRunner").dependencies({
    "ofApp" : function () { return new ofApp(null); },
    "ofAppBaseWindow": function () { return new ofAppBaseWindow(null); }
});
var extend      = require("./extend.js");

// We do this to avoid calling "this" on every API call
// Source code will get cleaner and more readable.
extend(true, GLOBAL, ofAppRunner);

var app = new ofApp();

app.mousePressed = function () {
    var ptr = ofGetWindowPtr();
    ptr.setWindowTitle("new title!");
    ptr.
}

ofSetupOpenGL(800, 600);
ofRunApp(app);
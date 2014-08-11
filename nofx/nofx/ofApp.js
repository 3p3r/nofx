var ofApp = require("../bin/nofx_ofBaseApp").ofApp;
var ofAppRunner = require("../bin/nofx_ofAppRunner").dependencies({
    "ofApp": function () { return new ofApp(null); }
});
var extend      = require("./extend.js");

// We do this to avoid calling "this" on every API call
// Source code will get cleaner and more readable.
extend(true, GLOBAL, ofAppRunner);

var app = new ofApp();

app.mousePressed = function () {
    var app2 = ofGetAppPtr();
    app2.mousePressed = function () { console.log("hello old!"); };
    console.log("hello new!");
}

ofSetupOpenGL(800, 600);
ofRunApp(app);
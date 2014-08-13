var ofApp = require("../bin/nofx_ofBaseApp").ofApp;
var ofAppBaseWindow = require("../bin/nofx_ofAppBaseWindow").ofAppBaseWindow;
var ofAppRunner = require("../bin/nofx_ofAppRunner").dependencies({
    "ofApp" : function () { return new ofApp(null); },
    "ofAppBaseWindow": function () { return new ofAppBaseWindow(null); }
});
var ofVec3f = require("../bin/nofx_ofVec3f").ofVec3f;
var extend      = require("./extend.js");

// We do this to avoid calling "this" on every API call
// Source code will get cleaner and more readable.
extend(true, GLOBAL, ofAppRunner);

var app = new ofApp();

var doit = function () {
    for (var i = 0; i < 100000; ++i) {
        var v1 = new ofVec3f(1, 2, 3);
        var v2 = new ofVec3f(100, 250, 56);
        var v3 = v1.getCrossed(v2);
    }
}

app.update = function () {
    
}

app.mousePressed = function () {

}

ofSetupOpenGL(150, 150);
ofRunApp(app);
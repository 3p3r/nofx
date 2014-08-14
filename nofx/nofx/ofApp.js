var floatPtr = require("../bin/nofx_pointer").floatPtr;

var ofApp = require("../bin/nofx_ofBaseApp").ofApp;

var ofAppBaseWindow = require("../bin/nofx_ofAppBaseWindow").ofAppBaseWindow;

var ofAppRunner = require("../bin/nofx_ofAppRunner").dependencies({
    "ofApp" : function () { return new ofApp(null); },
    "ofAppBaseWindow": function () { return new ofAppBaseWindow(null); }
});

var ofVec3f = require("../bin/nofx_ofVec3f").dependencies({
    "floatPtr": function () { return new floatPtr(null); }
}).ofVec3f;

// We do this to avoid calling "this" on every API call
// Source code will get cleaner and more readable.
var extend = require("./extend.js");
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
    var v1 = new ofVec3f(100, 200, 300);
    console.log(v1.getPtr());
    console.log(v1[0]);
    console.log(v1[1]);
    v1[1] = 456.5;
    console.log(v1[1]);
    console.log(v1[2]);
}

ofSetupOpenGL(150, 150);
ofRunApp(app);
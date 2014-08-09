var ofApp       = require("../bin/nofx_ofBaseApp").ofApp;
var ofAppRunner = require("../bin/nofx_ofAppRunner");
var extend      = require("./extend.js");

// We do this to avoid calling "this" on every API call
// Source code will get cleaner and more readable.
extend(true, GLOBAL, ofAppRunner);

var app = new ofApp();

app.draw = function () {  }

ofSetupOpenGL(800, 600);
ofRunApp(app);
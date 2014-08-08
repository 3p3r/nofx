var nofx = require("../bin/nofx");
var extend = require("./extend.js");
var fibers = require("./fibers");

// We do this to avoid calling "this" on every API call
// Source code will get cleaner and more readable.
extend(true, GLOBAL, nofx);

var app = new ofApp();

app.draw = function () {  }

console.log(process.cwd());

ofSetupOpenGL(800, 600);
ofRunApp(app);

//setInterval(function () { }, 0);
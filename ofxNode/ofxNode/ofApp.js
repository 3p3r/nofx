var ofxNode = require("../bin/ofxNode");
var extend = require("./extend.js");

// We do this to avoid calling "this" on every API call
// Source code will get cleaner and more readable.
extend(true, GLOBAL, ofxNode);

//This must be 
ofxNode.setup(function () {

})
.update(function () {

})
.draw(function () {

})
.keyPressed(function (key) {

})
.mouseDragged(function (x, y, button) {

})
.mousePressed(function (x, y, button) {

})
.mouseReleased(function (x, y, button) {

})
.ofSetupOpenGL(1024, 768)            // <-------- setup the GL context
.ofRunApp();
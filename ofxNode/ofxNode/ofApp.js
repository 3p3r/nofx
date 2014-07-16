var ofxNode = require("../bin/ofxNode");
ofxNode.draw = function() {console.log("drawing!");}
ofxNode.ofSetupOpenGL(800, 400).ofRunApp();
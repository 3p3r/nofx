var ofxNode = require("../../../../bin/ofxNode");
var extend = require("../../../extend.js");

// We do this to avoid calling "this" on every API call
// Source code will get cleaner and more readable.
extend(true, GLOBAL, ofxNode);

var blendMode = 1;
var rainbow = new ofImage();
var alpha = 0;
var counter = 0;
var vagRounded = new ofTrueTypeFont();
var eventString = "Alpha";
var timeString = "Press 1 - 5 to switch blend modes";

//This must be 
ofxNode.setup(function () {
    vagRounded.loadFont(process.cwd()+"\\data\\vag.ttf", 32);
    ofBackground(50, 50, 50);
    rainbow.allocate(256, 256, 0x02);
    rainbow.loadImage(process.cwd()+"\\data\\rainbow.tiff");
})
.update(function () {
    counter = counter + 0.033;
    alpha += 0.01;
    alpha = (alpha > 1.0) ? 1.0 : alpha;
})
.draw(function () {
    ofEnableBlendMode(1);

    ofSetHexColor(0xffffff);
    vagRounded.drawString(eventString, 98, 198);

    ofSetColor(255, 122, 220);
    vagRounded.drawString(eventString, 100, 200);

    ofSetHexColor(0xffffff);
    vagRounded.drawString(timeString, 98, 98);

    ofSetColor(255, 122, 220);
    vagRounded.drawString(timeString, 100, 100);

    ofSetColor(255, 255, 255, 255);


    ofEnableBlendMode(blendMode);

    rainbow.draw(ofGetMouseX(), ofGetMouseY());

    ofDisableBlendMode();
})
.keyPressed(function (key) {
    switch (key) {
        case 49:
            blendMode = 1;
            eventString = "Alpha";
            break;
        case 50:
            blendMode = 2;
            eventString = "Add";
            break;
        case 51:
            blendMode = 4;
            eventString = "Multiply";
            break;
        case 52:
            blendMode = 3;
            eventString = "Subtract";
            break;
        case 53:
            blendMode = 5;
            eventString = "Screen";
            break;
        default:
            break;
    }
})
.mouseDragged(function (x, y, button) {
})
.mousePressed(function (x, y, button) {
})
.mouseReleased(function (x, y, button) {
})
.ofSetupOpenGL(1024, 768)            // <-------- setup the GL context
.ofRunApp();
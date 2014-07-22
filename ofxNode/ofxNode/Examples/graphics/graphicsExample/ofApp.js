var ofxNode = require("../../../../bin/ofxNode");
var extend = require("../../../extend.js");

// We do this to avoid calling "this" on every API call
// Source code will get cleaner and more readable.
extend(true, GLOBAL, ofxNode);

ofxNode.setup(function() {
    this.counter = 0;
    this.bSmooth = false;
    ofSetCircleResolution(50)
    ofBackground(255,255,255)
    ofSetWindowTitle("graphics example")
    ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
})
.update(function() {
    this.counter += 0.033;
})
.draw(function() {
    //--------------------------- circles
    //let's draw a circle:
    var radius = 50 + 10 * Math.sin(this.counter);
    ofSetColor(255,130,0)
    ofFill()        // draw "filled shapes"
    ofCircle(100,400,radius)

    // now just an outline
    ofNoFill()
    ofSetHexColor(0xCCCCCC)
    ofCircle(100,400,80)

    // use the bitMap type
    // note, this can be slow on some graphics cards
    // because it is using glDrawPixels which varies in
    // speed from system to system.  try using ofTrueTypeFont
    // if this bitMap type slows you down.
    ofSetHexColor(0x000000)
    ofDrawBitmapString("circle", 75,500)


    //--------------------------- rectangles
    ofFill();
    for (var i = 0; i < 200; i++){
        ofSetColor(
            parseInt(ofRandom(0,255)),
            parseInt(ofRandom(0,255)),
            parseInt(ofRandom(0,255))
        )
        ofRect(
            ofRandom(250,350),
            ofRandom(350,450),
            ofRandom(10,20),
            ofRandom(10,20)
        );
    }
    
    ofSetHexColor(0x000000)
    ofDrawBitmapString("rectangles", 275,500)

    //---------------------------  transparency
    ofSetHexColor(0x00FF33)
    ofRect(400,350,100,100)
    // alpha is usually turned off - for speed puposes.  let's turn it on!
    ofEnableAlphaBlending()
    ofSetColor(255,0,0,127)   // red, 50% transparent
    ofRect(450,430,100,33)
    ofSetColor(255,0,0,parseInt(this.counter * 10) % 255)   // red, variable transparent
    ofRect(450,370,100,33)
    ofDisableAlphaBlending()
    ofSetHexColor(0x000000)
    ofDrawBitmapString("transparency", 410,500)

    //---------------------------  lines
    // a bunch of red lines, make them smooth if the flag is set

    ofSetHexColor(0xFF0000);
    for (var i = 0; i < 20; i++){
        this.ofLine(600,300 + (i*5),800, 250 + (i*10));
    }

    
    ofSetHexColor(0x000000)
    ofDrawBitmapString("lines\npress 's' to toggle smoothness", 600,500);
})
.keyPressed(function(key) {
    if (key == 's'.charCodeAt(0)){
        this.bSmooth = !this.bSmooth;
        if (this.bSmooth){
            this.ofEnableAntiAliasing(); 
        }else{
            this.ofDisableAntiAliasing(); 
        }
    }
})
.ofSetupOpenGL(1024,768)            // <-------- setup the GL context
// this kicks off the running of my app
// can be OF_WINDOW or OF_FULLSCREEN
// pass in width and height too:
.ofRunApp();
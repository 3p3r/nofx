var ofxNode = require("../bin/ofxNode");

var winW = 800,
winH = 550,
particlesNum = 250,
randomNess = 250,
particles = [],
magnets = [];

var delay = 5;
var timer = 0;

var p1 = ofxNode.ofVec3f(1, 1, 1);
var p2 = ofxNode.ofVec3f(100, 100, 100);

Particle = function() {
    this.size = 0.5 + Math.random() * 8.5;
    this.position = {
        x: 0,
        y: 0
    };
    this.shift = {
        x: 0,
        y: 0
    };
    this.angle = 0;
    this.speed = 0.01 + this.size / 4 * 0.03;
    this.force = 1 - Math.random() * 0.11;
    this.orbit = 1;
    this.magnet = null
}

Magnet = function() {
    this.orbit = 100;
    this.position = {
        x: 0,
        y: 0
    };
    this.connections = 0;
    this.size = 1
}

ParticleSystemInit = function(magnetPos) {
    var lMagnet = new Magnet;
    lMagnet.position.x = magnetPos.x;
    lMagnet.position.y = magnetPos.y;
    magnets.push(lMagnet);
    for (var i = 0; i < particlesNum; ++i) {
        var p = new Particle;
        p.position.x = magnetPos.x;
        p.position.y = magnetPos.y;
        p.shift.x = magnetPos.x;
        p.shift.y = magnetPos.y;
        particles.push(p)
    }
}

lengthSquared = function (a, b) {
    var c = b.x - a.x,
    h = b.y - a.y;
    return Math.sqrt(c * c + h * h)
}

ofxNode.setup(function () {
    for (var a = 0; a < 4; a++) {
        ParticleSystemInit({
            x: (winW - randomNess) * 0.5 + Math.random() * randomNess,
            y: (winH - randomNess) * 0.5 + Math.random() * randomNess
        });
    }
})
.dragEvent(function(dragInfo) {
    
})
.mouseMoved(function(x, y) {

})
.mousePressed(function (x, y, button) {

})
.draw(function () {
    //return;
    this.ofClear(0, 0, 0)
    .ofBackgroundGradient(
        this.ofColor(240, 240, 240),
        this.ofColor(255, 255, 255))
    .ofDrawBitmapString("ofxNode sample script.", 10, 20)
    .ofDrawBitmapStringHighlight("ofxNode sample script.", this.ofVec3f(10, 40, 0), this.ofColor(0, 0, 0), this.ofColor(255, 255, 255));
    if (ofxNode.ofGetElapsedTimeMillis() - timer > delay) {
        var a, b, c, h, D, u;
        a = -1;
        h = 0;
		c = 0;
        for (u = magnets.length; h < u; h++) {
            b = magnets[h];
            if (b.position.x < 0 || b.position.y < 0 || b.position.x > winW || b.position.y > winH) a = h;
            b.size += (b.connections / 3 - b.size) * 0.05;
            b.size = Math.max(b.size, 2);
            b.connections = 0
        }
        for (D = particles.length; c < D; c++) {
            a = particles[c];
            var y = -1,
            E = -1,
            l = null,
            v = {
                x: 0,
                y: 0
            };
            h = 0;
            for (u = magnets.length; h < u; h++) {
                b = magnets[h];
                y = lengthSquared(a.position, b.position) - b.orbit * 0.5;
                if (a.magnet != b) {
                    var m = b.position.x - a.position.x;
                    if (m > -randomNess && m < randomNess) v.x += m / randomNess;
                    m = b.position.y - a.position.y;
                    if (m > -randomNess && m < randomNess) v.y += m / randomNess
                }
                if (l == null || y < E) {
                    E = y;
                    l = b
                }
            }
            if (a.magnet == null || a.magnet != l) a.magnet = l;
            l.connections += 1;
            a.angle += a.speed;
            a.shift.x += (l.position.x + v.x * 6 - a.shift.x) * a.speed;
            a.shift.y += (l.position.y + v.y * 6 - a.shift.y) * a.speed;
            a.position.x = a.shift.x + Math.cos(c + a.angle) * a.orbit * a.force;
            a.position.y = a.shift.y + Math.sin(c + a.angle) * a.orbit * a.force;
            a.position.x = Math.max(Math.min(a.position.x, winW - a.size / 2), a.size / 2);
            a.position.y = Math.max(Math.min(a.position.y, winH - a.size / 2), a.size / 2);
            a.orbit += (l.orbit - a.orbit) * 0.1;
            particles[c] = a;
        }

        timer = ofxNode.ofGetElapsedTimeMillis();
    }
    magnets.forEach(function(b) {
        //drawing magnets
        ofxNode.ofSetColor(230, 230, 230);
        ofxNode.ofFill();
        ofxNode.ofCircle(b.position.x, b.position.y, b.size);
    });
    particles.forEach(function (a) {
        //drawing particles
        ofxNode.ofSetColor(10, 10, 10);
        ofxNode.ofFill();
        ofxNode.ofCircle(a.position.x, a.position.y, a.size / 2);
    })

})
.ofSetupOpenGL(winW, winH)
.ofRunApp();
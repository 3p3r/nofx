var ofxNode = require("../bin/ofxNode");

var i = 800,
j = 550,
F = 20,
p = 300,
e, d, t, q = [],
f = [],
n = 0,
o = 0,
w = false,
x = 0,
g = 0;

function Particle() {
    this.size = 0.5 + Math.random() * 3.5;
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

function Magnet() {
    this.orbit = 100;
    this.position = {
        x: 0,
        y: 0
    };
    this.dragging = false;
    this.connections = 0;
    this.size = 1
}

ofxNode.z = function (a) {
    var b = new Magnet;
    b.position.x = a.x;
    b.position.y = a.y;
    f.push(b);
    a = b.position;
    for (b = 0; b < F; b++) {
        var c = new Particle;
        c.position.x = a.x;
        c.position.y = a.y;
        c.shift.x = a.x;
        c.shift.y = a.y;
        q.push(c)
    }
}

ofxNode.B = function (a, b) {
    var c = b.x - a.x,
    h = b.y - a.y;
    return Math.sqrt(c * c + h * h)
}

ofxNode.launch = function () {
    for (var a = 0; a < 4; a++) ofxNode.z({
        x: (i - 300) * 0.5 + Math.random() * 300,
        y: (j - 300) * 0.5 + Math.random() * 300
    });
    ofxNode.ofSetupOpenGL(i, j).ofRunApp();
}

ofxNode.mouseMoved = function (x, y) {
    //console.log("mouse moved: x="+x+" y="+y);
}

ofxNode.mouseDragged = function (x, y, button) {
    console.log("mouse dragged: x=" + x + " y=" + y+" button="+button);
}

ofxNode.draw = function () {
    ofxNode.ofClear(0, 0, 0);
    var a, b, c, h, D, u;
    a = -1;
    h = 0;
    for (u = f.length; h < u; h++) {
        b = f[h];
        if (b.dragging) {
            b.position.x += (n - b.position.x) * 0.2;
            b.position.y += (o - b.position.y) * 0.2
        } else if (b.position.x < 0 || b.position.y < 0 || b.position.x > i || b.position.y > j) a = h;
        b.size += (b.connections / 3 - b.size) * 0.05;
        b.size = Math.max(b.size, 2);
        //            c = d.createRadialGradient(b.position.x, b.position.y, 0, b.position.x, b.position.y, b.size * 10);
        //            c.addColorStop(0, k[g].glowA);
        //            c.addColorStop(1, k[g].glowB);
        //            d.beginPath();
        //            d.fillStyle = c;
        //            d.arc(b.position.x, b.position.y, b.size * 10, 0, Math.PI * 2, true);
        //            d.fill();
        //            d.beginPath();
        //            d.fillStyle = c;
        //            d.arc(b.position.x, b.position.y, b.size, 0, Math.PI * 2, true);
        //            d.fill();
        b.connections = 0
    }
    a != -1 && f.length > 1 && f.splice(a, 1);
    c = 0;
    for (D = q.length; c < D; c++) {
        a = q[c];
        var y = -1,
        E = -1,
        l = null,
        v = {
            x: 0,
            y: 0
        };
        h = 0;
        for (u = f.length; h < u; h++) {
            b = f[h];
            y = ofxNode.B(a.position,
                b.position) - b.orbit * 0.5;
            if (a.magnet != b) {
                var m = b.position.x - a.position.x;
                if (m > -p && m < p) v.x += m / p;
                m = b.position.y - a.position.y;
                if (m > -p && m < p) v.y += m / p
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
        a.position.x = Math.max(Math.min(a.position.x,
            i - a.size / 2), a.size / 2);
        a.position.y = Math.max(Math.min(a.position.y, j - a.size / 2), a.size / 2);
        a.orbit += (l.orbit - a.orbit) * 0.1;
        //drawing particles
        ofxNode.ofSetColor(255, 0, 0);
        ofxNode.ofFill();
        ofxNode.ofCircle(a.position.x, a.position.y, a.size / 2);
    }
};
ofxNode.launch();
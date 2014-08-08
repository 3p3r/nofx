var nofx = require("../bin/nofx");
var extend = require("./extend.js");

// We do this to avoid calling "this" on every API call
// Source code will get cleaner and more readable.
extend(true, GLOBAL, nofx);
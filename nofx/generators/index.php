<?php
    error_reporting(E_ALL ^ E_STRICT);
    
    $OF_home = trim(`python parser.py getOF`);
    if ($OF_home == null || $OF_home == 'not found.') {
        if(!isset($_GET['OFROOT'])) {
            throw new Exception("Could not find OpenFrameworks on your system. Please check the NOFX_OF environment variable.");
        } else {
            $OF_home = trim($_GET['OFROOT']);
        }
    }
    define('OFROOT', $OF_home);
    define('NOFXSTRICT', true);
    
    //require_once('ofRectangle.php');
    //require_once('ofVec4f.php');
    //require_once('ofVec2f.php');
    //require_once('ofVec2f.php');
    //require_once('ofQuaternion.php');
?>
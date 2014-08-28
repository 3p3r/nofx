<?php
    $OF_home = trim(`python parser.py getOF`);
    if ($OF_home == null || $OF_home == 'not found.') {
        if(!isset($_GET['OFROOT'])) {
            throw new Exception("Could not find OpenFrameworks on your system. Please check the NOFX_OF environment variable.");
        } else {
            $OF_home = trim($_GET['OFROOT']);
        }
    }
    define('OFROOT', $OF_home);
    define('NOFXSTRICT', false);
    
    require_once('ofRectangle.php');
?>
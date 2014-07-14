ofxNode
=======
OpenFrameworks wrapped as a NodeJS module and beyond!
-----------------------------------------------------


----------


Before opening the project make sure you have following variables (texts in bold) on your path. The final folder structure for each environment variable should be as shown (assuming each project is cloned by Git):

 - **OFXNODE_NAN**
  - nan
     - .git
     - ...
 - **OFXNODE_NODE**
  - node
     - .git
     - ...
 - **OFXNODE_OF**
  - openFrameworks
     - .git
     - ...

***FOR WINDOWS ONLY:*** Also make sure before building all projects, you set the flag for **ALL** projects to **/MD** or **/MDd** in Visual Studio. This violates v8's default configuration but its inevitable for now.
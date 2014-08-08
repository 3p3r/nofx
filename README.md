![nofx](/nofx/nofx.png?raw=true "Openframeworks Node bindings")


----------


Before opening the project make sure you have following variables (texts in bold) defined on your environment. The final folder structure for each environment variable should be as shown (assuming each project is cloned by Git):

 - **[NOFX_NAN][1]**
  - nan
     - .git
     - ...
 - **[NOFX_NODE][2]**
  - node
     - .git
     - ...
 - **[NOFX_OF][3]**
  - openFrameworks
     - .git
     - ...

***FOR WINDOWS ONLY:*** Also make sure before building all projects, you set the flag for **ALL** projects to **/MD** or **/MDd** in Visual Studio.


----------

Build instructions (Windows):
-----------------------------
**After defining environement variables**, you may start building nofx. The first step in building nofx, is building Node (duh!). You should build Node **before** anything else. nofx expects to see Node's libraries and headers before it can compile. For compiling Node:

 1. Navigate to %NOFX_NODE%
 2. run `vcbuild.bat nobuild`
 3. open up `node.sln` in a **Visual Studio that matches the version of Visual Studio your OpenFrameworks clone is using**
 4. Upgrade node projects in visual studio if needed
 5. Change all code generation flags to /MD or /MDd
 6. Build.

After building Node, it's time for Googletest to be compiled:

 1. Navigate to %NOFX_GTEST%
 2. open up `msvc\gtest.sln` in a **Visual Studio that matches the version of Visual Studio your OpenFrameworks clone is using**
 3. Upgrade Gtest projects in visual studio if needed
 4. Add Preprocessor definition _VARIADIC_MAX=10 (only if you get std::tuples build errors, [take a look at this entry on SO][5])
 5. Change all code generation flags to /MD or /MDd
 6. Build.

The rest of the projects (OpenFrameworks, NaN, and nofx) will be built all together by builidng the **nofx.sln**.


  [1]: https://github.com/rvagg/nan
  [2]: https://github.com/joyent/node
  [3]: https://github.com/openframeworks/openFrameworks
  [4]: https://code.google.com/p/googletest/
  [5]: http://stackoverflow.com/a/8274747/1055628
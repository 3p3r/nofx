![nofx](/nofx/nofx.png?raw=true "Openframeworks Node bindings")

----------

Before opening the project make sure you have following variables (texts in bold) defined on your environment.

 - **[NOFX_NAN][1]**
 - **[NOFX_NODE][2]**
 - **[NOFX_OF][3]**

----------
The final folder structure for each environment variable should be as shown (assuming each project is cloned by Git):

    +------------+-------------+-------------------+
    |  NOFX_NAN  |  NOFX_NODE  |      NOFX_OF      |
    +----------------------------------------------+
    | │          | │           | │                 |
    | ├ nan      | ├ node      | ├ openFrameworks  |
    | │ │ .git   | │ │ .git    | │ │ .git          |
    | │ │ nan.h  | │ │ src/    | │ │ addons/       |
    | │ │ ...    | │ │ ...     | │ │ ...           |
    | │ └        | │ └         | │ └               |
    | ┴          | ┴           | ┴                 |
    +------------+-------------+-------------------+

***FOR WINDOWS ONLY:*** Also make sure before building all projects, you set the flag for **ALL** projects to **/MD** or **/MDd** in Visual Studio. OpenFrameworks can only be compiled with MD(d) flags (without headaches!)


----------

Build instructions (X-platform, for users)
-----------------------------

This module should be compatible with all platforms that Node **AND (&&)** OpenFrameworks support:

    npm install nofx

Install instructions (Windows, for hackers):
-----------------------------
**After defining environment variables**, you may start building nofx. The first step in building nofx, is building Node (duh!). You should build Node **before** anything else. nofx expects to see Node's libraries and headers before it can compile. For compiling Node:

 1. Navigate to %NOFX_NODE%
 2. run `vcbuild.bat nobuild nosign`
 3. open up `node.sln` in a **Visual Studio that matches the version of Visual Studio your OpenFrameworks clone is using**
 4. Upgrade node projects in visual studio if needed
 5. Change all code generation flags to /MD or /MDd
 6. Build.

The rest of the projects (OpenFrameworks, NaN, and nofx_*) will be built all together by building the **nofx.sln**. `Bindings.gyp`s will get generated automatically for you.

Adding bindings instructions (Windows, for hackers):
-----------------------------

 1. Add one of the supplied MSVC templates to your visual studio.
 2. Add a new project with that template and add your bindings.
 2. Set the **nofx** project in **nofx.sln** to be the start-up project.
 3. Add every other projects you see in the style of nofx_* as nofx dependency.
 4. Build.

  [1]: https://github.com/rvagg/nan
  [2]: https://github.com/joyent/node
  [3]: https://github.com/openframeworks/openFrameworks
  [4]: https://code.google.com/p/googletest/
  [5]: http://stackoverflow.com/a/8274747/1055628
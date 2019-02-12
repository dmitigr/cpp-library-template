The C++ library template {#mainpage}
====================================

The implementation is aimed to be as simple as possible (maybe even "dumb") for
better understanding and correctness.

**ATTENTION, this software is "alpha" quality, use at your own risk!**

Any [feedback][dmitigr_mailbox] (*especially results of testing*) is highly appreciated!

Features
========

Not implemented yet. Work in progress.

Example
=======

```cpp
// Example will be provided soon.
```

Download
========

The Dmitigr The_cpp_library repository is located at Github [here][dmitigr_github].

Installation and consuming
==========================

Dependencies
------------

- [CMake] build system version 3.13+;
- C++17 compiler ([GCC] 7.3+ or [Microsoft Visual C++][Visual_Studio] 15.7+);
- [dmitigr_internal] library.

Build time settings
-------------------

Settings that may be specified at build time by using [CMake] variables are:
  1. the type of the build (only meaningful to single-configuration generators);
  2. the flag to build the shared library (default is on);
  3. the flag to only install the header-only library (default is off);
  4. the flag to build the tests (default is on);
  5. installation directories.

Details:

|CMake variable|Possible values|Default on Unix|Default on Windows|
|:-------------|:--------------|:--------------|:-----------------|
|**The type of the build**||||
|CMAKE_BUILD_TYPE|Debug \| Release \| RelWithDebInfo \| MinSizeRel|Debug|Debug|
|**The flag to build the shared library**||||
|BUILD_SHARED_LIBS|On \| Off|On|On|
|**The flag to only install the header-only library**||||
|DMITIGR_THE_CPP_LIBRARY_HEADER_ONLY|On \| Off|Off|Off|
|**The flag of building the tests**||||
|DMITIGR_THE_CPP_LIBRARY_BUILD_TESTS|On \| Off|On|On|
|**Installation directories**||||
|CMAKE_INSTALL_PREFIX|*an absolute path*|"/usr/local"|"%ProgramFiles%\dmitigr_the_cpp_library"|
|DMITIGR_THE_CPP_LIBRARY_CMAKE_INSTALL_DIR|*a path relative to CMAKE_INSTALL_PREFIX*|"share/dmitigr_the_cpp_library/cmake"|"cmake"|
|DMITIGR_THE_CPP_LIBRARY_DOC_INSTALL_DIR|*a path relative to CMAKE_INSTALL_PREFIX*|"share/dmitigr_the_cpp_library/doc"|"doc"|
|DMITIGR_THE_CPP_LIBRARY_LIB_INSTALL_DIR|*a path relative to CMAKE_INSTALL_PREFIX*|"lib"|"lib"|
|DMITIGR_THE_CPP_LIBRARY_INCLUDE_INSTALL_DIR|*a path relative to CMAKE_INSTALL_PREFIX*|"include"|"include"|

Installation in common
----------------------

Dmitigr The_cpp_library is depends on [dmitigr_internal].

**WARNING** It's highly recommended to update the [dmitigr_internal] library (just pull and reinstall)
before every build of the Dmitigr The_cpp_library library!

Installation on Linux
---------------------

    $ git clone https://github.com/dmitigr/the-cpp-library.git
    $ mkdir -p the-cpp-library/build
    $ cd the-cpp-library/build
    $ cmake -DCMAKE_BUILD_TYPE=Debug ..
    $ make
    $ sudo make install

Installation on Microsoft Windows
---------------------------------

Run the Developer Command Prompt for Visual Studio and type:

    > git clone https://github.com/dmitigr/the-cpp-library.git
    > mkdir the-cpp-library\build
    > cd the-cpp-library\build
    > cmake -G "Visual Studio 15 2017 Win64" ..
    > cmake --build . --config Debug

Next, run the Elevated Command Prompt (i.e. the command prompt with administrator privileges) and type:

    > cd the-cpp-library\build
    > cmake -DBUILD_TYPE=Debug -P cmake_install.cmake

To make the installed DLL available for *any* application that depends on it, the symbolic link to the
dmitigr_the_cpp_library.dll (or to the debug version - dmitigr_the_cpp_libraryd.dll) should be created:

  - in %SYSTEMROOT%\System32 for the 64-bit DLL on 64-bit host (or for 32-bit DLL on 32-bit host);
  - in %SYSTEMROOT%\SysWOW64 for the 32-bit DLL on 64-bit host.

To create the symbolic link run the Elevated Command Prompt and use `mklink` command, for example:

    > cd /d %SYSTEMROOT%\System32
    > mklink dmitigr_the_cpp_libraryd.dll "%ProgramFiles%\dmitigr_the_cpp_library\lib\dmitigr_the_cpp_libraryd.dll"

Consuming
---------

If you are using CMake the consuming of the Dmitigr The_cpp_library library is quite simple. For example:

```cmake
cmake_minimum_required(VERSION 3.13)
project(foo)
find_package(dmitigr_the_cpp_library REQUIRED) # find shared version of the Dmitigr The_cpp_library library
set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
add_executable(foo foo.cpp)
target_link_libraries(foo dmitigr_the_cpp_library)
```

The above code snippet is minimal CMakeLists.txt that enough to build the
application `foo` that depends on the Dmitigr The_cpp_library library.

To consume the header-only version of the Dmitigr The_cpp_library library just specify it by using
`CONFIGS` option of [find_package][cmake_find_package]:

```cmake
find_package(dmitigr_the_cpp_library REQUIRED CONFIGS dmitigr_the_cpp_library_interface-config.cmake)
# ...
target_link_libraries(foo dmitigr_the_cpp_library_interface)
```

License
=======

Dmitigr The_cpp_library is distributed under zlib license. For conditions of distribution and use,
see file `LICENSE.txt`.

Donations
=========

Dmitigr The_cpp_library has been developed on the own funds. Donations are welcome! To make
a donation, please go [here][dmitigr_paypal].

Feedback
========

Any feedback are welcome. [Contact us][dmitigr_mailbox].

Copyright
=========

Copyright (C) Dmitry Igrishin

[dmitigr_mailbox]: mailto:dmitigr@gmail.com
[dmitigr_paypal]: https://paypal.me/dmitigr
[dmitigr_github]: https://github.com/dmitigr/the-cpp-library.git
[dmitigr_internal]: https://github.com/dmitigr/internal.git

[cmake_find_package]: https://cmake.org/cmake/help/latest/command/find_package.html

[CMake]: https://cmake.org/
[GCC]: https://gcc.gnu.org/
[Visual_Studio]: https://www.visualstudio.com/

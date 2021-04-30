# C++ Template Project

Author: Dr. Christian Bruccoleri

This is a set of files to implement a quick start project in C++ with gcc and
Visual Studio compilers. This is not the simplest configuration possible for
trivial programs, it is meant for programs that include multiple libraries and
comprehensive testing. Of course, you can use it for smaller programs too.

## What does this project contain out of the box?

This project is a basic template for a non-trivial C++ application which may
have dependencies on other libraries, need to define unit tests, and integration
with other best-practice toolsets for professional development. It is a work in
progress and will need to be frequently updated to keep up with the changes.

Here are some goals:

- At a minimum, it should build without modifications on Linux, Windows, and
  Mac.

- Support GTest as Unit Testing framework

- Support CTest for test automation through CMake

- Support Conan for libraries and dependency management

- Be ready for integration with Git

## What is the structure of this project?

This very simple project builds an executable called `cpptemplate` and a test
executable called `test_suite`. The two programs use code defined in a library,
`somelib` which is statically linked simply by including the source files in the
build of the two executables. The library is not built separately as a `.a`
(Linux) or `.lib` (Windows) because this is not the intended use case for this
code.

This structure is well suited to the type of programs I tend to write more
often, in which there is some functionality that I am implementing and then
demonstrating in a demo program. It works well for small programs, if you are
working on a larger project this structure is not ideal. In the latter case, a
breakdown of the project into separate modules (libraries) is probably best.

Having a separate test executable allows us to use CTest to thoroughly validate
the functionality being implemented by the library. It is possible to write many
tests that are not part of the main demo, but help during development and
debugging.

## Quick Reference: Conan and CMake

- [Documentation](https://docs.conan.io/en/latest/getting_started.html)
- [Conan Center](https://conan.io/center/)

0. Install conan: `pip install conan`
1. Find libraries: `conan search <libname> --remote=conan-center`
2. Create `conanfile.txt` in the main project folder, sections: `[requires]`,
   `[generators]`
3. Run conan in build folder: `conan install ..`
4. Integrate conan with CMake
5. Build!
    - `cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug`
    - `cmake --build .`
6. Test

Note: conan-centre may not have the latest build of GTest for the compiler that
you are using. Thus, you can rebuild GTest with Conan using the compiler you
have on your system. Here is an example for g++ v9.3.

```bash
# if you want to specify the compiler
conan install .. -s compiler.version=9.3 --build=missing`

# if you want to use the default compiler
conan install .. --build=missing`
```

Running CTest can be done with the help of an IDE, e.g. Visual Studio Code and others, or directly at the command line.
CTest must be run specifying where the test executable is. Example:

```bash
cd build
ctest bin
```

## License

This program is licensed using the MIT License. Generally speaking, it means you
can do anything you like with it. See the `LICENSE` file for details.

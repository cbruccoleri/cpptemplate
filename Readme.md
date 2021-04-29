# C++ Template Project

This is a set of files to implement a quick start project in C++ with gcc and
Visual Studio compilers.

## What is this project?

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

## QRF: Conan

- [Documentation](https://docs.conan.io/en/latest/getting_started.html)
- [Conan Center](https://conan.io/center/)

0. Install conan: `pip install conan`
1. Find libraries: `conan search <libname> --remote=conan-center`
2. Create `conanfile.txt` in the main project folder, sections: `[requires]`, `[generators]`
3. Run conan in build folder: `conan install ..`
4. Integrate conan with CMake
5. Build!
    - `cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug`
    - `cmake --build .`
6. Test

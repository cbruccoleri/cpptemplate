cmake_minimum_required(VERSION 3.11...3.16)
project(cpptemplate 
    VERSION 0.1.0
    LANGUAGES CXX)

# Note: it is assumed that you want to build a target having the same name as 
# the project. Replace ${PROJECT_NAME} as the target if needed.

# Require C++ 17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Support for Conan dependency manager
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
# The following ignores checking compiler version in the conan profile.
# If you need a specific compiler version, comment this out and use an
# appropriate Conan profile.
set(CONAN_DISABLE_CHECK_COMPILER ON)


# Enable support for CTest
include(CTest)
enable_testing()
# TODO: add your tests here
# 


# TODO: add your files here (*.cpp, *.h)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})


# Turn on all warnings and do not allow ignoring them.
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    # Consider adding also: -Werror
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()


#TODO: Do I need this?
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

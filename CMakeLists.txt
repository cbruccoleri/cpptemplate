cmake_minimum_required(VERSION 3.11...3.20)
project(cpptemplate 
    VERSION 0.1.0
    LANGUAGES CXX)

# Note: it is assumed that you want to build a target having the same name as 
# the project. Replace ${PROJECT_NAME} with the name you want if needed.
set(TARGET_NAME ${PROJECT_NAME})

# This is the name of the test executable
set(TEST_TARGET_NAME test_suite)

# Require C++ 17 standard. Change as you see fit.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


#### CONAN
# Support for Conan dependency manager
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


#### CTEST
# Enable support for CTest
include(CTest)
enable_testing()

# TODO: add your tests here. One is provided below as an example.
add_test(BasicTester bin/${TEST_TARGET_NAME})


#### PROJECT FILES
# TODO: add your files here (*.cpp, *.h) A basic configuration is provided as 
# an example
set(SOURCES 
    src/somelib.cpp
)

set(HEADERS 
    include/somelib.h
)

#### TARGETS
add_executable(${TARGET_NAME} src/main.cpp ${SOURCES} ${HEADERS})
target_link_libraries(${TARGET_NAME} ${CONAN_LIBS})
target_include_directories(${TARGET_NAME} PUBLIC include)

add_executable(${TEST_TARGET_NAME} tests/tests.cpp ${SOURCES} ${HEADERS})
target_link_libraries(${TEST_TARGET_NAME} ${CONAN_LIBS} ${GTEST_LIBS})
target_include_directories(${TEST_TARGET_NAME} PUBLIC include)

# Turn on all warnings
if(MSVC) # Visual Studio on Windows
    target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
else() # most other platforms
    # Consider adding also: -Werror
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()


#TODO: Do I need this?
set(CPACK_TARGET_NAME ${TARGET_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

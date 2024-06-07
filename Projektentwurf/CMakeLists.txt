# Define the minimum CMake version
cmake_minimum_required(VERSION 3.20)

# Define the project name
project(Project_2 VERSION 1.0 LANGUAGES CXX)

# Define the C++ standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add some compile options
add_compile_options(-Wall -Wextra -pedantic)

# Add a library for the functions
add_library(uni_library STATIC src/developer.cpp)

# Add the includes to the library
target_include_directories(uni_library PUBLIC include)

# Add an executable and assign files to it
add_executable(library_ex_exec src/main.cpp)

# Add the include directory to the executable
target_include_directories(library_ex_exec PUBLIC include)

# Link the library to the executable
target_link_libraries(library_ex_exec PRIVATE uni_library)

# Enable testing
enable_testing()

# Check if we have GTest
find_package(GTest REQUIRED)

# Include the GTest CMake stuff
include(GoogleTest)

# Create a test executable
add_executable(tests test/test_developer_struct.cpp)

# Link the GTest libraries
target_link_libraries(tests PRIVATE GTest::GTest GTest::Main)

# Link the library we want to test
target_link_libraries(tests PRIVATE uni_library)

# Add the include directories
target_include_directories(tests PUBLIC include)

# Discover and add tests to the test list
gtest_discover_tests(tests)

# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(Project_2 VERSION 1.0 LANGUAGES CXX)

# define the c++ standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -pedantic)

# add a library for the functions
add_library(uni_library STATIC 
src/developer.cpp
src/junior_developer.cpp
src/senior_developer.cpp)

# add the includes to the library
target_include_directories(uni_library PUBLIC include)

# add an executabel and assign files to it
add_executable(library_ex_exec src/main.cpp)
# add the include directory
target_include_directories(library_ex_exec PUBLIC include)
# link the library
target_link_libraries(library_ex_exec PRIVATE  uni_library)




// gtest:
enable_testing()
# check if we have gtest
find_package(GTest REQUIRED)
# include the gtest CMake stuff
include(GoogleTest)
# create a test executable
add_executable(tests test/test_developer_struct.cpp)
# link the gtest libraries
target_link_libraries(tests PRIVATE GTest::GTest GTest::Main)
# link the library we want to test
target_link_libraries(tests PRIVATE uni_library)
# add the include directories
target_include_directories(tests PUBLIC include)
# discover and add tests to the test list
gtest_discover_tests(tests)
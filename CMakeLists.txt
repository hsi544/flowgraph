project(flowGraph)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/lib)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources 
    main.cpp 
    Image2D.cpp
    Image2DTest.cpp)
add_executable(testImage2D ${sources})
target_link_libraries(testImage2D pthread)
target_link_libraries(testImage2D gmock)
target_link_libraries(testImage2D gtest)


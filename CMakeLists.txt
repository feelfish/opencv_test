cmake_minimum_required(VERSION 2.8)
SET(CMAKE_BUILD_TYPE Debug )
add_definitions(-std=c++11)
project(opencv_test)
#set(OpenCV_DIR /opt/opencv24/opencv-2.4.13)
set(CUDA_USE_STATIC_CUDA_RUNTIME OFF)
find_package(OpenCV REQUIRED)
include_directories(myheaders)
add_executable(${PROJECT_NAME}
    "main.cpp"
    "pathfinder.cpp"
    "control_gui.cpp"
    "carfinder.cpp"
    "main.h"
    "myheaders/pathfinder.h"
    "control_gui.h"
    "carfinder.h"
    )
target_link_libraries(opencv_test ${OpenCV_LIBS})

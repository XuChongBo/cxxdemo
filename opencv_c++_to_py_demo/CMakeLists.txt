cmake_minimum_required(VERSION 2.8.7)
#set(CMAKE_CXX_COMPILER "g++")

# ---[ project
PROJECT(examples C CXX)
INCLUDE_DIRECTORIES(/usr/include/python2.7/)
FILE(GLOB SOURCE_1 "${PROJECT_SOURCE_DIR}/*.cpp")
add_library(examples  SHARED ${SOURCE_1})

SET(depend_libs "-lopencv_contrib -lopencv_highgui  -lopencv_imgproc -lopencv_core ")
target_link_libraries(examples  libboost_python.so libpython2.7.so)
TARGET_LINK_LIBRARIES(examples  ${depend_libs})
set_target_properties(examples  PROPERTIES COMPILE_FLAGS " -shared -fPIC -std=c++11 ") 
SET_TARGET_PROPERTIES(examples PROPERTIES PREFIX "" OUTPUT_NAME "examples")


cmake_minimum_required(VERSION 2.8.7)
#set(CMAKE_CXX_COMPILER "g++")

# ---[ project
PROJECT(chg_py C CXX)
INCLUDE_DIRECTORIES(/usr/include/python2.7/)
FILE(GLOB SOURCE_1 "${PROJECT_SOURCE_DIR}/*.cc")
add_library(chg_py SHARED ${SOURCE_1})
target_link_libraries(chg_py libboost_python.so libpython2.7.so)

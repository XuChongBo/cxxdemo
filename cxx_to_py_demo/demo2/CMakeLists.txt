cmake_minimum_required(VERSION 2.8.7)

INCLUDE_DIRECTORIES(/usr/include/python2.7/)
INCLUDE_DIRECTORIES(/usr/lib/python2.7/config)

FILE(GLOB SOURCE_1 "${PROJECT_SOURCE_DIR}/python/*.cpp")
add_library(pytwocr SHARED ${SOURCE_1})
TARGET_LINK_LIBRARIES(pytwocr ${TWOCR_LINK})
SET_TARGET_PROPERTIES(pytwocr PROPERTIES COMPILE_FLAGS "-g -O3 -shared -fPIC") 
SET_TARGET_PROPERTIES(pytwocr PROPERTIES PREFIX "" OUTPUT_NAME "ocr")  #setprefix is "" to avoid generate the libxx.so

GET_TARGET_PROPERTY(v, pytwocr, OUTPUT_NAME) 
MESSAGE(STATUS "the output name of pytwocr is ${v}")
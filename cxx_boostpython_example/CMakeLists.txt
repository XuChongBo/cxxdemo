cmake_minimum_required(VERSION 2.8.7)

INCLUDE_DIRECTORIES(/usr/include/python2.7/)
INCLUDE_DIRECTORIES(/usr/lib/python2.7/config)
SET(depend_libs "-lopencv_contrib -lopencv_highgui  -lopencv_imgproc -lopencv_core")

FILE(GLOB SOURCE_1 "${PROJECT_SOURCE_DIR}/python/*.cpp")
FILE(COPY test.py DESTINATION "${PROJECT_BINARY_DIR}/python/")   

ADD_LIBRARY(pytwocr SHARED ${SOURCE_1})

TARGET_LINK_LIBRARIES(pytwocr  ${TWOCR_LINK})
TARGET_LINK_LIBRARIES(pytwocr  libboost_python.so libpython2.7.so)
TARGET_LINK_LIBRARIES(pytwocr  ${depend_libs})
TARGET_LINK_LIBRARIES(pytwocr ${twocr_depend_libs})  

SET_TARGET_PROPERTIES(pytwocr PROPERTIES COMPILE_FLAGS " -O3 -shared -fPIC -std=c++11") 
SET_TARGET_PROPERTIES(pytwocr PROPERTIES PREFIX "" OUTPUT_NAME "ocr")  #setprefix is "" to avoid generate the libxx.so
GET_TARGET_PROPERTY(v, pytwocr, OUTPUT_NAME) 


MESSAGE(STATUS "the output name of pytwocr is ${v}")
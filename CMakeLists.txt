cmake_minimum_required(VERSION 2.8.4)
project(SwigCallbacks)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
)
add_executable(SwigCallbacks ${SOURCE_FILES})

# Python.
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})
target_link_libraries(SwigCallbacks ${PYTHON_LIBRARIES})

# SWIG.
set(SWIG_LIBRARY_NAME module)
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
set(CMAKE_SWIG_OUTDIR "${CMAKE_BINARY_DIR}")
set(CMAKE_SWIG_FLAGS "")

set_source_files_properties(${PROJECT_SOURCE_DIR}/module.i PROPERTIES CPLUSPLUS ON)
set_source_files_properties(${PROJECT_SOURCE_DIR}/module.i PROPERTIES SWIG_FLAGS "-I${PROJECT_SOURCE_DIR}")
swig_add_module(${SWIG_LIBRARY_NAME} python ${PROJECT_SOURCE_DIR}/module.i ${SOURCE_FILES})
swig_link_libraries(${SWIG_LIBRARY_NAME} ${PYTHON_LIBRARIES})
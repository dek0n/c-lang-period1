cmake_minimum_required(VERSION 3.0.0)
project(csv_reader_project_v1 VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(csv_reader_project_v1 main.c functions.c functions.h)

configure_file(temperatures.csv ${CMAKE_BINARY_DIR}/temperatures.csv COPYONLY)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

cmake_minimum_required(VERSION 2.8) 
project(xop)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src SRC_LIST)
file(GLOB SRC_HEADER "${CMAKE_CURRENT_LIST_DIR}/src/*.h")

#C++11
#add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(${CMAKE_CURRENT_LIST_DIR}/src)

install(FILES ${SRC_HEADER} DESTINATION ${PROJECT_BINARY_DIR}/include)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#生成动态库
add_library(${CMAKE_PROJECT_NAME}_shared SHARED ${SRC_LIST})
set_target_properties(${CMAKE_PROJECT_NAME}_shared PROPERTIES OUTPUT_NAME "${CMAKE_PROJECT_NAME}")
install(TARGETS ${CMAKE_PROJECT_NAME}_shared LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/lib)

#生成静态库
add_library(${CMAKE_PROJECT_NAME}_static STATIC ${SRC_LIST})
set_target_properties(${CMAKE_PROJECT_NAME}_static PROPERTIES OUTPUT_NAME "${CMAKE_PROJECT_NAME}")
install(TARGETS ${CMAKE_PROJECT_NAME}_static ARCHIVE DESTINATION ${PROJECT_BINARY_DIR}/lib)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#生成example
add_subdirectory(example)



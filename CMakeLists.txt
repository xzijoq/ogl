cmake_minimum_required(VERSION 2.8.9)
project (opgl)

set(glfw glfw.lib) #TODO if windows else set libglfw
set(CMAKE_CXX_FLAGS "-Wall -g ")
include_directories (${CMAKE_SOURCE_DIR}/include/ )
link_directories(${CMAKE_SOURCE_DIR}/lib/  /usr/include)
set(SOURCES ${CMAKE_SOURCE_DIR}/src/glad.cpp ${CMAKE_SOURCE_DIR}/src/main.cpp)

add_executable (ogl ${SOURCES})
target_link_libraries(ogl  ${CMAKE_SOURCE_DIR}/lib/glfw3.lib )
#target_link_libraries(ogl  ${CMAKE_SOURCE_DIR}/lib/libglfw  -lX11  -lXrandr -lXxf86vm -lXinerama -lXcursor  -pthread -ldl  )

#-lGL -lXi -lm -lrt
#export(EXPORT $(CMAKE_SOURCE_DIR) FILE yo.cmake)
cmake_minimum_required(VERSION 3.8)
project (ogl VERSION 1.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#Find sdl2 and glm if possible; however were using glfw anyway
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
find_package(GLM)
find_package(SDL2)

add_executable(ogl ./src/main.cpp ./src/glad.c)
target_include_directories(ogl PUBLIC include lib ${GLM_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})
target_link_directories(ogl PUBLIC lib)
target_link_libraries(ogl -lglfw3 -lX11  -lXrandr -lXxf86vm -lXinerama -lXcursor  -pthread -ldl )

#for windows need to merge
#target_link_libraries(ogl  glfw3)


#-lGL -lXi -lm -lrt



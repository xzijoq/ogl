#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include "user/data.h"
#include "user/initWinGlfw.h"

int main()
{
 // macro expantion from include initWinGlfw
  initWinGLfw;
  gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress );

  while ( !glfwWindowShouldClose( window ) ) //to make compatable with sdl?
  {
    glfwPollEvents();
  }
}


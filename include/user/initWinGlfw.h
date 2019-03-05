#include "user/glContextData.h"


// for glfw, may redfine using 
#define initWinGLfw GLFWwindow* window = nullptr;\
  glfwInit();\
  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, windowData::oglMajor );\
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, windowData::oglMinor );\
  glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );\
  window = glfwCreateWindow( windowData::scWid, windowData::scHei, "uo", 0, 0 );\
  glfwMakeContextCurrent( window );\



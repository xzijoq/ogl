#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "user/data.h"
#include "user/initWindow.h"

std::string parseShader( const std::string &filepath );

unsigned int       compileShader( unsigned int type, const std::string &src );
unsigned int       createProgram( const std::string &vertextShaderSource,
                                  const std::string &fragmentShaderSource );
extern GLFWwindow *window;

//----------MAIN STARTS--------------------------

int main()
{
  initWinGlfw();

  std::string vertex_shader_source = parseShader( "./res/shaders/shader.vert" );
  std::string fragment_shader_source =
  parseShader( "./res/shaders/shader.frag" );
  createProgram( vertex_shader_source, fragment_shader_source );
  std::cout << glGetString( GL_VERSION );
  unsigned int vbo, vao, ebo;
  glGenVertexArrays( 1, &vao );
  glBindVertexArray( vao );

  glGenBuffers( 1, &vbo );
  glBindBuffer( GL_ARRAY_BUFFER, vbo );
  glBufferData( GL_ARRAY_BUFFER, sizeof( vertices ), vertices, GL_STATIC_DRAW );

  glGenBuffers( 1, &ebo );
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ebo );
  glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices,
                GL_STATIC_DRAW );

  // bind array data to shader
  glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ),
                         (void *)0 );
  glEnableVertexAttribArray( 0 );
  glVertexAttribPointer( 1, 4, GL_FLOAT, GL_FALSE, sizeof( float ),
                         (void *)( 12 * sizeof( float ) ) );
  glEnableVertexAttribArray( 1 );

  glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );

  while ( !glfwWindowShouldClose( window ) )  // to make compatable with sdl?
  {
    int width, height;
    glfwGetFramebufferSize( window, &width, &height );

        glClear( GL_COLOR_BUFFER_BIT );
    glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );

    glfwSwapBuffers( window );
    glfwWaitEvents();
  }
}

//--------------------END MAIN------------------------------------
unsigned int createProgram( const std::string &vertexShaderSource,
                            const std::string &fragmentShaderSource )
{
  unsigned int pid = glCreateProgram();
  unsigned int vsId = compileShader( GL_VERTEX_SHADER, vertexShaderSource );
  unsigned int fsId = compileShader( GL_FRAGMENT_SHADER, fragmentShaderSource );
  glAttachShader( pid, vsId );
  glAttachShader( pid, fsId );
  glLinkProgram( pid );

  int  result;
  char infoLog[ 512 ];
  glGetProgramiv( pid, GL_LINK_STATUS, &result );
  if ( result == false )
  {
    glGetProgramInfoLog( pid, 512, NULL, infoLog );
    std::cout << "Gl LINKER ERROR: " << std::endl << infoLog;
  }
  glUseProgram( pid );
  glDeleteShader( vsId );
  glDeleteShader( fsId );
  return pid;
}
unsigned int compileShader( unsigned int type, const std::string &src )
{
  unsigned int id = glCreateShader( type );
  const char * code = src.c_str();
  // std::cout<<src.c_str();
  glShaderSource( id, 1, &code, NULL );
  glCompileShader( id );
  // error checking
  int  result;
  char infoLog[ 512 ];
  glGetShaderiv( id, GL_COMPILE_STATUS, &result );
  if ( result == false )
  {
    glGetShaderInfoLog( id, 512, NULL, infoLog );
    std::cout << "SHADER COMPILE ERROR: " << std::endl << infoLog;
  }
  return id;
}

std::string parseShader( const std::string &filepath )
{
  std::string       line;
  std::stringstream ss;
  std::ifstream     streamSh;  // input stream
  streamSh.open( filepath );   // check for faliure
  if ( !streamSh )
  {
    std::cout << "\n XERROR: failed to open shader file: \n"
              << "try running the exe from it's own directory\n"
              << "as the shaders are loaded (compiled and linked) at run \n";
  }
  while ( getline( streamSh, line ) )  // takes line by like data (end of line)
                                       // from stream and put it into line
  {
    ss << line << "\n";
  }
  return ss.str();
}


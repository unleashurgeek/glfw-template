#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "game.h"

int main() {
  std::cout << "Starting OpenGL Test" << std::endl;
  int width = 640;
  int height = 480;
  if (glfwInit() == GL_FALSE) {
    std::cout << "failed to init GLFW" << std::endl;
    return 1;
  }

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  glfwSwapInterval(1); // Enables/Disables vsync (some GPUs do not honor it)

  GLFWwindow* window;
  if ((window = glfwCreateWindow(width, height, "gltest", 0, 0)) == 0) {
    std::cout << "failed to open window" << std::endl;
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "failed to initialize OpenGL context" << std::endl;
    glfwDestroyWindow(window);
    glfwTerminate();
    return 1;
  }

  Game game = Game();

  GLdouble deltaTime = 0;
  GLdouble lastTime = 0;
#ifndef NDEBUG
  int frames = 0;
  GLdouble fpsTime = glfwGetTime();
#endif

  game.init();

  while (!glfwWindowShouldClose(window)) {
    GLdouble currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;
    glfwPollEvents();

#ifndef NDEBUG
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
      std::cout << error << std::endl;
      break;
    }
#endif

    game.update(deltaTime);

    game.draw();

#ifndef NDEBUG
    frames++;
    if (glfwGetTime() - fpsTime >= 1.0) {
      std::cout << "FPS: " << frames << " Avg dt: " << 1000.0/(double)frames << std::endl;
      frames = 0;
      fpsTime = glfwGetTime();
    }
#endif

    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
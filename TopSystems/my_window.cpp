#include <chrono>
#include <iostream>

#include "glfw3.h"
#include "my_window.h"

using namespace std::chrono_literals;

Window::Window(window_params_t params, const char* name) {

  if (!glfwInit()) {
    throw std::runtime_error("glfwInit failed");
  }

  window_ = glfwCreateWindow(params.width, params.height, name, NULL, NULL);
  if (!window_) {
    glfwTerminate();
    throw std::runtime_error("glfwCreateWindow failed");
  }
}

void Window::render_opengl_wrapper() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawer_->draw();
  glfwSwapBuffers(window_);
  glfwPollEvents();
}

static std::chrono::milliseconds now_milliseconds() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
}

void Window::render_fps_wrapper() {
  static auto time_start = now_milliseconds();
  static std::chrono::milliseconds lag(0ms);
  static std::chrono::milliseconds timestep(1000ms / WINDOW_FPS);

  auto now = now_milliseconds();
  auto delta_time = now - time_start;
  time_start = now;
  lag += std::chrono::duration_cast<std::chrono::milliseconds>(delta_time);

  while (lag >= timestep) {
    lag -= timestep;
    render_opengl_wrapper();
  }
}

void Window::set_drawer(Drawer* drawer) {
  drawer_ = drawer;
}

void Window::render() {
  if (!drawer_) {
    return;
  }

  glfwMakeContextCurrent(window_);
  while (!glfwWindowShouldClose(window_)) {
    render_fps_wrapper();
  }
}

Window::~Window() {
  glfwTerminate();
}




#pragma once

#include "glfw3.h"
#include "drawer.h"
#include "window_params.h"


class Window {
public:
  Window(window_params_t params, const char* name);
  void set_drawer(Drawer* drawer);
  void render();
  ~Window();

private:
  GLFWwindow* window_;
  Drawer* drawer_;
  void render_opengl_wrapper();
  void render_fps_wrapper();
};
#pragma once

#include <vector>

#include "window_params.h"
#include "figure.h"
#include "figure_data.h"

class Drawer {
private:
  window_params_t params_;
  std::vector<Figure> figures;

public:
  Drawer(const window_params_t& params) : params_(params) {};
  void draw();
  void add_figure(Figure fig);
};

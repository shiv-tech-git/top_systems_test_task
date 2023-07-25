#include <algorithm>

#include "glfw3.h"

#include "figure_data.h"
#include "window_params.h"
#include "drawer.h"


void Drawer::draw() {
  for (Figure& fig : figures) {
    fig.draw(params_);
  }
}

void Drawer::add_figure(Figure fig) {
  figures.push_back(fig);
}
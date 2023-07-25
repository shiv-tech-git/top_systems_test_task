#include <iostream>

#include "my_window.h"
#include "drawer.h"
#include "utils.h"

void genetate_figures(const window_params_t& params, Drawer& drawer) {

  drawer.add_figure(random_circle(params));
  drawer.add_figure(random_circle(params));
  drawer.add_figure(random_circle(params));

  drawer.add_figure(random_square(params));
  drawer.add_figure(random_square(params));
  drawer.add_figure(random_square(params));

  drawer.add_figure(random_triangle(params));
  drawer.add_figure(random_triangle(params));
  drawer.add_figure(random_triangle(params));
}

int main(void) {
  srand(time(NULL));

  window_params_t win_params{ WINDOW_WIDTH, WINDOW_HEIGHT };
  Drawer drawer(win_params);
  genetate_figures(win_params, drawer);
  
  try {
    Window win{ win_params, WINDOW_NAME};
    win.set_drawer(&drawer);
    win.render();
  }
  catch (std::runtime_error& error) {
    std::cout << error.what() << std::endl;
    return 1;
  }

  return 0;
}
#include "glfw3.h"
#include "draw_figures.h"

#include <algorithm>

static point_2d_t coords_to_relative(const point_2d_t& point, const window_params_t& win_params) {
  point_2d_t res;
  res.x = point.x / win_params.width * 2 - 1;
  res.y = -1 * (point.y / win_params.height * 2 - 1);
  return res;
}

void update_position(const window_params_t& win_params, figure_common_data_t& data) {
  data.coords.x = data.coords.x + data.velocity.dir.x * data.velocity.speed;
  data.coords.y = data.coords.y + data.velocity.dir.y * data.velocity.speed;

  if (data.coords.x <= 0 || data.coords.x >= win_params.width) {
    data.velocity.dir.x *= -1;
  }

  if (data.coords.y <= 0 || data.coords.y >= win_params.height) {
    data.velocity.dir.y *= -1;
  }
}

void draw_figure(const window_params_t& win_params, square_data_t& data) {
  update_position(win_params, data);
  point_2d_t relative = coords_to_relative(data.coords, win_params);
  float side = (float)data.side / (float)win_params.height;
  float y_size = side / win_params.height * win_params.width;

  glBegin(GL_QUADS);
  glColor3f(data.color.red, data.color.green, data.color.blue);
  glVertex2f(relative.x, relative.y);
  glVertex2f(relative.x + side, relative.y);
  glVertex2f(relative.x + side, relative.y + y_size);
  glVertex2f(relative.x, relative.y + y_size);
  glEnd();
}

void draw_figure(const window_params_t& win_params, circle_data_t& data) {
  static const int num_segments = 64;

  update_position(win_params, data);
  point_2d_t relative = coords_to_relative(data.coords, win_params);

  glBegin(GL_POLYGON);
  glColor3f(data.color.red, data.color.green, data.color.blue);

  for (int ii = 0; ii < num_segments; ii++) {
    float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
    float x = (float)data.radius / (float)win_params.height * cosf(theta);
    float y = (float)data.radius / (float)win_params.height * sinf(theta) / win_params.height * win_params.width;
    glVertex2f(x + relative.x, y + relative.y);
  }
  glEnd();
}

void draw_figure(const window_params_t& win_params, triangle_data_t& data) {
  update_position(win_params, data);
  point_2d_t relative = coords_to_relative(data.coords, win_params);
  float size = (float)data.size / (float)win_params.height;

  glBegin(GL_TRIANGLES);
  glColor3f(data.color.red, data.color.green, data.color.blue);
  glVertex2f(relative.x - size / 2, relative.y);
  glVertex2f(relative.x + size / 2, relative.y);
  glVertex2f(relative.x, relative.y + size);
  glEnd();
}


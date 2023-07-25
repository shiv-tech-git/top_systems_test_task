#include <cmath>

#include "glfw3.h"
#include "utils.h"

vector_2d_t normalize_vector_2d(const vector_2d_t& vec) {
  vector_2d_t res;
  
  float mag = std::sqrt(vec.x * vec.x + vec.y * vec.y);
  res.x = vec.x / mag;
  res.y = vec.y / mag;

  return res;
}

// -1 : 1
inline static float rand_float_opengl() {
  int r = rand();
  int tmp = rand() % 1000;
  return static_cast<float> (tmp) / 500 - 1;
}

inline static float rand_float() {
  int r = rand();
  int tmp = rand() % 1000;
  return static_cast<float> (tmp) / 1000;
}

static int rand_int(int max) {
  return rand() % max;
}

static int rand_int(int min, int max) {
  return rand() % (max - min) + min;
}

vector_2d_t random_normalized_vector_2d() {
  vector_2d_t res;
  res.x = rand_float_opengl();
  res.y = rand_float_opengl();
  return normalize_vector_2d(res);
}

point_2d_t coords_to_relative(const point_2d_t& point, int max_width, int max_height) {
  point_2d_t res;
  res.x = point.x / max_width * 2 - 1;
  res.y = -1 * (point.y / max_height * 2 - 1);
  return res;
}


void random_figure_common_data(const window_params_t& params, figure_common_data_t& data) {
  data.coords.x = static_cast<float>(rand_int(params.width));
  data.coords.y = static_cast<float>(rand_int(params.height));

  data.velocity.dir = random_normalized_vector_2d();
  data.velocity.speed = static_cast<float>(rand_int(5, 10));

  data.color.red = rand_float();
  data.color.green = rand_float();
  data.color.blue = rand_float();
}

Figure random_triangle(const window_params_t& params) {
  triangle_data_t data;
  random_figure_common_data(params, data);
  data.size = rand_int(50, 200);
  return Figure{ data };
}

Figure random_square(const window_params_t& params) {
  square_data_t data;
  random_figure_common_data(params, data);
  data.side = rand_int(50, 200);
  return Figure{ data };
}

Figure random_circle(const window_params_t& params) {
  circle_data_t data;
  random_figure_common_data(params, data);
  data.radius = rand_int(50, 200);
  return Figure{ data };
}




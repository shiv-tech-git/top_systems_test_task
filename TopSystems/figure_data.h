#pragma once

typedef struct {
  float x;
  float y;
} point_2d_t;

typedef struct {
  float red;
  float green;
  float blue;
} color_t;

typedef struct {
  float x;
  float y;
} vector_2d_t;

typedef struct {
  vector_2d_t dir;
  float speed;
} velocity_t;

typedef struct {
  velocity_t  velocity;
  point_2d_t  coords;
  color_t     color;
} figure_common_data_t;

typedef struct square_data_tag : figure_common_data_t {
  int side;
} square_data_t;

typedef struct circle_data_tag : figure_common_data_t {
  int radius;
} circle_data_t;

typedef struct triangle_data_tag : figure_common_data_t {
  int size;
} triangle_data_t;



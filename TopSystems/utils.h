#pragma once

#include <chrono>

#include "figure.h"
#include "figure_data.h"
#include "window_params.h"

vector_2d_t normalize_vector_2d(const vector_2d_t&);
vector_2d_t random_normalized_vector_2d();
point_2d_t  coords_to_relative(const point_2d_t&, const window_params_t&);

Figure random_triangle(const window_params_t&);
Figure random_square(const window_params_t&);
Figure random_circle(const window_params_t&);


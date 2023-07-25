#pragma once

#include "window_params.h"
#include "figure_data.h"

void draw_figure(const window_params_t& win_params, square_data_t& data);
void draw_figure(const window_params_t& win_params, circle_data_t& data);
void draw_figure(const window_params_t& win_params, triangle_data_t& data);

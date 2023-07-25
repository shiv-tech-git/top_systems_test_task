#pragma once
#include <memory>
#include "draw_figures.h"

class Figure {
  struct IFigure {
    virtual ~IFigure() = default;
    virtual std::unique_ptr<IFigure> copy_() const = 0;
    virtual void draw(const window_params_t& win_params) = 0;
  };

  template <typename T>
  class FigureObject final : public IFigure {
  public:
    T data_;
    FigureObject(const T& x) : data_(x) {}
    std::unique_ptr<IFigure> copy_() const override {
      return std::make_unique<FigureObject>(*this);
    }
    virtual void draw(const window_params_t& win_params) {
      draw_figure(win_params, data_);
    }
  };

public:
  std::unique_ptr<IFigure> self_;

  template <typename T>
  Figure(T x) : self_(std::make_unique<FigureObject<T>>(std::move(x))) {}

  Figure& operator=(Figure x) noexcept {
    self_ = std::move(x.self_);
    return *this;
  }

  Figure(const Figure& fig) {
    self_ = fig.self_->copy_();
  }

  void draw(const window_params_t& win_params) {
    self_->draw(win_params);
  }
};

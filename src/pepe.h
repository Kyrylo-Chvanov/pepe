#pragma once

#include <raylib.h>

class Pepe {
 public:
  enum State {
    WANDERING,
    GRABBED,
  };
  Pepe() : state_{WANDERING} {}
  void Draw() const;
  void Update();
  State GetState() const { return state_; }
  void SetState(const State state) { state_ = state; }
 private:
  State state_;
};
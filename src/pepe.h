#pragma once

#include <raylib.h>

#include "animation.h"

constexpr FrameSize PEPE_FRAME_SIZE{16, 16};

class Pepe {
 public:
  enum State {
    WANDERING,
    GRABBED,
    BLINKING,
    FOCUS,
  };
  Pepe();
  ~Pepe() { UnloadTexture(texture_); }
  void Draw() const;
  void Update();
  State GetState() const { return state_; }
  void SetState(const State state) { state_ = state; }
  void FlipPepe(const bool flip) {
    animations_.FlipAnimation(flip);
  }

 private:
  void ProcessState();
  State state_;
  Texture2D texture_;
  AnimationPlayer animations_;
};
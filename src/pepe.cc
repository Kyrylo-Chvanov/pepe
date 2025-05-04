#include "pepe.h"

#include <raylib.h>

#include "animation.h"

Pepe::Pepe()
    : state_{WANDERING},
      texture_{LoadTexture("../assets/sprites/pepe/pepe.png")},
      animations_{texture_, PEPE_FRAME_SIZE} {
  animations_.AddAnimation("wander", Animation{1, 0, 0, 0});
  animations_.AddAnimation("blink", Animation{1, 1, 0, 0});
  animations_.AddAnimation("focus", Animation{1, 2, 0, 0});
  animations_.AddAnimation("grabbed", Animation{5, 3, 0, 1});
}

void Pepe::Draw() const {
  const int win_width{GetScreenWidth()};
  const int win_height{GetScreenHeight()};
  animations_.DrawAt(Rectangle{0, 0, static_cast<float>(win_width),
                               static_cast<float>(win_height)});
}

void Pepe::ProcessState() {
  if (state_ == State::FOCUS) {
    animations_.Play("focus");
  } else if (state_ == State::WANDERING) {
    animations_.Play("wander");
  } else if (state_ == State::BLINKING) {
    animations_.Play("blink");
  } else if (state_ == State::GRABBED) {
    animations_.Play("grabbed");
  }
}

void Pepe::Update() {
  animations_.Update();
  ProcessState();
}
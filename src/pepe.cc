#include "pepe.h"

#include <raylib.h>

#include "animation.h"

Pepe::Pepe()
    : state_{WANDERING},
      texture_{LoadTexture("../assets/sprites/pepe/pepe.png")},
      animations_{texture_, PEPE_FRAME_SIZE} {
  animations_.AddAnimation("idle", Animation{1, 0, 0, 1});
  animations_.Play("idle");
}

void Pepe::Draw() const {
  const int win_width{GetScreenWidth()};
  const int win_height{GetScreenHeight()};
  animations_.DrawAt(Rectangle{0, 0, static_cast<float>(win_width),
                               static_cast<float>(win_height)});
}

void Pepe::Update() { animations_.Update(); }
#include "pepe.h"
#include <raylib.h>

void Pepe::Draw() const {
  const int win_width{GetScreenWidth()};
  const int win_height{GetScreenHeight()};
  DrawCircle(win_width / 2.0f, win_height / 2.0f, win_height / 2.0f, WHITE);
}

void Pepe::Update() {}
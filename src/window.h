#pragma once

#include <raylib.h>

class Window {
 public:
  Window(const int width, const int height) : position_{} {
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_TOPMOST);
    InitWindow(width, height, "pepe");
    position_ = GetWindowPosition();
  }
  ~Window() { CloseWindow(); }

 private:
  Vector2 position_;
};
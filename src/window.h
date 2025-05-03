#pragma once

#include <raylib.h>

class Window {
 public:
  Window(const int width, const int height);
  ~Window() { CloseWindow(); }
  void Update();
  bool IsBeingDragged() { return IsMouseButtonDown(MOUSE_LEFT_BUTTON); }

 private:
  void ProcessDragging();
  Vector2 position_;
  Vector2 mouse_offset_;
};
#pragma once

#include <raylib.h>
#include <raymath.h>

class Window {
 public:
  Window(const int width, const int height);
  ~Window() { CloseWindow(); }
  void Update();
  bool IsBeingDragged() { return IsMouseButtonDown(MOUSE_RIGHT_BUTTON); }
  void MoveTo(const Vector2& position) {
    target_position_ = position;
    is_moving_ = true;
  }
  void MoveToRandomTarget() {
    MoveTo(GetRandomTarget());
  }
  bool IsMoving() const { return is_moving_; }
  void SetIsMoving(const bool value) { is_moving_ = value; }
  Vector2 GetMovementVector() { return target_position_ - position_; }

 private:
  Vector2 GetRandomTarget() const;
  void ProcessDragging();
  void ProcessSizeChanges();
  void ProcessMovement();
  bool is_moving_;
  Vector2 target_position_;
  Vector2 position_;
  Vector2 mouse_offset_;
};
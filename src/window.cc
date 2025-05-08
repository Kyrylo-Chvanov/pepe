#include "window.h"

#include <raylib.h>
#include <raymath.h>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cfloat>

Window::Window(const int width, const int height)
    : is_moving_{false},
      target_position_{},
      position_{},
      mouse_offset_{FLT_MAX, FLT_MAX} {
  SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_TOPMOST |
                 FLAG_WINDOW_UNDECORATED | FLAG_VSYNC_HINT);
  InitWindow(width, height, "pepe");
  position_ = GetWindowPosition();
}

void Window::ProcessDragging() {
  if (IsBeingDragged()) {
    sf::Vector2i mouse_position{sf::Mouse::getPosition()};
    if (FloatEquals(mouse_offset_.x, FLT_MAX)) {
      mouse_offset_ = Vector2{mouse_position.x - position_.x,
                              mouse_position.y - position_.y};
    }
    position_.x = mouse_position.x - mouse_offset_.x;
    position_.y = mouse_position.y - mouse_offset_.y;
    SetWindowPosition(position_.x, position_.y);
  } else {
    mouse_offset_ = Vector2{FLT_MAX, FLT_MAX};
  }
}

void Window::ProcessSizeChanges() {
  constexpr int SIZE_CHANGE{16};
  constexpr int MAX_WIN_SIZE{256};
  constexpr int MIN_WIN_SIZE{64};
  if (IsKeyPressed(KEY_EQUAL)) {
    int width{GetScreenWidth()};
    if (width < MAX_WIN_SIZE) {
      width += SIZE_CHANGE;
      SetWindowSize(width, width);
    }
  } else if (IsKeyPressed(KEY_MINUS)) {
    int width{GetScreenWidth()};
    if (width > MIN_WIN_SIZE) {
      width -= SIZE_CHANGE;
      SetWindowSize(width, width);
    }
  }
}

void Window::ProcessMovement() {
  if (is_moving_) {
    if (Vector2Distance(target_position_, position_) < 5) {
      is_moving_ = false;
    } else {
      constexpr int PEPE_SPEED{100};
      position_ +=
          Vector2Normalize(GetMovementVector()) * PEPE_SPEED * GetFrameTime();
      SetWindowPosition(position_.x, position_.y);
    }
  }
}

Vector2 Window::GetRandomTarget() const {
  const int current_monitor{GetCurrentMonitor()};
  const int monitor_width{GetMonitorWidth(current_monitor)};
  const int monitor_height{GetMonitorHeight(current_monitor)};
  const int screen_width{GetScreenWidth()};
  const int screen_height{GetScreenHeight()};
  return Vector2{static_cast<float>(GetRandomValue(
                     screen_width, monitor_width - screen_width)),
                 static_cast<float>(GetRandomValue(
                     screen_height, monitor_height - screen_height))};
}

void Window::Update() {
  ProcessDragging();
  ProcessSizeChanges();
  ProcessMovement();
}
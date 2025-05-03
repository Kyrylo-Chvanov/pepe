#include "window.h"

#include <raylib.h>
#include <raymath.h>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

Window::Window(const int width, const int height)
    : position_{}, mouse_offset_{MAXFLOAT, MAXFLOAT} {
  SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_TOPMOST |
                 FLAG_WINDOW_UNDECORATED | FLAG_VSYNC_HINT);
  InitWindow(width, height, "pepe");
  position_ = GetWindowPosition();
}

void Window::ProcessDragging() {
  if (IsBeingDragged()) {
    sf::Vector2i mouse_position{sf::Mouse::getPosition()};
    if (FloatEquals(mouse_offset_.x, MAXFLOAT)) {
      mouse_offset_ = Vector2{mouse_position.x - position_.x,
                              mouse_position.y - position_.y};
    }
    position_.x = mouse_position.x - mouse_offset_.x;
    position_.y = mouse_position.y - mouse_offset_.y;
    SetWindowPosition(position_.x, position_.y);
  } else {
    mouse_offset_ = Vector2{MAXFLOAT, MAXFLOAT};
  }
}

void Window::Update() { ProcessDragging(); }
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <raylib.h>

constexpr int kWinWidth = 200;
constexpr int kWinHeight = 200;

int main() {
  SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_UNDECORATED);
  InitWindow(kWinWidth, kWinHeight, "Pepe");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && IsCursorOnScreen()) {
      sf::Vector2i mouse_pos = sf::Mouse::getPosition();
      SetWindowPosition(mouse_pos.x - kWinWidth / 2, mouse_pos.y - kWinHeight / 2);
    }

    BeginDrawing();
      ClearBackground(BLANK);
      DrawCircle(kWinWidth / 2, kWinHeight / 2, 100, GREEN);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
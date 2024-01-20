#define DEBUG

#include <SFML/Window.hpp>
#include <raylib.h>

#ifdef DEBUG
#include <iostream>
#endif

int main() {

  Image pepe_sprite = LoadImage("sprites/pepe.png");
  const int kWinWidth = pepe_sprite.width;
  const int kWinHeight = pepe_sprite.height;

  SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_UNDECORATED);
  InitWindow(kWinWidth, kWinHeight, "Pepe");
  SetTargetFPS(60);

  Texture2D pepe = LoadTextureFromImage(pepe_sprite);
  UnloadImage(pepe_sprite);

  bool IsBeingDragged = false;

  while (!WindowShouldClose()) {
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && IsCursorOnScreen()) {
      IsBeingDragged = true;
    } else if (!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
      IsBeingDragged = false;
    }
    if (IsBeingDragged) {
      sf::Vector2i mouse_pos = sf::Mouse::getPosition();
      SetWindowPosition(mouse_pos.x - kWinWidth / 2, mouse_pos.y - kWinHeight / 2);
    }
    BeginDrawing();
      ClearBackground(BLANK);
      DrawTexture(pepe, 0, 0, WHITE);
    EndDrawing();
  }

  UnloadTexture(pepe);
  CloseWindow();
  return 0;
}
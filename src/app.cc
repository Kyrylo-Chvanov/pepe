#include "app.h"

#include <raylib.h>

#include "pepe.h"
#include "window.h"

constexpr int WIN_WIDTH{42};
constexpr int WIN_HEIGHT{42};

App::App() : window_{WIN_WIDTH, WIN_HEIGHT}, pepe_{} {}

void App::Update() { pepe_.Update(); }

void App::Draw() const {
  ClearBackground(BLANK);
  pepe_.Draw();
}

void App::Run() {
  while (!WindowShouldClose()) {
    Update();
    BeginDrawing();
    Draw();
    EndDrawing();
  }
}
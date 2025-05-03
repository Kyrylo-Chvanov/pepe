#include "app.h"

#include <raylib.h>

#include "pepe.h"
#include "window.h"

constexpr int WIN_WIDTH{42};
constexpr int WIN_HEIGHT{42};

App::App() : window_{WIN_WIDTH, WIN_HEIGHT}, pepe_{} {}

void App::Update() { 
  window_.Update();
  pepe_.Update();
  UpdatePepeState();
}

void App::UpdatePepeState() {
  if (window_.IsBeingDragged()) {
    pepe_.SetState(Pepe::State::GRABBED);
  } else {
    pepe_.SetState(Pepe::State::WANDERING);
  }
}

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
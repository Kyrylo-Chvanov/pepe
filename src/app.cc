#include "app.h"

#include <raylib.h>

#include "pepe.h"
#include "timer.h"
#include "window.h"

constexpr int WIN_WIDTH{64};
constexpr int WIN_HEIGHT{64};

App::App() : window_{WIN_WIDTH, WIN_HEIGHT}, pepe_{} {}

void App::Update() { 
  window_.Update();
  pepe_.Update();
  UpdatePepeState();
  ProcessPepeState();
}

void App::ProcessPepeState() {
  if (pepe_.GetState() == Pepe::State::WANDERING) {
    ProcessPepeWanderingState();
  } else if (pepe_.GetState() == Pepe::State::BLINKING) {
    ProcessPepeBlinkingState();
  } else {
    window_.SetIsMoving(false);
  }
}

void App::ProcessPepeWanderingState() {
  static Timer timer{0};
  if (!window_.IsMoving()) {
    if (timer.IsStopped()) {
      timer.SetLifeTime(GetRandomValue(2, 5));
      timer.Start();
    } else if (timer.Done()) {
      window_.MoveToRandomTarget();
      pepe_.FlipPepe(window_.GetMovementVector().x < 0);
    }
  }
}

void App::ProcessPepeBlinkingState() {
  static Timer timer{0};
  if (timer.IsStopped()) {
    timer.SetLifeTime(0.5);
    timer.Start();
  } else if (timer.Done()) {
    pepe_.SetState(Pepe::State::WANDERING);
  }
}

void App::UpdatePepeState() {
  if (window_.IsBeingDragged()) {
    pepe_.SetState(Pepe::State::GRABBED);
  } else if (IsWindowFocused()) {
    pepe_.SetState(Pepe::State::FOCUS);
  } else {
    if (pepe_.GetState() != Pepe::State::BLINKING) {
      if (GetRandomValue(1, 500) == 200) {
        pepe_.SetState(Pepe::State::BLINKING);
      } else {
        pepe_.SetState(Pepe::State::WANDERING);
      }
    }
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
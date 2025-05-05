#pragma once

#include <raylib.h>

#include "pepe.h"
#include "window.h"

class App {
 public:
  App();
  void Update();
  void Draw() const;
  void Run();

 private:
  void ProcessPepeState();
  void ProcessPepeWanderingState();
  void ProcessPepeBlinkingState();
  void UpdatePepeState();
  Window window_;
  Pepe pepe_;
};
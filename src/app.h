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
  Window window_;
  Pepe pepe_;
};
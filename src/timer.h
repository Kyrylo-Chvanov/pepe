#pragma once

#include <raylib.h>
#include <raymath.h>

#include <cfloat>

class Timer {
 public:
  Timer(const double life_time) : start_time_{DBL_MAX}, life_time_{life_time} {}
  void Start() { start_time_ = GetTime(); }
  bool Done() {
    if (GetTime() - start_time_ >= life_time_) {
      Stop();
      return true;
    }
    return false;
  }
  void Stop() { start_time_ = DBL_MAX; }
  bool IsStopped() { return start_time_ == DBL_MAX; }
  void SetLifeTime(const double life_time) { life_time_ = life_time; }

 private:
  double start_time_;
  double life_time_;
};
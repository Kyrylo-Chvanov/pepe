#include "animation.h"
#include <raylib.h>
#include <utility>

Animation::Animation(const unsigned speed, const unsigned row,
                     const unsigned from, const unsigned to)
    : speed{speed} {
  for (unsigned i{from}; i <= to; i++) {
    frames.emplace_back(AnimationFrame{i, row});
  }
}

void AnimationPlayer::Play(const char* animation) {
  if (animations_.find(animation) == animations_.end()) {
    TraceLog(LOG_WARNING, "ANIMATION: '%s' doesn't exist", animation);
    return;
  }
  current_animation_ = animation;
  frame_counter_ = 0;
  current_frame_ = 0;
}

void AnimationPlayer::AddAnimation(const char* animation_name, const Animation& animation) {
  if (!animations_.insert(std::make_pair(animation_name, animation)).second) {
    TraceLog(LOG_WARNING, "ANIMATION: '%s' already exists", animation_name);
    return;
  }
}

void AnimationPlayer::Update() {
  Animation current{animations_.at(current_animation_)};
  frame_counter_++;
  if (frame_counter_ >= (GetFPS()/current.speed)) {
    frame_counter_ = 0;
    current_frame_++;
    if (current_frame_ >= current.frames.size()) {
      current_frame_ = 0;
    }
    frame_rect_.x = current.frames[current_frame_].x * frame_size_.x;
    frame_rect_.y = current.frames[current_frame_].y * frame_size_.y;
  }
}
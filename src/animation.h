#pragma once

#include <raylib.h>

#include <map>
#include <vector>

struct AnimationFrame {
  unsigned x, y;
};

using FrameSize = AnimationFrame;
using Frames = std::vector<AnimationFrame>;

struct Animation {
  Animation(const unsigned speed, const unsigned row, const unsigned from,
            const unsigned to);
  Animation(const unsigned speed, const Frames& frames)
      : speed{speed}, frames{frames} {}
  unsigned speed;
  Frames frames;
};

class AnimationPlayer {
 public:
  AnimationPlayer(const Texture2D& texture, const FrameSize& frame_size)
      : frame_counter_{0},
        current_frame_{0},
        frame_rect_{0, 0, static_cast<float>(frame_size.x),
                    static_cast<float>(frame_size.y)},
        current_animation_{nullptr},
        frame_size_{frame_size},
        texture_{texture} {}
  void Play(const char* animation, const bool reset = false);
  void AddAnimation(const char* animation_name, const Animation& animation);
  void Update();
  const char* GetCurrentAnimation() const { return current_animation_; }
  void DrawAt(const Rectangle& destination) const {
    if (current_animation_ != nullptr) {
      DrawTexturePro(texture_, frame_rect_, destination, Vector2{0, 0}, 0, WHITE);
    }
  }

 private:
  void UpdateFrameRect();
  unsigned frame_counter_;
  unsigned current_frame_;
  Rectangle frame_rect_;
  const char* current_animation_;
  const FrameSize frame_size_;
  const Texture2D texture_;
  std::map<const char*, Animation> animations_;
};
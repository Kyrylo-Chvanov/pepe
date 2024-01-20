#define DEBUG

#include <SFML/Window.hpp>
#include <raylib.h>

int main() {
  #ifndef DEBUG
  SetTraceLogLevel(LOG_ERROR);
  #endif

  Image pepe_sprite{LoadImage("sprites/pepe.png")};
  const int kWinWidth{pepe_sprite.width};
  const int kWinHeight{pepe_sprite.height};
  constexpr int kGravitySpeed{500}, kWanderingSpeed{500}, kActionInterval{4}, kMinWanderingDistance{5}, kMaxWanderingDistance{15};

  SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_TOPMOST);
  InitWindow(kWinWidth, kWinHeight, "Pepe");
  SetTargetFPS(60);

  Texture2D pepe{LoadTextureFromImage(pepe_sprite)};
  UnloadImage(pepe_sprite);

  bool IsBeingDragged{false};

  double time{GetTime()};
  int wandering_distance{0};
  int wandering_direction{1}; // can be 1 or -1
  int max_wandering_distance{GetRandomValue(kMinWanderingDistance, kMaxWanderingDistance)};
  while (!WindowShouldClose()) {
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && IsCursorOnScreen()) {
      IsBeingDragged = true;
    } else if (!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
      IsBeingDragged = false;
    }
    
    if (IsBeingDragged) {
      sf::Vector2i mouse_pos{sf::Mouse::getPosition()};
      SetWindowPosition(mouse_pos.x - kWinWidth / 2, mouse_pos.y - kWinHeight / 2);
    } else {
      Vector2 win_pos{GetWindowPosition()};
      if (win_pos.y < GetMonitorHeight(GetCurrentMonitor()) - kWinHeight) {
        win_pos.y += kGravitySpeed * GetFrameTime();
        time = GetTime(); // Reset saved time cuz if I dont Pepe will start wandering immediately after falling
      } else {
        double current_time{GetTime()};
        if (current_time - time > kActionInterval || wandering_distance > 0) {
          time = current_time;
          win_pos.x += wandering_direction * kWanderingSpeed * GetFrameTime();
          if (wandering_distance == max_wandering_distance) {
            wandering_distance = 0;
            wandering_direction *= -1;
            max_wandering_distance = GetRandomValue(kMinWanderingDistance, kMaxWanderingDistance);
          } else {
            wandering_distance++;
          }
        }
      }
      SetWindowPosition(win_pos.x, win_pos.y);
    }
    
    BeginDrawing();
      ClearBackground(BLANK);
      DrawTextureRec(pepe, 
        Rectangle{0, 0, static_cast<float>(wandering_direction * -pepe.width), 
        static_cast<float>(pepe.height)}, Vector2{0, 0}, WHITE);
    EndDrawing();
  }

  UnloadTexture(pepe);
  CloseWindow();
  return 0;
}
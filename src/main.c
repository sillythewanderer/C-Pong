#include <raylib.h>

int main() {
  // screen size (constants for now)
  const int screen_size = 512;
  const int screen_width = screen_size;
  const int screen_height = screen_size;

  // raylib window initialization
  InitWindow(screen_width, screen_height, "ball for pong");

  // the size of the "ball" (radius)
  float ball_size = (float)screen_size / 43; 

  // screen edges (for colision handling)

  float screen_edge_left = ball_size;
  float screen_edge_right = GetScreenWidth() - ball_size;

  // the center of the window
  Vector2 screen_center = {((float)screen_width / 2), ((float)screen_height / 2)};
  
  // the position of the center of the ball
  Vector2 ball_position = {(screen_center.x), (screen_center.y)}; 

  // ball speed
  Vector2 ball_speed = {200, 160};

  // desired fps
  SetTargetFPS(60);

  // main game loop
  while (!WindowShouldClose()) {

    // delta time is a number used to make non framerate dependant physics (by multiplying delta time with the physics operations you wish to perform)
    float delta_time = GetFrameTime();

    ball_position.x += ball_speed.x * delta_time;
    ball_position.y += ball_speed.y * delta_time;

    // detecting when the ball is at the edge of the window
    if ((ball_position.x >= (GetScreenWidth() - ball_size)) || (ball_position.x <= ball_size)) ball_speed.x *= -1.0f;
    if ((ball_position.y >= (GetScreenHeight() - ball_size)) || (ball_position.y <= ball_size)) ball_speed.y *= -1.0f;

    // drawing functions
    BeginDrawing();
      ClearBackground(BLACK);
      DrawCircleV(ball_position, ball_size, WHITE);
    EndDrawing();
  }

  // closing the window and de-allocating it from memory
  CloseWindow();

  return 0;
}

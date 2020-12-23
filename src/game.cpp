#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : bat(grid_width, grid_height),
    ball(grid_width, grid_height),
      _grid_width(grid_width),
      _grid_height(_grid_height),
      engine(dev())
{
  /* ball = new ParanoidBall(_grid_width, _grid_height); */
  PlaceBall();
  CheckCollision();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, bat);
    Update();
    renderer.Render(bat, ball);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceBall() {
  int x, y;
  while (true) {
    x = 5; //TODO: Set starting point
    y = 5;
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!bat.BatCell(x, y)) {
      ball.ball_x = x;
      ball.ball_y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!bat.alive) return;

  bat.Update();

  lock_collision.lock();
  ball.Update(collision);
  lock_collision.unlock();

  CheckCollision();

  int new_x = static_cast<int>(bat.head_x);
  int new_y = static_cast<int>(bat.head_y);

  // Check if there's food over here
  if (ball.ball_x == new_x && ball.ball_y == new_y) {
    score++;
    PlaceBall();
    // Grow snake and increase speed.
    bat.GrowBody();
    bat.speed += 0.02;
  }
}

void Game::CheckCollision()
{
  printf("y positons for ball and bat %f, %f\n", ball.ball_y, bat.body.front().y);
  
    if ((ball.ball_x == 0) || (ball.ball_x == _grid_width))
    {
        collision = ParanoidBall::Collision::WallLeft;
    }
    //TODO: Separate for left and right walls

    else if (ball.ball_y < 0.1)
    {
        collision = ParanoidBall::Collision::WallTop;
    }

    else if (abs((ball.ball_y + 1) - bat.body.front().y) < 0.1) 
    { 
      for(auto const& it : bat.body)
      {
        //printf("x positons for ball and bat %f, %f\n", ball.ball_x, it.x);
        if (ball.ball_x + 1 == it.x)
        {
          collision = ParanoidBall::Collision::Bat;
        }

      }
    }

    else if (ball.ball_y == bat.body.front().y)
    { 
      collision = ParanoidBall::Collision::WallBottom;

    }

    else
    {
      collision = ParanoidBall::Collision::None;
    }

}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return bat.size; }
#include "game.h"
#include <iostream>
#include "SDL.h"
#include <thread>
#include <memory>
#include <random>
#include <algorithm>


Game::Game(std::size_t grid_width, std::size_t grid_height)
    : bat(grid_width, grid_height),
    ball(grid_width, grid_height),
    _grid_width(grid_width),
    _grid_height(grid_height),
    engine(dev())
{
  /* ball = new ParanoidBall(_grid_width, _grid_height); */
  PlaceBricks();
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
    renderer.Render(bat, ball, bricks);

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

    if (collision == ParanoidBall::Collision::WallBottom)
    {
        SDL_Quit();
        break;
    }
  }
}

void Game::PlaceBricks()
{
  std::random_device rd; // obtain a random number from hardware
  std::mt19937 gen(rd()); // seed the generator
  std::uniform_int_distribution<> distr_x(0, (_grid_width-ParanoidBrick::brick_size)); // define the range
  std::uniform_int_distribution<> distr_y(0, 10);
  for (int i=0; i<25; i++)
  {
    int rand_x = distr_x(gen)/3; //This divide by 3 is done for renderer to consider brick width. FIXME: Can this be simplified?
    int rand_y = distr_y(gen);
    printf("Random x and y is %d, %d\n", rand_x, rand_y);

    // Find if brick is a part of already present bricks
    auto it = std::find_if(occupied_bricks.begin(), occupied_bricks.end(), [rand_x, rand_y](const SDL_Point& e) {return ((e.x == rand_x) && (e.y == rand_y));});
    if (it != occupied_bricks.end())
    {
      i--;
    } 
    else
    {
      SDL_Point curr_brick_pixel = {rand_x, rand_y};
      ParanoidBrick new_brick = ParanoidBrick(rand_x, rand_y);
      //occupied_bricks.emplace_back(new_brick.brick_body);
      bricks.emplace_back(new_brick);
    }
  }
}

void Game::PlaceBall() {
  int x, y;
  while (true) {
    x = 5; //TODO: Set starting point
    y = 5;
    // FIXME:Checks that the location is not occupied by a brick item before placing
    // ball. Check if this is needed
    if (!bat.BatCell(x, y)) {
      ball.ball_x = x;
      ball.ball_y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!bat.alive) return;

  std::promise<ParanoidBat> prms;
  std::thread t1(&ParanoidBat::Update, &bat);
  //bat.Update();

  _lock_collision.lock();
  std::thread t2(&ParanoidBall::Update, &ball, collision, static_cast<int>(bat.direction));
  //ball.Update(collision, static_cast<int>(bat.direction));
  _lock_collision.unlock();

  t1.join();
  t2.join();
  CheckCollision();

  int new_x = static_cast<int>(bat.head_x);
  int new_y = static_cast<int>(bat.head_y);

  // FIXME: Check if there's ball over here. Check if this is needed
  if (ball.ball_x == new_x && ball.ball_y == new_y) {
    score++;
    PlaceBall();
    // FIXME: Grow bat and increase speed. Check if this is needed
    bat.GrowBody();
    bat.speed += 0.02;
  }
}

void Game::CheckCollision()
{
    //printf("x positons for ball and bat %f, %d\n", ball.ball_x, bat.body.front().x);
    //printf("y positons for ball and bat %f, %d\n", ball.ball_y, bat.body.front().y);
    if (ball.ball_y < 0.1)
    {
        collision = ParanoidBall::Collision::WallTop;
    }

    else if (abs(ball.ball_y - _grid_height) <= 0.3)
    { 
      collision = ParanoidBall::Collision::WallBottom;
    }

    else if (0.1 >= ball.ball_x)
    {
        collision = ParanoidBall::Collision::WallLeft;
    }
    else if (_grid_width-1 < ball.ball_x)
    {
        collision = ParanoidBall::Collision::WallRight;
    }
    //TODO: Separate for left and right walls

    else if (abs((ball.ball_y + 1) - bat.body.front().y) < 0.3) 
    { 
      for(auto const& it : bat.body)
      {
        if (static_cast<int>(ball.ball_x) == it.x)
        {
          collision = ParanoidBall::Collision::Bat;
        }

      }
    }

    else if (CheckBrickCollision())
    {

    }

    else
    {
      CheckBrickCollision();
      collision = ParanoidBall::Collision::None;
    }
    //printf("Grid height is %f, Collision is %d\n", _grid_height, collision);
    //printf("Diff to bat y %d\n", abs(static_cast<int>(ball.ball_y + 1) - bat.body.front().y));
}

bool Game::CheckBrickCollision()
{
  SDL_Point curr_ball_pixel = {ball.ball_x, ball.ball_y};
  for (auto it : bricks)
  {
    for (auto it1 : it.brick_body)
    {
          //printf("%d, %d \n", it1.x, curr_ball_pixel.x);

      if ((it1.x == curr_ball_pixel.x) && (it1.y == curr_ball_pixel.y))
      {
        printf("Brick collsison \n");
        return true;
      }
    }
  }
return false;

}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return bat.size; }
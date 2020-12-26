#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "bat.h"
#include "ball.h"

#include <memory>
#include <mutex>

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  ParanoidBat bat;
  ParanoidBall ball;

  std::mutex _lock_collision;

  std::random_device dev;
  std::mt19937 engine;

  float _grid_width;
  float _grid_height;
  int score{0};

  void PlaceBall();
  void Update();

  ParanoidBall::Collision collision{ParanoidBall::Collision::None};
  void CheckCollision();

};

#endif
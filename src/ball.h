#ifndef PARANOID_BALL_H
#define PARANOID_BALL_H

#include "SDL.h"

class ParanoidBall{
  public:
  enum class Direction {k1, k2, k3, k4, k5, k6, k7, k8, k9};

  ParanoidBall(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        ball_x(grid_width / 2),
        ball_y(grid_height - 1) 
        {
        };
  void Update();
  bool BallCell(int x, int y);
  void GrowBody();

  Direction direction = Direction::k8;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float ball_x;
  float ball_y;

  //std::vector<SDL_Point> body;

  private:
  void UpdateBall();
  //void UpdateBody(SDL_Point& center);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif // PARANOID_BALL_H
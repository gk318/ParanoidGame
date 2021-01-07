#ifndef PARANOID_BRICK_H
#define PARANOID_BRICK_H

#include <vector>
#include "SDL.h"

class ParanoidBrick{
  public:
  //enum class Direction {kLeft, kRight, kStop};

  ParanoidBrick(int left_x, int left_y);
  
  void Create();
  bool BrickCell(int x, int y);
  void DeleteBrick();

  //Direction direction = Direction::kRight;

  int brick_size{3};
  bool alive{true};
  int left_x;
  int left_y;
  std::vector<SDL_Point> brick_body{brick_size};

  private:
  //void UpdateHead();
  //void UpdateBody(SDL_Point& center);

  //bool growing{false};
  int grid_width;
  int grid_height;
};

#endif
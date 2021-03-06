#ifndef PARANOID_BAT_H
#define PARANOID_BAT_H

#include <vector>
#include "SDL.h"

class ParanoidBat{
  public:
  enum class Direction {kLeft, kRight, kStop};

  ParanoidBat(int grid_width, int grid_height);
  
  void Update();
  bool BatCell(int x, int y);
  void GrowBody();

  Direction direction = Direction::kRight;

  float speed{0.1f};
  int size{4};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

  private:
  void UpdateHead();
  void UpdateBody(SDL_Point& center);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif
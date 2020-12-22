#ifndef PARANOID_BAT_H
#define PARANOID_BAT_H

#include <vector>
#include "SDL.h"

class ParanoidBat{
  public:
  enum class Direction {kLeft, kRight};

  ParanoidBat(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height - 1) {};
  void Update();
  bool BatCell(int x, int y);
  void GrowBody();

  Direction direction = Direction::kRight;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

  private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif
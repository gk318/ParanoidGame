#include "bat.h"
#include <cmath>
#include <iostream>

void ParanoidBat::Update() {
  SDL_Point prev_head{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_head{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the bat head has moved to a new
  // cell.
  if (current_head.x != prev_head.x || current_head.y != prev_head.y) {
    UpdateBody(current_head);
  }
}

void ParanoidBat::UpdateHead() {
  switch (direction) {
    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}

void ParanoidBat::UpdateBody(SDL_Point& center) {

  body.clear();
  body.push_back(center);

  SDL_Point leftmost_cell{center.x-1, center.y};
  SDL_Point rightmost_cell{center.x+1, center.y};

  body.push_back(leftmost_cell);
  body.push_back(rightmost_cell);

/*   switch (direction) {
    case Direction::kLeft:
      head_x -= speed;
      body.emplace(body.begin(), leftmost_cell);
      body.erase(body.end());
      break;

    case Direction::kRight:
      head_x += speed;
      body.emplace_back(rightmost_cell);
      body.erase(body.begin());
      break; */
  //}

/*   // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died. TODO: Check if the ball is lost
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }*/
}

void ParanoidBat::GrowBody() {growing = true;}

// Inefficient method to check if cell is occupied by bat.
bool ParanoidBat::BatCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}
#include "ball.h"
#include <cmath>
#include <iostream>

void ParanoidBall::Update() {
  SDL_Point prev_ball{
      static_cast<int>(ball_x),
      static_cast<int>(
          ball_y)};  // We first capture the head's cell before updating.
  UpdateBall();
  SDL_Point current_ball{
      static_cast<int>(ball_x),
      static_cast<int>(ball_y)};  // Capture the head's cell after updating.

/*   // Update all of the body vector items if the bat head has moved to a new
  // cell.
  if (current_ball.x != prev_ball.x || current_ball.y != prev_ball.y) {
    UpdateBody(current_ball);
  } */
}

void ParanoidBall::UpdateBall() {
  switch (direction) {
    case Direction::k1:
      ball_x -= speed;
      ball_y -= speed;
      break;

    case Direction::k2:
      ball_y -= speed;
      break;

    case Direction::k3:
      ball_x += speed;
      ball_y -= speed;
      break;

    case Direction::k4:
      ball_x -= speed;
      break;

    case Direction::k6:
      ball_x += speed;
      break;

    case Direction::k7:
      ball_x -= speed;
      ball_y += speed;
      break;

    case Direction::k8:
      ball_y += speed;
      break;
    
    case Direction::k9:
      ball_x += speed;
      ball_y += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  ball_x = fmod(ball_x + grid_width, grid_width);
  ball_y = fmod(ball_y + grid_height, grid_height);
}

void ParanoidBall::GrowBody() {growing = true;}

// Inefficient method to check if cell is occupied by ball.
bool ParanoidBall::BallCell(int x, int y) {
  if (x == static_cast<int>(ball_x) && y == static_cast<int>(ball_y)) {
    return true;
  }
  return false;
}
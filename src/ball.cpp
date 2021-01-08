#include "ball.h"
#include <cmath>
#include <iostream>

void ParanoidBall::Update(Collision const& collision, int batDirection) {
  switch (direction) {
    case Direction::k1:
      switch (collision)
      {
        case Collision::WallLeft:
          direction = Direction::k3;
          break;
               
        case Collision::WallTop:
          direction = Direction::k7;
          break;

        default:
          ball_x -= speed;
          ball_y -= speed;
          break;
      }
      break;

    case Direction::k2:
        switch (collision)
        {
          case Collision::WallTop:
            ball_y += speed;
            direction = Direction::k8;
            break;
          
          default:
            ball_y -= speed;
            break;
        }
      break;

    case Direction::k3:
      switch (collision)
      {
        case Collision::WallRight:
          direction = Direction::k1;
          break;

        case Collision::WallTop:
          direction = Direction::k9;
          break;
        
        default:
          ball_x += speed;
          ball_y -= speed;
          break;
      }

      break;

    case Direction::k4:
      ball_x -= speed;
      break;

    case Direction::k6:
      ball_x += speed;
      break;

    case Direction::k7:

      switch (collision)
      {
        case Collision::None:
          ball_x -= speed;
          ball_y += speed;
          break;

        case Collision::Bat:
          ball_y -= speed;
          switch (batDirection)
          {
            case 0:
              direction = Direction::k3;
              break;
            case 1:
              direction = Direction::k2;
              break;
            default:
              direction = Direction::k1;
              break;
          }
          break;
        
        default:
          ball_y += speed;
          break;
      }
      break;
      break;

    case Direction::k8:
        //printf("%d\n", static_cast<int>(collision));
        switch (collision)
        {
            case Collision::None:
              ball_y += speed;
              break;

            case Collision::Bat:
              ball_y -= speed;
              switch (batDirection)
              {
                case 0:
                  direction = Direction::k3;
                  break;
                case 1:
                  direction = Direction::k1;
                  break;
                default:
                 direction = Direction::k2;
                 break;
              }
              break;
            
            default:
              ball_y += speed;
              break;
        }
      break;
    
    case Direction::k9:
      switch (collision)
      {
          case Collision::None:
            ball_x += speed;
            ball_y += speed;
            break;

          case Collision::Bat:
            ball_y -= speed;
            switch (batDirection)
            {
              case 0:
                direction = Direction::k2;
                break;
              case 1:
                direction = Direction::k1;
                break;
              default:
                direction = Direction::k3;
                break;
            }
            break;
          
          default:
            ball_y += speed;
            break;
      }
      break;
  }

  // Wrap around to the beginning if going off of the screen.
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
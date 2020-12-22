#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::ChangeDirection(ParanoidBat &snake, ParanoidBat::Direction input,
                                 ParanoidBat::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, ParanoidBat &bat) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_LEFT:
          ChangeDirection(bat, ParanoidBat::Direction::kLeft,
                          ParanoidBat::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(bat, ParanoidBat::Direction::kRight,
                          ParanoidBat::Direction::kLeft);
          break;
      }
    }
  }
}
#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::ChangeDirection(ParanoidBat &bat, ParanoidBat::Direction input) const {
  if (bat.direction != input) bat.direction = input;
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
          ChangeDirection(bat, ParanoidBat::Direction::kLeft);
          break;

        case SDLK_RIGHT:
          ChangeDirection(bat, ParanoidBat::Direction::kRight);
          break;
      }
    }
  }
}
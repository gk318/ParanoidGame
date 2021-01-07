#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "bat.h"
#include "ball.h"
#include "brick.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(ParanoidBat const bat, ParanoidBall const &ball, ParanoidBrick const &brick);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif
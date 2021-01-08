#include "brick.h"

#include <iostream>

ParanoidBrick::ParanoidBrick(int left_x, int left_y) :
    left_x(left_x), left_y(left_y)
{
    Create();
}

void ParanoidBrick::Create()
{
    brick_body.clear();
    for (int idx=0; idx < brick_size; idx++)
    {
        SDL_Point current_pixel;
        current_pixel.x = left_x + idx;
        current_pixel.y = left_y;
        brick_body.push_back(current_pixel);
    }
}
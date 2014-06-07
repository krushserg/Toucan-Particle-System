/*
  Copyright (C) Sergey Rakhmanov

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#pragma once
#include <memory>
#include <limits>
namespace toucan
{
using namespace std;


struct Particle
{
    double position_x = 0;
    double position_y = 0;
    double velocity_x = 0;
    double velocity_y = 0;

    double angle = 0;
    double velocity_angular = 0;

    double lifetime = 0;
    double lifetime_max = 1;
    bool dead = false;

    double additional_dt = 0;

    double halfsize_x = 0.5;
    double halfsize_y = 0.5;

    double texcoord_x1=0;
    double texcoord_y1=0;
    double texcoord_x2=1;
    double texcoord_y2=1;

    unsigned char color[4] = {255,255,255,255};

    unsigned long mask = numeric_limits<unsigned long>::max();

};
}

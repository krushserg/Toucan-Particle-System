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

#include "affector.h"
#include <iostream>


namespace toucan
{
using namespace std;
class BaseAffector : public Affector
{
public:

    BaseAffector(double ax, double ay)
        :_ax(ax), _ay(ay)
    {

    }
    void operator ()(Particle& particle, double dt)
    {
        particle.lifetime += dt;
        if(particle.lifetime>=particle.lifetime_max)
        {
            particle.dead = true;
            return;
        }

        particle.velocity_x += _ax*dt;
        particle.velocity_y += _ay*dt;

        particle.position_x += particle.velocity_x*dt;
        particle.position_y += particle.velocity_y*dt;
        particle.angle += particle.velocity_angular*dt;
    }

private:
    double _ax = 0;
    double _ay = 0;
};
}

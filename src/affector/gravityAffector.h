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
class GravityAffector : public Affector
{
public:

    GravityAffector()
        :GravityAffector(0, 0, 1)
    {
    }

    GravityAffector(double _x, double _y, double _gravity)
    {
        setPosition(_x, _y,_gravity);
    }
    void setPosition(double _x, double _y, double _gravity)
    {
        x = _x;
        y = _y;
        gravity = _gravity;
    }

    void operator ()(Particle& particle, double dt)
    {

        double dx = particle.position_x - x;
        double dy = particle.position_y - y;

        double dist = sqrt(pow(dx,2)+pow(dy,2));
        double power = 1./dist;
        particle.velocity_x -= gravity*dt*dx*power;
        particle.velocity_y -= gravity*dt*dy*power;
    }

private:
    double x = 0;
    double y = 0;
    double gravity;

};
}

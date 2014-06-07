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
#include "randomizer.h"
#include "randomizer/uniformRandomizer.h"
#include "affector.h"
#include <iostream>


namespace toucan
{
using namespace std;
class RandomVelocityAffector : public Affector
{
public:

    RandomVelocityAffector(double velocity_min, double velocity_max,\
                            double angle_min = 0, double angle_max = 2.0*M_PI,\
                            shared_ptr<Randomizer> velocity_randomizer = make_shared<UniformRandomizer>(),\
                            shared_ptr<Randomizer> angle_randomizer = make_shared<UniformRandomizer>())
        :_velocity_min(velocity_min),_velocity_max(velocity_max),\
          _angle_min(angle_min), _angle_max(angle_max),\
          _velocity_randomizer(velocity_randomizer),\
          _angle_randomizer(angle_randomizer)
    {

    }

    void operator ()(Particle& particle, double dt)
    {
        double velocity = _velocity_randomizer->get(_velocity_min, _velocity_max);
        double angle = _angle_randomizer->get(_angle_min, _angle_max);
        particle.velocity_x += cos(angle)*velocity;
        particle.velocity_y += sin(angle)*velocity;
    }

private:
    double _velocity_min=0;
    double _velocity_max=0;
    double _angle_min=0;
    double _angle_max=0;
    shared_ptr<Randomizer> _velocity_randomizer;
    shared_ptr<Randomizer> _angle_randomizer;
};
}

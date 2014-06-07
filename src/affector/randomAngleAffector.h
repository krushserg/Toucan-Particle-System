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
class RandomAngleAffector : public Affector
{
public:

    RandomAngleAffector(double angle_min = 0, double angle_max = M_PI*2,\
                            shared_ptr<Randomizer> angle_randomizer = make_shared<UniformRandomizer>())\
        :_a_min(angle_min), _a_max(angle_max),\
          _angle_randomizer(angle_randomizer)
    {

    }

    void operator ()(Particle& particle, double dt)
    {
        particle.angle += _angle_randomizer->get(_a_min, _a_max);
    }

private:
    double _a_min=0;
    double _a_max=0;
    shared_ptr<Randomizer> _angle_randomizer;

};
}

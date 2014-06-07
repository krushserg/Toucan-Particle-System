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
class RandomSizeAffector : public Affector
{
public:

    RandomSizeAffector(double size_x_min, double size_x_max,\
                       double size_y_min, double size_y_max,\
                            shared_ptr<Randomizer> size_randomizer = make_shared<UniformRandomizer>())\
        :_x_min(size_x_min),_y_min(size_y_min),\
         _x_max(size_x_max),_y_max(size_y_max),\
          _size_randomizer(size_randomizer)
    {

    }
    RandomSizeAffector(double size_min, double size_max,\
                            shared_ptr<Randomizer> size_randomizer = make_shared<UniformRandomizer>())\
        :_x_min(size_min),_y_min(size_min),\
         _x_max(size_max),_y_max(size_max),\
          _size_randomizer(size_randomizer),\
          square(true)
    {

    }

    void operator ()(Particle& particle, double dt)
    {
        particle.halfsize_x = _size_randomizer->get(_x_min, _x_max)*0.5;
        if(square)
            particle.halfsize_y = particle.halfsize_x;
        else
            particle.halfsize_y = _size_randomizer->get(_y_min, _y_max)*0.5;
    }

private:
    double _x_min=0;
    double _x_max=0;
    double _y_min=0;
    double _y_max=0;
    shared_ptr<Randomizer> _size_randomizer;
    bool square = false;
};
}

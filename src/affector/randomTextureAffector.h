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
#include <vector>

namespace toucan
{
using namespace std;

struct quad_t
{
    double x1;
    double y1;
    double x2;
    double y2;
};

class RandomTextureAffector : public Affector
{
public:

    RandomTextureAffector(shared_ptr<Randomizer> number_randomizer = make_shared<UniformRandomizer>())\
          :_number_randomizer(number_randomizer)
    {

    }
    void addCoords(double x, double y, double w, double h)
    {
        quad_t q;
        q.x1 = x;
        q.y1 = y;
        q.x2 = x+w;
        q.y2 = y+h;
        _data.push_back(q);
    }

    void operator ()(Particle& particle, double dt)
    {
        if(_data.empty())
            return;
        int n = _number_randomizer->get(0, _data.size());
        particle.texcoord_x1 = _data[n].x1;
        particle.texcoord_y1 = _data[n].y1;
        particle.texcoord_x2 = _data[n].x2;
        particle.texcoord_y2 = _data[n].y2;
    }

private:
    vector<quad_t> _data;
    shared_ptr<Randomizer> _number_randomizer;

};
}

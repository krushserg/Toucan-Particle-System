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

struct color_t
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

class RandomColorAffector : public Affector
{
public:

    RandomColorAffector(shared_ptr<Randomizer> number_randomizer = make_shared<UniformRandomizer>())\
          :_number_randomizer(number_randomizer)
    {

    }
    void addColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        color_t q;
        q.r = r;
        q.g = g;
        q.b = b;
        q.a = a;
        _data.push_back(q);
    }

    void operator ()(Particle& particle, double dt)
    {
        if(_data.empty())
            return;
        int n = _number_randomizer->get(0, _data.size());
        particle.color[0] = _data[n].r;
        particle.color[1] = _data[n].g;
        particle.color[2] = _data[n].b;
        particle.color[3] = _data[n].a;
    }

private:
    vector<color_t> _data;
    shared_ptr<Randomizer> _number_randomizer;

};
}

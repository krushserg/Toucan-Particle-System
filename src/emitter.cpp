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
#include "emitter.h"
#include <iostream>
#include <algorithm>
using namespace toucan;
using namespace std;
void Emitter::particlesPerSecond(int count)
{
    _pps = max(0, count);
    _secondmode = true;
}
void Emitter::particlesPerStep(int count)
{
    _pps = max(0, count);
    _secondmode = false;
}

void Emitter::particlesLifetime(double min_lifetime, double  max_lifetime,\
                                shared_ptr<Randomizer> lifetime_randomizer)
{
    _min_lifetime = min_lifetime;
    _max_lifetime = max_lifetime;
    _lifetime_randomizer = lifetime_randomizer;
}

void Emitter::step(vector<Particle>& particles, double dt)
{
    double save_last_make_time = last_make_time;
    size_t make_count;
    if(_secondmode)
    {
        if(_pps<=0)
            return;
        last_make_time += dt;


        make_count = last_make_time * static_cast<double>(_pps);

        last_make_time -= (static_cast<double>(make_count)/static_cast<double>(_pps));
    }
    else
    {
        make_count = _pps;
    }

    auto firstdead = particles.begin();
    auto end = particles.end();
    for(size_t i = 0; i < make_count; i++)
    {
        firstdead = find_if(firstdead, end, [](const Particle& pt){return pt.dead;});
        Particle p = operator()();
        if(_secondmode)
            p.additional_dt = p.lifetime = double(i)/double(make_count)*save_last_make_time;

        p.lifetime_max = _lifetime_randomizer->get(_min_lifetime, _max_lifetime);

        for(shared_ptr<Affector> aff: affector_data)
        {
            aff->operator ()(p, dt);

        }
        if(firstdead == end)
            particles.push_back(p);
        else
            (*firstdead) = p;
    }

}

void Emitter::addAffector(shared_ptr<Affector> affector)
{
    affector_data.push_back(affector);
}

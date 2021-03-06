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
#include "particle.h"
#include "area.h"
#include "affector.h"
#include "randomizer/uniformRandomizer.h"
#include <vector>
namespace toucan
{
using namespace std;

class Affector;
class Emitter
{
public:

    void particlesPerSecond(int count);
    void particlesPerStep(int count);
    void particlesLifetime(double min_lifetime, double max_lifetime,\
                   shared_ptr<Randomizer> lifetime_randomizer = make_shared<UniformRandomizer>());
    void step(vector<Particle>& particles, double dt);
    virtual Particle operator()() = 0;

    void addAffector(shared_ptr<Affector> affector);

private:
    vector<shared_ptr<Affector> > affector_data;
    double last_make_time=0.;
    int _pps=1;
    bool _secondmode;
    shared_ptr<Randomizer> _lifetime_randomizer = make_shared<UniformRandomizer>();
    double _min_lifetime=1;
    double _max_lifetime=1;
};
}

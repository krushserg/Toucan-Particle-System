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
#include "area.h"
#include "particle.h"
#include <algorithm>
using namespace toucan;
using namespace std;

void Area::addEmitter(shared_ptr<Emitter> emitter)
{
    emitter_data.push_back(emitter);
}

void Area::addAffector(shared_ptr<Affector> affector)
{
    affector_data.push_back(affector);
}

void Area::addParticle(const Particle& particle)
{
    particle_data.push_back(particle);
}
void Area::setDrawer(shared_ptr<Drawer> drawer)
{
    _drawer = drawer;
}

void Area::step(double dt)
{
    dt = max(0., dt);

    if(_drawer)
        _drawer->clear();


    for(shared_ptr<Emitter> emitter: emitter_data)
    {
        emitter->step(particle_data, dt);
    }
    for(Particle& particle: particle_data)
    {
        if(particle.dead)
            continue;
        for(shared_ptr<Affector> affector: affector_data)
        {
            if(!affector->checkMask(particle.mask))
                continue;
            affector->operator ()(particle, dt + particle.additional_dt);
        }
        particle.additional_dt = 0;
        if(_drawer)
            _drawer->addParticle(particle);
    }

}
size_t Area::getParticleCount()
{
    return particle_data.size();
}

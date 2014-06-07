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
#include "emitter.h"
#include "affector.h"
#include "particle.h"
#include "drawer.h"
#include <memory>
#include <vector>
namespace toucan
{
using namespace std;


class Emitter;
class Area
{
public:
    void addEmitter(shared_ptr<Emitter> emitter);
    void addAffector(shared_ptr<Affector> affector);
    void addParticle(const Particle& particle);
    void setDrawer(shared_ptr<Drawer> drawer);
    void step(double dt);

    size_t getParticleCount();
private:
    vector<shared_ptr<Emitter>> emitter_data;
    vector<shared_ptr<Affector>> affector_data;
    vector<Particle> particle_data;

    shared_ptr<Drawer> _drawer;
};

}

#pragma once
#include "emitter.h"
#include "particle.h"
#include <memory>
#include <vector>
namespace toucan
{
using namespace std;
class Area
{
public:
    Area(size_t max_particle_count);
    void addEmitter(shared_ptr<Emitter> emitter);
    void addParticle(const Particle& particle);
private:

    vector<shared_ptr<Emitter>> emitter_data;
    vector<Particle> particle_data;
};

}

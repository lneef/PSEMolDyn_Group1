//
// Created by lukas on 29.11.22.
//

#include "ParticleList.h"

void ParticleList::apply(std::function<void(Particle &)> fun) {
    for (auto &p: particles) {
        fun(p);
    }
}

void ParticleList::applyX(std::function<void(Particle &)> fun) {
    apply(fun);
}

size_t ParticleList::size() {
    return particles.size();
}

ParticleList::~ParticleList() = default;

void ParticleList::addParticle(Particle &p) {
    particles.push_back(p);

}

void ParticleList::addParticle(Particle &&p) {
    particles.push_back(p);
}

void ParticleList::applyF(std::function<void(Particle &, Particle &)> fun) {
    auto it1 = particles.begin();
    auto it2 = particles.begin();

    for (; it1 != particles.end(); ++it1) {
        ++it2;
        for (auto it3 = it2; it3 != particles.end(); ++it3) {
            auto &p1 = *it1;
            auto &p2 = *it3;
            fun(p1, p2);
        }
    }

}

std::list<Particle>::iterator ParticleList::begin() {
    return particles.begin();
}

std::list<Particle>::iterator ParticleList::end() {
    return particles.end();
}

std::list<Particle>::iterator ParticleList::remove(std::list<Particle>::iterator &iterator) {
    return particles.erase(iterator);
}

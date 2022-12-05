#include "ParticleContainer.h"

void ParticleContainer::setParticles(const std::vector<Particle> &particles) {
    this->particles = particles;
}

const std::vector<Particle> &ParticleContainer::getParticles() const {
    return this->particles;
}

void ParticleContainer::addParticle(Particle &&particle) {
    particles.push_back(particle);
}

size_t ParticleContainer::size() {
    return particles.size();
}

Particle &ParticleContainer::operator[](size_t i) {
    return particles[i];
}

void ParticleContainer::applyX(std::function<void(Particle &)> fun) {
    apply(fun);

}

void ParticleContainer::applyF(std::function<void(Particle &, Particle &)> fun) {
    size_t len = particles.size();

    for (size_t i = 0; i < len; ++i) {
        for (size_t j = i + 1; j < len; ++j) {
            Particle &p1 = particles[i];
            Particle &p2 = particles[j];
            fun(p1, p2);
        }
    }

}

void ParticleContainer::apply(std::function<void(Particle &)> fun) {
    for (auto &p: particles) {
        fun(p);
    }

}

void ParticleContainer::addParticle(Particle &p) {
    particles.push_back(p);
}

void ParticleContainer::clear() {
    particles.clear();
}

ParticleContainer::~ParticleContainer() = default;




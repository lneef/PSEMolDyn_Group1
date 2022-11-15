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
Particle& ParticleContainer::operator[](size_t i){
    return particles[i];
}

void ParticleContainer::prealloc(size_t len){
    size_t size = particles.size();
    particles.resize(size + len);
}

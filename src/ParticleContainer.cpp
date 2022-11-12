#include "ParticleContainer.h"

using p_iterator = ParticleContainer::iterator;

p_iterator::iterator(std::vector<Particle>::iterator
current){
this->
current = current;
}

p_iterator ParticleContainer::begin() {
    return iterator(particles.begin());
}

p_iterator ParticleContainer::end() {
    return iterator(particles.end());
}

bool p_iterator::operator==(p_iterator it) {
    return current == it.current;
}

bool p_iterator::operator!=(p_iterator it) {
    return current != it.current;
}

p_iterator::reference p_iterator::operator*() const {
    return *current;
}

p_iterator &p_iterator::operator++() {
    current++;
    return *this;
}

p_iterator p_iterator::operator++(int) {
    p_iterator tmp = *this;
    current++;
    return tmp;
}

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

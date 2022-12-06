//
// Created by lukas on 06.12.22.
//
#include "ParticleIterator.h"

bool ParticleIterator::operator!=(ParticleIterator &it2) {
    return it!=it2.it;
}

ParticleIterator &ParticleIterator::operator++() {
    ++it;
    return *this;
}

ParticleIterator::reference ParticleIterator::operator*() {
    return *it;
}

ParticleIterator::ParticleIterator(std::vector<Particle>::iterator ref) : it(ref) {

}

std::vector<Particle>::iterator &ParticleIterator::get() {
    return it;
}

bool ParticleIterator::operator!=(ParticleIterator &&it2) {
    return it != it2.it;
}

ParticleIterator::pointer ParticleIterator::operator->() {
    return it .operator->();
}

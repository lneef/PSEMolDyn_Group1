//
// Created by lukas on 12.12.22.
//
#pragma once

#include "container/ParticleContainer.h"
#include "forceCalculation/LennardJones.h"

class Periodic {
    std::array<double, 3> offset{};
public:
    void apply(ParticleContainer& par, Particle& p, std::function<void(Particle &, Particle &)> &fun);
    void vert(double domain);
    void hor(double domain);

};
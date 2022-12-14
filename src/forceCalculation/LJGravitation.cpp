//
// Created by lukas on 14.12.22.
//

#include "LJGravitation.h"

LJGravitation::LJGravitation(double g_arg) {
    g = g_arg;
}

void LJGravitation::calculateF(std::shared_ptr<Container> &particles) {
    particles->apply([this](Particle& p){
        std::array<double, 3> force{};
        force[1] = p.getM() * g;
        p.updateF(force);
    });

    ljForce.calculateF(particles);
}

LJGravitation::~LJGravitation() = default;

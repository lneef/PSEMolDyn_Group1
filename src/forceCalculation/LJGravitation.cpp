

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

    particles->applyF([](Particle& p1, Particle& p2){
        LennardJones::calculateF(p1, p2);
    });
}

LJGravitation::~LJGravitation() = default;
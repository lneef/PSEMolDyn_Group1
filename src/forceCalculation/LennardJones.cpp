//
// Created by dominik on 05.11.22.
//

#include "LennardJones.h"

LennardJones::~LennardJones() = default;
LennardJones::LennardJones() {
    zeroCrossing = 1;
    depthOfPotentialWell = 5;
}

void LennardJones::calculateF(ParticleContainer &particles) {
    particles.apply([](Particle &p){
       std::array<double,3> zero{};
       p.setF(zero);
    });

    particles.apply2([this](Particle &p1, Particle &p2){
        std::array<double, 3> xij = p1.getX() - p2.getX();
        double norm = ArrayUtils::L2Norm(xij);
        double pow_6 = pow((zeroCrossing / norm), 6);
        double scalar = ((-24 * depthOfPotentialWell) / pow(norm, 2)) * (pow_6 - 2 * pow(pow_6, 2));
        std::array<double,3> newF = scalar * xij;
        p1.setF(p1.getF() + newF);
        p2.setF(-1 * newF + p2.getF());


    });
}


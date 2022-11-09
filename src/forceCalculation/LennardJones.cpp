//
// Created by dominik on 05.11.22.
//

#include "LennardJones.h"

LennardJones::~LennardJones() = default;

void LennardJones::calculateF(ParticleContainer &particles) {
    int depthOfPotentialWell = 5;
    int zeroCrossing = 1;

    std::vector<Particle> particle_v = particles.getParticles();
    for (auto p1 = std::begin(particle_v); p1 != std::end(particle_v); p1++){
       std::array<double,3> newF1 = p1->getF();
       for(auto p2 = p1 +1; p2 != std::end(particle_v); p2++){
           std::array<double, 3> newF2 = p2->getF();
            //check if it the same particle
            if (p1 == p2) {
                continue;
            }
            std::array<double, 3> xij;
            for (int i = 0; i < 3; i++) {
                xij[i] = p1->getX()[i] - p2->getX()[i];
            }
            double norm = calculateNorm(xij);
            double pow_6 = pow((zeroCrossing / norm), 6);
            for (int i = 0; i < 3; i++) {
                double force_value = ((-24 * depthOfPotentialWell) / pow(norm, 2)) * (pow_6 - 2 * pow(pow_6, 2));
                newF1[i] += force_value;
                newF2[i] -= force_value;
            }
            p2->setF(newF2);
       }
       p1->setF(newF1);
    }
}

double LennardJones::calculateNorm(std::array<double, 3> x) {
    double norm = sqrt(pow(x[0], 2) + pow(x[1], 2) + pow(x[2], 2));
    return norm;
}

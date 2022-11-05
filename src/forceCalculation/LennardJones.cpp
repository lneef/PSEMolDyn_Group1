//
// Created by dominik on 05.11.22.
//

#include "LennardJones.h"

LennardJones::~LennardJones() = default;

void LennardJones::calculateF(ParticleContainer &particles) {
    //ToDo: Parameter mit Übergabe und nicht Hardcode values?
    int depthOfPotentialWell = 5;
    int zeroCrossing = 1;

    //ToDo: change to no pair twice
    for (auto &p1: particles) {
        std::array<double, 3> newF1 = p1.getF();
        for (auto &p2: particles) {
            std::array<double, 3> newF2 = p1.getF();
            //check if it the same particle
            if (p1 == p2) {
                continue;
            }
            std::array<double, 3> xij;
            double norm = calculateNorm(xij);
            double pow_6 = pow((zeroCrossing / norm), 6);
            for (int i = 0; i < 3; i++) {
                xij[i] = p1.getX()[i] - p2.getX()[i];
                double force_value = ((-24 * depthOfPotentialWell) / pow(xij, 2)) * (pow_6 - 2 * pow(pow_6, 2));
                newF1[i] += force_value;
                newF2[i] -= force_value;
            }
            p2.setF(newF2);
        }
        p1.setF(newF1);
    }
}

double Gravitation::calculateNorm(std::array<double, 3> x) {
    double norm = sqrt(pow(x[0], 2) + pow(x[1], 2) + pow(x[2], 2));
    return norm;
}

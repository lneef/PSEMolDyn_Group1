//
// Created by dominik on 27.10.22.
//

#include "Gravitation.h"

//calculation new force
void Gravitation::calculateF(ParticleContainer &particles) {
    //iterate over all pairs of particles
    for (auto &p1: particles) {
        std::array<double, 3> newF{};
        for (auto &p2: particles) {
            //check if it the same particle
            if (p1 == p2) {
                continue;
            }
            std::array<double, 3> xij;
            for (int i = 0; i < 3; i++) {
                xij[i] = p1.getX()[i] - p2.getX()[i];
            }
            double norm = calculateNorm(xij);

            std::array<double, 3> xji;
            //simple force calculation for all dimensions
            for (int i = 0; i < 3; i++) {
                xji[i] = p2.getX()[i] - p1.getX()[i];
                newF[i] += (p1.getM() * p2.getM() * (xji[i])) / pow(norm, 3);
            }
        }
        p1.setF(newF);
    }
}

//calculate norm of a vector
double Gravitation::calculateNorm(std::array<double, 3> x) {
    double norm = sqrt(pow(x[0], 2) + pow(x[1], 2) + pow(x[2], 2));
    return norm;
}

Gravitation::~Gravitation() = default;

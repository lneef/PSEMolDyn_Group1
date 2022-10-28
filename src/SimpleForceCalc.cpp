//
// Created by dominik on 27.10.22.
//

#include "SimpleForceCalc.h"

void SimpleForceCalc::calculateF(std::list <Particle> &particles) {
    std::list<Particle>::iterator iterator;
    iterator = particles.begin();

    for (auto &p1: particles) {
        std::array<double, 3> newF{};
        for (auto &p2: particles) {
            // @TODO: insert calculation of forces here!
            if (p1 == p2) {
                continue;
            }
            std::array<double, 3> xij;
            for (int i = 0; i < 3; i++) {
                xij[i] = p1.getX()[i] - p2.getX()[i];
            }
            double norm = calculateNorm(xij);

            std::array<double, 3> xji;
            for (int i = 0; i < 3; i++) {
                xji[i] = p2.getX()[i] - p1.getX()[i];
                newF[i] += (p1.getM() * p2.getM() * (xji[i])) / pow(norm, 3);
            }
        }
        p1.setF(newF);
    }
}

double SimpleForceCalc::calculateNorm(std::array<double, 3> x) {
    double norm = sqrt(pow(x[0], 2) + pow(x[1], 2) + pow(x[2], 2));
    return norm;
}
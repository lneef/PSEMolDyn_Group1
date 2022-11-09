//
// Created by dominik on 09.11.22.
//
#pragma once

#include "../ParticleContainer.h"
#include "../utils/MaxwellBoltzmannDistribution.h"

class CuboidGenerator {
private:
    double meanV = 0.1;

    std::array<double, 3> calculateV(std::array<double, 3> v);

public:
    CuboidGenerator();

    virtual ~CuboidGenerator();

    void
    generateCuboid(ParticleContainer &particles, std::array<double, 3> x, std::array<int, 3> n, double h, double m,
                   std::array<double, 3> v);
};


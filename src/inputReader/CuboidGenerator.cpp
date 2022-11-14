
#include "CuboidGenerator.h"
#include <iostream>

CuboidGenerator::CuboidGenerator() = default;

CuboidGenerator::~CuboidGenerator() = default;

std::array<double, 3> CuboidGenerator::calculateV(std::array<double, 3> v) {
    MaxwellBoltzmannDistribution mb;
    //calculate velocity with thermal friction
    std::array<double, 3> mbV = mb.maxwellBoltzmannDistributedVelocity(meanV, sizeof(v) / sizeof(v[0]));
    std::array<double, 3> newV{};
    for (int i = 0; i < 3; i++) {
        newV[i] = v[i] + mbV[i];
    }
    return newV;
}

void CuboidGenerator::generateCuboid(ParticleContainer &particles, std::array<double, 3> x, std::array<int, 3> n,
                                     double h, double m, std::array<double, 3> v) {
    std::array<double, 3> newV = calculateV(v);
    std::array<double, 3> newX{};
    //iterate over cuboid in each dimension
    for (int x_cord = 0; x_cord < n[0]; x_cord++) {
        newX[0] = x[0] + (x_cord * h);
        for (int y_cord = 0; y_cord < n[1]; y_cord++) {
            newX[1] = x[1] + (y_cord * h);
            for (int z_cord = 0; z_cord < n[2]; z_cord++) {
                newX[2] = x[2] + (z_cord * h);
                //stores particle in ParticleContainer
                particles.addParticle(Particle(newX, newV, m));
            }
        }
    }

}



#pragma once

#include "../ParticleContainer.h"
#include "../utils/MaxwellBoltzmannDistribution.h"

/**
 * @brief CuboidGenerator generates cuboids of particles form input values
 *
 * CuboidGenerator generates cuboids of particles form input values, which are collected by instances of Cuboid_TxtFile or Cuboid_cl.
*/
class CuboidGenerator {
private:
    double meanV = 0.1;

    /**
     * @brief Calculates velocity of particles with given velocity and the MaxwellBoltzmannDistribution
     *
     * @param v Array representaion of the velocities of the particles in all three dimensions
     * @return velocity with thermal friction
    */
    std::array<double, 3> calculateV(std::array<double, 3> v);

public:
    CuboidGenerator();

    virtual ~CuboidGenerator();

    /**
     * @brief Generates cuboids of particles with given values and stores them in instance of ParticleContainer
     *
     * @param particles ParticleContainer where the particles are stored
     * @param x Array represention three dimensional position of the particle
     * @param n Array representation of quantity of particles in each dimension
     * @param h Integer representation of distance between the particles
     * @param m Integer representation of mass of one particle
     * @param v Array representaion of the velocities of the particles in all three dimensions
    */
    void generateCuboid(ParticleContainer &particles, std::array<double, 3> x, std::array<int, 3> n, double h, double m,
                        std::array<double, 3> v);
};

